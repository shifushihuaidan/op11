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
$rid="(select rid from reader where rname='".$_SESSION['name2']."')";
$sql="select * from bbook where  bid='".$s1."' and rid=".$rid;
//echo $sql."<br/>";
$res=mysql_query($sql);
//echo "�����1".$res;
//echo mysql_num_rows($res)."��";
if($res&&mysql_num_rows($res))
{
	$row = mysql_fetch_assoc($res);
	$time1=$row['jssj'];
	$time2= date('Y-m-d',time());
	$days=(strtotime($time2)-strtotime($time1))/86400;
	$res4=mysql_query($rid);
    $row= mysql_fetch_assoc($res4);
	$ri=$row['rid'];
	if($days>30)
	{   
		$s2=2*($days-30);
		$sql2="update bbook set fakuan=".$s2.""
		."where  bid='".$s1."' and rid=".$rid;
		$res2=mysql_query($sql2);
		//echo "�����".$res2;
		if(!$res2)
		{
			$s3="��Ҫ������".$s2."Ԫ,���˷����ٻ�����ȷ��";
			echo "
			<script>alert('$s3');</script>
			";
		}
	}
	$sql3="update book set shuliang=shuliang+1
	where bid='".$s1."'";
	//echo $sql3;
	$res3=mysql_query($sql3);
	//echo $ri;
	$sql5="update reader set jieshuliang=jieshuliang-1
	where rid='".$ri."'";
	//echo $sql5;
	$res5=mysql_query($sql5);
	$sql6="delete from bbook where bid='".$s1."'and 
	rid= '".$ri."'";
	//echo $sql6;
	$res6=mysql_query($sql6);
	alertMes("����ɹ�","index2.php?");	
}
?>