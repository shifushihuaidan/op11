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
	<center><h1>��ӭ�����Ӱͼ���</h1></center>
</div>
<div class="left">
	<ul>
		<li><a href="duzhe.php?cc=��ҳ">��ҳ</a></li>
		<li><a href="duzhe.php?cc=����">���ȫ��</a></li>
		<li><a href="duzhe.php?cc=����">����</a></li>
		<li><a href="duzhe.php?cc=����">������</a></li>
		<li><a href="duzhe.php?cc=ע��">ע��</a></li>
	</ul>
</div>
<div class="coment">
	<?php
		switch($_GET['cc'])
		{
			case "��ҳ":include("1.php");break;
			case "����":include("2.php");break;
			case "����":include("3.php");break;
			case "����":include("4.php");break;
			case "ע��":include("5.php");break;
			case "����":include("huanshu.php");break;
			case "����":include("jieshu.php");break;
			default:
				include("1.php");break;
		}
	?>
</div>
<div class="button">
	<center><h3>��ϵͳ�ɻ�ӰЭ������Ա�����</h3></center>
</div>
</div>
</body>
</html>