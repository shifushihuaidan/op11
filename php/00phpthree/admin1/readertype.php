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
<a href="index1.php?aa=型管理">读者类型设置</a>
<div class="a1">
	<a href="#">添加读者类型信息</a>
</div>
<div class="a2">
<table width="777" height="290" border="1"> 
<th colspan="2">读者类型名称</th>
<th colspan="2">可借数量</th>
<th>删除</th>
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
<a href="#">删除</a>
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