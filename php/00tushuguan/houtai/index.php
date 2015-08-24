<!doctype html>
<html>
<head>
<?php
	error_reporting(0);
	session_cache_limiter( "private, must-revalidate" );
  	session_start();
	include("checklogin.php");
?>
<link rel="stylesheet" type="text/css" href="css/style.css">
<style>
.bodys{
	background-color:#4C94C1;
}

.mid{
	height:115px;
	width:776px;
	background-image:url(Images/hander.gif);
	position:relative;
	margin:0 auto;
}
.nihao{
	font-family:"华文新魏";
	position: absolute;
	right:0;
	bottom:0;
}
.menu {
font-family: arial, sans-serif; 
width:776px; 
margin:0 auto;
align
}
.menu ul {
padding:0; 
margin:0;
list-style-type: none;
}

.menu ul li {
float:left; 
position:relative;
}
.menu ul li a, .menu ul li a:visited {
display:block; 
text-align:center; 
text-decoration:none; 
width:100px; 
height:30px; 
color:#000; 
border:1px solid #fff;
border-width:1px 1px 0 0;
background:#4C94C1; 
line-height:30px; 
font-size:11px;
}

.menu ul li ul {
display: none;
}

.menu ul li:hover a {
color:#fff; 
background:#b3ab79;
}

.menu ul li:hover ul {
display:block; 
position:absolute; 
top:31px; 
left:0; 
width:105px;
}

.menu ul li:hover ul li a {
display:block; 
background:#faeec7; 
color:#000;
}

.menu ul li:hover ul li a:hover {
background:#dfc184; 
color:#000;
}
.data{
	width:169px;
	height:30px;
	background:#72AACC;
	font-family: arial, sans-serif;
	text-align:center;
	border:1px solid #fff;
	border-width:1px 1px 0 0;
}
.chuban{
	float:none;
	text-align:center;
	font-family: arial, sans-serif;
	font-size:16px;
    color:#FFFFFF;
}
.bandan{
	width:776px; 
	margin-left:300px;
	clear:both
}
.clear{ clear:both}
</style>

<meta charset="utf-8">
<title>index</title>


</head>

<body class="bodys">
		<div class="mid">
    	<div class="nihao">你好！用户：<?php echo $_SESSION['user_username']; ?></div>
        </div>

<div class="menu">
<ul>
<li class="data"><?php $time=date('Y年m月d日 H:i:s',time());echo $time;?></li>
<li><a class="hide" href="index.php">首页</a></li>
<li><a class="hide" href="#">系统设置</a>

    <ul>
    <li><a href="index.php?Tswap=Tlm" >图书馆信息</a></li>
    <li><a href="index.php?Tswap=Tguan" >管理员设置</a></li>
    <li><a href="index.php?Tswap=Tcs" >参数设置</a></li>
    <li><a href="index.php?Tswap=Tsj" >书架设置</a></li>
    </ul>
</li>
<li><a class="hide" href="#">读者管理</a>

    <ul>
    <li><a href="index.php?Tswap=Tr" >读者档案信息</a></li>
    <li><a href="index.php?Tswap=Tra" >添加读者</a></li>
    <li><a href="index.php?Tswap=Trm" >读者信息修改</a></li>
    </ul>
</li>
<li><a class="hide" href="#">图书管理</a>

    <ul>
    <li><a href="index.php?Tswap=Tb" >图书档案管理</a></li>
    <li><a href="index.php?Tswap=Tbm" >图书信息修改</a></li>
    <li><a href="index.php?Tswap=Tba" >添加图书</a></li>
    </ul>
</li>
<li><a class="hide" href="index.php?Tswap=Tg">更改口令</a></li>
<li><a class="hide" href="index.php?Tswap=Tz">注销</a></li>
</ul>
</div>
<div class="clear"></div>
<table width="776" border="0" align="center" cellpadding="0" cellspacing="0" class="tableBorder">
	<td>
	<table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td valign="top" bgcolor="#FFFFFF"><table width="99%" height="510"  border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF" class="tableBorder_gray">
  <tr>
    <td height="510" valign="top" style="padding:5px;">
<?php
@$Tswap=$_GET['Tswap']; 
switch($Tswap){
	case "Tcs": include"canshu.php";
	break;
	case "Tsj": include"bookj.php";
	break;
	case "Tra": include"readeradd.php";
	break;
	case "Trm": include"readerm.php";
	break;
	case "Tr": include"reader.php";
	break;
	case "Tba": include"bookadd.php";
	break;
	case "Tbm": include"bookm.php";
	break;
	case "Tb": include"book.php";
	break;
	case "TguanAdd": include"guanliyuanAdd.php";
	break;
	case "Tguan": include"guanliyuan.php";
	break;
	case "Tlm": include"librarym.php";
	break;
	case "Tg": include"kouling.php";
	break;
	case "Tz": include "zhuxiao.php";
	break;
	default :include "paiming.php";
	break;
}
?>

</td>
  </tr>
</table></td>
  </tr>
</table>
</td>
  </tr>
</table>

<div class="chuban">copyright 2007 www.mrbook 吉林***师范大学图书馆</div>
       

</body>
</html>