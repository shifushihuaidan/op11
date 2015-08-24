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
当前位置:
<a href="index1?aa=图档管理">图书档案信息</a>
<div class="a1">
	<a href="index1?aa=添书">添加图书信息</a>
</div>
<div class="a2">
<table width="777" height="290" border="1"> 
<th>条形码</th>
<th>图书名称</th>
<th>图书类型</th>
<th>出版社</th>
<th>书架</th>
<th>修改</th>
<th>删除</th>
<?php
$sql="select * from book";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	while ($row = mysql_fetch_assoc($res)) 
	{
		echo "<tr>";
		echo "<td>".$row['bid']."</td>";
		echo "<td>".$row['bname']."</td>";
        echo "<td>".$row['btype']."</td>";
		echo "<td>".$row['chubanshe']."</td>";
		echo "<td>".$row['shujia']."</td>";
?>
<td>
<a href="index1?aa=修书&id=<?php echo 
$row['bid']?>">修改</a>
</td>
<td>
<a href="index1?aa=删书&id=<?php echo 
$row['bid']?>">删除</a>
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