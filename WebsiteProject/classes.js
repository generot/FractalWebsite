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

    DrawCircle(pos, radius) {
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

// let canvas = document.getElementById("Canvas");
// let pos = {
//     x: canvas.width/2,
//     y: canvas.height/2
// };

// function debug(){
//     var lt = new CanvasManagement(canvas);
//     lt.clear();
//     lt.DrawCircle(pos, 100);
// }

// debug();