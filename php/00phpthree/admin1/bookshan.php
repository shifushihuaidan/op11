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
	alertMes("É¾³ýÊé¼®³Â¹¬","index1?aa=Í¼µµ¹ÜÀí");
}
else
{
	alertMes("É¾³ýÊé¼®Ê§°Ü","index1?aa=Í¼µµ¹ÜÀí");
}
?>