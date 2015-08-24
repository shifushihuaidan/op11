<?php
session_start();
?>
<html>
<head>
<link rel="stylesheet" type="text/css" href="./admin1/c1.css">
<script src="./admin1/j1.js" type="text/javascript"></script>
<style type="text/css">
    .b0
	{
		width:777;
		height:100%;
		margin:0 auto;
	}
	.b1
	{
		width:776;
		height:115;
		background:url(./admin1/images/banner.gif);
	}
	.b2
	{
		width:776;
		height:40;
		/*border:1px solid red;*/
	}
	.b3
	{
		width:776;
		height:370;
		border:1px solid green;
		background-color:FFFFFF;
	}
	.b4
	{
		width:776;
		height:50;
		/*border:1px solid blue;*/
	}
	body
	{
		background-color:281C20;
		background-image:url(./image/3.jpg);
		background-repeat:no-repeat;
		background-attachment:fixed;
		background-position:center;
	}
</style>
</head>
<body bgcolor="4C94C1" onload="st()">
<div class="b0">
<div class="b1">
</div>
<div class="b2">
<label>
当前用户:<?php echo $_SESSION['name2']?></label>
<label id="b5">
</label>
<ul id="a1">
    <li><a href="index2?aa=首页">首页</a></li>
	<li><a href="index2?aa=浏览">浏览图书</a> </li>
	<li><a href="index2?aa=找书">查找图书</a> </li>
	<li><a href="index2?aa=口令">更改口令</a> </li>
	<li><a href="index2?aa=注销">注销</a> </li>
</ul>
</div>
<div class="b3">
<?php
		switch($_GET['aa'])
		{
			case "首页":include("yijieshu.php");break;
			case "浏览":include("liulan.php");break;
			case "找书":include("zhaoshu.php");break;
			case "口令":include("gaimi.php");break;
			case "注销":include("zhuxiao.php");break;
			case "还书":include("huanshu.php");break;
			case "借书":include("jieshu.php");break;
			case "找书书":include("zhaoshu1.php");break;
			default:
				include("yijieshu.php");break;
		}
		//include("xx.php");
?>
</div>
<div class="b4">
<center><font size="2" color="282828">
本系统由海贼王编写</font></center>
<center><font size="2" color="282828">
1240610927白一泽</font></center>
</div>	
</div>
</body>
</html>