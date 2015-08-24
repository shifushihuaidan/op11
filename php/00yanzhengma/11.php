<?php


function yanzhengma()
{
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


/*for($i = 0; $i < 4; $i++) 
{
 
   $code .= rand(0, 9);
}*/


//$c="";
/*for($j=0;$j<4;$j++)
{
    $c.=substr($b,$j,1);
  
  /*imagestring($img, rand(5,50), rand(10,60), rand(10,40), $c, $black);


}*/

imagestring($img, 5, rand(2,30), rand(0,40), $c, $black);

//imagestring($img, rand(5,30), 10, 10, $c, $black);

$aa=rand(20,29);

for($j=0;$j<$aa;$j++)

{

imageline($img,rand(0,100),rand(0,100),rand(0,100),rand(0,100),$red);


}

//加入噪点干扰

for($i=0;$i<500;$i++) 
{
  
imagesetpixel($img, rand(0, 100) , rand(0, 100) , $black);
 
  imagesetpixel($img, rand(0, 100) , rand(0, 100) , $green);

}

//输出验证码

header("content-type: image/png");


imagepng($img);
imagedestroy($img);
}

?>