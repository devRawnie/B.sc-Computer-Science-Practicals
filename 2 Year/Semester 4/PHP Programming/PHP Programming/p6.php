<!DOCTYPE html>
<html>
<head>
    <title>TRANSALE "HELLO"</title>
    <style>
    select{
        margin: 10px;
        padding: 20px;
        width: 200px;
    }
    form input[type="submit"]{
        margin: 10px;
        padding: 10px;
        border: 1px solid black;
    }
    h2{
        font-size: 1.5em;
    }
    h1{
        text-align: center;
        font-size: 3em;
    }
    </style>
    <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>
</head>
<body>
    <h1>TRANSLATE "HELLO"</h1><hr/>
<div id="p6_form">
    <form action="p6.php" method="POST">
        <h2>Hello in <select name="language" required>
        <?php
                $xml = simplexml_load_file('translations.xml') or die("Error Loading file");
                foreach($xml->children() as $child)
                {
                    echo "<option value=\"{$child->language}\" > {$child->language} </option>";
                }
        ?>
        </select>
        </h2>
        <input type="submit" value="Translate">    
    </form> 
</div>
<div id="p6_output">
    <h1>
        <?php

        if(isset($_POST['language']))
        {
            $val = $_POST['language'];
            
            $xml = simplexml_load_file('translations.xml') or die("Error Loading file");
            foreach($xml->children() as $child)
            {
                if($val == $child->language)
                {
                    echo " '{$child->value}'";
                    break;
                }
            }

        }

        ?>

        </h1>
</div>
</body>
</html>
