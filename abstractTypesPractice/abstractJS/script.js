class Persona{
    constructor(){
        if (this.constructor === Persona){
            throw new Error("its not possible to instance this class, try using a subclass");
        }
    }
    decir(){
        throw new Error("decir() method must be implemented");
    }
}

class EstudiantePrimerizo extends Persona{
     decir(){
        return "Me estoy divirtiendo mucho aprendiendo a programar :D";
     }
}

class EstudianteSenior extends Persona{
    decir(){
        return "Lol no saben la que les espera";
    }
}

estudiante1 = new EstudiantePrimerizo();
estudiante2 = new EstudianteSenior();

document.getElementById("estudiante1").innerText = estudiante1.decir();
document.getElementById("estudiante2").innerText = estudiante2.decir();