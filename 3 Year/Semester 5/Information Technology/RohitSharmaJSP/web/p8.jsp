<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>
<%@taglib prefix="rohit" uri="WEB-INF/tlds/custom_tag.tld" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<div class="container-fluid mt-2 p-3">
      <h2><u>Practical 8</u></h2>
      <div class="container-fluid font-italic font-weight-bold">
          <p class="lead"> Create a custom tag <strong>"reverse"</strong> with a mandatory attribute "input" to reverse a string
      </p>
      </div>            
</div>
<hr/>
<div class="container-fluid mt-2 p-3">
    <h3><u>Solution</u></h3>
    <div class="container-fluid mt-2 p-3">        
        <form action="p8.jsp" method="POST">
            <input type="input" class="p-1" name="str" placeholder="Enter any string" required="required">
            <input type="submit" class="btn btn-success" value="Reverse"/>
        </form> 
    </div>
    <c:if test="${not empty param.str}">
        <div class="container-fluid mt-2 p-3">
        <h4>
            Original String: <u>${param.str}</u><br/>
            Reversed String: <u><rohit:reverse input="${param.str}"/></u>
        </h4>
        </div>
    </c:if>
</div>
<%@ include file="/Layouts/footer.jsp" %>
