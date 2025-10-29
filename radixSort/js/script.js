function printArray(arr, id) {
    let text = "";
    for (let ele of arr) {
        text += ele + ", ";
    }
    document.getElementById(id).innerText = text;
}

let arr = [938, 4, 102, 30, 5, 2, 4928, 701, 230, 71, 92, 474, 91, 2];

console.log("desordenados: ");
printArray(arr, "desordenados");

let max = arr[0];
for (let ele of arr) {
    if (max < ele) {
        max = ele;
    }
}

let cont = 1;
while (1 < max) {
    max /= 10;
    cont++;
}

for (let k = 0; k < cont; k++) {
    for (let i = 1; i < arr.length; i++) {
        let reserva = arr[i];
        let j = i - 1;

        let exp = Math.pow(10, k);
        let digit_reserva = Math.floor(reserva / exp) % 10;
        
        while (j >= 0) {
            let digit_j = Math.floor(arr[j] / exp) % 10;
            if (digit_reserva < digit_j) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = reserva;
    }
}

console.log("ordenados: ");
printArray(arr, "ordenados");