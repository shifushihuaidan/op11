<?php
include("mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
$sql="select * from lib";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	$row=mysql_fetch_assoc($res);
}
$c1=$row['lname'];
$c2=$row['yname'];
$c3=$row['tel'];
$c4=$row['addr'];
$c5=$row['lemail'];
$c6=$row['wz'];
$c7=$row['ltime'];
$c8=$row['ldes'];
//echo $c7;
?>
<html>
<head>
<script type="text/javascript">
<!--
	function fun()
	{
		window.location="index1.php";
	}
//-->
</script>
<style type="text/css">
	.a1
	{
		/*border:1 solid red;*/
		width:500;
		height:400;
		margin:0 auto;
		text-align:center;
	}
</style>
</head>
<body>
当前位置:
<a href="#">系统设置</a>》
<a href="index1.php?aa=图修改">图书馆信息修改</a>
<div class="a1">
	<form method="post" action="">
		图书馆名称:<input type="text" name="lname" 
		value="<?php echo $c1 ?>"
		required="required"/><br />
        院长:<input type="text" name="yname"
		value="<?php echo $c2 ?>"
		required="required"/><br />
		联系电话:<input type="tel"name="tel" 
		value="<?php echo $c3 ?>" 
		required="required"/><br />
		联系地址:<input type="text"name="addr" 
		value="<?php echo $c4 ?>" 
		required="required"/><br />
		E-mail:<input type="email" name="lemail"
		pattern="[\w\.\-]+@[a-z0-9\-]+\.(com|cn)"
		value="<?php echo $c5 ?>" 
		required="required"/><br />
		图书馆网址:<input type="url" name="wz" 
		value="<?php echo $c6 ?>"
		required="required"/><br />
        建立时间:<input type="date" name="ltime" 
		value="<?php echo $c7 ?>"
		required="required"/><br />
		图书馆描述:<br/><textarea rows="3" cols="20" name="ldes"
		required="required"
		><?php echo $c8 ?>
        </textarea>
		<br />
                <input type="submit" name="sub" value="保存" />
                <input type="button" name="reset" value="取消"
				onclick="fun()">
		</form>
</div>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
	$sql="update lib set lname= '".$_POST['lname']
		." ', yname= ' ".$_POST['yname']
		." ', tel= '".$_POST['tel']
		." ', addr= '".$_POST['addr']
		." ', lemail= '".$_POST['lemail']
		." ', wz= '".$_POST['wz']
		." ', ltime= '".$_POST['ltime']
		." ', ldes= '".$_POST['ldes']."'";
	//echo $sql;
	//alertMes("测试","#");
	$res1=mysql_query($sql);
	if($res1)
	{
		alertMes("更新图书馆成功","index1.php");
	}
	else
	{
		alertMes("更新图书馆失败","index1.php?aa=图修改");
	}
}
?>