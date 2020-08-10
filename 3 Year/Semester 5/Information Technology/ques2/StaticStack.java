/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ques2;

/**
 *
 * @author KMV
 */
public class StaticStack extends Stack {

    private int[] list;
    private int top;
    private int size;

    public StaticStack(int size) {
        System.out.println("\nStatic Stack implementation!!");
        this.size = size;
        list = new int[size];
        top = -1;
    }

    @Override
    void push(int x) {
        if (top < size - 1) {
            list[++top] = x;
            display();
        } else {
            System.out.println("\nStack is full. Delete some elements first!");
        }
    }

    @Override
    void display() {
        if (top == -1) {
            System.out.println("\nStack is empty!");
        } else {

            System.out.println("\nThe Stack is: ");
            for (int i = top; i >= 0; i--) {
                System.out.print(list[i] + "->");
            }
            System.out.println();
        }
    }

    @Override
    int pop() throws IndexOutOfBoundsException {
        int x = list[top];
        top--;
        return x;
    }

}
