<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>无标题文档</title>
<?php
include("lianjie.php");
if($_POST[submit]!=""){
$name=$_POST[name];
$pwd=$_POST[pwd];
$sql=mysql_query("insert into manager (name,pwd) values('$name','$pwd')");
if($sql==true){
echo "<script language=javascript>alert('管理员添加成功！');window.close();window.opener.location.reload();</script>";
}
else{
echo "<script language=javascript>alert('管理员添加失败！".str_replace("'","‘",mysql_error())."');window.close();window.opener.location.reload();</script>";
}
}
?>
</head>

<body>
</body>
</html>