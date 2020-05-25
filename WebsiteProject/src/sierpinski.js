var canvas = document.getElementById("myCanvas"),
ctx = canvas.getContext("2d");

let vr1 = {
    x: 300,
    y: 50
};

var tr = {
    a: new Triangle(ctx, vr1, 550)
}, itr = 0;

var cman = new CanvasManagement(canvas);
function draw(obj, iter){
    let objects = [];
    Object.keys(obj).forEach(function(key){
        objects.push(obj[key]);
    });
    if(iter > 0){
        for(let i = 0; i < objects.length; i++){
            draw(objects[i].triple(), iter-1);
        }
    }
}