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
		height:80;
		background-color:F1F1F1;
		/*border:1px solid red;*/
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
</style>
</head>
<body>
<div class="a1">
<font size="16" color=""><strong>图书借阅排行榜</strong></font>
</div>
<table width="777" height="290" border="1"> 
<th>排名</th>
<th>图书条形码</th>
<th>图书名称</th>
<th>图书类型</th>
<th>书架</th>
<th>出版社</th>
<th>作者</th>
<th>单价</th>
<th>借阅次数</th>
<?php
$sql="select * from book ORDER BY cishu DESC";
$res=mysql_query($sql);
$i=1;
if($res&&mysql_num_rows($res))
	{
		while ($row = mysql_fetch_assoc($res)) 
       { 
			echo "<tr>";
			echo "<td>".$i."</td>";
			echo "<td>".$row['bid']."</td>"; 
			echo "<td>".$row['bname']."</td>";
			echo "<td>".$row['btype']."</td>";
			echo "<td>".$row['shujia']."</td>";
			echo "<td>".$row['chubanshe']."</td>";
			echo "<td>".$row['zuozhe']."</td>";
			echo "<td>".$row['bprice']."</td>";
			echo "<td>".$row['cishu']."</td>";
			echo "</tr>";
			$i++;
       }
	}
?>
</table>
</body>
</html>