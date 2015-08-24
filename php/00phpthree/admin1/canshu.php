<?php
include("mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
$sql="select * from zhengjian where zname='借阅证'";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	$row=mysql_fetch_assoc($res);
}
$c1=$row['zprice'];
$c2=$row['ztime'];
?>
<html>
<head>
<style type="text/css">
	.a1
	{
		width:300;
		height:300;
		/*border:1 solid red;*/
		margin :0 auto;
	}
</style>
<script type="text/javascript">
<!--
	function fun()
	{
		window.location="index1.php";
	}
//-->
</script>
</head>
<body>
当前位置:
<a href="#">系统设置</a>》
<a href="index1.php?aa=参设置">参数设置</a>
<div  class="a1">
	<form method="post" action="">
		办证费:<input type="text" 
		required
		name="zprice" 
		placeholder="原价是<?php 
		echo $c1;
		?>"/>元<br />
		有效时间:<input type="text" 
		required
		name="ztime" 
		placeholder="原来是<?php 
		echo $c2;
		?>"/>月<br />
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
	$sql="update zhengjian set zprice='"
	.$_POST['zprice']."',ztime='"
	.$_POST['ztime']."'";
	$res=mysql_query($sql);
	if($res)
	{
		alertMes("更新成功","index1.php");
	}
	else
	{
		alertMes("更改失败","index1.php?aa=参设置");
	}
}
?>