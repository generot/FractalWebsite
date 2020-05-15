class CanvasManagement{
    constructor(canvas){
        this.canvas = canvas;
        this.ctx = this.canvas.getContext("2d");
    }

    clear(){
        let texture = this.ctx.getImageData(0, 0, this.canvas.width, this.canvas.height).data;

        for(let i = 0; i < this.canvas.height; i++)
            for(let j = 0; j < this.canvas.width; j++){
                let ind = (j + i * this.canvas.width) * 4;
                texture[ind] = texture[ind+1] = texture[ind+2] = 255;
                texture[ind+3] = 255;
            }
    
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

    static ToRadians(deg){return deg * Math.PI/180;}
}

class Rectangle {
    constructor(ctx, posX, posY, width, height){
        this.ctx = ctx;
        this.posX = posX;
        this.posY = posY;
        this.width = width;
        this.height = height;
    }

    GetArea(){return this.width * this.height;}
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
    Fill(){this.ctx.fillRect(this.posX, this.posY, this.width, this.height);}
}

class Square extends Rectangle {
    constructor(ctx, posX, posY, length){
        super(ctx, posX, posY, length, length);
        this.length = length;
        this.Fill();
    }
    quadruple(){
        let i = {
            a: new Square(this.ctx, this.posX - this.length/4, 
                this.posY - this.length/4, this.length/2),
            b: new Square(this.ctx, this.posX + 3*this.length/4, 
                this.posY - this.length/4, this.length/2),
            c: new Square(this.ctx, this.posX - this.length/4, 
                this.posY + 3*this.length/4, this.length/2),
            d: new Square(this.ctx, this.posX + 3*this.length/4, 
                this.posY + 3*this.length/4, this.length/2)
        };
        return i;
    }
}

class Graphics {
    static DrawLine(ctx, x1, y1, x = 0, y = 0){
        ctx.beginPath();

        ctx.moveTo(x,y);
        ctx.lineTo(x1, y1);

        ctx.closePath();
        ctx.stroke();
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