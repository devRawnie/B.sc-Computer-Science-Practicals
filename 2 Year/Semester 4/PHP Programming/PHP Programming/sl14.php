<!DOCTYPE html>
<html>
<head>
    <title>SUM OF ODD NUMBERS</title>
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
        padding: 10px;
    }
    </style>
        <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>

</head>
<body>
    <h2 style="text-align: center;">SUM OF FIRST N ODD NUMBERS</h2><hr/>
<div id="sl14_form">
    <form action="sl14.php" method="POST">
        <input type="number" name="no1" placeholder="Enter value of N" min="1" step="1" required/>
        <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="sl14_output">
    <h2> 
    
    <?php
        if(isset($_POST['no1']))
        {
            
            $val = $_POST['no1'];
            echo " SUM OF ".$val." ODD NUMBERS <br/><br/> ";
            echo printSumFirstNOdd($val);            
        }
        function printSumFirstNOdd($num)
        {
            $i = 0;
            $j = 0;
            $sum = 0;
            while($i < $num)
            {
                if($j % 2 != 0)
                {
                    echo $j;
                    $sum += $j;
                    if($i != $num-1)
                    {
                        echo " + ";
                    }                                        
                    $i++;
                }
                $j++;
            }
            echo " = ".$sum;
        }
 
        ?>

        </h2>
</div>
</body>
</html>
