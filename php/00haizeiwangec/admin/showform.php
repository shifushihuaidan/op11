<?php
header ( "Content-type: text/html; charset=UTF-8" ); 						//设置文件编码格式
require("system/system.inc.php");  						//包含配置文件

if(isset($_GET['page_type']) && isset($_GET['page'])){
	$page=$_GET['page'];
	$page_type=$_GET['page_type'];

}else{
	$page_type="";
	$page=1;
}
$sql = $seppage->ShowData("select id,formid,vendee,taker,total,pay_method,del_method,state from tb_form",$conn,10,$page);	
$smarty->assign("formarr",$sql);
$smarty->assign('rst1_page',$seppage->ShowPage("产品","个",$page_type,'',"a"));
$smarty->assign('title','查看订单');
$smarty->display('showform.tpl');
?>