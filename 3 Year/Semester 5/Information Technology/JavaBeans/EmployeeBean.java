/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaBeans;

import java.io.Serializable;

/**
 *
 * @author KMV
 */
public class EmployeeBean implements Serializable{
    private String name;
    private int employeeID;
    private int salary;
    
    public EmployeeBean() {
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }
    
    public String getName() {
        return name;
    }

    public int getEmployeeID() {
        return employeeID;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setEmployeeID(int employeeID) {
        this.employeeID = employeeID;
    }
    
    public String toString(){
        return "\nID: " + this.getEmployeeID() + "\nName: " + this.getName() + "\nSalary: " + this.getSalary();
    }
}
