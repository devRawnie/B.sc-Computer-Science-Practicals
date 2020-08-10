/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package customtags;

import java.io.IOException;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.SimpleTagSupport;

/**
 *
 * @author dev_rawnie
 */
public class ReverseTag extends SimpleTagSupport {
    private String input;
    @Override
    public void doTag() throws JspException, IOException {
        JspWriter out = getJspContext().getOut();
        StringBuilder str = new StringBuilder(input);
        out.write(str.reverse().toString());
    }
    
    public void setInput(String input){
        this.input = input;
    }
    
    
}
