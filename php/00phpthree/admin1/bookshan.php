<?php
include("mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
?>
<?php 
$sql="delete from book where bid='"
.$_GET['id']."'";
$res=mysql_query($sql);
if($res)
{
	alertMes("ɾ���鼮�¹�","index1?aa=ͼ������");
}
else
{
	alertMes("ɾ���鼮ʧ��","index1?aa=ͼ������");
}
?>