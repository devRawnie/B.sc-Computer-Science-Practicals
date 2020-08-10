<%@page import="java.util.Enumeration"%>
<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>  
<%@ taglib prefix = "c" uri = "http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix = "fn" uri = "http://java.sun.com/jsp/jstl/functions" %>
<style>
    #response{
        width: 50%;
    }
    #response > .row > .col {
        text-align: left;
        font-weight: bold;
        padding: 5px;
        border: 1px solid white;
        border-collapse: collapse;
    }
</style>
<div class="container-fluid mt-2 p-3">
    <h2><u>Practical 3</u></h2>
    <div class="container-fluid font-italic font-weight-bold">            
        <p class="lead">
            Validate user input entered in a form.The input must include Name, DOB, Email ID, Lucky Number, Favourite Food etc.
        </p>
    </div>
    <hr/>
    <div class="form-group mt-2 p-3">
        <h3><u>Solution</u></h3>
        <form action="p3.jsp" method="POST" class="container border border-light p-3">
            <input type="hidden" name="submitted" value="true"/>
            <div class="row">
                <div class="col-2 py-2 ml-2">
                    <h5>Name:</h5> 
                </div>
                <div class="col-6 py-2 ml-2">
                    <input type="text" name="name" class="form-control" />
                </div>
                <c:if test="${"Submit" == param.submit && empty param.name}">
                    <c:set var="error" value="true"/>
                    <div class="col m-auto">
                        <span class="text-danger ">Name field can not be empty</span>
                    </div>
                </c:if>
            </div>
            <div class="row">
                <div class="col-2 py-2 ml-2">
                    <h5>Date of Birth: </h5>
                </div>
                <div class="col-6 py-2 ml-2">
                    <input type="date" name="dob" class="form-control" />
                </div>
                <c:if test="${"Submit" == param.submit && empty param.dob}">
                    <c:set var="error" value="true"/>
                    <div class="col m-auto">
                        <span class="text-danger ">DOB field can not be empty</span>
                    </div>
                </c:if>
            </div>
            <div class="row">
                <div class="col-2 py-2 ml-2">
                    <h5>Email: </h5>
                </div>
                <div class="col-6 py-2 ml-2">
                    <input type="email" name="email" class="form-control"/>
                </div>
                <c:if test="${"Submit" == param.submit && empty param.email}">
                    <c:set var="error" value="true"/>
                    <div class="col m-auto">
                        <span class="text-danger ">Email field can not be empty</span>
                    </div>
                </c:if>
            </div>
            <div class="row">
                <div class="col-2 py-2 ml-2">
                    <h5>Gender: </h5>
                </div>
                <div class="col-2 py-2 ml-2">
                        <input type="radio" name="gender" value="Male"/> Male
                </div>
                <div class="col-2 py-2 ml-2">
                        <input type="radio" name="gender" value="Female"/> Female
                </div>
                <c:if test="${"Submit" == param.submit && empty param.gender}">
                    <c:set var="error" value="true"/>
                    <div class="col m-auto">
                        <span class="text-danger">Please select an option</span>
                    </div>
                </c:if>
            </div>
            <div class="row">
                <div class="col-2 py-2 ml-2">
                    <h5>Favorite food: </h5>
                </div>
                <div class="col-2 py-2 ml-2">
                    <input type="checkbox" name="food" value="Pizza"/> Pizza
                </div>
                <div class="col-2 py-2 ml-2">
                    <input type="checkbox" name="food"  value="Pasta"/> Pasta 
                </div>
                <div class="col-2 py-2 ml-2">
                    <input type="checkbox" name="food" value="Chinese"/> Chinese 
                </div>                
            </div>
            <input type="submit" name="submit" class="btn btn-success m-2 p-2" value="Submit"/>
            <c:set var="error" value="false"/>
        </form>
    </div>
</div>
<c:if test="${error == "false" && param.submit == "Submit"}">
    <div id="response" class="container-fluid border">
        <div class="row">
            <div class="col">
                Name: 
            </div>
            <div class="col">
                ${param.name}
            </div>
        </div>
        <div class="row">
            <div class="col">
                Date of Birth: 
            </div>
            <div class="col">
                <c:set var="date_of_birth" value="${fn:split(param.dob, '-')}"/>
                <c:set var="year" value="${date_of_birth[0]}"/>
                <c:set var="month" value="${date_of_birth[1]}"/>
                <c:set var="day" value="${date_of_birth[2]}"/>
                <c:out value="${day}-${month}-${year}"/>
            </div>
        </div>
        <div class="row">
            <div class="col">
                Email: 
            </div>
            <div class="col">
                ${param.email}
            </div>
        </div>            
        <div class="row">
            <div class="col">
                Gender: 
            </div>
            <div class="col">
                ${param.gender}
            </div>
        </div>
        <div class="row">
            <div class="col">
                Favorite Food: 
            </div>
            <div class="col">
                <c:forEach items="${paramValues.food}" var="f">
                    <c:out value="${f}"/>
                </c:forEach>
            </div>
        </div>
    </div>
</c:if>
<%@ include file="/Layouts/footer.jsp" %>  