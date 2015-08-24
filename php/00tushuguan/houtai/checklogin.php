
<?php
session_start();
if( $_SESSION['user_username']==""){
	echo "<script>alert('对不起，请通过正确的途径登录图书馆管理系统!');window.location.href='login.php';</script>";
}
?>
