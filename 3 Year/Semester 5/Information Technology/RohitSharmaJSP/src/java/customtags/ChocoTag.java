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
public class ChocoTag extends SimpleTagSupport {
    private String texture;
    @Override
    public void doTag() throws JspException, IOException {
        JspWriter out = getJspContext().getOut();
        if(texture.equals("Chewy")){
            out.println("Fivestar, BarOne");
        }else if(texture.equals("Crunchy")){
            out.println("Munch, KitKat");
        }
            
    }

    public void setTexture(String texture) {
        this.texture = texture;
    }
    
    
}
