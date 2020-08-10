<!DOCTYPE html>
<html>
<head>
    <title>Compare 3 No</title>
    <style>
    form input[type="number"]{
        text-indent: 10px;
        margin: 10px;
        width: 300px;
        padding: 10px;
        border: 1px solid black;
    }
    form input[type="submit"]{
        margin: 10px;
        padding: 10px;
        border: 1px solid black;
    }
   
    h2{
        text-align: center;
    }
    </style>
        <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>
</head>
<body>
    <h2 style="text-align: center;">FACTORIAL OF A NUMBER</h2><hr/>
<div id="sl11_form">
    <form action="sl11.php" method="POST">
        <input type="number" name="number" placeholder="Enter Any Positive Number" min="1" step="1" required/>
        <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="sl11_output">
    <h2>
    <?php
        if(isset($_POST['number']))
        {
            $n = $_POST['number'];
        
            echo "Factorial of ".$n." is : ".getFactorial($n);
        }
       
        function getFactorial($num)
        {
            $result = 1;
            for($i = $num; $i > 1; $i--)
            {
                $result *= $num;
            }
            return $result;
        }
       ?>

        </h2>
</div>
</body>
</html>
