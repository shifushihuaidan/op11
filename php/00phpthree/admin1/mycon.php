<?php
$link=mysql_connect('localhost','root','root') or die("���ݿ�����ʧ��Error:".mysql_errno().":".mysql_error());
mysql_set_charset('gbk');
mysql_select_db('tushuguan') or die("ָ�����ݿ��ʧ��");
?>