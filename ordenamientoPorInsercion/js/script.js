const arr = [29, 84, 56, 2, 76, 37, 39, 2];

function printArr(arr){
    let txt = "";

    arr.forEach(ele => {
        txt += ele + " ";
    });
    return txt;
}

document.getElementById("desordenado").innerText = printArr(arr);

for(i = 1; i < arr.length; i++){
    reserva = arr[i];

    j = i-1;
    while(j >= 0 && reserva < arr[j]){
        arr[j + 1] = arr[j];

        j -= 1;
    }
    arr[j + 1] = reserva;
}

document.getElementById("ordenado").innerText = printArr(arr);