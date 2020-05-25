let canvas = document.getElementById("myCanvas");
let cont = canvas.getContext("2d"), idata = cont.getImageData(0, 0, canvas.width, canvas.height),
pixels = idata.data;

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
    //let prevScale = scale;
    if(zoom) {
        scale += factor;
        factor = scale/defScale * 4;
    }
    else if(!zoom && scale+1 > defScale) {
        scale -= factor
        factor = scale/defScale * 4;
    }
}

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
    //Експериментални движения
    case 104: {
        offset.y -= speed/scale * defScale;
        break;
    }
    case 101: {
        offset.y += speed/scale * defScale;
        break;
    }
    case 100: {
        offset.x -= speed/scale * defScale;
        break;
    }
    case 102: {
        offset.x += speed/scale * defScale;
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

            let iterator, max = 100;
            for(iterator = 0; iterator < max; iterator++){
                let sqA = real*real - img*img, 
                sqB = 2*real*img;

                real = constReal + sqA;
                img = constImg + sqB;
                if(Math.abs(real + img) > 4)
                    break;
            }

            let index = (j + x + (i + y) * canvas.width) * 4, toComp = Math.floor(max/3);
            pixels[index+3] = 255;

            if(iterator == max)
                pixels[index] = pixels[index+1] = pixels[index+2] = 0;
            else {
                let hsbVal = Graphics.HSLtoRGB((iterator * 20) % 360, 0.7, 0.6);
                pixels[index] = hsbVal.r;
                pixels[index + 1] = hsbVal.g;
                pixels[index + 2] = hsbVal.b;
            }
        }

    idata.data = pixels;
    cont.putImageData(idata, 0, 0);
}

setInterval(draw, 1000/60);
