<!DOCTYPE html>
<html>
<head>
    <title>String manipulation</title>
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
    form input[type="radio"]
    {
        margin: 10px;
    }
    radioButton{
        margin: 10px;
        padding: 10px;
    }
    </style>
    <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>
</head>
<body>
    <h2 style="text-align: center;">MANIPULATE STRING</h2><hr/>
<div id="p3_form">
    <form action="p3.php" method="POST">
        
        <input type="text" name="str" placeholder="Enter any String" required/><br/>
        <input type="radio" name="choice" value="1" required/> Remove WhiteSpaces <br/>
        <input type="radio" name="choice" value="2" required/> Check If String Contains Another String 
        <input type="text" name="substr" placeholder="Enter part of string to check"/> <br/> 
        <input type="radio" name="choice" value="3" required/> Check if a String is Lowercase <br/>
        <input type="radio" name="choice" value="4" required/> Replate first "the" in the string <br/>
        <input type="submit" value="Submit">
            </form> 
</div>
<div id="p3_output">
    <h2>
    
    <?php
        if(isset($_POST['str']) && isset($_POST['choice']))
        {
            $mainString = $_POST['str'];
            $ch = $_POST['choice'];
            switch($ch)
            {
                case 1: removeSpaces($mainString);
                        break;
                case 2: checkInString($mainString);
                        break;
                case 3: checkLowerCase($mainString);
                        break;
                case 4: changeFirstThe($mainString);
                        break;
                default: echo "EMPTY SELECTION";
            }
        }
        function removeSpaces($string)
        {
            echo "RESULTING STRING :  ";
            echo str_replace(" ", "", $string);
        }

        function checkInString($string)
        {
            $contains = false;
            $char = isset($_POST["substr"]) ? $_POST["substr"] : false ;
            if($char != "")
            {
                if($char !== false)
            {
                if(strpos($string, $char) !== false)
                {
                    $contains = true;
                }
                if($contains)
                {
                    echo "\"".$char."\" found in \"".$string. "\" ";
                }
                else
                {
                    echo "\"".$char."\" not found in \"".$string. "\" ";
                }
            }
        }
            else
            {
                echo "No Substring Entered";
            }
        }

        function checkLowerCase($string)
        {
            echo "Code under development";
        }
        function changeFirstThe($string)
        {
            echo "Code under development";
        }
    ?>

        </h2>
</div>
</body>
</html>
