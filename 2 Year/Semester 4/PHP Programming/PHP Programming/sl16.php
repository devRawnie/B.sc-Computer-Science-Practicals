<!DOCTYPE html>
<html>
<head>
    <title>Fibonacci Series</title>
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
        margin: 10px;
    }
    </style>
        <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>

</head>
<body>
    <h2 style="text-align: center;">FIBONACCI SERIES UPTO N TERMS</h2><hr/>
<div id="sl16_form">
    <form action="sl16.php" method="POST">
        <input type="number" name="number" placeholder="Enter Any Positive Number" min="1" step="1" required/>
        <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="sl16_output">
    <h2>
    <?php
        if(isset($_POST['number']))
        {
            $n = $_POST['number'];
            echo " SERIES: ";
            printFib($n);
        }
        function printFib($num)
        {
            for($i = 0; $i < $num ; $i++)
            {
                echo getFib($i)." ";
            }
        }
        function getFib($val)
        {
            if($val == 0 || $val == 1)
            {
                return $val;
            }
            else
            {
                return getFib($val - 1) + getFib($val - 2);
            }
        }
        ?>

        </h2>
</div>
</body>
</html>
