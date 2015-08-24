<?php
session_start();
?>
<?php 
include("mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
?>
<html>
<head>
<style type="text/css">
	.a1
	{
		width:100%;
		height:200;
		background-color:4C94C1;
	}
	.a2
	{
		width:100%;
		height:250;
		background-color:86C1E6;
	}
	.a3
	{
		width:100%;
		height:100;
		background-color:4C94C1;
	}
	.a4
	{
		border-top:1px solid 86C1E6;
		/*border-left:1px solid 86C1E6;*/
        background:url(./images/bg.gif);
		background-position:center;
        /*background-repeat:no-repeat;*/
		width:603;
		height:243;
		margin:0 auto;
	}
	.a5
	{
		/*border:1px solid red;*/
		width:300;
		height:100;
        margin:100 40;
	}
</style>
</head>
<body>
<div class="a1">
</div>
<div class="a2">
	<div class="a4">
	<div class="a5">
		<form method="post" action="">
		    用户名程:<input type="text" name="uname" placeholder=
			"请输入你的用户名" required><br/>
			用户密码:<input type="password" name="umima" placeholder=
			"请输入你的密码" required><br/>
			<input type="submit" name="sub" value="确定">
			<input type="reset" value="重置">
            <input type="button" value="关闭" onclick="window.close()">
		</form>
	</div>
	</div>
</div>
<div class="a3">
	<center>本系统由海贼王编写</center>
</div>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
	$name=$_POST['uname'];
	$mima=$_POST['umima'];
	$sql="select uname from user where uname='";
	$sql.=$name."'";
	$sql2="select rname from reader where rname='";
	$sql2.=$name."'";
	$res=mysql_query($sql);
	//echo $sql2."<br>";
	$res2=mysql_query($sql2);
    //$s1=mysql_num_rows($res2);
	//echo $s1;
	if($res&&mysql_num_rows($res))
	{
		$sql="select uname from user where uname='";
		$sql.=$name."' and umima= '".$mima."'";
		$res=mysql_query($sql);
		if($res&&mysql_num_rows($res))
		{
			$_SESSION['name1']=$name;
			alertMes("管理员登陆成功","index1.php");
		}
		else
		{	
			alertMes("登陆失败,管理员密码不正确","index.php");
		}
	}
	elseif($res2&&mysql_num_rows($res2))
	{
		$sql2="select rname from reader where rname='";
		$sql2.=$name."' and rmima= '".$mima."'";
		$res2=mysql_query($sql2);
		if($res2&&mysql_num_rows($res2))
		{
			$_SESSION['name2']=$name;
			alertMes("读者登陆成功","../index2.php");
		}
		else
		{	
			alertMes("登陆失败,读者密码不正确","index.php");
		}
	}
	else
	{
		alertMes("登陆失败,用户名不存在","index.php");
	}
}
?>