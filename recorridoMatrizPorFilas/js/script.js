const arr = new Array(9).fill(0);
let twoDimArr = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

let k = 0;
for(row of twoDimArr){
    for(ele of row){
        document.getElementById("matriz").innerText += ele;
        arr[k] = ele
        k += 1;
    }
    document.getElementById("matriz").innerText += "\n"
}

for(ele of arr){
    document.getElementById("vector").innerText += ele
}