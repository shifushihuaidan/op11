<?php
$link=mysql_connect('localhost','root','root') or die("数据库连接失败Error:".mysql_errno().":".mysql_error());
mysql_set_charset('gbk');
mysql_select_db('tushuguan') or die("指定数据库打开失败");
?>