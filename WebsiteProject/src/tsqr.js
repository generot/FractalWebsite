var canvas = document.getElementById("canvas");
let ctx = canvas.getContext("2d");

var manager = new CanvasManagement(canvas);

var centLen = 300;
let newSq =  {
    a: new Square(ctx, canvas.width/2 - centLen/2, canvas.height/2 - centLen/2, centLen, "white")
};

var cnt = 0;
function setup(obj, beginning, max){
    let array = [];
    Object.keys(obj).forEach(function(key){
        array.push(obj[key].quadruple());
    });
    if(beginning < max) {
        for(let i = 0; i < array.length; i++)
            setup(array[i], beginning+1, max);
    }
}
