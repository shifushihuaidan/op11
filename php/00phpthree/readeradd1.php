<?php
session_start();
?>
<?php
include("./admin1/mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
$c1=$_SESSION['rname'];
$c2=$_SESSION['sex'];
if($c2=="男")
{
	$c21="checked";
}
else
{
	$c22="checked";
}
$c3=$_SESSION['rid'];
$c4=$_SESSION['rtype'];
switch($c4)
{
	case "学生":$c41="selected";break;
	case "工作人士":$c42="selected";break;
	case "教师":$c43="selected";break;
}
$c5=$_SESSION['work'];
switch($c5)
{
	case "大一学生":$c51="selected";break;
	case "大二学生":$c52="selected";break;
	case "教师":$c53="selected";break;
}
$c6=$_SESSION['birth'];
$c7=$_SESSION['ztype'];
switch($c7)
{
	case "身份证":$c71="selected";break;
	case "学生证":$c72="selected";break;
	case "教师证":$c73="selected";break;
}
$c8=$_SESSION['znum'];
$c9=$_SESSION['rtel'];
$c10=$_SESSION['remail'];
$c11=$_SESSION['beizhu'];
$c12=$_SESSION['rmima'];
?>
<html>
<head>
<script type="text/javascript">
<!--
	function fun()
	{
		window.location="index.php";
	}
//-->
</script>
<style type="text/css">
	.a1
	{
		/*border:1 solid red;*/
		width:500;
		height:500;
		margin:20 auto;
		text-align:center;
	}
	body
	{
	background-color:281C20;
	background-image:url(./image/1.jpg);
	background-repeat:no-repeat;
	background-attachment:fixed;
	background-position:center;
	}
</style>
</head>
<body>
<div class="a1">
	<form method="post" action="">
		姓名:<input type="text" name="rname" 
		value="<?php echo $c1 ?>"
		required="required"/><br/>
		密码:<input type="text" name="rmima" 
		value="<?php echo $c12 ?>"
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
		验证码:<input type="text" required
                name="yanzhengma"
                />
                <img src="yanzhengma.php" 
                id="i1" 
                onclick="this.src='yanzhengma.php?'
                +Math.random()"
                />
				<br/>
                <label onclick="
                document.getElementById('i1').
                src='yanzhengma.php?'
                +new Date().getTime()"
                >看不清换一张</label>
                <br />
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
	$sql="insert into reader values ('".$_POST['rid']
		." ',' ".$_POST['rname']
		." ','".$_POST['work']
		." ','".$_POST['sex']
		." ','".$_POST['rtype']
		." ','".$_POST['birth']
		." ','".$_POST['remail']
		." ', '".$_POST['beizhu']
		."','".$_POST['ztype']
		."',' ".$_POST['znum']
		."',' ".$_POST['rtel']."',0,'".$_POST['rmima']
		."')";
	$_SESSION['rid']=$_POST['rid'];
	$_SESSION['rname']=$_POST['rname'];
	$_SESSION['work']=$_POST['work'];
	$_SESSION['sex']=$_POST['sex'];
	$_SESSION['rtype']=$_POST['rtype'];
	$_SESSION['birth']=$_POST['birth'];
	$_SESSION['remail']=$_POST['remail'];
	$_SESSION['beizhu']=$_POST['beizhu'];
	$_SESSION['ztype']=$_POST['ztype'];
	$_SESSION['znum']=$_POST['znum'];
	$_SESSION['rtel']=$_POST['rtel'];
	$_SESSION['rmima']=$_POST['rmima'];
	//echo $sql;
	//alertMes("测试","#");
	$res1=mysql_query($sql);
	if($res1)
	{
		alertMes("注册成功","index2.php");
	}
	else
	{
		alertMes("注册失败","readeradd1.php");	
	}
}
?>