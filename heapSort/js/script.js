function heapSort(array){
    temp = 0;
    for(let i = 1; i < array.length; i++){
        for(let j = array.length - i; j > 0; j--){
            if(array[j] > array[Math.round((j-1)/2)]){
                temp = array[j];
                array[j] = array[Math.round((j-1)/2)]
                array[Math.round((j-1)/2)] = temp
            }
        }
        temp = array[0];
        array[0] = array[array.length - i];
        array[array.length - i] = temp;
    }
}

const arr = [6, 1, 5, 60, 13, 2, 78, 41, 11, 14, 18, 38, 484, 23, 1];
let text = "";

arr.forEach((ele) =>{
    text = text.concat(ele + " ");
})
document.getElementById("desordenados").innerText = text;

heapSort(arr);

text = "";

arr.forEach((ele) =>{
    text = text.concat(ele + " ");
})
document.getElementById("ordenados").innerText = text;