<?php
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
?>
<?php
session_destroy();
//��һ��������session���ڷ������˵����ݡ�
//setcookie(session_name(),'',time()-3600);
//�ڶ�����ɾ���ͻ��˵�session cookie
$_SESSION=array();
//������������ȫ�ֱ���$_SESSION
alertMes("ע���ɹ�","index.php");
?>