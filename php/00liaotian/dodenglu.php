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
	$sql="select name,mima from yonghu where name='".$nam."';";
	$res=mysql_query($sql);
	if($res&&mysql_num_rows($res))
	{    
		$j1=0;
		$ca=mysql_fetch_assoc($res);
        for($i=0;$i<count($ca);$i++)
		{
			if($ca[name]==$nam&&$ca[mima]==$mima)
				{
				  $j1=1;
                  break;
				}
		    else
			{
				$j1=0;
			}
		}
		if($j1==1)
		{
        $_SESSION['name1']=$nam;
        alertMes("登陆成功","./liaotian.php");
		}
		else
		{
        alertMes("登陆失败","./denglu.php");
		}
	}
?>