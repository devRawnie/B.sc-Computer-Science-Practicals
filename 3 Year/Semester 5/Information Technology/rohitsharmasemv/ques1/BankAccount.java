/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rohitsharmasemv.ques1;

/**
 *
 * @author KMV
 */
class MinimumBalanceException extends Exception {
    public MinimumBalanceException(String s) {
        super(s);
    }
}

public class BankAccount {
    private int account_no;
    private float balance;
    // private final int SLAB1 = 5;
    // private final int SLAB2 = 10;
    // private final int SLAB3 = 20;

    public BankAccount(int acc) {
        this.account_no = acc;
        this.balance = 0;
    }

    public float deposit(float x) {
        this.balance += x;
        return this.balance;
    }

    public float withdraw(float x) {
        try {
            if (this.balance - x < 1000)
                throw new MinimumBalanceException("The balance after withdrawl can not be less than 1000$");
            else {
                this.balance -= x;
                return this.balance;
            }
        } catch (MinimumBalanceException e) {
            System.out.println(e.getMessage());
        }
        return -1;
    }

    public int getAccountNo() {
        return this.account_no;
    }

    public float getBalance() {
        return this.balance;
    }

    public float taxDeduction() {
        float tax = 0;
        if (balance > 1500 && balance < 3000)
            tax = (float) 0.05 * balance;
        else if (balance > 3000)
            tax = (float) 0.1 * balance;
        this.balance -= tax;
        return tax;

    }

    @Override
    public String toString() {
        return "\n Account No: " + getAccountNo() + "\n Balance: " + getBalance();
    }
}
