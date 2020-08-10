<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>
<%@taglib prefix="pvi" uri="WEB-INF/tlds/p6_tags.tld" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<div class="container-fluid mt-2 p-3">
      <h2><u>Practical 6</u></h2>
      <div class="container-fluid font-italic font-weight-bold">
          <p class="lead">Create your custom library which contains two tags: &lt;hello&gt;, &lt;choco&gt;.
          Usage of the tags:</p>
          <ul>
              <li><p class="lead">
                &lt;hello name="Ajay"&gt;: Output should be Hello Ajay. It
                contains a mandatory attribute 'name' which can accept Dynamic Value
                  </p>
              </li>
              <li><p class="lead">
                  &lt;choco texture="Chewy"&gt;: Output should be Fivestar, BarOne<br/>
                  &lt;choco texture="Crunchy"&gt;: Output should be Munch, KitKat<br/>
                  That means the mandatory attribute must accept a value and based on the attributes value, it should give output.
                  You must use a bean ChocoBean for this purpose
                  </p>
              </li>
          </ul>          
      </div>            
</div>
<hr/>
<div class="container-fluid mt-2 p-3">
    <h3><u>Solution</u></h3>
<div class="row">
    <div class="col-6">
        <div class="container-fluid mt-2 p-3 text-center">
            <h3><u>&lt;hello&gt; Example</u></h3>
            <div class="container-fluid mt-2 p-3">        
                <form action="p6.jsp" method="POST">
                    <input type="input" id="inputVal" class="p-1" name="input" placeholder="Enter your name" required="required">
                    <input type="submit" class="btn btn-success " value="Submit"/>
                </form> 
            </div>
            <c:if test="${param.input != null}">
                <div class="container-fluid mt-2 p-3">
                <h4>
                    <pvi:hello name="${param.input}"/>
                </h4>
                </div>
            </c:if>
        </div>
    </div>
    <div class="col-6">
        <div class="container-fluid mt-2 p-3 text-center">
            <h3><u>&lt;choco&gt; Example</u></h3>
            <div class="container-fluid mt-2 p-3">        
                <form action="p6.jsp" method="POST">
                    <select name="texture" class="p-1" required="required">
                        <option selected disabled>Select a texture</option>
                        <option value="Crunchy">Crunchy</option>
                        <option value="Chewy">Chewy</option>
                    </select>
                    <input type="submit" class="btn btn-success" value="Submit"/>
                </form> 
            </div>
            <c:if test="${param.texture != null}">
                <div class="container-fluid mt-2 p-3">
                <h4>
                    <pvi:choco texture="${param.texture}"/>
                </h4>
                </div>
            </c:if>
        </div>
    </div>
</div>
</div>
<%@ include file="/Layouts/footer.jsp" %>
