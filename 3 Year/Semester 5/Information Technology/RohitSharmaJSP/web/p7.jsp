<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>
<%@taglib prefix="rohit" uri="WEB-INF/tlds/custom_tag.tld" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<div class="container-fluid mt-2 p-3">
      <h2><u>Practical 7</u></h2>
      <div class="container-fluid font-italic font-weight-bold">
          <p class="lead">Create a custom tag <strong>"substring"</strong> with 3 mandatory attributes "input", "start" and "end" which will do
          substring operation on a given input
          </p>
      </div>            
</div>
<hr/>
<div class="container-fluid mt-2 p-3">
    <h3><u>Solution</u></h3>
    <div class="container-fluid mt-2 p-3">        
        <form action="p7.jsp" method="POST">
            <input type="input" id="inputVal" class="p-1" name="input" placeholder="Enter any string" required="required">
            <input type="number" id="startRange" class="p-1" name="start" placeholder="Starting Index" min="0" step="1" required="required">
            <input type="number" id="endRange" class="p-1" name="end" placeholder="Ending Index" min="0" step="1">
            <input type="submit" class="btn btn-success" value="Find Substring"/>
        </form> 
    </div>
    <c:if test="${param.input != null}">
        <div class="container-fluid mt-2 p-3">
        <h4>
            Original String: <u>${param.input}</u><br/>
            Starting Index: ${param.start}<br/>
            Ending Index: ${param.end}<br/>
            Substring: <u><rohit:substring input="${param.input}" start="${param.start}" end="${param.end}"/></u>
        </h4>
        </div>
    </c:if>
</div>
<script>
    $(document).ready(function(){
       $('#endRange').click(function(){
          if($('#inputVal').val() == ""){
              $(this).val('');
              alert('No string entered in input');
          }else{
              let str = $('#inputVal').val();
              $(this).prop('max', str.length);
          } 
       });
       $('#startRange').click(function(){
           if($('#inputVal').val() == ""){
              $(this).val('');
              alert('No string entered in input');
          }
       });
    });
</script>
<%@ include file="/Layouts/footer.jsp" %>
