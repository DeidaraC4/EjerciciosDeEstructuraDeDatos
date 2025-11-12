MAX_SIZE = 100
stack = [0] * MAX_SIZE
top = -1

def push(item):
    global top #modificar el valor de top para todas las funciones que lo esten usando
    if top == MAX_SIZE - 1:
        print("stack overflow")
        return
    top += 1
    stack[top] = item

def pop():
    global top
    if top == -1:
        print("Stack Underflow")
        return -1
    item = stack[top]
    top -= 1
    return item

def peek():
    if top == -1:
        print("Pila vacia")
        return -1
    return stack[top]

def isEmpty():
    return top == -1

def isFull():
    return top == MAX_SIZE - 1

push(10)
push(20)
push(30)

print(f"elemento superior: {peek()}")
print(f"extrae elemento: {pop()}")
print(f"elemento superior: {peek()}")