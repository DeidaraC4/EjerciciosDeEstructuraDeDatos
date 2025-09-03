const numeros = [1, 2, 3, 4, 5];

document.getElementById("output").innerText = numeros;

numeros[0] = "erickferna29";

document.writeln(numeros + "<br>");

numeros.pop(4);

document.writeln(numeros + "<br>");

numeros.push("infinito y mas alla");

document.writeln(numeros);

document.getElementById("palco").addEventListener("click", () => {
    alert("la cantidad total de elementos del array es " + numeros.length);
});