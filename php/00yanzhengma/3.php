<?php
Header("Content-type: image/gif");
$im = imagecreatetruecolor(100, 40);
$black = ImageColorAllocate($im, 0,0,0);
$white = ImageColorAllocate($im, 255,255,255);
ImageTTFText($im, 20, 0, 10, 20, $white, "/somewhere/arial.ttf", "I am NUMBER ONE !!");
ImageGif($im);
ImageDestroy($im);
?>