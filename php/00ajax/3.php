<?php
/*
PHP5.2������json�����Ƿǳ��ܻ�ӭ�ģ����Ǿ������Է��֣�
json_encode�����ĵĴ�����������ģ�
1�����ܴ���GB���룬���е�GB���붼���滻�ɿ��ַ���
2��utf8��������ı������unicode���룬�������\u2353���ִ���
�൱��javascript��escape��������Ľ����

json_encode �ǶԱ�������data���룬
���õı���Ϊgb2312ʱ �����޷�ת����
�������Ϊ�գ�Ӧ����ת�����룬�ڽ��������
�������� urlencode �� urldecode
*/
$b1= urlencode('·��'); 
$b2=urlencode('��¡');
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