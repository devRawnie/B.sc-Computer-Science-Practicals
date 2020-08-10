<%-- 
    Document   : pattern-with-foreach
    Created on : 15 Oct, 2019, 7:59:10 PM
    Author     : dev_rawnie
--%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>  
<div class="container-fluid mt-2 p-3 ">
        <h2><u>Practical 1 with &lt;c:foreach&gt; loop</u></h2>
        
        <hr/>
        <div class="container-fluid form-group mt-2 p-3">
            <h3><u>Solution</u></h3>
            <form action="pattern-with-foreach.jsp" method="GET">
            <label>
                <input type="text" placeholder="Enter any number" name="num" id="num" class="form-control" required="required" pattern="[0-9]+"/>
            </label>
            <input type="submit" value="submit" class="btn btn-success"/>
        </form>
        <small class="text-danger" style="display:none;" id="error">Input can only be a number</small>
        
        </div>            
        <c:set value="${!empty(param.num)}" var="test"/>
        <c:if test="${test}">
            <div class="container-fluid mt-2 p-3 border border-light">
                <c:out value="Pattern of side: ${param.num}"/>
                <%= "<br/>"%>
                <c:forEach var="i" begin="1" end="${param.num}" step="1">
                        <c:forEach var="j" begin="1" end="${i}" step="1">
                            <c:out value="${j} "/>
                        </c:forEach>
                        <%= "<br/>"%>
                </c:forEach>
            </div> 
        </c:if>    
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

