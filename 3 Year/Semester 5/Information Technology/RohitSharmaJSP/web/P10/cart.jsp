<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>  
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<c:if test="${empty product}">
    <c:redirect url="/P10/product_page.jsp"/>
</c:if>
<div class="container-fluid mt-2 p-3">
    <h3>
        Hello <c:out value="${name}"/>
    </h3>
    <h3>You selected the following products</h3>
    <div class="container-fluid mt-2 p-3">
        <ul>            
            <c:forEach items="${product}" var="p">
                <li>
                    <h3>
                        <c:out value="Product ${p}"/>
                    </h3>
                </li>
            </c:forEach>
        </ul>
    </div>
</div>
<%@ include file="/Layouts/footer.jsp" %>  
