<?php
header ( "Content-type: text/html; charset=UTF-8" ); 						//设置文件编码格式
require("system/system.inc.php");  						//包含配置文件
$reback = '0';
$wurl = $_GET['wurl'];
$id = (int)$_GET['id'];

$names = iconv("gbk","utf-8",$_GET['names']);

$sql = "update tb_links set name='$names',url='$wurl' where id = '$id'";

$rst = $admindb->ExecSQL($sql,$conn);
if($rst){
	$reback = '1';
}else{
	$reback = '2';
}
echo $reback;
?>