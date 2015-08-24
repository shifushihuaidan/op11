<?php
session_start();
?>
<?php
include("mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
$c1=$_SESSION['bid'];
$c2=$_SESSION['bname'];
$c3=$_SESSION['btype'];
switch($c3)
{
	case "编程语言":$c31="selected";break;
	case "网络编程语言":$c32="selected";break;
	case "安卓":$c33="selected";break;
}
$c4=$_SESSION['zuozhe'];
$c5=$_SESSION['yizhe'];
$c6=$_SESSION['chubanshe'];
switch($c6)
{
	case "北京大学":$c61="selected";break;
	case "南京大学":$c62="selected";break;
	case "浙江大学":$c63="selected";break;
	case "人名教育出版蛇":$c64="selected";break;
}
$c7=$_SESSION['bprice'];
$c8=$_SESSION['page'];
$c9=$_SESSION['shujia'];
switch($c9)
{
	case "jsp书架":$c91="selected";break;
	case "C#书架":$c92="selected";break;
	case "C++书架":$c93="selected";break;
	case "php书架":$c94="selected";break;
}
?>
<html>
<head>
<script type="text/javascript">
<!--
	function fun()
	{
		window.location="index1?aa=图档管理";
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
<a href="index1?aa=图档管理">图书档案信息</a>》
<a href="index1.php?aa=添书">添加图书</a>
<div class="a1">
	<form method="post" action="">
		条形码:<input type="text" name="bid" 
		value="<?php echo $c1 ?>"
		required="required"/><br/>
		图书名称:<input type="text" name="bname" 
		value="<?php echo $c2 ?>"
		required="required"/><br/>
		图书类型:<select name="btype">
                    <option value="编程语言" <?php echo $c31?>
					>编程语言</option>
                    <option value="网络编程语言" <?php echo $c32?>
					>网络编程语言</option>
                    <option value="安卓" <?php echo $c33?>
					>安卓</option>
                </select><br />
		作者:<input type="text" name="zuozhe" 
		value="<?php echo $c4 ?>"
		required="required"/><br/>
		一泽:<input type="text" name="yizhe" 
		value="<?php echo $c5 ?>"
		required="required"/><br/>
		出版社:<select name="chubanshe">
                    <option value="北京大学" <?php echo $c61?>
					>北京大学</option>
                    <option value="南京大学" <?php echo $c62?>
					>南京大学</option>
                    <option value="浙江大学" <?php echo $c63?>
					>浙江大学</option>
					<option value="人名教育出版蛇" <?php echo $c64?>
					>人名教育出版蛇</option>
                </select><br />
		价格:<input type="text" name="bprice" 
		value="<?php echo $c7 ?>"
		required="required"/><br/>
		页码:<input type="text" name="page" 
		value="<?php echo $c8 ?>"
		required="required"/><br/>
		书架:<select name="shujia">
                    <option value="jsp书架" <?php echo $c91?>
					>jsp书架</option>
                    <option value="C#书架" <?php echo $c92?>
					>C#书架</option>
                    <option value="C++书架" <?php echo $c93?>
					>C++书架</option>
					<option value="php书架" <?php echo $c94?>
					>php书架</option>
                </select><br />
                <input type="submit" name="sub" value="保存" />
                <input type="button" name="reset" value="返回"
				onclick="fun()">
		</form>
</div>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
	$sql="insert into book values ('".$_POST['bid']
		." ', ' ".$_POST['bname']
		." ',  '".$_POST['btype']
		." ',  '".$_POST['shujia']
		." ', '".$_POST['chubanshe']
		." ',  '".$_POST['zuozhe']
		." ','".$_POST['bprice']
		." ', '".$_POST['yizhe']
		."' , ".$_POST['page'].",0)";
	//echo $sql;
	$_SESSION['bid']=$_POST['bid'];
	$_SESSION['bname']=$_POST['bname'];
	$_SESSION['btype']=$_POST['btype'];
	$_SESSION['shujia']=$_POST['shujia'];
	$_SESSION['chubanshe']=$_POST['chubanshe'];
	$_SESSION['zuozhe']=$_POST['zuozhe'];
	$_SESSION['bprice']=$_POST['bprice'];
	$_SESSION['yizhe']=$_POST['yizhe'];
	$_SESSION['page']=$_POST['page'];
	//alertMes("测试","#");
	$res1=mysql_query($sql);
	if($res1)
	{
		alertMes("添加书籍成功","index1?aa=图档管理");
	}
	else
	{
		alertMes("添加书籍失败","index1?aa=添书");
	}
}
?>