<?php
session_start();
?>
<?php 
/**
 * 连接数据库
 * @return resource
 */
   function alertMes($mes,$url)
	{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
    }
	$link=mysql_connect('localhost','root','0794444944') or die("数据库连接失败Error:".mysql_errno().":".mysql_error());
	mysql_set_charset('gbk');
	mysql_select_db('opliao') or die("指定数据库打开失败");
    //$mima=md5($_POST['mima']);
    $mima=$_POST['mima'];
	$nam=$_POST['name1'];
	$sql="insert into yonghu(name,mima) values ('".$nam."','".$mima."');";
    $res=mysql_query($sql);
    if($res)
	{
        $_SESSION['name1']=$nam;
        alertMes("注册成功","./liaotian.php");
	}
?>

