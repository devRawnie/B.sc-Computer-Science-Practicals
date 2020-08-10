/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rohitsharmasemv.ques1;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author KMV
 */
class User {

    private String name;
    private BankAccount account;

    public String getName() {
        return name;
    }

    int getAccountNo() {
        return account.getAccountNo();
    }

    float getBalance() {
        return account.getBalance();
    }

    public void setBankAccount(BankAccount account) {
        this.account = account;
    }

    public User(String name, BankAccount account) {
        this.name = name;
        this.account = account;
        System.out.println("\n\nUser created successfully");
        System.out.println(this);
    }

    @Override
    public String toString() {
        return "\nName: " + name + "\nAccount Number: " + getAccountNo();
    }
}

class Users {

    private ArrayList<User> users;

    public Users() {
        users = new ArrayList<>();
    }

    public void addNewUser(User user) {
        users.add(user);
    }

    public User userExists(int accountNo) {
        for (User user : users) {
            if (user.getAccountNo() == accountNo) {
                return user;
            }
        }
        return null;
    }
}

class Execute {

    private Bank bank;
    private Users users;

    public Execute(Bank bank) {
        this.bank = bank;
        users = new Users();
        System.out.println("\nWelcome to Virtual Bank!!");
    }

    public void showBankSubMenu() {
        System.out.println("\n1.Add Account in Bank");
        System.out.println("2.Get total Balance in Bank");
        System.out.println("3.Check if an Account Exists");
        System.out.println("4.Find Account with minimum and maximum balance");
        System.out.println("5.Find no of accounts with specific balance");
        System.out.println("6.Deduct Taxes");
        System.out.println("7.Exit");
        System.out.print("Enter your choice: ");
    }

    public void executeBankSubMenu() {
        Scanner in = new Scanner(System.in);
        while (true) {
            showBankSubMenu();
            int choice = in.nextInt();
            switch (choice) {
            case 1:
                BankAccount acc = bank.addAccount();
                System.out.println("\nNew Account created successfully. Details are:\n " + acc);
                break;
            case 2:
                System.out.println("Total Balance in Bank: " + bank.getTotalBalanceInBank());
                break;
            case 3:
                System.out.println("\nEnter an account number");
                BankAccount response = bank.accountExists(in.nextInt());
                if (response != null) {
                    System.out.println(response);
                } else {
                    System.out.println("\nAccount does not exist");
                }
                break;
            case 4:
                System.out.println("\n\n1.Find Account with Maximum Balance");
                System.out.println("2.Find Account with Minimum Balance");
                System.out.println("Enter your choice");
                bank.findMaxMin(in.nextInt());
                break;
            case 5:
                System.out.println("\nEnter the balance, you want to check the accounts against");
                float balance = in.nextFloat();
                System.out.println("\nNo of accounts with balance " + balance + " = " + bank.countAccounts(balance));
                break;
            case 6:
                System.out.println("\nEnter an account number: ");
                int ac = in.nextInt();
                float tax = bank.deductTaxes(ac);
                if (tax != Float.NaN) {
                    if (tax == 0)
                        System.out.println("Your balance is not in tax deductible slab.");
                    else
                        System.out.println("Tax deducted: " + tax);
                    System.out.println("New Balance: " + new BankAccount(ac).getBalance());
                }
                break;
            case 7:
                System.exit(0);
            default:
                System.out.println("\nInvalid choice");
            }
        }
    }

    public void init() {
        Scanner in = new Scanner(System.in);
        while (true) {
            System.out.println("\n1.User");
            System.out.println("2.Admin");
            System.out.println("3.Exit");
            System.out.print("Enter your choice: ");
            int ch = in.nextInt();
            switch (ch) {
            case 1:
                showUserSubMenu();
                break;
            case 2:
                executeBankSubMenu();
                break;
            case 3:
                System.exit(0);
                return;
            default:
                System.out.println("Invalid choice. Please try again");
            }
        }
    }

    private void showUserSubMenu() {
        Scanner in = new Scanner(System.in);
        System.out.println("\n1. New User");
        System.out.println("2.Existing User");
        int choice = in.nextInt();
        switch (choice) {
        case 1:
            registerNewUser();
            break;
        case 2:
            System.out.print("\nEnter your account no: ");
            int accountNo = in.nextInt();
            User us = users.userExists(accountNo);
            if (us != null)
                executeUserSubMenu(accountNo);
            else
                System.out.println("Account Number does not exist");
            break;
        default:
            System.out.println("\nInvalid choice. Please try again");
            return;
        }
    }

    private void executeUserSubMenu(int acc) {
        Scanner in = new Scanner(System.in);
        while (true) {
            System.out.println("\n\n1.Credit");
            System.out.println("2.Debit");
            System.out.println("3.CheckBalance");
            System.out.println("4.Return to Previous Menu");
            System.out.println("Enter your choice");
            int ch = in.nextInt();
            switch (ch) {
            case 1:
                System.out.println("Enter Balance to be credited");
                float balance = in.nextFloat();
                balance = bank.credit(acc, balance);
                if (balance != -1)
                    System.out.println("Credited Successfully. Updated balance: " + balance);
                break;
            case 2:
                System.out.println("Enter Balance to be debited");
                float balance1 = in.nextFloat();
                balance1 = bank.debit(acc, balance1);
                if (balance1 != -1)
                    System.out.println("Debited Successfully. Updated balance: " + balance1);
                break;
            case 3:
                System.out.println("Your balance is: " + users.userExists(acc).getBalance());
                break;
            case 4:
                return;
            default:
                System.out.println("Invalid Choice");
            }
        }
    }

    private void registerNewUser() {
        Scanner in = new Scanner(System.in);
        System.out.println("\nEnter your name:");
        String name = in.nextLine();
        BankAccount account = bank.addAccount();
        User user = new User(name, account);
        users.addNewUser(user);
        executeUserSubMenu(user.getAccountNo());
    }

}

public class Main {

    public static void main(String[] args) {
        Bank bank = new Bank();
        Execute exec = new Execute(bank);
        exec.init();
    }
}
