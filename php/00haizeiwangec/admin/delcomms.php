<?php
header ( "Content-type: text/html; charset=UTF-8" ); 						//�����ļ������ʽ
require("system/system.inc.php");  	
$rd = $_GET['rd'];
$reback = "0";
	$sql = "delete from tb_commo where id = ".$rd;
	$arr = $admindb->ExecSQL($sql,$conn);
	if($arr){
		$reback = "1";
	}
echo $reback;
?>