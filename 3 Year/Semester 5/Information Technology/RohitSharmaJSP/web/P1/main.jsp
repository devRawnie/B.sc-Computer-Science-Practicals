    <%@ include file="/Layouts/header.jsp" %>  
    <%@ include file="/Layouts/navbar.jsp" %>  
    
    <div class="container-fluid mt-2 p-3 ">
        <h2><u>Practical 1</u></h2>
        <div class="container-fluid font-italic font-weight-bold">            
            <p class="lead">Display the pattern:</p>
            <code>1<br/>1 2<br/>1 2 3</code>
            <p class="lead">Take 'n' in a textbox from user. Display this pattern using:</p>
            <ul>
                <li>Scriptlet</li>
                <li>&lt;c:foreach&gt; loop</li>
            </ul>
        </div>
        <hr/>
        <div class="container-fluid form-group mt-2 p-3">
            <h3><u>Solution</u></h3>
            <ul>
                <li><h4><a href="pattern-with-scriptlet.jsp">Scriptlet</a></h4></li>
                <li><h4><a href="pattern-with-foreach.jsp">Using &lt;c:foreach&gt; loop</a></h4></li>
            </ul>
        </div>
  <%@ include file="/Layouts/footer.jsp" %>  
  
  