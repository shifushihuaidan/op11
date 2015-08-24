<?php

$img = imagecreatetruecolor(100, 40);


$black = imagecolorallocate($img, 0x00, 0x00, 0x00);


$green = imagecolorallocate($img, 0x00, 0xFF, 0x00);


$red = imagecolorallocate($img, 0xFF, 0x00, 0x00);


$white = imagecolorallocate($img, 0xFF, 0xFF, 0xFF);


imagefill($img,0,0,$white);

//生成随机的验证码

$code = '';

$a=join("",array_merge(range(0,9),range("A","Z"),range("a","z")));

$b=str_shuffle($a);

$c=substr($b,0,4);

$fos=array("aaa.ttf","bb.ttf","cc.ttf","dd.ttf","ee.ttf","ff.ttf","gg.ttf","hh.TTF");
for($i=0;$i<4;$i++)
{
$size=mt_rand(12,18);
$an=mt_rand(-17,17);
$x=mt_rand(10,66);//5+$i*$size;
$y=mt_rand(20,36);
$fo="./ziti/".$fos[mt_rand(0,count($fos)-1)];
//$fo="./ziti/".$fos[1];
$co=imagecolorallocate($img, mt_rand(50,90), mt_rand(80,200), mt_rand(90,180));
$text=substr($c,$i,1);
imagettftext($img,$size,$an,$x,$y,$co,$fo,$text);
}
/*$fos=array("aaa.ttf","bb.ttf","cc.ttf","dd.ttf","ee.ttf","ff.ttf","gg.ttf","hh.TTF");
$size=mt_rand(12,18);
$an=mt_rand(-15,15);
$x=5+$i*$size;
$y=mt_rand(20,26);
//$fo="./ziti/".$fos[mt_rand(0,count($fos)-1)];
$fo="./ziti/".$fos[1];
$co=imagecolorallocate($img, mt_rand(50,90), mt_rand(80,200), mt_rand(90,180));
imagettftext($img,$size,$an,$x,$y,$co,$fo,$c);*/


//加入横线干扰
/*
$aa=rand(20,29);

for($j=0;$j<$aa;$j++)

{

imageline($img,rand(0,100),rand(0,100),rand(0,100),rand(0,100),$red);

}*/

//加入噪点干扰

for($ia=0;$ia<500;$ia++) 
{
  
imagesetpixel($img, rand(0, 100) , rand(0, 100) , $black);
 
  imagesetpixel($img, rand(0, 100) , rand(0, 100) , $green);

}
//输出验证码

header("content-type: image/png");

imagepng($img);

imagedestroy($img);
/*header ( "content-type:image/gif" );
imagegif ( $img );
imagedestroy ( $img );*/
?>