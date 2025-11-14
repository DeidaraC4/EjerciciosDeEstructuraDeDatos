const MAXSIZE = 5;
let queue = new Array(MAXSIZE);
let front = -1, rear = -1;

function insertar() {
    let elementoStr = prompt("\nIngrese el elemento: ");
    
    if (elementoStr === null) {
        console.log("\nInserción cancelada.\n");
        return;
    }

    let elemento = parseInt(elementoStr);

    if (isNaN(elemento)) {
        console.log("\nentrada invalida. vuelva a intentarlo.\n");
        return;
    }

    if (rear === MAXSIZE - 1) {
        console.log("\nDESBORDAMIENTO (OVERFLOW)\n");
        return;
    }
    if (front === -1 && rear === -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = elemento;
    console.log("\nElemento insertado correctamente.\n");
}

function eliminar() {
    if (front === -1 || front > rear) {
        console.log("\nSUBDESBORDAMIENTO (UNDERFLOW)\n");
        return;
    }
    let elemento = queue[front];
    if (front === rear) {
        front = rear = -1;
    } else {
        front++;
    }
    console.log(`\nElemento eliminado: ${elemento}\n`);
}

function mostrar() {
    if (rear === -1 || front === -1 || front > rear) {
        console.log("\nLa cola esta vacia.\n");
    } else {
        console.log("\nElementos en la cola:\n");
        for (let i = front; i <= rear; i++) {
            console.log(queue[i]);
        }
    }
}

document.getElementById("startButton").addEventListener("click", () => {
    
    queue = new Array(MAXSIZE);
    front = -1;
    rear = -1;
    console.clear();
    console.log("--- Simulación de Cola Iniciada (Cola reseteada) ---");

    let opcion = 0;
    const menu = `
************************* MENU PRINCIPAL ***************************
======================================================================
1. Insertar un elemento
2. Eliminar un elemento
3. Mostrar La cola
4. Salir
Ingrese su opcion: 
    `;

    while (opcion !== 4) {
        let input = prompt(menu);

        if (input === null) {
            console.log("\nSimulación cancelada por el usuario.\n");
            opcion = 4;
            continue; 
        }

        opcion = parseInt(input);

        if (isNaN(opcion)) {
            opcion = -1;
        }

        switch (opcion) {
            case 1:
                insertar();
                break;
            case 2:
                eliminar();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                console.log("\nSaliendo del programa.\n");
                break;
            default:
                console.log("\nOpcion invalida. Intente nuevamente.\n");
                break;
        }
    }
});