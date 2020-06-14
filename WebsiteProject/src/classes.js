class CanvasManagement{
    constructor(canvas){
        this.canvas = canvas;
        this.ctx = this.canvas.getContext("2d");
    }

    clear(val = 0){
        let size = 4*this.canvas.width*this.canvas.height, texture = new Uint8ClampedArray(size);
        texture.fill(val);

        let newData = new ImageData(texture, this.canvas.width, this.canvas.height);
        this.ctx.putImageData(newData, 0, 0);
    }
    DrawCircle(pos, radius){
        let texture = this.ctx.getImageData(0, 0, this.canvas.width, this.canvas.height).data;
        for(let i = 0; i < 2*Math.PI; i += 0.0001){
            let x = Math.floor(Math.cos(i) * radius + pos.x), y = Math.floor(Math.sin(i) * radius + pos.y);
            let index = (x + y * this.canvas.width) * 4;

            texture[index] = texture[index+1] = texture[index+2] = 0;
            texture[index+3] = 255;
        }
        let newData = new ImageData(texture, this.canvas.width, this.canvas.height);
        this.ctx.putImageData(newData, 0, 0);
    }

    static ToRadians(deg){ return deg * Math.PI/180; }
}

class Rectangle {
    constructor(ctx, posX, posY, width, height){
        this.ctx = ctx;
        this.posX = posX;
        this.posY = posY;
        this.width = width;
        this.height = height;
    }

    GetArea(){ return this.width * this.height; }
    Draw(){
        this.ctx.beginPath();
        this.ctx.moveTo(this.posX, this.posY);

        this.ctx.lineTo(this.posX + this.width, this.posY);
        this.ctx.lineTo(this.posX + this.width, this.posY + this.height);

        this.ctx.moveTo(this.posX + this.width, this.posY + this.height);

        this.ctx.lineTo(this.posX, this.posY + this.height);
        this.ctx.lineTo(this.posX, this.posY);
        this.ctx.stroke();

        this.ctx.closePath();
    }
    Fill(color){
        this.ctx.fillStyle = color;
        this.ctx.fillRect(this.posX, this.posY, this.width, this.height);
    }
}

class Square extends Rectangle {
    constructor(ctx, posX, posY, length, col = "black"){
        super(ctx, posX, posY, length, length);
        this.length = length;
        this.col = col;
        this.Fill(this.col);
    }
    quadruple(){
        let i = {
            a: new Square(this.ctx, this.posX - this.length/4, 
                this.posY - this.length/4, this.length/2, this.col),
            b: new Square(this.ctx, this.posX + 3*this.length/4, 
                this.posY - this.length/4, this.length/2, this.col),
            c: new Square(this.ctx, this.posX - this.length/4, 
                this.posY + 3*this.length/4, this.length/2, this.col),
            d: new Square(this.ctx, this.posX + 3*this.length/4, 
                this.posY + 3*this.length/4, this.length/2, this.col)
        };
        return i;
    }
}

class Graphics {
    static DrawLine(ctx, x1, y1, color = "black", x = 0, y = 0){
        ctx.beginPath();

        ctx.moveTo(x,y);
        ctx.lineTo(x1, y1);

        ctx.closePath();
        ctx.strokeStyle = color;
        ctx.stroke();
    }

    static HSLtoRGB(hue, sat, br){
        if((hue >= 0 && hue <= 360) && (sat >= 0 && sat <= 1) && (br >= 0 && br <= 1)){
            let c = (1 - Math.abs(2*br - 1)) * sat,
            x = c * (1 - Math.abs((hue/60) % 2 - 1)),
            m = br - c/2;

            let primeR, primeG, primeB;
            if(hue >= 0 && hue <= 60){
                primeR = c;
                primeG = x;
                primeB = 0;
            } else if(hue >= 60 && hue <= 120){
                primeR = x;
                primeG = c;
                primeB = 0;
            } else if(hue >= 120 && hue <= 180){
                primeR = 0;
                primeG = c;
                primeB = x;
            } else if(hue >= 180 && hue <= 240){
                primeR = 0;
                primeG = x;
                primeB = c;
            } else if(hue >= 240 && hue <= 300){
                primeR = x;
                primeG = 0;
                primeB = c;
            } else if(hue >= 300 && hue <= 360){
                primeR = c;
                primeG = 0;
                primeB = x;
            }

            return {
                r: (primeR + m) * 255,
                g: (primeG + m) * 255,
                b: (primeB + m) * 255
            };

        } else return 0;
    }
}

class Triangle {
    constructor(ctx, vrt1, len){
        this.ctx = ctx;
        this.vrt = vrt1;
        this.len = len;
        let height = Math.floor(Math.sqrt(len*len - len*len/4));

        ctx.save();
        ctx.translate(vrt1.x, vrt1.y);
        Graphics.DrawLine(ctx, -len/2, height);

        ctx.translate(-len/2, height);
        Graphics.DrawLine(ctx, len, 0);

        ctx.translate(len, 0);
        Graphics.DrawLine(ctx, -len/2, -height);
        ctx.restore();
    }

    triple(){
        let newVert = {
            x: this.vrt.x + this.len/4,
            y: this.vrt.y + Math.floor(Math.sqrt(this.len*this.len/4 - this.len*this.len/16))
        }, nVertReverse = {
            x: this.vrt.x - this.len/4,
            y: this.vrt.y + Math.floor(Math.sqrt(this.len*this.len/4 - this.len*this.len/16))
        }

        return {
            a: new Triangle(this.ctx, this.vrt, this.len/2),
            b: new Triangle(this.ctx, newVert, this.len/2),
            c: new Triangle(this.ctx, nVertReverse, this.len/2)
        }
    }
}

class Lsystem {
    constructor(axiom, ...rules){
        this.axiom = axiom;
        this.ruleset = rules;
    }

    ApplyRules(iter) {
        let modstr = "";
        for(let i = 0; i < this.axiom.length; i++){
            for(let j = 0; j < this.ruleset.length; j++){
                if(this.axiom[i] == this.ruleset[j].a){
                    modstr += this.ruleset[j].b;
                    break;
                } else if(j == this.ruleset.length - 1) modstr += this.axiom[i];
            }
        }

        this.axiom = modstr;
        if(iter > 0) this.ApplyRules(iter-1);
    }
}