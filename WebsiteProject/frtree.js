var canvas = document.getElementById("canvas");
var ctx = canvas.getContext("2d"), iterations = 1;

var cman = new CanvasManagement(canvas);

function FractalTree(len, ang, iter, intransX, intransY){
    ctx.save();
    ctx.translate(intransX, intransY);
    Graphics.DrawLine(0, -len);
    ctx.translate(0, -len);

    if(iter > 0){
        ctx.save();
        ctx.rotate(CanvasManagement.ToRadians(ang));
        FractalTree(len*0.8, ang, iter-1, 0, 0);
        ctx.restore();

        ctx.save();
        ctx.rotate(CanvasManagement.ToRadians(-ang));
        FractalTree(len*0.8, ang, iter-1, 0, 0);
        ctx.restore();
    }
    ctx.restore();
}

function draw(){
    cman.clear();
    let slider = document.getElementById("mySlider").value,
    slider2 = document.getElementById("Slider").value;
    FractalTree(slider2, slider, iterations, canvas.width/2, canvas.height);
}

setInterval(draw, 1000/60);


