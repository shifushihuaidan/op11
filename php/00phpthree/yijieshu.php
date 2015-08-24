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
<th>条形码</th>
<th>借书时间</th>
<th>图书名称</th>
<th>图书类型</th>
<th>出版社</th>
<th>还书</th>
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
<a href="index2?aa=还书&id=<?php echo 
$row['bid']?>">还书</a>
</td>
<?php
		echo "</tr>";
	}
}
else
{
	alertMes("你一本书都还没借过","index2.php?aa=浏览");
}
?>
</table>
</div>
</body>
</html>