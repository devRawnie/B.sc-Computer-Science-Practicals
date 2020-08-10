<!DOCTYPE html>
<html>
<head>
    <title>EVEN NUMBERS</title>
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
    </style>
        <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>

</head>
<body>
    <h2 style="text-align: center;">FIRST N EVEN NUMBERS</h2><hr/>
<div id="sl13_form">
    <form action="sl13.php" method="POST">
        <input type="number" name="no1" placeholder="Enter value of N" min="1" step="1" required/>
        <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="sl13_output">
    <h2> 
    
    <?php
        if(isset($_POST['no1']))
        {
            
            $val = $_POST['no1'];
            echo " FIRST ".$val." EVEN NUMBERS ARE: ";
            echo printFirstN($val);            
        }
        function printFirstN($num)
        {
            $i = 0;
            $j = 0;
            while($i < $num)
            {
                if($j % 2 == 0)
                {
                    echo $j."  ";
                    $i++;
                }
                $j++;
            }
        }
 
        ?>

        </h2>
</div>
</body>
</html>
