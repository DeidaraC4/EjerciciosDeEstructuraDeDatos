arr = [4, 10, 9, 47, 90, 9, 3, 341, 551, 79, 8];

let text = "";
arr.forEach(ele => {
    text = text.concat(ele, " ");
})

document.getElementById("desordenados").innerText = text;

for(div = Math.floor((arr.length - 1)/2); div >= 1; div = Math.floor(div/2)){
    let separation = div;
    for(i = div; i < arr.length; i++){
        reserve = arr[i];

        j = i - separation;
        while(j >= 0 && reserve < arr[j]){
            arr[j + separation] = arr[j];

            j -= separation;
        }
        arr[j + separation] = reserve;
    }
}

text = "";
arr.forEach(ele => {
    text = text.concat(ele, " ");
})
document.getElementById("ordenados").innerText = text;