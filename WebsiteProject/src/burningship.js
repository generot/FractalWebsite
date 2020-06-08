let canvas = document.getElementById("myCanvas");
let cont = canvas.getContext("2d"), pixels = new Uint8ClampedArray(4*canvas.width*canvas.height);

let scale = 200, defScale = scale, factor = 1, speed = 0.018888;
let manager = new CanvasManagement(canvas);

var offset = {
    x: 0,
    y: 0
};

function setOffset(event){
    let halfX = canvas.width/2, halfY = canvas.height/2;
    let normX = (event.clientX % canvas.width - halfX)/halfX, 
    normY = (event.clientY % canvas.height - halfY)/halfY;

    offset.x += normX/scale * defScale;
    offset.y += normY/scale * defScale;
}

function setScale(zoom){
    if(zoom) {
        scale += factor;
        factor = scale/defScale * 4;
    }
    else if(!zoom && scale+1 > defScale) {
        scale -= factor
        factor = scale/defScale * 4;
    }
}

function abs(value){ return value > 0 ? value : -value; }

window.addEventListener("keydown", function(event){
    switch(event.which){
    case 107: {
        setScale(true);
        break;
    }
    case 109: {
        setScale(false);
        break;
    }
    default: return;
    }
});

function draw(){
    manager.clear();
    let x = canvas.width/2, y = canvas.height/2;

    for(let i = -y; i < y; i++)
        for(let j = -x; j < x; j++){
            let real = j/scale + offset.x, img = i/scale + offset.y;

            const constReal = real, constImg = img;

            let iterator, max = 50;
            for(iterator = 0; iterator < max; iterator++){
                let areal = abs(real), aimg = abs(img);

                let sqA = real*real - img*img, 
                sqB = 2*areal*aimg;

                real = sqA + constReal;
                img = sqB + constImg;
                if(real*real + img*img > 4)
                    break;
            }

            let index = (j + x + (i + y) * canvas.width) * 4;
            pixels[index+3] = 255;

            if(iterator == max)
                pixels[index] = pixels[index + 1] = pixels[index + 2] = 0;
            else {
                pixels[index + 2] = 0;
                pixels[index] = iterator/max * 400;
                pixels[index + 1] = iterator/max * 200;
            }
        }

    let idata = new ImageData(pixels, canvas.width, canvas.height);
    cont.putImageData(idata, 0, 0);
}

setInterval(draw, 1000/60);
