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
<meta charset="utf8">
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
</style>
</head>
<body>
<div class="a2">
<table width="777" height="290" border="1"> 
<th>������</th>
<th>ͼ������</th>
<th>ͼ������</th>
<th>������</th>
<th>���</th>
<th>����</th>
<?php
$sql="select * from bookinfo";
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
<a href="duzhe?cc=����&id=<?php echo 
$row['id']?>">����</a>
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

