<?php
include("./admin1/mycon.php");
function alertMes($mes,$url)
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
<div class="a2">
<table width="777" height="290" border="1"> 
<th>������</th>
<th>����ʱ��</th>
<th>ͼ������</th>
<th>ͼ������</th>
<th>������</th>
<th>����</th>
<?php
$rid="(select rid from reader where rname='".$_SESSION['name2']."')";
$sql="select * from bbook where rid=".$rid;
//echo $sql;
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	while ($row = mysql_fetch_assoc($res)) 
	{
		echo "<tr>";
		echo "<td>".$row['bid']."</td>";
		$sql2="select * from book where bid='".$row['bid']."'";
		$res1=mysql_query($sql2);
		$row1 = mysql_fetch_assoc($res1);
		echo "<td>".$row['jssj']."</td>";
        echo "<td>".$row1['bname']."</td>";
		echo "<td>".$row1['btype']."</td>";
		echo "<td>".$row1['chubanshe']."</td>";
?>
<td>
<a href="index2?aa=����&id=<?php echo 
$row['bid']?>">����</a>
</td>
<?php
		echo "</tr>";
	}
}
else
{
	alertMes("��һ���鶼��û���","index2.php?aa=���");
}
?>
</table>
</div>
</body>
</html>