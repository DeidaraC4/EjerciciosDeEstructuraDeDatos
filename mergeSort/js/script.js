function merge(array, left, mid, right){
    let a1 = mid - left + 1;
    let a2 = right - mid;

    const L = new Array(a1);
    const R = new Array(a2);

    for(let i = 0; i < a1; i++){
        L[i] = array[left + i];
    }

    for(let j = 0; j < a2; j++){
        R[j] = array[mid + j + 1];
    }

    let i = 0;
    let j = 0;
    let k = left;

    while(i < a1 && j < a2){
        if(L[i] < R[j]){
            array[k] = L[i];
            i++;
            k++;
        }else{
            array[k] = R[j];
            j++;
            k++;
        }
    }

    while(i < a1){
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < a2){
        array[k] = R[j];
        j++;
        k++;
    }
}

function mergeSort(array, left, right){
    if (left < right){
        let mid = Math.floor((right - left)/2) + left;
    
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

const arr = [34, 1, 48, 71, 29, 12, 303, 81, 8, 315, 3, 4, 32, 52, 53];

let text = "";
arr.forEach(element => { 
    text = text.concat(element + " ");
})

document.getElementById("desordenados").innerText = text;

mergeSort(arr, 0, arr.length - 1);

text = "";
arr.forEach(element => { 
    text = text.concat(element + " ");
})

document.getElementById("ordenados").innerText = text;