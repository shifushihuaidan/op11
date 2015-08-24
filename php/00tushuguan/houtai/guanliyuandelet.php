<!doctype html>
<html>
<head>
<?php
include("lianjie.php");
$id=$_GET[id];
$sql=mysql_query("delete from manager where id='$id'");
if($sql==true ){
echo "<script language=javascript>alert('管理员删除成功！');history.back();location.href='index.php?Tswap=Tguan';</script>";
}
else{
echo "<script language=javascript>alert('管理员删除失败！".str_replace("'","‘",mysql_error())."');history.back();</script>";
}
?>
<meta charset="utf-8">
<title>delelte</title>
</head>

<body>
</body>
</html>