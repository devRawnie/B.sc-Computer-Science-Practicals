<!DOCTYPE html>
<html>
<head>
    <title>PRINT TRIANGLE</title>
    <style>
    form input[type="text"], input[type="number"]{
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
    <h2 style="text-align: center;">PRINT TRIANGLE WITH A SPECIAL CHARACTER</h2><hr/>
<div id="sl17_form">
    <form action="sl17.php" method="POST">
        <input type="text" name="char" placeholder="Enter any character" required/>
        <input type="number" name="side" placeholder="Enter Side of triangle" min="1" step="1" required/>
                <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="sl17_output">
    <h2>
    <?php
        if(isset($_POST['char']) && isset($_POST['side']) )
        {
            $ch = $_POST['char'];
            $n = $_POST['side'];
            printTriangle($ch, $n);
            
        }
        function printTriangle($ch, $side)
        {
            for($i = 0; $i < $side ; $i++)
            {
                for($j = 0; $j <= $i ; $j++)
                {
                    echo $ch." ";
                }
                echo "<br/>";
            }
        }
        ?>

        </h2>
</div>
</body>
</html>
