<?php
include("./houtai/lianjie.php");
function alerts($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
?>
<html>
<head>
<style type="text/css">
	.a3
	{
		width:777;
		height:300;
		margin:0 auto;
	}
	.a2
	{
		width:1000;
		height:400;
		background-color:281C20;
		background-image:url(./image/4.jpg);
		background-repeat:no-repeat;
		background-attachment:fixed;
		background-position:center;
		color:blue;
	}
	body
	{
		color:green;
	}
</style>
</head>
<body>
<div class="a2">
	<div class="a1">
	<form method="post" action="">
		����:<input type="text" name="rname"
		required
		placeholder="����ؼ��ּ���"
		>
		<input type="submit" name="sub" value="ģ����ѯ">
	</form>
</div>
<div class="a3">
<table width="777" height="290" border="1"> 
<th>������</th>
<th>ͼ������</th>
<th>ͼ������</th>
<th>������</th>
<th>���</th>
<th>����</th>
<?php
if(isset($_POST['sub']))
{
$s1=$_POST['rname'];
$s2='%'.$s1.'%';
$sql="select * from bookinfo where bookname  like 
'".$s2."'";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	while ($row = mysql_fetch_assoc($res)) 
	{
		echo "<tr>";
		echo "<td>".$row['id']."</td>";
		echo "<td>".$row['bookname']."</td>";
        echo "<td>".$row['booktype']."</td>";
		echo "<td>".$row['publishing']."</td>";
		echo "<td>".$row['bookcase']."</td>";
?>
<td>
<a href="duzhe?aa=����&id=<?php echo 
$row['id']?>">����</a>
</td>
<?php
		echo "</tr>";
	}
}
else
{
	alerts("�Բ���ú�͸���","duzhe.php?aa=����");
}
}
?>
</table>
</div>
</div>
</body>
</html>
