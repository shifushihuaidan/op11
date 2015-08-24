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
$sql = $seppage->ShowData("select id,name,brand,area,model,stocks,sell,addtime from tb_commo order by sell",$conn,10,$page);	
$smarty->assign("commoarr",$sql);
$smarty->assign('rst1_page',$seppage->ShowPage("产品","个",$page_type,'',"a"));
$smarty->assign('title','查看商品');
$smarty->display('showcommo.tpl');
?>