using System;

public class StackProgram
{
    private static int MAX_SIZE = 100;
    private static int[] stack = new int[MAX_SIZE];
    private static int top = -1;

    public static void push(int item)
    {
        if (top == MAX_SIZE - 1)
        {
            Console.WriteLine("stack overflow");
            return;
        }
        stack[++top] = item;
    }

    public static int pop()
    {
        if (top == -1)
        {
            Console.WriteLine("Stack Underflow");
            return -1; // Devuelve -1 para concordar con peek()
        }
        return stack[top--];
    }

    public static int peek()
    {
        if (top == -1)
        {
            Console.WriteLine("Pila vacia");
            return -1;
        }
        return stack[top];
    }

    public static bool isEmpty()
    {
        return top == -1;
    }

    public static bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    public static void Main(string[] args)
    {
        push(10);
        push(20);
        push(30);

        Console.WriteLine("elemento superior: " + peek());
        Console.WriteLine("extrae elemento: " + pop());
        Console.WriteLine("elemento superior: " + peek());
    }
}