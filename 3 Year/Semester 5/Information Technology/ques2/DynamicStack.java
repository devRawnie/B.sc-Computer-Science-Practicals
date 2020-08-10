/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ques2;

import java.util.ArrayList;

/**
 *
 * @author KMV
 */
public class DynamicStack extends Stack {

    private ArrayList<Integer> list;

    public DynamicStack() {
        System.out.println("\nDynamic Stack Implementation");
        list = new ArrayList<>();
    }

    @Override
    void push(int x) {
        list.add(x);
    }

    @Override
    int pop() throws IndexOutOfBoundsException {
        int x = list.get(list.size() - 1);
        list.remove(list.size() - 1);
        return x;
    }

    @Override
    void display() {
        if (list.size() > 0) {
            System.out.println("\nThe Stack is: ");
            for (int i = list.size() - 1; i >= 0; i--) {
                System.out.print(list.get(i) + "->");
            }
            System.out.println();
        } else {
            System.out.println("\nStack is empty!");
        }

    }

}
