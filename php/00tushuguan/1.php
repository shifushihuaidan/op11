<?php
include("houtai/lianjie.php");
?>
<?php
function alerts($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
?>
<html>
<head>
<style type="text/css">
	a 
	{
		text-decoration:none;
	}
	.a2
	{
		
		width:777;
		height:300;
	}
	table {
        border-collapse:collapse;
        border-spacing:0;
        border:1px solid 0A5F93;
    }
    table td {
        border-color:0A5F93;
        text-align:center;
    }
    table th{
        background-color:E3F4F7;
	}
	table tr{
        border:1px solid 0A5F93;
	}
	body
	{
		color:blue;
	}
</style>
</head>
<body>
<div class="a2">
<table width="777" height="290" border="1"> 
<th>������</th>
<th>����ʱ��</th>
<th>ͼ������</th>
<th>ͼ������</th>
<th>������</th>
<th>����</th>
<?php
$sql="select * from bbook where rid=32";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	while ($row = mysql_fetch_assoc($res)) 
	{
		echo "<tr>";
		echo "<td>".$row['bid']."</td>";
		$sql2="select * from bookinfo where id=".$row['bid'];
		$res1=mysql_query($sql2);
		$row1 = mysql_fetch_assoc($res1);
		//echo $sql2;
		echo "<td>".$row['jieshutime']."</td>";
        echo "<td>".$row1['bookname']."</td>";
		echo "<td>".$row1['booktype']."</td>";
		echo "<td>".$row1['publishing']."</td>";
?>
<td>
<a href="duzhe.php?cc=����&id=<?php echo 
$row['bid']?>">����</a>
</td>
<?php
		echo "</tr>";
	}
}
else
{
	alerts("��δ����","duzhe.php?cc=���");
}
?>
</table>
</div>
</body>
</html>