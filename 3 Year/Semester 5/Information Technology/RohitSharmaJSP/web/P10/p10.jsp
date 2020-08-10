<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>  
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<c:if test="${param.submit == 'Submit' && not empty param.name && not empty param.age}">
    <c:set var="name" value="${param.name}" scope="session"/>
    <c:set var="age" value="${param.age}" scope="session"/>
</c:if>
<c:if test="${not empty name && not empty age}">
        <c:redirect url="/P10/product_page.jsp"/>
</c:if>
<div class="container-fluid mt-2 p-3">
    <h2><u>Practical 10</u></h2>
    <div class="container-fluid font-italic font-weight-bold">            
        <p class="lead">Ask a user's name and age on HTML form. 
            Then display Hello &lt;uname&gt; on a JSP page. 
            Then on the same page ask the product the user would like to buy. 
            Then redirect to another JSP which would display: Hello &lt;uname&gt;,
            you have ordered &lt;product&gt;.(Use Session Scope variable using setTag)
        </p>
    </div>
<hr/>
    <div class="form-group mt-2 p-3">
        <h3><u>Solution 10</u></h3>
            <form action="p10.jsp" method="POST" class="container border border-light p-3">
                <div class="row">
                    <div class="col-2 py-2 ml-2">
                        <h4>Name:</h4>
                    </div>
                    <div class="col-6 py-2 ml-2">
                        <input type="text" class="form-control d-block" name="name"/>
                    </div>
                    <div class="col">
                        <c:if test="${param.submit == 'Submit'  && empty param.name}">
                            <span class="text-danger">Name field can not be empty</span>
                        </c:if>
                    </div>
                </div>
                <div class="row">
                    <div class="col-2 py-2 ml-2">
                        <h4>Age:</h4>
                    </div>
                    <div class="col-6 py-2 ml-2">
                        <input type="number" class="form-control d-block" step="1" min="1" name="age"/>
                    </div>
                    <div class="col">
                        <c:if test="${param.submit == 'Submit'  && empty param.age}">
                            <span class="text-danger">Age field can not be empty</span>
                        </c:if>
                    </div>
                </div>
                <div class="col-5 py-2 ml-2">
                    <input class="btn btn-success d-block" type="submit" value="Submit" name="submit"/>
                </div>
            </form>
    </div>
</div>
<%@ include file="/Layouts/footer.jsp" %>  