<?php
include("mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
$sql="select * from zhengjian where zname='����֤'";
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
��ǰλ��:
<a href="#">ϵͳ����</a>��
<a href="index1.php?aa=������">��������</a>
<div  class="a1">
	<form method="post" action="">
		��֤��:<input type="text" 
		required
		name="zprice" 
		placeholder="ԭ����<?php 
		echo $c1;
		?>"/>Ԫ<br />
		��Чʱ��:<input type="text" 
		required
		name="ztime" 
		placeholder="ԭ����<?php 
		echo $c2;
		?>"/>��<br />
		<input type="submit" name="sub" value="����" />
        <input type="button" name="reset" value="ȡ��"
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
		alertMes("���³ɹ�","index1.php");
	}
	else
	{
		alertMes("����ʧ��","index1.php?aa=������");
	}
}
?>