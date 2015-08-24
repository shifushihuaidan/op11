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
<style type="text/css">
	.a3
	{
		width:777;
		height:300;
		margin:0 auto;
	}
	.a2
	{
		width:1000;
		height:400;
		background-color:281C20;
		background-image:url(./image/4.jpg);
		background-repeat:no-repeat;
		background-attachment:fixed;
		background-position:center;
		color:blue;
	}
	body
	{
		color:green;
	}
</style>
</head>
<body>
<div class="a2">
	<div class="a1">
	<form method="post" action="">
		书名:<input type="text" name="rname"
		required
		placeholder="输入关键字即可"
		>
		<input type="submit" name="sub" value="模糊查询">
	</form>
</div>
<div class="a3">
<table width="777" height="290" border="1"> 
<th>条形码</th>
<th>图书名称</th>
<th>图书类型</th>
<th>出版社</th>
<th>书架</th>
<th>借书</th>
<?php
if(isset($_POST['sub']))
{
$s1=$_POST['rname'];
$s2='%'.$s1.'%';
$sql="select * from bookinfo where bookname  like 
'".$s2."'";
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
<a href="duzhe?aa=借书&id=<?php echo 
$row['id']?>">借书</a>
</td>
<?php
		echo "</tr>";
	}
}
else
{
	alerts("对不起煤油该书","duzhe.php?aa=找书");
}
}
?>
</table>
</div>
</div>
</body>
</html>
