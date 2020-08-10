<!DOCTYPE html>
<html>
<head>
    <title>REVERSE A STRING</title>
    <style>
    form input{
        margin: 10px;
        padding: 10px;
        border: 1px solid black;
    }
    </style>
    <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>
</head>
<body>
    <h2 style="text-align: center;">REVERSE ANY ENTERED STRING</h2><hr/>
<div id="p1_form">
    <form action="p1.php" method="POST">
        <input type="text" name="str" placeholder="Enter any String." required/>
        <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="p1_output">
    <h2>
    
    <?php
        if(isset($_POST['str']))
        {
            $val = $_POST['str'];
            echo "Entered String: ".$val;
            echo "<br/>Reversed String: ".strrev($val);            
        }
        ?>

        </h2>
</div>
</body>
</html>
