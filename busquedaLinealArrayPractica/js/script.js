const arr = [1, 2, 3, 4, 5]

document.getElementById("button").addEventListener("click", () => {
    let num = document.getElementById("input").value
    if (num in arr){
        console.log("true")
    }else{
        console.log("false")
    }
})