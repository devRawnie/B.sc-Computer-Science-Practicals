/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jdbc_p2;

import java.sql.*;
import javax.sql.*;
import java.util.Scanner;
import MYSQLConnection.Query;
/**
 *
 * @author KMV
 */
public class Main {

    private static final String URL = "jdbc:mysql://localhost:3306/db5781";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "keshav";

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        try{
            Driver d = new com.mysql.jdbc.Driver();
            DriverManager.registerDriver(d);

            System.out.println("Creating Connection");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);
            System.out.println("Connection Established");
            while (true) {
                System.out.println("\nEnter your choice: ");
                System.out.println("1.Stored Procedure using Callable Statement");
                System.out.println("2.Prepared Statement Example");
                System.out.println("3.Exit::");
                switch (in.nextInt()) {
                    case 1:
                        CallableStatement callable = conn.prepareCall(Query.P2.Q1);
                        System.out.println("\nPreparing Callable statement with Stored Procedure to fetch total rows");
                        callable.registerOutParameter(1, java.sql.Types.INTEGER);

                        callable.executeUpdate();

                        System.out.println("No of rows in table 'student' is " + callable.getInt(1));
                        callable.close();
                        System.out.println("Closing Callable statement");
                        break;
                    case 2:
                        PreparedStatement stmt = conn.prepareStatement(Query.P2.Q2);
                        System.out.print("Enter name of the student: ");
                        in.nextLine();
                        String name = in.nextLine();
                        System.out.println(name);
                        stmt.setString(1, name);
                        ResultSet rs = null;
                        try {
                            rs = stmt.executeQuery();
                            System.out.printf("Result for student %s is:\nSubject\tMarks\n", name);
                            while (rs.next()) {
                                System.out.printf("S1 \t %d \t \n S2 \t %d \n S3 \t %d \n", rs.getInt(1), rs.getInt(2), rs.getInt(3));
                            }
                        }
                         catch (SQLException e) {
                            System.out.println(e.getMessage());
                        }
                        rs.close();
                        stmt.close();
                        break;
                    case 3:
                        conn.close();
                        System.out.println("Closing Connection");
                        System.exit(0);
                    default:
                        System.out.println("Invalid Choice");
                }
            }
        }
        catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }catch(Exception e){
            System.out.println(e.getMessage());
        }

        }

    }
