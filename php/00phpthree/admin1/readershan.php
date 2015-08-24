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
	alertMes("É¾³ý¶ÁÕß³Â¹¬","index1?aa=¶Áµµ¹ÜÀí");
}
else
{
	alertMes("É¾³ý¶ÁÕßÊ§°Ü","index1?aa=¶Áµµ¹ÜÀí");
}
?>