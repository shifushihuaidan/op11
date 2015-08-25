<?php
include("smarty_inc.php");
$smt->assign("name","海贼王");
$a[]=array("name"=>"路飞","says"=>"船长");
$a[]=array("name"=>"索隆","says"=>"二船员");
$a[]=array("name"=>"香吉士","says"=>"厨师");
$a[]=array("name"=>"娜美","says"=>"航海士");
$smt->assign("aa",$a);
$vl="my name is op 123";
$smt->assign("na1",$vl);
$smt->display("1.html");
?>