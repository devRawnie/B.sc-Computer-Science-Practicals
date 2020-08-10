/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package customtags;

import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.SimpleTagSupport;

/**
 *
 * @author KMV
 */
public class CustomTagToday extends SimpleTagSupport{
    private char choice;

    public CustomTagToday() {
        choice = 'x';
    }
    
    public void setChoice(char choice) {
        this.choice = choice;
    }
    
    @Override
    public void doTag() throws JspException, IOException {
        //To change body of generated methods, choose Tools | Templates.
        JspWriter out = getJspContext().getOut();
        switch(choice){
            case 'x' :   
            case 'a' : String date = new SimpleDateFormat("dd-MM-yyyy").format(new Date());
                       String time = new SimpleDateFormat("h:mm a").format(new Date());
                       out.write("<h4>Date: ".concat(date).concat("</h4><br><h4>Time: ").concat(time).concat("</h4>"));
                       break;
            case 'h':  String h = new SimpleDateFormat("h").format(new Date());          
                       out.write(Integer.parseInt(h));
                       break;          
            default: out.write("Invalid Input");           
        }
    }
    
}
