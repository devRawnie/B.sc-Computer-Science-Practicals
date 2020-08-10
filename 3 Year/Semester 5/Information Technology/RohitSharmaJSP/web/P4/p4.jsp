<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>  
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>
<div class="container-fluid mt-2 p-3">
    <h2><u>Practical 4</u></h2>
    <div class="container-fluid font-italic font-weight-bold">            
        <p class="lead">Display Good Morning &lt;uname&gt;, Good Afternoon &lt;uname&gt;, or 
            Good Evening &lt;uname&gt; based on the current time of the day.
        </p>
        </div>
    <hr/>
    
    <div class="container-fluid mt-2 p-3">
        <h3><u>Solution</u></h3>
    <div class="container-fluid mt-2 p-3">
        <form action="p4.jsp" method="POST">
            <div class="row">
                <div class="col-2">
                    <h4>Name:</h4>
                </div>
                <div class="col-4">
                    <input type="text" class="form-control d-block" name="name" required="required"/>
                </div>
                <div class="col-2">
                    <input class="btn btn-success d-block" type="submit" value='Submit' name="submit"/>
                </div>
            </div>
        </form>
    </div>
        <c:if test="${'Submit' == param.submit}">
            <c:set var="now" value="<%=new java.util.Date()%>" />  
            <fmt:formatDate pattern="hh:mm a" value="${now}" var="date"/>
            <div class="row">
            <div class="col-1">
                <div class="text-light text-right mt-2">
                    <i class="fa fa-clock-o fa-4x"></i>
                </div>
            </div>
            <div class="col-11 mt-auto">
                <h2>
                    <c:out value="${date}"/>
                </h2>
        </div>
        <div class="col-12">
            <h2>
                    <fmt:formatDate pattern="h" value="${now}" var="hour"/>
                    <c:set var="h" value="${Integer.parseInt(hour)}"/>
                    <c:choose>
                        <c:when test="${h > 0 && h < 12}">
                            <c:out value="Hello ${param.name}, Good Morning"/>
                        </c:when>
                        <c:when test="${h > 12 && h < 17}">
                            <c:out value="Hello ${param.name}, Good Afternoon"/>
                        </c:when>                        
                        <c:when test="${h >17 }">
                            <c:out value="Hello ${param.name}, Good Night"/>
                        </c:when>
                    </c:choose>
            </h2>
        </div>
    </div>    
</div>
</c:if>
</div>
<%@ include file="/Layouts/footer.jsp" %>  