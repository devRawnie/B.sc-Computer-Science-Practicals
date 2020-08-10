<!DOCTYPE html>
<html>
<head>
    <title>SORT AN ARRAY</title>
    <style>
    form input[type="text"]{
        margin: 10px;
        padding: 10px;
        width: 300px;
        border: 1px solid black;
    }
    form input[type="submit"]{
        margin: 10px;
        padding: 10px;
        border: 1px solid black;
    }
    </style>
    <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>
</head>
<body>
    <h2 style="text-align: center;">SORT AN ARRAY</h2><hr/>
<div id="p2_form">
    <form action="p2.php" method="POST">
        <input type="text" name="str" placeholder="Enter the array values seperated by a space." required/>
        <br/><input type="submit" value="Submit">    
    </form> 
</div>
<div id="p2_output">
    <h2>
    
    <?php
        if(isset($_POST['str']))
        {
            $val = $_POST['str'];
            if(strpos($val, ",") !== false)
            {
                echo "Please do not enter any special characters.";
            }
            else
            {
                sortArray($val);
            }
            
        }
        function sortArray($val)
        {
            echo "Original Array: ".$val;
            $inpArr = explode(" ", $val);
            sort($inpArr);
            $outArr = implode(" ", $inpArr);
            echo "<br/>Sorted Array: ".$outArr;
        }
        ?>

        </h2>
</div>
</body>
</html>
