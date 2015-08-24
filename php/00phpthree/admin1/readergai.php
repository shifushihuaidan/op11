<?php
//session_start();
?>
<?php
include("mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
$sql="select * from reader where rid='"
.$_GET['id']."'";
//echo $sql;
//$_SEESION['id']=$_GET['id'];
$res=mysql_query($sql);
//echo $sql;
if($res&&mysql_num_rows($res))
{
	$row=mysql_fetch_assoc($res);
}
//var_dump($row);
$c1=$row["rname"];
$c2=$row["sex"];
$c21=$c22="";
if($c2=="男")
{
	$c21="checked";
}
else
{
	$c22="checked";
}
$c3=$row["rid"];
$c4=$row["rtype"];
$c41=$c42=$c43="";
switch($c4)
{
	case "学生":$c41="selected";break;
	case "工作人士":$c42="selected";break;
	case "教师":$c43="selected";break;
}
/*echo $c4;
echo $c41."1学生<br/>";
echo $c42."2工作人士<br/>";
echo $c43."3<br/>";*/
$c5=$row["work"];
$c51=$c52=$c53="";
switch($c5)
{   
	case "大一学生":$c51="selected";break;
	case "大二学生":$c52="selected";break;
	case "教师":$c53="selected";break;
}
$c6=$row["birth"];
$c7=$row["ztype"];
$c71=$c72=$c73="";
switch($c7)
{
	case "身份证":$c71="selected";break;
	case "学生证":$c72="selected";break;
	case "教师证":$c73="selected";break;
}
$c8=$row["znum"];
$c9=$row["rtel"];
$c10=$row["remail"];
$c11=$row["beizhu"];
?>
<html>
<head>
<script type="text/javascript">
<!--
	function fun()
	{
		window.location="index1?aa=读档管理";
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
<a href="#">读者管理</a>》
<a href="index1.php?aa=读档管理">读者档案信息</a>
》
<a href="index1.php?aa=修读"">修改读者信息</a>
<div class="a1">
	<form method="post" action="">
		姓名:<input type="text" name="rname" 
		value="<?php echo $c1 ?>"
		required="required"/><br/>
		性别:<input type="radio" name="sex"
		value="男" <?php echo $c21?>
		>男
            <input type="radio" name="sex"
		value="女" <?php echo $c22?>
			>女<br />
		条形码:<input type="text" name="rid" 
		value="<?php echo $c3 ?>"
		required="required"/><br/>
		读者类型:<select name="rtype">
                    <option value="学生" <?php echo $c41?>
					>学生</option>
                    <option value="工作人士" <?php echo $c42?>
					>工作人士</option>
                    <option value="教师" <?php echo $c43?>
					>教师</option>
                </select><br />
        职业:<select name="work">
                    <option value="大一学生" <?php echo $c51?>
					>大一学生</option>
                    <option value="大二学生" <?php echo $c52?>
					>大二学生</option>
                    <option value="教师" <?php echo $c53?>
					>教师</option>
                </select><br />
		出生日期:<input type="text" name="birth" 
		value="<?php echo $c6 ?>"
		required="required"/><br/>
		有效证件:<select name="ztype">
                    <option 
					value="身份证" <?php echo $c71?>
					>身份证</option>
                    <option 
					value="学生证" <?php echo $c72?>
					>学生证</option>
                    <option 
					value="教师证" <?php echo $c73?>
					>教师证</option>
                </select><br />
		证件号码:<input type="text" name="znum" 
		value="<?php echo $c8 ?>"
		required="required"/><br/>
		电话:<input type="tel"name="rtel" 
		value="<?php echo $c9 ?>" 
		required="required"/><br />
		E-mail:<input type="email" name="remail"
		pattern="[\w\.\-]+@[a-z0-9\-]+\.(com|cn)"
		value="<?php echo $c10 ?>" 
		required="required"/><br />
		备注:<br/><textarea rows="3" cols="20" name="beizhu"
		required="required"
		><?php echo $c11 ?>
        </textarea>
		<br />
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
	$sql="update reader set rname= '".$_POST['rname']
		." ', sex= ' ".$_POST['sex']
		." ', rid= '".$_POST['rid']
		." ', rtype= '".$_POST['rtype']
		." ', work= '".$_POST['work']
		." ', birth= '".$_POST['birth']
		." ', ztype= '".$_POST['ztype']
		." ', znum= '".$_POST['znum']
		."' ,rtel= '".$_POST['rtel']
		."' ,remail=' ".$_POST['remail']
		."' ,beizhu=' ".$_POST['beizhu']."'"
		."where rid='".$_GET['id']."'";
	//echo $sql;
	//alertMes("测试","#");
	$res1=mysql_query($sql);
	if($res1)
	{
		alertMes("修改读者成功","index1?aa=读档管理");
	}
	else
	{
		alertMes("修改读者失败","index1?aa=修读");
	}
}
?>