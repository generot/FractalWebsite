//Testing commitment
var canvas = document.getElementById("myCanvas");
var cont = canvas.getContext("2d"), idata = cont.getImageData(0, 0, canvas.width, canvas.height),
pixels = idata.data;

var scale = 200, defScale = scale, factor = 15;

var offset = {
    x: 0,
    y: 0
};

function clear(){
    for(let i = 0; i < canvas.height; i++)
        for(let j = 0; j < canvas.width; j++){
            let ind = (j + i * canvas.width) * 4;
            pixels[ind] = pixels[ind+1] = pixels[ind+2] = pixels[ind+3] = 255;
        }

    idata.data = pixels;
    cont.putImageData(idata, 0, 0);
}

function setOffset(event){
    let halfX = canvas.width/2, halfY = canvas.height/2;
    let normX = (event.clientX % canvas.width - halfX)/halfX, 
    normY = (event.clientY % canvas.height - halfY)/halfY;

    offset.x += normX/scale * defScale;
    offset.y += normY/scale * defScale;
}

function setScale(){
    let prevScale = scale;
    scale += factor;
    factor += scale - prevScale;
}

function draw(){
    clear();
    let x = canvas.width/2, y = canvas.height/2, sc = parseInt(scale, 10);

    for(let i = -y; i < y; i++)
        for(let j = -x; j < x; j++){
            let real = j/sc + offset.x, img = i/sc + offset.y;
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

            if(iterator < toComp){
                pixels[index] = iterator/max/1.2 * (Math.random()+5) * 60;
                pixels[index+1] = pixels[index+2] = 0;
            } else if(iterator > toComp && iterator < toComp*2){
                pixels[index] = iterator/max/1.4 * (Math.random()+5) * 60;
                pixels[index+1] = iterator/max/1.7 * (Math.random()+5) * 65;
                pixels[index+2] = 0;
            } else if(iterator > toComp*2 && iterator < max){
                pixels[index] = iterator/max/1.4 * (Math.random()+5) * 60;
                pixels[index+1] = iterator/max/1.5 * (Math.random()+4) * 65;
                pixels[index+2] = iterator/max/1.3 * (Math.random()+5) * 70;
            } else pixels[index] = pixels[index+1] = pixels[index+2] = 0;
        }

    idata.data = pixels;
    cont.putImageData(idata, 0, 0);
}

setInterval(draw, 1000/60);
