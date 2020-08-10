    <%@ include file="/Layouts/header.jsp" %>  
    <%@ include file="/Layouts/navbar.jsp" %>  
    
    <div class="container-fluid mt-2 p-3 ">
        <h2><u>Practical 1- With Scriptlet</u></h2>
        <hr/>
        <div class="container-fluid form-group mt-2 p-3">
            <h3>Solution</h3>
            <form action="pattern-with-scriptlet.jsp" method="GET">
            <label>
                <input type="text" placeholder="Enter any number" name="num" id="num" class="form-control" required="required" pattern="[0-9]+"/>
            </label>
            <input type="submit" value="submit" class="btn btn-success"/>
        </form>
        <small class="text-danger" style="display:none;" id="error">Input can only be a number</small>
        
        </div>            
    
    <%
        try{
            if(request.getParameter("num") != "null"){
                int p = Integer.parseInt(request.getParameter("num"));
                out.print("<div class='container-fluid mt-2 p-3 border border-light'>Pattern of side: "
                        + p + " <br/> ");
                for(int i = 1; i <= p;   i++){
                    for(int j = 1; j <= i ; j++){
                        out.print(j + " ");
                    }
                    out.print("<br/>");
                }
            }
            out.print("</div>");
        }catch(NumberFormatException e){
           
        }catch(Exception e1){}
    %>
    </div>
    <script>
        $(document).ready(function(){
            $("#num").on('input', function(){
                let pattern = /^[0-9]{1,}$/;
                let n = $(this).val();
                if(!pattern.test(n)){
                    $('#error').show();
                }else{
                    $('#error').hide();
                }
            
           }); 
        });
    </script>
  <%@ include file="/Layouts/footer.jsp" %>  
  
  