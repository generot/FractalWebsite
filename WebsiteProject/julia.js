let canvas = document.getElementById("Canvas");
let ctx = canvas.getContext("2d");

let width = canvas.width, height = canvas.height, manager = new CanvasManagement(canvas),
pixels = new Uint8ClampedArray(4*width*height);

let m0 = document.getElementById("mode0"), m1 = document.getElementById("mode1");
var input = parseFloat(document.getElementById("input1").value), 
input2 = parseFloat(document.getElementById("input2").value);

var pos = {
    x: 0,
    y: 0
};
var tpos = {
    x: input,
    y: input2
};

window.addEventListener("mousemove", function(event){
    pos.x = ((event.clientX % width)-width/2)/(width/2);
    pos.y = ((event.clientY % height)-height/2)/(height/2);
})

function draw(post){
    manager.clear();

    let halfw = width/2, halfh = height/2;
    for(let i = -halfh; i < halfh; i++)
        for(let j = -halfw; j < halfw; j++){
            let x = j/200, y = i/200;

            const real = post.x, img = post.y;

            let iter, max = 100;
            for(iter = 0; iter < max; iter++){
                let sqReal = x * x - y * y,
                sqImg = 2 * x * y;

                x = real + sqReal;
                y = img + sqImg;
                if(Math.abs(x+y) > 4)
                    break;
            }
            iter *= 2;

            let index = (j + halfw + (i + halfh) * width) * 4, toComp = Math.floor(max/3);
            pixels[index+3] = 255;

            if(iter < toComp){
                pixels[index] = iter/max * (Math.random()+5) * 60;
                pixels[index+1] = pixels[index+2] = 0;
            } else if(iter > toComp && iter < toComp*2){
                pixels[index] = iter/max * (Math.random()+5) * 60;
                pixels[index+1] = iter/max * (Math.random()+5) * 65;
                pixels[index+2] = 0;
            } else if(iter > toComp*2 && iter < max){
                pixels[index] = iter/max * (Math.random()+5) * 60;
                pixels[index+1] = iter/max * (Math.random()+5) * 65;
                pixels[index+2] = iter/max * (Math.random()+5) * 50;
            } else pixels[index] = pixels[index+1] = pixels[index+2] = 0;
        }

        let imageData = new ImageData(pixels, width, height);
        ctx.putImageData(imageData, 0, 0);
}

var interval = setInterval(draw, 1000/60, pos);


