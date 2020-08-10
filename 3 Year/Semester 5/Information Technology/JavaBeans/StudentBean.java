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
public class StudentBean implements Serializable {
    private String name;
    private int age;
    private int roll;

    public StudentBean() {

    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public int getRoll() {
        return roll;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setRoll(int rollNo) {
        this.roll = rollNo;
    }

    public String toString() {
        return "\nName: " + this.getName() + "\nAge:" + this.getAge() + "\nRoll Number:" + this.getRoll();
    }

}
