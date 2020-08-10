package rohitsharmasemv.ques1;

import java.util.ArrayList;

/**
 *
 * @author KMV
 */
class NegativeAmountException extends Exception {
    public NegativeAmountException(String s) {
        super(s);
    }
}

class AccountDoesNotExistException extends Exception {

    public AccountDoesNotExistException(String s) {
        super(s);
    }
}

public class Bank {
    private int counter;
    private ArrayList<BankAccount> accounts;

    public Bank() {
        this.counter = 0;
        this.accounts = new ArrayList<>();
    }

    private int incrementCounter() {
        return ++counter;
    }

    public BankAccount addAccount() {
        BankAccount bankAccount = new BankAccount(incrementCounter());
        this.accounts.add(bankAccount);
        return bankAccount;
    }

    public float getTotalBalanceInBank() {
        float totalSum = 0;
        for (BankAccount ac : this.accounts) {
            totalSum += ac.getBalance();
        }
        return totalSum;
    }

    public void findMaxMin(int choice) {
        float temp;
        BankAccount acc = null;
        switch (choice) {
        case 1:
            temp = Float.MIN_VALUE;
            for (BankAccount ac : this.accounts) {
                temp = Float.max(temp, ac.getBalance());
                acc = ac;
            }
            break;
        case 2:
            temp = Float.MAX_VALUE;
            for (BankAccount ac : this.accounts) {
                temp = Float.min(temp, ac.getBalance());
                acc = ac;
            }
            break;
        default:
            System.out.println("Invalid Choice");
            return;
        }
        System.out.println(acc);
    }

    public BankAccount accountExists(int account_no) {
        for (BankAccount ac : this.accounts) {
            if (ac.getAccountNo() == account_no) {
                return ac;
            }
        }
        return null;
    }

    public int countAccounts(float balance) {
        int count = 0;
        for (BankAccount ac : accounts) {
            if (ac.getBalance() >= balance) {
                count++;
            }
        }
        return count;
    }

    public float credit(int accountNo, float amount) {
        if (accountExists(accountNo) != null) {
            for (BankAccount ac : accounts) {
                if (ac.getAccountNo() == accountNo) {
                    try {
                        if (amount > 0) {
                            ac.deposit(amount);
                            return ac.getBalance();
                        } else {
                            throw new NegativeAmountException("The amount to be credited can not be less than 0!");
                        }
                    } catch (NegativeAmountException e) {
                        System.out.println(e.getMessage());
                    }
                }
            }
        }
        return -1;
    }

    public float debit(int accountNo, float amount) {
        if (accountExists(accountNo) != null) {
            for (BankAccount ac : accounts) {
                if (ac.getAccountNo() == accountNo) {
                    try {
                        if (amount > 0) {
                            ac.withdraw(amount);
                            return ac.getBalance();
                        } else {
                            throw new NegativeAmountException("The amount to be debited can not be less than 0!");
                        }
                    } catch (NegativeAmountException e) {
                        System.out.println(e.getMessage());
                    }
                }
            }
        }
        return -1;
    }

    public float deductTaxes(int accountNo) {
        try {
            if (accountExists(accountNo) != null) {
                for (BankAccount ac : accounts) {
                    if (ac.getAccountNo() == accountNo) {
                        return ac.taxDeduction();
                    }
                }
            } else
                throw new AccountDoesNotExistException("The given account number does not exist in our records!!");
        } catch (AccountDoesNotExistException e) {
            System.out.println(e.getMessage());
        }
        return Float.NaN;

    }
}
