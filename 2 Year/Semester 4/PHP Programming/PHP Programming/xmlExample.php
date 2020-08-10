<!DOCTYPE <!DOCTYPE html>
<html>
<head>
    <title>XML Example</title>
    <style>
        h1, h2{
            text-align: center;
        }
        form input[type="text"]
        {
            display: block;
            margin: 0px 0px 10px 10px;
        }
        form input[type="submit"]
        {
            margin-left: 10px;
            padding: 5px;
        }
    </style>
</head>
<body>
    <h1>STUDENT DATABASE</h1><hr/><br/>
    <h2>Add Record</h2>
    <form action="xmlExample.php"   method="POST">
    <input  type="text" name="name" placeholder="Enter Name" required/>
    <input  type="text" name="course" placeholder="Enter Course Name" required/>
    <input  type="text" name="year" placeholder="Enter Year" required/>
    <input  type="text" name="roll" placeholder="Enter Roll Number" required/>
    <input  type="submit" value="Add Record"  />
    </form>

    <br/><br/><hr/>

    <h2>Display Record</h2><br/><br/>
    <?php
        $xml = simplexml_load_file('students_record.xml') or die("Error opening file");
        
        foreach($xml->children() as $child)
        {
        echo "  Roll no. $child->roll: $child->name studies in $child->course, $child->year year. <br/>";
        }

?>


</body>
</html>

    <?php
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $name = $_POST["name"];
        $course = $_POST["course"];
        $year = $_POST["year"];
        $roll = $_POST["roll"];

        $xml = simplexml_load_file("students_record.xml") or die("Error loading file");

        $child = $xml->addChild('student');

        $child->addChild('name', $name);
        $child->addChild('course', $course);
        $child->addChild('year', $year);
        $child->addChild('roll', $roll);

        $xml->asXML('students_record.xml');


        $dom = new DOMDocument('1.0');
        $dom->preserveWhiteSpace = false;
        $dom->formatOutput = true;
        $dom->loadXML($xml->asXML());
        $dom->save('students_record.xml');


    }
    ?>