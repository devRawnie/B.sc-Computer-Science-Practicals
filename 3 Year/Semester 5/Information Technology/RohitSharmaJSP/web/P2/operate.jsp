<%-- 
    Document   : operate
    Created on : 9 Oct, 2019, 9:02:06 PM
    Author     : dev_rawnie
--%>
<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %> 
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

    <div class="container-fluid mt-2 p-3">
    <h2><u>Practical 2: Solution</u></h2>
    <c:choose>
        <c:when test="${param.submit == "Calculate(scriptlet method)"}">
        <h2>
        <%
            if(request.getParameter("num1") != "null" && request.getParameter("num2") != "null"){
                try{
                    int num1 = Integer.parseInt(request.getParameter("num1"));
                    int num2 = Integer.parseInt(request.getParameter("num2"));
                    String res = null;
                      switch(request.getParameter("choice")){
                        case "+": res = String.format("%d + %d = %d", num1, num2, num1 + num2);
                            break;
                        case "-": res = String.format("%d - %d = %d", num1, num2, num1 - num2);
                            break;
                        case "*": res = String.format("%d * %d = %d", num1, num2, num1 * num2);
                            break;
                    }
                    out.print(res);
                }catch(Exception e){
                }
            }
       %>
        </h2>
        </c:when>
       <c:when test="${param.submit == "Calculate(Expression Language)"}">
           <h2>
               <strong>Expression Language Result:</strong>
           </h2>
           <h2>
               <c:choose>
                   <c:when test="${param.choice == "+"}">
                       <c:out value="Result: ${param.num1 + param.num2}"/>
                   </c:when>
                    <c:when test="${param.choice == "-"}">
                       <c:out value="Result: ${param.num1 - param.num2}"/>
                    </c:when>
                    <c:when test="${param.choice == "*"}">
                       <c:out value="Result: ${param.num1 * param.num2}"/>
                   </c:when>
               </c:choose>
           </h2>
       </c:when>
    </c:choose>
    
    </div>

<%@ include file="/Layouts/footer.jsp" %>      
