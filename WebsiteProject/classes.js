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