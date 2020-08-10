<?php
	session_start();
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Login Page</title>
	</head>

<body>

<form action="index.php" method="POST">
	<input type="text" name="username" placeholder="Enter Login ID"/>
	<br/>
	<input type="text" name="password" placeholder="Enter Password"/>
	<br/>
	<input type="submit" value="Submit"/>
	
</form>
<?php

	$userID = "abc";
	$userPass = "123";
	
	if($_SESSION["username"] == $userID && $_SESSION["password"] === $userPass)
	{
			header("Location: index2.php");
	}
	
	if($_SERVER["REQUEST_METHOD"] == "POST")
	{
		$id = $_POST["username"];
		$pass = $_POST["password"];
		
		if($id === $userID  && $pass === $userPass)
		{
			echo "Working";
			$_SESSION["username"] = $id;
			$_SESSION["password"] = $pass;	
			header("Location: https://www.google.com");
		}
	}
?>

</body>
</html>