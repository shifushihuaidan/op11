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
		width:120;
		height:30;
		/*border:1 solid red;*/
		margin:0 200 0 650;
	}
	a 
	{
		text-decoration:none;
	}
	.a2
	{
		
		width:777;
		height:300;
		/*border:1 solid red;*/
	}
	table {
        border-collapse:collapse;
        border-spacing:0;
        border:1px solid 0A5F93;
    }
    table td {
        border-color:0A5F93;
        text-align:center;
		/*border:0px;*/
    }
    table th{
        background-color:E3F4F7;
	}
	table tr{
        border:1px solid 0A5F93;
	}
</style>
</head>
<body>
��ǰλ��:
<a href="#">���߹���</a>��
<a href="index1.php?aa=��������">���ߵ�����Ϣ</a>
<div class="a1">
	<a href="index1.php?aa=����">���Ӷ�����Ϣ</a>
</div>
<div class="a2">
<table width="777" height="290" border="1"> 
<th>������</th>
<th>����</th>
<th>��������</th>
<th>֤������</th>
<th>֤������</th>
<th>�绰</th>
<th>Email</th>
<th colspan="2">����</th>
<?php
$sql="select * from reader";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	while ($row = mysql_fetch_assoc($res)) 
	{
		echo "<tr>";
		echo "<td>".$row['rid']."</td>";
		echo "<td>".$row['rname']."</td>";
        echo "<td>".$row['rtype']."</td>";
		echo "<td>".$row['ztype']."</td>";
		echo "<td>".$row['znum']."</td>";
		echo "<td>".$row['rtel']."</td>";
		echo "<td>".$row['remail']."</td>";
?>
<td>
<a href="index1?aa=�޶�&id=<?php echo 
$row['rid']?>">�޸�</a>
</td>
<td>
<a href="index1?aa=ɾ��&id=<?php echo 
$row['rid']?>">ɾ��</a>
</td>
<?php
		echo "</tr>";
	}
}
?>
</table>
</div>
</body>
</html>