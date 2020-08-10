/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaBeans;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author KMV
 */
class Person{
    private ArrayList<StudentBean> student;
    private ArrayList<EmployeeBean> employee;
    public Person(){
        student = new ArrayList<>();
        employee = new ArrayList<>();
    }
    public void addStudent(StudentBean student){
        this.student.add(student);
    }
    public void addEmployee(EmployeeBean employee){
        this.employee.add(employee);
    }
    public StudentBean getStudent(int roll){
        for(StudentBean st: student){
            if(st.getRoll() == roll){
                return st;
            }
        }
        return null;
    }
    public EmployeeBean getEmployee(int employeeID){
        for(EmployeeBean em: employee){
            if(em.getEmployeeID() == employeeID){
                return em;
            }
        }
        return null;
    }    
    public void displayStudents(){
        if(student.size() > 0){
        	System.out.print("Students:");
            for(StudentBean st: student){
                System.out.println(st);
            }
        }else{
            System.out.println("No Student in the list");
        }
        
    }
    public void displayEmployee(){
        if(employee.size() > 0){
        for(EmployeeBean em: employee){
        	System.out.print("Employees:");
        	System.out.println(em);
        }
        }else{
            System.out.println("No employee in the list");
        }
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Person p = new Person();
        while(true){
            System.out.println("\n1.Student\n2.Employee\n3.Exit");
            switch(in.nextInt()){
                case 1: p.displayStudents();
                        System.out.println("1.Add Student\n2.Find Student\n3.Exit: ");
                        stu: switch(in.nextInt()){
                            case 1: StudentBean sb = new StudentBean();
                            		in.nextLine();
                                    System.out.println("Enter name of the student");
                                    sb.setName(in.nextLine());
                                    System.out.println("Enter roll number of the student");
                                    sb.setRoll(in.nextInt());
                                    System.out.println("Enter age number of the student");
                                    sb.setAge(in.nextInt());
                                    p.addStudent(sb);
                                    System.out.println("Added Student successfully");
                                    break;
                            case 2: System.out.println("Enter roll number of the student");
                                    int roll = in.nextInt();
                                    StudentBean bean = p.getStudent(roll);
                                    if(bean != null) {
                                    	System.out.println(bean);
                                    }
                                    else {
                                    	System.out.println("Student does not exist");                                 
                                    }
                                    break;
                            case 3: break stu;        
                            default: System.out.println("Invalid choice");
                        }
                    break;
                case 2: p.displayEmployee();
                        System.out.println("1.Add Employee\n2.Find Employee\n3.Exit: ");
                        emp: switch(in.nextInt()){
                            case 1: EmployeeBean em = new EmployeeBean();
                                    in.nextLine();
                            		System.out.println("Enter name of the employee");
                                    em.setName(in.nextLine());
                                    System.out.println("Enter employee id of the student");
                                    em.setEmployeeID(in.nextInt());
                                    System.out.println("Enter salary of the student");
                                    em.setSalary(in.nextInt());
                                    p.addEmployee(em);
                                    System.out.println("Added employee successfully");
                                    break;         
                            case 2: System.out.println("Enter employee ID: ");
		                            int id = in.nextInt();
		                            EmployeeBean bean = p.getEmployee(id);
		                            if(bean != null) {
		                            	System.out.println(bean);
		                            }
		                            else {
		                            	System.out.println("Employee does not exist");                                 
		                            }
		                            break;    
                            case 3: break emp;        
                            default: System.out.println("Invalid choice");         
                        }
                    break;
                        
                case 3: System.exit(0);
                default: System.out.println("Invalid choice");
            }
        }
        
    }
}
