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
<a href="#">读者管理</a>》
<a href="index1.php?aa=读档管理">读者档案信息</a>
<div class="a1">
	<a href="index1.php?aa=添读">添加读者信息</a>
</div>
<div class="a2">
<table width="777" height="290" border="1"> 
<th>条形码</th>
<th>姓名</th>
<th>读者类型</th>
<th>证件类型</th>
<th>证件号码</th>
<th>电话</th>
<th>Email</th>
<th colspan="2">操作</th>
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
<a href="index1?aa=修读&id=<?php echo 
$row['rid']?>">修改</a>
</td>
<td>
<a href="index1?aa=删读&id=<?php echo 
$row['rid']?>">删除</a>
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