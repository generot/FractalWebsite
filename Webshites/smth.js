var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d");
var button = document.getElementsByName("MyButton");
var radius = prompt("Enter a number");

function fractal(x, y, r, step){
    ctx.arc(x, y, r, 0, 2 * Math.PI);
    ctx.stroke();
    if(step > 0) {
        fractal(x-r, y, r/2, step-1);
        fractal(x+r, y, r/2, step-1);
    }
}

function setup(){
    let iters = 5, rad = parseInt(radius, 10);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    fractal(canvas.width/2, canvas.height/2, rad, iters);
}

function isClicked(){
    radius = prompt("Enter another number");
    setup();
}

setup();