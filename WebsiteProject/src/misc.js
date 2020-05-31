var cnv = document.getElementById("canvas"),
ctx = cnv.getContext("2d"), cmn = new CanvasManagement(cnv);

let rules1 = {
    a: 'F',
    b: "FF"
},  rules2 = {
    a: 'X',
    b: "F+[[X]-X]-F[-FX]+X"
}, axiom = "X";

var it = 0;
cmn.clear();

function start(iter){
    let lsysinst = new Lsystem(axiom, rules2, rules1);
    lsysinst.ApplyRules(iter);

    cmn.clear();
    ctx.translate(cnv.width, cnv.height);
    ctx.rotate(CanvasManagement.ToRadians(-35));

    let modstr = lsysinst.axiom, lineLen = 10;

    for(let i = 0; i < modstr.length; i++){
        if(modstr[i] == 'F'){
            Graphics.DrawLine(ctx, 0, -lineLen, "white");
            ctx.translate(0, -lineLen);
        } 
        else if(modstr[i] == '+')
            ctx.rotate(CanvasManagement.ToRadians(25));
        else if(modstr[i] == '-')
            ctx.rotate(CanvasManagement.ToRadians(-25));
        else if(modstr[i] == '[')  
            ctx.save();
        else if(modstr[i] == ']') 
            ctx.restore();
    }
}