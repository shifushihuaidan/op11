<?php
//$s1=urlencode($_GET['name']);
//$s2=urlencode($_GET['mima']);
//$s1=urlencode("海贼");
//$s2=urlencode("你好");
$s1=$_POST['name'];
$s2=$_POST['mima'];
$ab=array('c1'=>$s1,'c2'=>$s2,'c3'=>'数量','c4'=>12345);
echo json_encode($ab); 
//echo "传过来的name是".$s;
?>
