<?php
session_start();
?> 
<?php 
/**
 * �������ݿ�
 * @return resource
 */
   function alertMes($mes,$url)
	{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
    }
	$link=mysql_connect('localhost','root','0794444944') or die("���ݿ�����ʧ��Error:".mysql_errno().":".mysql_error());
	mysql_set_charset('gbk');
	mysql_select_db('opliao') or die("ָ�����ݿ��ʧ��");
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
        alertMes("��½�ɹ�","./liaotian.php");
		}
		else
		{
        alertMes("��½ʧ��","./denglu.php");
		}
	}
?>