var canvas = document.getElementById("cnv"),
ctx = canvas.getContext("2d"), canman = new CanvasManagement(canvas);

var rule1 = {
    a: 'X',
    b: "X+YF+"
},  rule2 = {
    a: 'Y',
    b: "−FX−Y"
},  axiom = "FX";

var it = 0;
canman.clear();

function Setup(iter){
    canman.clear();

    let lsys = new Lsystem(axiom, rule1, rule2);
    lsys.ApplyRules(iter);

    let str = lsys.axiom, initLen = 7;
    ctx.translate(150, 400);

    for(let i = 0; i < str.length - 1; i++){
        if(str[i] == 'F'){
            Graphics.DrawLine(ctx, 0, -initLen, "white");
            ctx.translate(0, -initLen);
        } else if(str[i] == '+')
            ctx.rotate(CanvasManagement.ToRadians(90));
        else ctx.rotate(CanvasManagement.ToRadians(-90));
    }
}
