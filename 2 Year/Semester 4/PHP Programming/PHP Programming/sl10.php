<!DOCTYPE html>
<html>
<head>
    <title>Compare 3 No</title>
    <style>
    form input{
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
    <h2 style="text-align: center;">COMPARE 3 NUMBERS</h2><hr/>
<div id="sl10_form">
    <form action="sl10.php" method="POST">
        <input type="number" name="no1" placeholder="Enter First Number" required/>
        <input type="number" name="no2" placeholder="Enter Second Number" required/>
        <input type="number" name="no3" placeholder="Enter Third Number" required/>
        <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="sl10_output">
    <h2>Largest Number: 
    
    <?php
        if(isset($_POST['no1']) && isset($_POST['no2']) && isset($_POST['no3']))
        {
            echo checkNumbers($_POST["no1"], $_POST["no2"], $_POST["no3"]);
        }
        function checkNumbers($a, $b, $c)
        {
            if($a > $b)
            {
             if($a > $c)
                {
                    return $a;
                }
            }
            else
            {
                return $b > $c ? $b : $c;
            }

        }
        ?>

        </h2>
</div>
</body>
</html>
