let canvas = document.getElementById("myCanvas");
let cont = canvas.getContext("2d");

var scale = 180, defScale = scale, factor = 1, speed = 0.018888, slider = document.getElementById("sldr");

let manager = new CanvasManagement(canvas), imData = cont.getImageData(0, 0, canvas.width, canvas.height),
pixels = imData.data;


var offset = {
    x: -0.5,
    y: 0
}, max = 50;

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

window.addEventListener("keydown", function(event){
    //Numpad input
    switch(event.which){
    case 107: setScale(true); break; //'+'
    case 109: setScale(false); break; //'-'
    case 104: max < 500 ? max += 5 : 0; break; //'8'
    case 105: max > 5 ? max -= 5 : 0; break; //'9'
    default: break;
    }
    
});

function draw(){
    manager.clear();
    let x = canvas.width/2, y = canvas.height/2;

    for(let i = -y; i < y; i++)
        for(let j = -x; j < x; j++){
            let index = (j + x + (i + y) * canvas.width) * 4,
            real = j/scale + offset.x, img = i/scale + offset.y;

            const constReal = real, constImg = img;

            let iterator;
            
            for(iterator = 0; iterator < max; iterator++){
                let sqA = real*real - img*img, 
                sqB = 2*real*img;
        
                real = constReal + sqA;
                img = constImg + sqB;
                if(real * real + img * img > 4)
                    break;
            }

            pixels[index+3] = 255;
            
            if(iterator == max)
                pixels[index] = pixels[index+1] = pixels[index+2] = 0;
            else {
                let hsbVal = Graphics.HSLtoRGB((iterator/max) * 360, 0.6, 0.5);
                pixels[index] = hsbVal.r;
                pixels[index + 1] = hsbVal.g;
                pixels[index + 2] = hsbVal.b;
            }
        }

    imData.data = pixels;
    cont.putImageData(imData, 0, 0);
}

setInterval(draw, 10/6);

