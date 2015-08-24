<?php
	include_once("system/system.inc.php");
	$sql = "select name,url from tb_links order by id";
	$arr = $admindb->ExecSQL($sql,$conn);
	$smarty->assign('linarr',$arr);
?>