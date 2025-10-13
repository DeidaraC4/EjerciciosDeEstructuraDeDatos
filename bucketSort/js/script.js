const arr = [0.93, 0.4, 0.50, 0.34, 0.94, 0.90, 0.94, 0.992, 0.42, 0.34, 0.42, 0.33, 0.25, 0.2, 0.04, 0.19, 0.52, 0.07, 0.32];

const bucket = Array.from({length: 10}, () => [])

let text = "";
arr.forEach(ele => {
    text = text.concat(ele, " ");
}); document.getElementById("desordenados").innerText = text;

arr.forEach(ele => {
    bucket[Math.floor(ele*10)].push(ele);
})

arr.length = 0;

bucket.forEach(list => {
    for(i = 1; i < list.length; i++){
        let reserve = list[i];

        j = i - 1;
        while(j>=0 && reserve < list[j]){
            list[j + 1] = list[j];

            j -= 1;
        }
        list[j + 1] = reserve;
    }
    arr.push(list);
})

text = "";
arr.forEach(ele => {
    text = text.concat(ele, " ");
}); document.getElementById("ordenados").innerText = text;