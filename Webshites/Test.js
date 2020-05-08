class myClass {
    constructor(name, age){
        this.name = name;
        this.age = age;
    }
    getInfo() {
        console.log("The student's name is " + this.name + " and he is " + this.age + " years old. ");    
    }
};

class Derived extends myClass{
    constructor(name, age, grade) {
        super(name, age);
        this.grade = grade;
    }
    getGrade() {
        console.log(this.name + "'s grade is: " + this.grade);
    }
}

function setup(){
    var student = new Derived("John Karabakh", 12, 6);
    student.getInfo();
    student.getGrade();
}

setup();