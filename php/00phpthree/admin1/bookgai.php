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
$sql="select * from book where bid='"
.$_GET['id']."'";
//echo $sql;
//$_SEESION['id']=$_GET['id'];
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	$row=mysql_fetch_assoc($res);
}
$c1=$row['bid'];
$c2=$row['bname'];
$c3=$row['btype'];
$c31=$c32=$c33="";
/*
if($c3=="�������")
{
	$c31="selected";
}
elseif($c3=="����������")
{
	$c32="selected";
}
else
{
	$c33="selected";
}*/
switch($c3)
{
	case "�������":$c31="selected";break;
	case "����������":$c32="selected";break;
	case "��׿":$c33="selected";break;
}
$c4=$row['zuozhe'];
$c5=$row['yizhe'];
$c6=$row['chubanshe'];
$c61=$c62=$c63=$c64="";
/*
if($c6=="������ѧ")
{
	$c61="selected";
}
elseif($c6=="�Ͼ���ѧ")
{
	$c62="selected";
}
elseif($c6=="�㽭��ѧ")
{
	$c63="selected";
}
else
{
	$c64="selected";
}*/
switch($c6)
{
	case "������ѧ":$c61="selected";break;
	case "�Ͼ���ѧ":$c62="selected";break;
	case "�㽭��ѧ":$c63="selected";break;
	case "��������������":$c64="selected";break;
}
$c7=$row['bprice'];
$c8=$row['page'];
$c9=$row['shujia'];
$c91=$c92=$c93=$c94="";
/*
if($c9=="jsp���")
{
	$c91="selected";
}
elseif($c9=="C#���")
{
	$c92="selected";
}
elseif($c9=="C++���")
{
	$c93="selected";
}
else
{
	$c94="selected";
}*/
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
<a href="index1.php?aa=����">�޸�ͼ����Ϣ</a>
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
	$sql="update book set bid= '".$_POST['bid']
		." ', bname= ' ".$_POST['bname']
		." ', btype= '".$_POST['btype']
		." ', zuozhe= '".$_POST['zuozhe']
		." ', yizhe= '".$_POST['yizhe']
		." ', chubanshe= '".$_POST['chubanshe']
		." ', bprice= '".$_POST['bprice']
		." ', page= ".$_POST['page']
		." ,shujia= '".$_POST['shujia']."'"
		."where bid='".$_GET['id']."'";
	//echo $sql;
	//alertMes("����","#");
	$res1=mysql_query($sql);
	if($res1)
	{
		alertMes("�����鼮�ɹ�","index1?aa=ͼ������");
	}
	else
	{
		alertMes("�����鼮ʧ��","index1?aa=����");
	}
}
?>