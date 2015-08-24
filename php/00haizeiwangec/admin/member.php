<?php
header ( "Content-type: text/html; charset=UTF-8" ); 						//设置文件编码格式
require("system/system.inc.php");  						//包含配置文件
if(isset($_GET['page'])){
	$page=$_GET['page'];
}else{
	$page=1;
}
if(isset($_GET['page_type'])){
	$page_type=$_GET['page_type'];
}else{
	$page_type="";
}
$sql = $seppage->ShowData("select id,name,isfreeze from tb_user",$conn,10,$page);	
$smarty->assign("memarr",$sql);
$smarty->assign('rst1_page',$seppage->ShowPage("产品","个",$page_type,'',"a"));
$smarty->assign('title','会员管理');
$smarty->display('member.tpl');
?>