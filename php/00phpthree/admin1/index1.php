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
��ǰ�û�:<?php echo $_SESSION['name1']?></label>
<label id="b5">
</label>
<ul id="a1">
    <li><a href="index1?aa=��ҳ">��ҳ</a></li>
	<li><a href="#" onmouseover="open1('a2')"
	onmouseout="closetime()"
	>ϵͳ����</a>
	<div id="a2" onmouseover="clodetime()"
	onmouseout="closetime()"
	>
		<a href="index1?aa=ͼ�޸�">ͼ����Ϣ�޸�</a>
		<a href="index1?aa=������">����ԱȨ������</a>
		<a href="index1?aa=������">��������</a>
		<a href="index1?aa=������">�������</a>
	</div>
	</li>
	<li><a href="#" onmouseover="open1('a3')"
	onmouseout="closetime()">���߹���</a>
	<div id="a3" onmouseover="clodetime()"
	onmouseout="closetime()"
	>
		<a href="index1?aa=�͹���">�������͹���</a>
		<a href="index1?aa=��������">���ߵ�������</a>
	</div>
   </li>
	<li><a href="index1?aa=ͼ������">ͼ�鵵������</a> </li>
	<li><a href="index1?aa=����">���Ŀ���</a> </li>
	<li><a href="index1?aa=ע��">ע��</a> </li>
</ul>
</div>
<div class="b3">
<?php
		switch($_GET['aa'])
		{
			case "��ҳ": include("tushu.php");break;
			case "ͼ�޸�": include("tushuguanxiugai.php");break;
			case "������": include("quanxian.php");break;
			case "������": include("canshu.php");break;
            case "������": include("shujia.php");break;
			case "�͹���": include("readertype.php");break;
			case "��������":include("reader.php");break;
			case "ͼ������":include("book.php");break;
			case "����":include("gaimima.php");break;
			case "ע��":include("zhuxiao.php");break;
			case "���":include("readeradd.php");break;
			case "�޶�":include("readergai.php");break;
			case "ɾ��":include("readershan.php");break;
			case "����":include("bookadd.php");break;
			case "����":include("bookgai.php");break;
			case "ɾ��":include("bookshan.php");break;
			case "����":include("gaimima.php");break;
			default:
				include("tushu.php");
		}
		//include("xx.php");
?>
</div>
<div class="b4">
<center><font size="2" color="blue">
��ϵͳ�ɺ�������д</font></center>
<center><font size="2" color="blue">
1240610927��һ��</font></center>
</div>	
</div>
</body>
</html>