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
	case "�������":$c31="selected";break;
	case "����������":$c32="selected";break;
	case "��׿":$c33="selected";break;
}
$c4=$_SESSION['zuozhe'];
$c5=$_SESSION['yizhe'];
$c6=$_SESSION['chubanshe'];
switch($c6)
{
	case "������ѧ":$c61="selected";break;
	case "�Ͼ���ѧ":$c62="selected";break;
	case "�㽭��ѧ":$c63="selected";break;
	case "��������������":$c64="selected";break;
}
$c7=$_SESSION['bprice'];
$c8=$_SESSION['page'];
$c9=$_SESSION['shujia'];
switch($c9)
{
	case "jsp���":$c91="selected";break;
	case "C#���":$c92="selected";break;
	case "C++���":$c93="selected";break;
	case "php���":$c94="selected";break;
}
?>
<html>
<head>
<script type="text/javascript">
<!--
	function fun()
	{
		window.location="index1?aa=ͼ������";
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
<a href="index1?aa=ͼ������">ͼ�鵵����Ϣ</a>��
<a href="index1.php?aa=����">���ͼ��</a>
<div class="a1">
	<form method="post" action="">
		������:<input type="text" name="bid" 
		value="<?php echo $c1 ?>"
		required="required"/><br/>
		ͼ������:<input type="text" name="bname" 
		value="<?php echo $c2 ?>"
		required="required"/><br/>
		ͼ������:<select name="btype">
                    <option value="�������" <?php echo $c31?>
					>�������</option>
                    <option value="����������" <?php echo $c32?>
					>����������</option>
                    <option value="��׿" <?php echo $c33?>
					>��׿</option>
                </select><br />
		����:<input type="text" name="zuozhe" 
		value="<?php echo $c4 ?>"
		required="required"/><br/>
		һ��:<input type="text" name="yizhe" 
		value="<?php echo $c5 ?>"
		required="required"/><br/>
		������:<select name="chubanshe">
                    <option value="������ѧ" <?php echo $c61?>
					>������ѧ</option>
                    <option value="�Ͼ���ѧ" <?php echo $c62?>
					>�Ͼ���ѧ</option>
                    <option value="�㽭��ѧ" <?php echo $c63?>
					>�㽭��ѧ</option>
					<option value="��������������" <?php echo $c64?>
					>��������������</option>
                </select><br />
		�۸�:<input type="text" name="bprice" 
		value="<?php echo $c7 ?>"
		required="required"/><br/>
		ҳ��:<input type="text" name="page" 
		value="<?php echo $c8 ?>"
		required="required"/><br/>
		���:<select name="shujia">
                    <option value="jsp���" <?php echo $c91?>
					>jsp���</option>
                    <option value="C#���" <?php echo $c92?>
					>C#���</option>
                    <option value="C++���" <?php echo $c93?>
					>C++���</option>
					<option value="php���" <?php echo $c94?>
					>php���</option>
                </select><br />
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
	//alertMes("����","#");
	$res1=mysql_query($sql);
	if($res1)
	{
		alertMes("����鼮�ɹ�","index1?aa=ͼ������");
	}
	else
	{
		alertMes("����鼮ʧ��","index1?aa=����");
	}
}
?>