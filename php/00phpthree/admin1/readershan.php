<?php
include("mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
?>
<?php 
$sql="delete from reader where rid='"
.$_GET['id']."'";
$res=mysql_query($sql);
if($res)
{
	alertMes("ɾ�����߳¹�","index1?aa=��������");
}
else
{
	alertMes("ɾ������ʧ��","index1?aa=��������");
}
?>