const arr = [10, 20, 30, 40, 50, 60];
let text;

text = "<p>Los elementos de la lista son: </p><li>";
for (i of arr){
    text += `<ul>${i}</ul>`;
}
text += "</li>";

document.getElementById("button").addEventListener("click", () => {
    num = document.getElementById("num").value;
    position = document.getElementById("position").value;
    arr.splice(position, 0, num);
    arr.pop();
    console.log(arr)
})

document.getElementById("list").innerHTML = text;