let canvas = document.getElementById("Canvas");
let ctx = canvas.getContext("2d");

let width = canvas.width, height = canvas.height, manager = new CanvasManagement(canvas),
pixels = new Uint8ClampedArray(4*width*height);

let m0 = document.getElementById("mode0"), m1 = document.getElementById("mode1");

var pos = {
    x: 0,
    y: 0
};
var tpos = {
    x: 0,
    y: 0
};

window.addEventListener("mousemove", function(event){
    pos.x = ((event.clientX % width)-width/2)/(width/2);
    pos.y = ((event.clientY % height)-height/2)/(height/2);
})

function draw(post){
    manager.clear();

    tpos.x = parseFloat(document.getElementById("input1").value);
    tpos.y = parseFloat(document.getElementById("input2").value);

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
            //iter *= 2;

            let index = (j + halfw + (i + halfh) * width) * 4, toComp = Math.floor(max/3);
            pixels[index+3] = 255;

            if(iter == max)
                pixels[index] = pixels[index+1] = pixels[index+2] = 0;
            else {
                let hsbVal = Graphics.HSLtoRGB((iter * 20) % 360, 0.7, 0.6);
                pixels[index] = hsbVal.r;
                pixels[index + 1] = hsbVal.g;
                pixels[index + 2] = hsbVal.b;
            }
        }

        let imageData = new ImageData(pixels, width, height);
        ctx.putImageData(imageData, 0, 0);
}

var interval;
interv(draw, 1000/60, pos);

function interv(func, time, arg){
    interval = setInterval(func, time, arg);
}


