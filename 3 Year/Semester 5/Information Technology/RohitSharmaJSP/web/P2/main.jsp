  <%@ include file="/Layouts/header.jsp" %>  
  <%@ include file="/Layouts/navbar.jsp" %>  
    <div class="container-fluid mt-2 p-3">
    <h2><u>Practical 2</u></h2>
        <div class="container-fluid font-italic font-weight-bold">            
            <p class="lead">Make two files as follows</p>
            <ol style="list-style-type: lower-latin">
                <li><p class="lead"><u>main.html</u>: shows 2 text boxes and 3 radio buttons with values "addition", "subtraction" and "multiplication"</p></li>
                <li><p class="lead"><u>operate.jsp</u>: depending on what the user selects, perform the corresponding function.( Give two implementations using 'request.getParameter()' and using 'expression language' )</p></li>
            </ol>
            
        </div>
        <hr/>
        
        <div class="container-fluid form-group mt-3" >
            <h3><u>Solution</u></h3>
        
            <p class="text-danger" style="display:none;" id="error1">Input 1 can only be a number</p>
            <p class="text-danger" style="display:none;" id="error2">Input 2 can only be a number</p>

            <form action="operate.jsp" method="POST" class="mt-3">
                    <div class="row">
                        <input type="text" name="num1" id="num1" placeholder="Enter number 1" class="form-control col-3 m-2" required="required" pattern="[0-9]+" />
                        <input type="text" name="num2" id="num2" placeholder="Enter number 2" class="form-control col-3 m-2" required="required" pattern="[0-9]+" />
                    </div>    

                <br/>
                <label class="radio-inline"><input type="radio" name="choice" value="+" checked> Addition</label>
                 <br/><label class="radio-inline"><input type="radio" name="choice" value="-"> Subtraction</label>
                 <br/><label class="radio-inline"><input type="radio" name="choice" value="*"> Multiplication</label> 
               <br/>
                <input type="submit" name="submit" class="btn btn-success" value="Calculate(scriptlet method)"/>
                <input type="submit" name="submit" class="btn btn-success" value="Calculate(Expression Language)"/>
            </form>
        </div>
    </div>

    <script>
        $(document).ready(function(){
           let pattern = /^[0-9]{1,}$/;
           $('#num1').on('input', function(){
              if(!pattern.test($(this).val())){
                  $('#error1').show();
              }else{
                  $('#error1').hide();
              } 
           });
           
           $('#num2').on('input', function(){
              if(!pattern.test($(this).val())){
                  $('#error2').show();
              }else{
                  $('#error2').hide();
              } 
           });
        });
    </script>
  <%@ include file="/Layouts/footer.jsp" %>  