function getPivot(array, start, end){
    let i = start - 1;
    let pivot = array[end];
    let temp;

    for(j = start; j <= end; j++){
        if(array[j] <= pivot){
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    return i
}

function quickSort(array, start, end){
    if(end <= start){
        return
    }

    pivot = getPivot(array, start, end)
    quickSort(array, start, pivot - 1)
    quickSort(array, pivot + 1, end)
}

const arr = [78, 64, 91, 73, 40, 15, 91, 36, 47, 51, 67, 19, 34, 69, 2, 1, 36, 4, 49, 7, 25, 94, 53, 5, 2];
let text = "";
arr.forEach(element => {
    text = text.concat(" ", element)
});
document.getElementById("desordenados").innerText = text;

text = ""

quickSort(arr, 0, arr.length - 1);

arr.forEach(element => {
    text = text.concat(" ", element)
});

document.getElementById("ordenados").innerText = text;
