<?php 
	error_reporting(0);	
	mysql_pconnect('localhost','root','root')or die("连接数据库失败！！");
	mysql_select_db('the_library')or die ("不能连接到library".mysql_error());
	mysql_query("set names utf8");

?>