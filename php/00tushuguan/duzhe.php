<html>
<head>
<style type="text/css">
	body
	{
		background-color:281C20;
		background-image:url(./image/6.jpg);
		background-repeat:no-repeat;
		background-attachment:fixed;
		background-position:center;
	}
	.contain
	{
		
		width:1200;
		height:550;
		margin: 0 auto;
		color:red;
	}
	.font
	{
		float:left;
		
		width:1200;
		height:80;
		color:488D72;
	}
	.left
	{
		float:left;
		
		width:160;
		height:400;
	}
	.left ul
	{
		list-style:none;
	}
    .left ul li
	{
	margin:50 0;
	}
	.coment
	{
		float:left;
		border:1 solid blue;
		width:1000;
		height:400;
	}
	.button
	{
		float:left;
		
		width:1200;
		height:70;
	}
	a
	{
		text-decoration:none;
	}
</style>
</head>
<body>
<div class="contain">
<div class="font">
	<center><h1>欢迎进入火影图书馆</h1></center>
</div>
<div class="left">
	<ul>
		<li><a href="duzhe.php?cc=首页">首页</a></li>
		<li><a href="duzhe.php?cc=看书">浏览全书</a></li>
		<li><a href="duzhe.php?cc=找书">找书</a></li>
		<li><a href="duzhe.php?cc=改密">改密码</a></li>
		<li><a href="duzhe.php?cc=注销">注销</a></li>
	</ul>
</div>
<div class="coment">
	<?php
		switch($_GET['cc'])
		{
			case "首页":include("1.php");break;
			case "看书":include("2.php");break;
			case "找书":include("3.php");break;
			case "改密":include("4.php");break;
			case "注销":include("5.php");break;
			case "还书":include("huanshu.php");break;
			case "借书":include("jieshu.php");break;
			default:
				include("1.php");break;
		}
	?>
</div>
<div class="button">
	<center><h3>本系统由火影协会垃圾员工完成</h3></center>
</div>
</div>
</body>
</html>