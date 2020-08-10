<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>
<%@taglib prefix="rohit" uri="WEB-INF/tlds/custom_tag.tld" %>
<div class="container-fluid mt-2 p-3">
      <h2><u>Practical 9</u></h2>
      <div class="container-fluid font-italic font-weight-bold">
          <p class="lead">    
           Create a custom tag <strong>"today"</strong> that displays today's date and time.
            </p>
      </div>            
</div>
<hr/>
<div class="container-fluid mt-2 p-3">
    <h3><u>Solution</u></h3>
        <rohit:today/>
    </h3>
</div>
    <%@ include file="/Layouts/footer.jsp" %>
