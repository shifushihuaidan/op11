<?php
/*
PHP5.2新增的json功能是非常受欢迎的，但是经过测试发现，
json_encode对中文的处理是有问题的：
1、不能处理GB编码，所有的GB编码都会替换成空字符。
2、utf8编码的中文被编码成unicode编码，变成类似\u2353的字串，
相当于javascript的escape函数处理的结果。

json_encode 是对变量进行data编码，
所用的编码为gb2312时 中文无法转换，
所以输出为空；应该先转换编码，在进行输出。
对中文用 urlencode 和 urldecode
*/
$b1= urlencode('路飞'); 
$b2=urlencode('索隆');
$ab=array('c1'=>$b1,'c2'=>$b2);
echo urldecode(json_encode($ab)); 
?>
<!--<html>
<head>
<meta http-equiv="content-type" content="text/html;charset=gbk" />
</head>
<body>
</body>
</html>
-->