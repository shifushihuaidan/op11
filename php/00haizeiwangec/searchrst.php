<?php	
require("system/system.inc.php"); 				
if(!empty($_GET['act']) &&  $_GET['act'] == "simple"){
	$cont=iconv("utf-8","utf-8",$_REQUEST['conts']);
	$sql = "select * from tb_commo where name like '%".$cont."%'";
}else if(isset( $_GET['act']) && $_GET['act'] == "high"){
	$name = iconv("utf-8","utf-8",$_GET['name']);
	echo $name;
	$model = iconv("utf-8","utf-8",$_GET['model']);
	$class = iconv("utf-8","utf-8",$_GET['stype']);
	$sql = "select * from tb_commo where name like '%".$name."%' and model like '%".$model."%' and class like '%".$class."%' ";
}

$searcharr = $admindb->ExecSQL($sql,$conn);
if($searcharr){
	$smarty->assign('result',"TRUE");
	$smarty->assign('searcharr',$searcharr);
}else{
	$smarty->assign('result',"FALSE");
}
$smarty->assign('title','²éÑ¯½á¹û');
$smarty->display('searchrst.tpl');
?>
