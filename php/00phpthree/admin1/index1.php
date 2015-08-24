<?php
session_start();
?>
<html>
<head>
<link rel="stylesheet" type="text/css" href="./c1.css">
<script src="./j1.js" type="text/javascript"></script>
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
		background:url(./images/banner.gif);
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
		/*border:1px solid green;*/
		background-color:FFFFFF;
	}
	.b4
	{
		width:776;
		height:50;
		/*border:1px solid blue;*/
	}
</style>
</head>
<body bgcolor="4C94C1" onload="st()">
<div class="b0">
<div class="b1">
</div>
<div class="b2">
<label>
当前用户:<?php echo $_SESSION['name1']?></label>
<label id="b5">
</label>
<ul id="a1">
    <li><a href="index1?aa=首页">首页</a></li>
	<li><a href="#" onmouseover="open1('a2')"
	onmouseout="closetime()"
	>系统设置</a>
	<div id="a2" onmouseover="clodetime()"
	onmouseout="closetime()"
	>
		<a href="index1?aa=图修改">图书信息修改</a>
		<a href="index1?aa=管设置">管理员权限设置</a>
		<a href="index1?aa=参设置">参数设置</a>
		<a href="index1?aa=架设置">书架设置</a>
	</div>
	</li>
	<li><a href="#" onmouseover="open1('a3')"
	onmouseout="closetime()">读者管理</a>
	<div id="a3" onmouseover="clodetime()"
	onmouseout="closetime()"
	>
		<a href="index1?aa=型管理">读者类型管理</a>
		<a href="index1?aa=读档管理">读者档案管理</a>
	</div>
   </li>
	<li><a href="index1?aa=图档管理">图书档案管理</a> </li>
	<li><a href="index1?aa=口令">更改口令</a> </li>
	<li><a href="index1?aa=注销">注销</a> </li>
</ul>
</div>
<div class="b3">
<?php
		switch($_GET['aa'])
		{
			case "首页": include("tushu.php");break;
			case "图修改": include("tushuguanxiugai.php");break;
			case "管设置": include("quanxian.php");break;
			case "参设置": include("canshu.php");break;
            case "架设置": include("shujia.php");break;
			case "型管理": include("readertype.php");break;
			case "读档管理":include("reader.php");break;
			case "图档管理":include("book.php");break;
			case "口令":include("gaimima.php");break;
			case "注销":include("zhuxiao.php");break;
			case "添读":include("readeradd.php");break;
			case "修读":include("readergai.php");break;
			case "删读":include("readershan.php");break;
			case "添书":include("bookadd.php");break;
			case "修书":include("bookgai.php");break;
			case "删书":include("bookshan.php");break;
			case "改密":include("gaimima.php");break;
			default:
				include("tushu.php");
		}
		//include("xx.php");
?>
</div>
<div class="b4">
<center><font size="2" color="blue">
本系统由海贼王编写</font></center>
<center><font size="2" color="blue">
1240610927白一泽</font></center>
</div>	
</div>
</body>
</html>