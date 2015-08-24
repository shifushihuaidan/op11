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
$sql="select * from user where uname='"
.$_SESSION['name1']."'";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	$row=mysql_fetch_assoc($res);
}
$c1=$row['uname'];
$c2=$row['umima'];
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
</style>
<script type="text/javascript">
<!--
	function fun()
	{
		window.location="index1";
	}
//-->
</script>
</head>
<body>
当前位置:
<a href="index1.php?aa=改密">更改密码</a>
<div class="a1">
	<form method="post" action="">
		管理员名称:<input type="text" 
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
</body>
</html>
<?php
if(isset($_POST['sub']))
{
	$_SESSION['mima1']=$_POST['mima1'];
	$_SESSION['mima2']=$_POST['mima2'];
	if($_POST['mima1']==$_POST['mima2'])
	{
		$sql="update user set umima='"
		.$_POST['mima1']."'"
		."where uname='".$_SESSION['name1']."'";
		$res=mysql_query($sql);
		if($res)
		{
			alertMes("更改密码成功","index1.php");
		}
		else
		{
			alertMes("更改密码失败","index1.php?aa=改密");
		}
	}
	else
	{
		alertMes("两次输入密码不匹配","index1.php?aa=改密");
	}
}
?>