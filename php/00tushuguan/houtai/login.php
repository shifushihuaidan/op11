<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>login page</title>
<?php
	error_reporting(0);
	session_cache_limiter( "private, must-revalidate" );
  	session_start();
	if(isset($_POST['sure'])) {  
	$_SESSION['user_username'] =$_POST['username'];
	$_SESSION['user_password'] =$_POST['password'];
	if($_SESSION['user_username']==""){
		echo "<script>alert('你的用户名为空，请输入！！');history.back();</script>";}
	else if($_SESSION['user_password']==""){
		echo "<script>alert('你的密码为空，请输入！！');history.back();</script>";}
	else{      
		
		include("lianjie.php");
		$sql=mysql_query("select * from manager where adminname='".$_SESSION['user_username']."' and password='".$_SESSION['user_password']."'");
		$into=mysql_fetch_array($sql);
		if($into==false){
			echo "<script>alert('您输入的管理员名称错误，请重新输入！！');history.back();</script>";
			exit;
			}
			else{
				echo "<script>alert('登陆成功，欢迎回来!!!');window.location='index.php';</script>";
                } 
	}
}
?>
<style>
.HandD{
	background:#4C94C1;
}
.mid{
	height:243px;
	width:100%;
	background:#86C1E6;
	margin:220px auto;
}
.picture{
	margin:0 auto;
	background-image:url(Images/login_bg.gif);
	width: 603px;
	height: 243px;
}
.words{
		padding-top:100px;
		padding-left:30px;
}
.chuban{
	text-align:center;
	font-family: arial, sans-serif;
	font-size:16px;
    color:#666666;
}
}
</style>
</head>

<body class="HandD">
    <div class="mid">
		<div class="picture">
        <div class="words">
    	<form name="form" action="" method="post">
    		<span>username:</span>
        	<input type="text" name="username" maxlength="10" value="<?php /*if(!empty($_SESSION['user_username']))echo $_SESSION['user_username'];*/?>" /><br/>
        	<span>password:</span>
        	<input type="password" name="password" maxlength="10" value="<?php /* if(!empty($_SESSION['user_password']))echo $_SESSION['user_password'];*/?>" /><br/>
            <input type="submit" name="sure" value="login" style=" margin-left:10px;" />
            <input type="reset" name="resset" value="resset" style="margin-left:0;" />
            <input type="button" name="cancel" value="cancel" onClick="window.close();" style="margin-left:0;" />
    	</form>
        </div>
 		</div>   
    </div>
    <div class="chuban">copyright 2007 www.mrbook 吉林***师范大学图书馆</div>


</body>
</html>