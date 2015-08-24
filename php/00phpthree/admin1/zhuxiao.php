<?php
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
?>
<?php
session_destroy();
//第一步，销毁session存在服务器端的数据。
//setcookie(session_name(),'',time()-3600);
//第二步，删除客户端的session cookie
$_SESSION=array();
//第三步，销毁全局变量$_SESSION
alertMes("注销成功","index.php");
?>