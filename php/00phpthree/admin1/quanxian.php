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
    }
    table th{
        background-color:E3F4F7;
	}
</style>
</head>
<body>
当前位置:
<a href="#">系统设置</a>》
<a href="index1.php?aa=管设置">管理员权限设置</a>
<div class="a1">
	<a href="#">添加管理员信息</a>
</div>
<div class="a2">
<table width="777" height="290" border="1"> 
<th>管理员名称</th>
<th>系统设置</th>
<th>读者管理</th>
<th>图书档案管理</th>
<th>图书归还</th>
<th>系统查询</th>
<th>权限设置</th>
<th>操作</th>
<?php
$sql="select * from user";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
 {
		while ($row = mysql_fetch_assoc($res)) 
       { 
			//print_r($row);
			//echo "<br/>";
			echo "<tr>";
			echo "<td>".$row['uname']."</td>";
            
?>
<td>
<input type="checkbox" name="x1" value="1"
disabled
<?php if($row['us']=="1") echo "checked";?>
/>
</td>
<td>
<input type="checkbox" name="x2" value="1"
disabled
<?php if($row['udg']=="1") echo "checked";?>
/>
</td>
<td>
<input type="checkbox" name="x3" value="1"
disabled
<?php if($row['utg']=="1") echo "checked";?>
/>
</td>
<td>
<input type="checkbox" name="x4" value="1"
disabled
<?php if($row['uth']=="1") echo "checked";?>
/>
</td>
<td>
<input type="checkbox" name="x5" value="1"
disabled
<?php if($row['usc']=="1") echo "checked";?>
/>
</td>
<td>
<a href="#">权限设置</a>
</td>
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