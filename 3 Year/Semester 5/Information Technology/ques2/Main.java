/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ques2;

import java.util.Scanner;

/**
 *
 * @author KMV
 */
public class Main {

    static Scanner in = new Scanner(System.in);
    static void displayMenu(){
        System.out.println("\n\n1.Push");
        System.out.println("2.Pop");
        System.out.println("3.Display");
        System.out.println("4.Go to main menu");
        System.out.print("Enter your choice: ");
    }
    static void init(Stack stack) {
        while (true) {
            displayMenu();
            int x = in.nextInt();
            switch (x) {
                case 1:
                    System.out.println("\nEnter any number: ");
                    int number = in.nextInt();
                    stack.push(number);
                    break;
                case 2:
                    try {
                        System.out.println("\n" + stack.pop() + " removed from stack");
                    } catch (IndexOutOfBoundsException e) {
                        System.out.println("\nStack is empty!");
                    }
                    break;
                case 3:
                    stack.display();
                    break;
                case 4:
                    return;
                default:
                    System.out.println("Invalid Choice.");
            }

        }
    }

    public static void main(String[] args) {
        while(true){
        System.out.println("\n\nEnter your choice: ");
        System.out.println("1.Static Stack");
        System.out.println("2.Dynamic Stack");
        System.out.println("3.Exit");
        int ch = in.nextInt();
        switch(ch){
            case 1: System.out.println("Enter size of the stack");
                    int size = in.nextInt();
                    init(new StaticStack(size));
                    break;
            case 2: init(new DynamicStack());
                    break;
            case 3: System.exit(0);        
            default: System.out.println("Invalid Choice");        
        }
        }
    }
}
