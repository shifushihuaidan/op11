<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>bookjia</title>
<link rel="stylesheet" type="text/css" href="css/style.css">

<?php  
error_reporting(0);
include("lianjie.php");  
if($_GET[action]=="del"){
$id=$_GET[id];
$sql=mysql_query("delete from bookcase where id='$id'");
if($sql==ture){
	echo "<script language='javascript'>alert('成功删除书架名称！');history.go(-1);</script>";
}else{
	echo "<script language='javascript'>alert('书架删除操作失败！.{$sql}.');history.go(-1);</script>";
}
}?>

</head>

<body>
<table width="98%" height="487"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td align="center" valign="top">
<?php
include("lianjie.php");       //连接数据源信息
$sql=mysql_query("select * from bookcase order by id desc");      //查询图书书架信息表中的数据信息
$info=mysql_fetch_array($sql);      //执行SQL语句
$totalnum=mysql_num_rows($sql);
if($info==false){      //如果图书书架信息表中为空值，则弹出“暂无书架信息”
?>
          <table width="100%" height="30"  border="0" cellpadding="0" cellspacing="0">
            <tr>
              <td height="36" align="center">暂无书架信息！</td>
            </tr>
          </table>
          <table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td>
      <a href="#" onClick="window.open('bookjadd.php','','width=292,height=175')">添加书架信息</a> </td>
  </tr>
</table>
 <?
}else{   //否则输出书架信息
$pagesize=10;
$pagecount=(int)(($totalnum-1)/$pagesize)+1;  
$page_len=7; 
$max_p=$pagecount; 
$pages=$pagecount; 
//判断当前页码 
if(empty($_GET['page'])||$_GET['page']<0){ 
$page=1; 
}else { 
$page=$_GET['page']; 
} 
  ?>
 <table width="91%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="84%">&nbsp;      </td>
<td width="16%" align="right">
      <a href="#" onClick="window.open('bookjadd.php','','width=292,height=175')">添加书架信息&nbsp;</a> </td>	  
  </tr>
</table>  
  <table width="91%"  border="1" cellpadding="0" cellspacing="0" bordercolor="#FFFFFF" bordercolordark="#D2E3E6" bordercolorlight="#FFFFFF">
  <tr align="center" bgcolor="#e3F4F7">
    <td width="84%">书架名称</td>
    <td width="8%">编辑</td>
    <td width="8%">删除</td>
  </tr>
<?php 
$offset=$pagesize*($page-1); 
$sql="select * from  bookcase order by id desc limit $offset,$pagesize";
$result=mysql_query($sql); 
while ($info=mysql_fetch_array($result)){ 
?> 
  <tr>
    <td style="padding:5px;"><?php echo $info[name];?></td>
    <td align="center"><a  style="cursor:hand " onClick="window.open('bookcase_edit.php?id=<?php echo $info[id]; ?>','','width=292,height=175')">编辑</a></td>
    <td align="center"><a href="index.php?Tswap=Tsj&action=del&id=<?php echo $info[id];?>">删除</a></td>
  </tr>
<?
}
}
?>  
</table>
</td>
      </tr>
    </table>


</body>
</html>