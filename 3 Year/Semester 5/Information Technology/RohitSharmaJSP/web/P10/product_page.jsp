<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>  
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<c:if test="${empty name}">
    <c:redirect url="/P10/p10.jsp"/>
</c:if>
<c:if test="${param.submit == 'Submit' && not empty paramValues.product}">
    <c:set var="product" value="${paramValues.product}" scope="session"/>
</c:if>
<c:if test="${not empty product}">
    <c:redirect url="/P10/cart.jsp"/>
</c:if>
<div class="container-fluid mt-2 p-3">
    <h2 style="text-transform: capitalize;">
       Hello <c:out value="${name}"/>, Select any products
    </h2>
    <div class="container-fluid mt-2 p-3">
        <form class="form-group" action="product_page.jsp" method="POST">
            <h4>
                <div class="row">
                    <label class="contain">Product 1
                      <input type="checkbox" name="product" value="1">
                      <span class="checkmark"></span>
                    </label>
                </div>
                <div class="row">
                    <label class="contain">Product 2
                      <input type="checkbox" name="product" value="2">
                      <span class="checkmark"></span>
                    </label>
                </div>
                <div class="row">
                    <label class="contain">Product 3
                      <input type="checkbox" name="product" value="3">
                      <span class="checkmark"></span>
                    </label>
                </div>
                <div class="row">
                    <label class="contain">Product 4
                      <input type="checkbox" name="product" value="4">
                      <span class="checkmark"></span>
                    </label>
                </div>
                <div class="row">
                    <label class="contain">Product 5
                      <input type="checkbox" name="product" value="5">
                      <span class="checkmark"></span>
                    </label>
                </div>
            </h4>
            <input type="submit" class="btn-success btn" value="Submit" name="submit"/>
        </form>
    </div>        
</div>
<%@ include file="/Layouts/footer.jsp" %>  
