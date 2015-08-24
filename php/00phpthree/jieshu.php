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
?>
<?php 
$s1=$_GET['id'];
//echo $s1."<br/>";
$s2=$_GET['shuliang'];
//echo $s2;
if($s2>0)
{
	
		$rid="(select rid from reader where rname='".$_SESSION['name2']."')";
		$res4=mysql_query($rid);
		$row= mysql_fetch_assoc($res4);
		$ri=$row['rid'];
		$sql="select * from reader where rid='".$ri."'";
		$res=mysql_query($sql);
		$row= mysql_fetch_assoc($res);
		$jsl=$row['jieshuliang'];
		$rtype=$row['rtype'];
		//echo $rtype;
		$sql2="select * from dutype where rtype='".$rtype."'";
		$res2=mysql_query($sql2);
		$row2= mysql_fetch_assoc($res2);
		$ksl=$row2['rshuliang'];
		//echo "可借数量".$ksl;
		if($jsl<$ksl)
		{
			$sql3="update book set shuliang=shuliang-1
			where bid='".$s1."'";
			$res3=mysql_query($sql3);
			$sql5="update reader set jieshuliang=jieshuliang+1
			where rid='".$ri."'";
			$res5=mysql_query($sql5);
			$time2= date('Y-m-d',time());
			$sql6="insert into bbook(bid,rid,jssj) values('"
			.$s1."','".$ri."','".$time2."')";
			//echo $sql6;
			$res6=mysql_query($sql6);
			alertMes("借书成功","index2.php?aa=浏览");
		}
		else
		{
			alertMes("抱歉你没有资格在借书了","index2.php?aa=浏览");
		}
}
else
{
	alertMes("抱歉该书数量不足","index2.php?aa=浏览");
}
?>