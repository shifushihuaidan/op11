<?php
function alerts($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
$id=$_GET['id'];
$ti= date('Y-m-d',time());
$sql="insert into bbook(bid,rid,jieshutime) values(".$id.",32,'".$ti."')";
$res=mysql_query($sql);
//echo $sql;
alerts("½èÊé³É¹¦","duzhe.php?cc=ä¯ÀÀ");
?>