<!DOCTYPE html>
<html>
<head>
    <title>Check Prime</title>
    <style>
    input[type="number"]{
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
        text-align: center;
    }
    </style>
        <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>
</head>
<body>
    <h2 style="text-align: center;">CHECK PRIME</h2><hr/>
<div id="sl12_form">
    <form action="sl12.php" method="POST">
        <input type="number" name="no1" placeholder="Enter any positive number" min="1" step="1" required/>
        <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="sl12_output">
    <h2> 
    
    <?php
        if(isset($_POST['no1']))
        {
            $val = $_POST['no1'];
            echo $val." IS ";
            echo checkPrime($val) ? " A PRIME NO " : " IS NOT A PRIME NO ";
            
        }
        function checkPrime($a)
        {
            $flag = true;
            for($i = 2; $i <=$a/2 ; $i++)
            {
                if( $a % $i == 0)
                {
                    $flag = false;
                    break;
                }
            }
            return $flag;
        }
        ?>

        </h2>
</div>
</body>
</html>
