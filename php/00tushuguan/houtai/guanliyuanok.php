<?php
include("lianjie.php");
if($_POST[submit]!=""){
$name=$_POST[name];
$pwd=$_POST[pwd];
$sql=mysql_query("insert into manager (adminname,password) values('$name','$pwd')");
if($sql==true){
echo "<script language=javascript>alert('����Ա��ӳɹ���');window.close();window.opener.location.reload();</script>";
}
else{
echo "<script language=javascript>alert('����Ա���ʧ�ܣ�".str_replace("'","��",mysql_error())."');window.close();window.opener.location.reload();</script>";
}
}
?>
