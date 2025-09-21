const arr = [45, 62, 41, 41, 34, 31, 87, 99, 86, 15];

function printArr(arr){
    let txt = " ";
    arr.forEach(ele => {
        txt += ele + " ";
    });
    return txt;
}

document.getElementById("desordenado").innerText = printArr(arr);

for(i = 0; i < arr.length; i++){
    little = i

    for(j = i + 1; j < arr.length; j++){
        if(arr[little] > arr[j]){
            little = j;
        }
    }
    let temp = arr[i];
    arr[i] = arr[little];
    arr[little] = temp;
}

document.getElementById("ordenado").innerText = printArr(arr);