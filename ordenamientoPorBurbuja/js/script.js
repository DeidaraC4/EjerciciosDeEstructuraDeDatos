const arr = [64, 39, 82, 37, 49, 21, 18, 54, 21, 34, 87, 21, 32, 41, 23, 23, 67, 98, 43, 56];
let bubble = 0;

for (ele of arr){
    document.getElementById("txt1").innerText += ele + " ..";
}

for (let i = 0; i < arr.length; i++){
    for (let j = 0; j < arr.length - i; j++){
        if (arr[j] > arr[j+1]){
            bubble = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = bubble;
        }
    }
}

for (ele of arr){
    document.getElementById("txt2").innerText += ele + " ..";
}