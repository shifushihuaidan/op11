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
if($c2=="��")
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
	case "ѧ��":$c41="selected";break;
	case "������ʿ":$c42="selected";break;
	case "��ʦ":$c43="selected";break;
}
/*echo $c4;
echo $c41."1ѧ��<br/>";
echo $c42."2������ʿ<br/>";
echo $c43."3<br/>";*/
$c5=$row["work"];
$c51=$c52=$c53="";
switch($c5)
{   
	case "��һѧ��":$c51="selected";break;
	case "���ѧ��":$c52="selected";break;
	case "��ʦ":$c53="selected";break;
}
$c6=$row["birth"];
$c7=$row["ztype"];
$c71=$c72=$c73="";
switch($c7)
{
	case "���֤":$c71="selected";break;
	case "ѧ��֤":$c72="selected";break;
	case "��ʦ֤":$c73="selected";break;
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
��ǰλ��:
<a href="#">���߹���</a>��
<a href="index1.php?aa=��������">���ߵ�����Ϣ</a>
��
<a href="index1.php?aa=�޶�"">�޸Ķ�����Ϣ</a>
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
	//alertMes("����","#");
	$res1=mysql_query($sql);
	if($res1)
	{
		alertMes("�޸Ķ��߳ɹ�","index1?aa=��������");
	}
	else
	{
		alertMes("�޸Ķ���ʧ��","index1?aa=�޶�");
	}
}
?>