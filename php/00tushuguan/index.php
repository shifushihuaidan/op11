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
	$_SESSION['name1'] =$_POST['username'];
	$_SESSION['user_password'] =$_POST['password'];
	if($_SESSION['name1']==""){
		echo "<script>alert('����û���Ϊ�գ������룡��');history.back();</script>";}
	else if($_SESSION['user_password']==""){
		echo "<script>alert('�������Ϊ�գ������룡��');history.back();</script>";}
	else{      
		
		include("lianjie.php");
		$sql=mysql_query("select * from reader where name='".$_SESSION['name1']."' and pwd='".$_SESSION['user_password']."'");
		//echo "<script>alert('$_POST['username']');</script>";
		$into=mysql_fetch_array($sql);
		if($into==false){
			echo "<script>alert('����������ƴ������������룡��');history.back();</script>";
			exit;
			}
			else{
				echo "<script>alert('��½�ɹ�����ӭ����!!!');window.location='duzhe.php';</script>";
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
<script type="text/javascript">
	function fun1()
	{
		window.location='duzheadd.php';
	}
</script>
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
			<input type="button"  value="regist" onClick="fun1()" 
			style="margin-left:0;" />
            <input type="button" name="cancel" value="cancel" onClick="window.close();" style="margin-left:0;" />
    	</form>
        </div>
 		</div>   
    </div>
    <div class="chuban">copyright 2007 www.mrbook ����***ʦ����ѧͼ���</div>


</body>
</html>