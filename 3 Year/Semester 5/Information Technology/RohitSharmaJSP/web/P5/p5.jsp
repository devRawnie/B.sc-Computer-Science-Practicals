<%@ include file="/Layouts/header.jsp" %>  
<%@ include file="/Layouts/navbar.jsp" %>  
<div class="container-fluid mt-2 p-3">
       <h2><u>Practical 5</u></h2>
        <div class="container-fluid font-italic font-weight-bold">            
            <p class="lead">Let the user enter a word in a textbox and let her/him
                select one of even or odd radio buttons. If she/he selects odd, check
                the odd positions in the word entered, if they all contains vowels, then
                display the message "You Win", else display "You Lose". Similarly if the user selects even, 
                check for vowels in all even positions in the word entered. Use JSTL's 'fn' library.
            </p>

        </div>
        <hr/>
    <div class="form-group mt-2 p-3">
        <h3><u>Solution</u></h3>
        <form action="p5.jsp" method="GET">
            <div>
                <label>
                    <input class="form-control" type="text" name="word" id="word" placeholder="Enter any word" required="required" pattern="[a-zA-Z]+" />
                </label>
            </div>
            <div> 
                <p>Choose the position to be marked: </p>
                <label class="radio-inline"><input type="radio" name="choice" id="odd" value="odd"> Odd </input></label>
                <br/><label class="radio-inline"><input type="radio" name="choice" id="even" value="even"> Even </input></label>
            </div>
            <input type="submit" value="Submit" class="btn btn-success"/>
        </form>
    </div>
    <%
    if(request.getParameter("word") != null && request.getParameter("choice") != null){  

        String word = request.getParameter("word");
        String temp = word.toLowerCase();
        String val = request.getParameter("choice");
        String r = "<div class='container-fluid mt-2 p-3 border border-light'><h1 class='text-light'>RESULT</h1><br/>"
                + "<h1 class='text-light p-2 my-2 border-bottom border-light d-inline'>";
        int choice = val.equals("odd")? 1 : 0;
        int score = 0;
        for(int i = 0; i < word.length(); i++){
            if( (i+1) %2 == choice){
                char c = temp.charAt(i);
                switch((int)c){
                    case 97:
                    case 101:
                    case 105:
                    case 111:
                    case 117: score++;                               
                                r += "<span class='bg-success'> " + 
                             word.charAt(i) + " </span>";
                                break;
                    default:
                            r += "<span class='bg-danger'> " + 
                             word.charAt(i) + " </span>";
                }
            }else{
                score++;
                r += word.charAt(i) ;
            }
        }
        
        if(score == word.length()){
            r += "</h1><h4 class='text-success my-2'>You win</h4></div>";            
        }else{
            r += "</h1><h4 class='text-danger my-2'>You lose</h4></div>";            
        }
        out.print(r);
    }
%>
</div>
<%@ include file="/Layouts/footer.jsp" %>  