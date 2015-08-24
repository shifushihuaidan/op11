<?php
session_start();
?>
<?php
include("./admin1/mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
$rid="(select rid from reader where rname='".$_SESSION['name2']."')";
$res4=mysql_query($rid);
$row= mysql_fetch_assoc($res4);
$ri=$row['rid'];
$sql="select * from reader where rid='"
.$ri."'";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	$row=mysql_fetch_assoc($res);
}
$c1=$row['rname'];
$c2=$row['rmima'];
?>
<html>
<head>
<style type="text/css">
	.a1
	{
		width:300;
		height:300;
		/*border:1 solid red;*/
		margin:0 auto;
		/*background-color:blue;*/
	}
	.a2
	{
		width:777;
		height:370;
		/*border:1 solid red;*/
		background-color:281C20;
		background-image:url(./image/5.jpg);
		background-repeat:no-repeat;
		background-attachment:fixed;
		background-position:center;
		color:blue;
	}
</style>
<script type="text/javascript">
<!--
	function fun()
	{
		window.location="index2.php";
	}
//-->
</script>
</head>
<body>
<div class="a2">
<div class="a1">
	<form method="post" action="">
		读者名称:<input type="text" 
		name="uname"
		placeholder="<?php echo $c1;?>"
		readonly
		><br/>
		原来的密码:<input type="text"
		placeholder="<?php echo $c2;?>"
		readonly
		><br/>
		新的密码:<input type="text" 
		value="<?php echo $_SESSION['mima1']?>"
		required
		name="mima1" placeholder="请输入新的密码"
		><br/>
		确认新密码:<input type="text"
		value="<?php echo $_SESSION['mima2']?>"
		required
		name="mima2" placeholder="请再次输入新的密码"
		><br/>
		<input type="submit" name="sub" value="保存" />
                <input type="button" name="reset" value="取消"
				onclick="fun()">
	</form>
</div>
</div>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
	$_SESSION['mima1']=$_POST['mima1'];
	$_SESSION['mima2']=$_POST['mima2'];
	if($_POST['mima1']==$_POST['mima2'])
	{
		$sql="update reader set rmima='"
		.$_POST['mima1']."'"
		."where rid='".$ri."'";
		$res=mysql_query($sql);
		if($res)
		{
			alertMes("更改密码成功","index2.php");
		}
		else
		{
			alertMes("更改密码失败","index2.php?aa=口令");
		}
	}
	else
	{
		alertMes("两次输入密码不匹配","index2.php?aa=口令");
	}
}
?>