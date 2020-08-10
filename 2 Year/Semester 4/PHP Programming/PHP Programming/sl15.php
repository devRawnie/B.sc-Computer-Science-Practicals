<!DOCTYPE html>
<html>
<head>
    <title>PALINDROME</title>
    <style>
    input[type="text"]{
        margin: 10px;
        padding: 10px;
        width: 300px;
        border: 1px solid black;
    }
    input[type="submit"]{
        margin: 10px;
        padding: 10px;
        border: 1px solid black;
    }
    h2{
        padding: 10px;
    }
    </style>
        <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>

</head>
<body>
    <h2 style="text-align: center;">CHECK WHETHER THE GIVEN STRING IS A PALINDROME</h2><hr/>
<div id="sl15_form">
    <form action="sl15.php" method="POST">
        <input type="text" name="val" placeholder="Enter any string" required/>
        <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="sl15_output">
    <h2> 
    
    <?php
        if(isset($_POST['val']))
        {
            
            $val = $_POST['val'];
            
            echo " Entered string \" ".$val." \"";
            echo $val == strrev($val) ? " is a palindrome. " : " is not a palindrome.  ";
        }
        
        ?>

        </h2>
</div>
</body>
</html>
