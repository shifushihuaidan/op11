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
<a href="index1.php?aa=�͹���">������������</a>
<div class="a1">
	<a href="#">��Ӷ���������Ϣ</a>
</div>
<div class="a2">
<table width="777" height="290" border="1"> 
<th colspan="2">������������</th>
<th colspan="2">�ɽ�����</th>
<th>ɾ��</th>
<?php
$sql="select * from dutype";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	while ($row = mysql_fetch_assoc($res)) 
	{
		echo "<tr>";
?>
<td colspan="2">
<?php
		echo $row['rtype']."</td>";
        //echo "<td></td>";
?>
<td colspan="2">
<?php
echo $row['rshuliang']."</td>";
		//echo "<td></td>";
		//echo "<td></td>";
?>
<td>
<a href="#">ɾ��</a>
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