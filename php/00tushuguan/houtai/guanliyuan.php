<!doctype html>
<?php 
error_reporting(0);
session_start();?>
<html>
<head>
<meta charset="utf-8">
<title>无标题文档</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>

<body>
    <table width="98%" height="487"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td align="center" valign="top">
<?php
include("lianjie.php");
$sql=mysql_query("select * from manager");
$totalNum=mysql_num_rows($sql);
if($totalNum==0){
?>
          <table width="100%" height="30"  border="0" cellpadding="0" cellspacing="0">
            <tr>
              <td height="36" align="center">暂无管理员信息！</td>
            </tr>
          </table>
          <table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td>
      <a href="#" onClick="window.open('guanliyuanAdd.php','','width=292,height=175')">添加管理员信息</a> </td>
  </tr>
</table>
 <?php
}else{
$pagesize=30;
$pagecount=(int)(($totalNum-1)/$pagesize)+1;  
$page_len=7; 
$max_p=$pagecount; 
$pages=$pagecount;  
if(empty($_GET['page'])||$_GET['page']<0){ 
$page=1; 
}else { 
$page=$_GET['page']; 
} 
 ?>
 <table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="84%">&nbsp;      </td>
<td width="16%">
      <a href="#" onClick="window.open('guanliyuanAdd.php','','width=292,height=175')">添加管理员信息</a> </td>	  
  </tr>
</table>  
  <table width="91%"  border="1" cellpadding="0" cellspacing="0" bordercolor="#FFFFFF" bordercolordark="#D2E3E6" bordercolorlight="#FFFFFF">
  <tr align="center" bgcolor="#e3F4F7">
    <td width="26%">管理员名称</td>
    <td width="12%">系统设置</td>
    <td width="12%">读者管理</td>
    <td width="12%">图书档案管理</td>
    <td width="11%">图书借还</td>
    <td width="11%">系统查询</td>
    <td width="8%">权限设置</td>
    <td width="8%">操作</td>
  </tr>
<?php 
$offset=$pagesize*($page-1); 
$sql="select m.id,m.adminname,p.sysset,p.readerset,p.bookset,p.borrowback,p.sysquery from manager as m left join (select * from purview)as p on m.id=p.id limit $offset,$pagesize";
$result=mysql_query($sql); 
while ($info=mysql_fetch_array($result)){ 
?> 
  <tr>
    <td style="padding:5px;"><?php echo $info[adminname];?></td>
    <td align="center"><input name="checkbox" type="checkbox" class="noborder" value="checkbox" disabled="disabled" <?php if($info[sysset]==1){echo ("checked");}?>></td>
    <td align="center"><input name="checkbox" type="checkbox" class="noborder" value="checkbox" disabled="disabled" <?php if($info[readerset]==1){echo("checked");}?>></td>
    <td align="center"><input name="checkbox" type="checkbox" class="noborder" value="checkbox" disabled <?php if($info[bookset]==1){echo("checked");}?>></td>
    <td align="center"><input name="checkbox" type="checkbox" class="noborder" value="checkbox" disabled <?php if($info[borrowback]==1){echo("checked");}?>></td>
    <td align="center"><input name="checkbox" type="checkbox" class="noborder" value="checkbox" disabled <?php if($info[sysquery]==1){echo("checked");}?>></td>
    <td align="center"><a href="#" onClick="window.open('manager_modify.php?id=<?php echo $info[id]; ?>','','width=292,height=175')">权限设置</a></td>
    <td align="center"><a href="guanliyuandelet.php?id=<?php echo $info[id];?>">删除</a></td>
  </tr>
<?php
 }
}
?>  
</table>
</td>
      </tr>
    </table>
</body>
</html>