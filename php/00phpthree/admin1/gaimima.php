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
��ǰλ��:
<a href="index1.php?aa=����">��������</a>
<div class="a1">
	<form method="post" action="">
		����Ա����:<input type="text" 
		name="uname"
		placeholder="<?php echo $c1;?>"
		readonly
		><br/>
		ԭ��������:<input type="text"
		placeholder="<?php echo $c2;?>"
		readonly
		><br/>
		�µ�����:<input type="text" 
		value="<?php echo $_SESSION['mima1']?>"
		required
		name="mima1" placeholder="�������µ�����"
		><br/>
		ȷ��������:<input type="text"
		value="<?php echo $_SESSION['mima2']?>"
		required
		name="mima2" placeholder="���ٴ������µ�����"
		><br/>
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
			alertMes("��������ɹ�","index1.php");
		}
		else
		{
			alertMes("��������ʧ��","index1.php?aa=����");
		}
	}
	else
	{
		alertMes("�����������벻ƥ��","index1.php?aa=����");
	}
}
?>