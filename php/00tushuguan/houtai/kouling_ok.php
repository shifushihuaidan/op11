<!doctype html>
<html>
<head>
<meta charset="utf-8">
<?php error_reporting(0);
session_start();
$newpwd=$_POST[pwd];
include("lianjie.php");
$sql=mysql_query("update manager set password='$newpwd' where adminname='$_SESSION[user_username]'");?>
<script language="javascript">alert("口令更改成功!");window.location.href="index.php?Tswap=Tg";</script>	

</head>
</html>