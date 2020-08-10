<!DOCTYPE html>
<html>
<head>
    <title>BIRTHDAY COUNTDOWN</title>
    <script>
    function startTimer()
    {
        var days = <?php echo time()  ?> * 1000;
        console.log(days);
        // document.getElementById("demo").innerHTML= 
    }
    
    </script>



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
    p{
        text-align: center;
        font-size: 2em;
    }
    </style>
    <link rel="icon" href="logo-php.png" type="image/gif" sizes="any"/>



</head>
<body>
    <h2 style="text-align: center;">BIRTHDAY COUNTDOWN TIMER</h2><hr/>
<div id="p4_form">
    <form action="p4.php" method="POST">
        BIRTHDAY : <input type="date" name="bday"  required/>
        <input type="submit" value="Submit">

    </form>

    <button  onClick="startTimer()">START TIMER</button> 
</div>
<div id="p4_output">
    <h2>
    <p id="demo"></p>

<script>
// Set the date we're counting down to
var countDownDate = new Date("Jan 5, 2021 15:37:25").getTime();

// Update the count down every 1 second
var x = setInterval(function() {

  // Get todays date and time
  var now = new Date().getTime();

  // Find the distance between now and the count down date
  var distance = countDownDate - now;

  // Time calculations for days, hours, minutes and seconds
  var days = Math.floor(distance / (1000 * 60 * 60 * 24));
  var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
  var seconds = Math.floor((distance % (1000 * 60)) / 1000);

  // Display the result in the element with id="demo"
  document.getElementById("demo").innerHTML = days + "d " + hours + "h "
  + minutes + "m " + seconds + "s ";

  // If the count down is finished, write some text
  if (distance < 0) {
    clearInterval(x);
    document.getElementById("demo").innerHTML = "EXPIRED";
  }
}, 1000);

</script>

    </h2>
</div>


    <?php
        if(isset($_POST['bday']))
        {
        $date1 = $_POST['bday'];
        $dateArr = explode("-", $date1);
        $endTime = gmmktime(0, 0, 0, $dateArr[1], $dateArr[2], $dateArr[0]);
        $endDate = new DateTime("@".$endTime);
        $_POST["countDownDate"] = $endTime;
        $startDate = new DateTime("@".time());

        echo $startDate->format("d-m-Y");
        echo "<br/>";
        echo $endDate->format("d-m-Y");
        echo "<br/>";
        
        $diff = $endDate->diff($startDate);
        echo $diff->format("%Y years %m months %d days %H hours %i minutes %s seconds");    
        echo "<br/>";
        
    
        
        }
        ?>


</body>
</html>
