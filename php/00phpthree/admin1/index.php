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
		    �û�����:<input type="text" name="uname" placeholder=
			"����������û���" required><br/>
			�û�����:<input type="password" name="umima" placeholder=
			"�������������" required><br/>
			<input type="submit" name="sub" value="ȷ��">
			<input type="reset" value="����">
            <input type="button" value="�ر�" onclick="window.close()">
		</form>
	</div>
	</div>
</div>
<div class="a3">
	<center>��ϵͳ�ɺ�������д</center>
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
			alertMes("����Ա��½�ɹ�","index1.php");
		}
		else
		{	
			alertMes("��½ʧ��,����Ա���벻��ȷ","index.php");
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
			alertMes("���ߵ�½�ɹ�","../index2.php");
		}
		else
		{	
			alertMes("��½ʧ��,�������벻��ȷ","index.php");
		}
	}
	else
	{
		alertMes("��½ʧ��,�û���������","index.php");
	}
}
?>