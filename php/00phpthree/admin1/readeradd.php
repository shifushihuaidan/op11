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
$c1=$_SESSION['rname'];
$c2=$_SESSION['sex'];
if($c2=="��")
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
	case "ѧ��":$c41="selected";break;
	case "������ʿ":$c42="selected";break;
	case "��ʦ":$c43="selected";break;
}
$c5=$_SESSION['work'];
switch($c5)
{
	case "��һѧ��":$c51="selected";break;
	case "���ѧ��":$c52="selected";break;
	case "��ʦ":$c53="selected";break;
}
$c6=$_SESSION['birth'];
$c7=$_SESSION['ztype'];
switch($c7)
{
	case "���֤":$c71="selected";break;
	case "ѧ��֤":$c72="selected";break;
	case "��ʦ֤":$c73="selected";break;
}
$c8=$_SESSION['znum'];
$c9=$_SESSION['rtel'];
$c10=$_SESSION['remail'];
$c11=$_SESSION['beizhu'];
?>
<html>
<head>
<script type="text/javascript">
<!--
	function fun()
	{
		window.location="index1?aa=��������";
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
<div class="a1">
	<form method="post" action="">
		����:<input type="text" name="rname" 
		value="<?php echo $c1 ?>"
		required="required"/><br/>
		�Ա�:<input type="radio" name="sex"
		value="��" <?php echo $c21?>
		>��
            <input type="radio" name="sex"
		value="Ů" <?php echo $c22?>
			>Ů<br />
		������:<input type="text" name="rid" 
		value="<?php echo $c3 ?>"
		required="required"/><br/>
		��������:<select name="rtype">
                    <option value="ѧ��" <?php echo $c41?>
					>ѧ��</option>
                    <option value="������ʿ" <?php echo $c42?>
					>������ʿ</option>
                    <option value="��ʦ" <?php echo $c43?>
					>��ʦ</option>
                </select><br />
        ְҵ:<select name="work">
                    <option value="��һѧ��" <?php echo $c51?>
					>��һѧ��</option>
                    <option value="���ѧ��" <?php echo $c52?>
					>���ѧ��</option>
                    <option value="��ʦ" <?php echo $c53?>
					>��ʦ</option>
                </select><br />
		��������:<input type="text" name="birth" 
		value="<?php echo $c6 ?>"
		required="required"/><br/>
		��Ч֤��:<select name="ztype">
                    <option 
					value="���֤" <?php echo $c71?>
					>���֤</option>
                    <option 
					value="ѧ��֤" <?php echo $c72?>
					>ѧ��֤</option>
                    <option 
					value="��ʦ֤" <?php echo $c73?>
					>��ʦ֤</option>
                </select><br />
		֤������:<input type="text" name="znum" 
		value="<?php echo $c8 ?>"
		required="required"/><br/>
		�绰:<input type="tel"name="rtel" 
		value="<?php echo $c9 ?>" 
		required="required"/><br />
		E-mail:<input type="email" name="remail"
		pattern="[\w\.\-]+@[a-z0-9\-]+\.(com|cn)"
		value="<?php echo $c10 ?>" 
		required="required"/><br />
		��ע:<br/><textarea rows="3" cols="20" name="beizhu"
		required="required"
		><?php echo $c11 ?>
        </textarea>
		<br />
                <input type="submit" name="sub" value="����" />
                <input type="button" name="reset" value="����"
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
		."',' ".$_POST['rtel']."',0,'"."1234"
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
	//echo $sql;
	//alertMes("����","#");
	
	$res1=mysql_query($sql);
	if($res1)
	{
		alertMes("��Ӷ��߳ɹ�","index1?aa=��������");
	}
	else
	{
		alertMes("���ʧ��","index1?aa=���");	
	}
}
?>