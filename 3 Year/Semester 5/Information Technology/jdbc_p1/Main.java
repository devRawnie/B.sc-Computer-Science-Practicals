package jdbc_p1;
import java.sql.*;
import javax.sql.*;

import MYSQLConnection.Query;

import java.util.Scanner;


public class Main {

    private static final String URL = "jdbc:mysql://localhost:3306/db5781";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "keshav";

    static void menuHandler() {
    	System.out.println("\nEnter your choice: ");
        System.out.println("1.Find total number of students");
        System.out.println("2.Print Average marks in a subject.");
        System.out.println("3.Find name of student getting highest marks");
        System.out.println("4.Find number of students getting first, second and third division");
        System.out.println("5.Find subject wise toppers");
        System.out.println("6.Find average marks");
        System.out.println("7.Find the student getting highest marks");
        System.out.println("8. Exit::");
    }

    public static void main(String[] args) throws Exception {

        Connection conn = null;
        Statement stmt = null;
        Scanner in = new Scanner(System.in);
        try {
            Driver d = new com.mysql.jdbc.Driver();
//            Driver d = new com.mysql.cj.jdbc.Driver();
        	DriverManager.registerDriver(d);
            System.out.println("Creating connection");
        	conn = DriverManager.getConnection(URL, "dev_rawnie", "iliTN@38sb");
        	System.out.println("Connection Created");
        	stmt = conn.createStatement();
            loop: while (true) {
            	menuHandler();
            	int choice =  in.nextInt();
            	System.out.println(choice + " ");
                sc: switch (choice) {
                    case 1:
                        ResultSet r1 = stmt.executeQuery(Query.P1.Q1);
                        while (r1.next()) {
                            System.out.println("\nNumber of students : " + r1.getString(1));
                        }
                        r1.close();
                        stmt.clearBatch();
                        break;
                    case 2: System.out.println("\nEnter the subject\n1.S1\n2.S2\n3.S3\n");
                            String sub;
                            switch(in.nextInt()){
                                case 1: sub = "S1"; break;
                                case 2: sub = "S2"; break;
                                case 3: sub = "S3"; break;
                                default: System.out.println("Invalid choice"); break sc;
                            }
                            stmt.clearBatch();
                            ResultSet r2 = stmt.executeQuery(Query.P1.Q2A + sub + Query.P1.Q2B);
                            while(r2.next())
                            {
                                System.out.println("\nAverage Marks in " + sub + " is: " + r2.getInt(1));
                            }
                            r2.close();
                            stmt.clearBatch();
                        break;
                    case 3: stmt.clearBatch();
                            ResultSet r3 = stmt.executeQuery(Query.P1.Q3);
                            while(r3.next()){
                                System.out.println("\nThe highest marks are " + r3.getInt(2) + " scored by student " + r3.getString(1) );
                            }
                            r3.close();
                            stmt.clearBatch();
                        break;
                    case 4:	stmt.clearBatch();
                        	ResultSet r4 = stmt.executeQuery(Query.P1.Q4);
            							System.out.println("\nDivision\tNo of Students");
            							while(r4.next()){
            								System.out.printf("\t%d\t%d\n", r4.getInt(1), r4.getInt(2));
            							}
                          r4.close();
                          stmt.clearBatch();
            						break;
                    case 5: stmt.clearBatch();
                            ResultSet r5 = stmt.executeQuery(Query.P1.Q5);
                            System.out.println("\nName of student\t Marks");
                            while(r5.next()){
              								System.out.printf("\t%s\t%d\n", r5.getString(1), r5.getInt(2));
              							}
                            r5.close();
                            stmt.clearBatch();
                        break;
                    case 6: stmt.clearBatch();
                            ResultSet r6 = stmt.executeQuery(Query.P1.Q6);
                            System.out.println("\nName\tSub1\tSub2\tSub3\tAverage");
                            while(r6.next()){
              								System.out.printf("%s\t%d\t%d\t%d\t%.2f\n", r6.getString(1), r6.getInt(2), r6.getInt(3), r6.getInt(4), r6.getFloat(5));
              							}
                            r6.close();
                            stmt.clearBatch();
                        break;
                    case 7: stmt.clearBatch();
                                ResultSet r7 = stmt.executeQuery(Query.P1.Q7);
                                while(r7.next()){
                                    System.out.println("\nThe second highest marks are: " + r7.getInt(2) + " scored by student: " + r7.getString(1) );
                                }
                                r7.close();
                                stmt.clearBatch();
                            break;
                    case 8: break loop;
                    default: System.out.println("Invalid choice, please try again");
                }
            }
            stmt.close();
            conn.close();
            in.close();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }


    }
}
