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
public abstract class Stack {
    public Stack() {

    }

    abstract void push(int x);

    abstract int pop() throws IndexOutOfBoundsException;

    abstract void display();

}
