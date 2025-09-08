const arr = new Array(9).fill(0);
let twoDimArr = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

let k = 0;
for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
        document.getElementById("matriz").innerText += twoDimArr[j][i];
        arr[k] = twoDimArr[j][i];
        k += 1;
    }
    document.getElementById("matriz").innerText += "\n"
}

for(ele of arr){
    document.getElementById("vector").innerText += ele
}