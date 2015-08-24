<!doctype html>

<?php  
error_reporting(0);
session_start();
include("checklogin.php");
include("lianjie.php");
if($_GET[action]=="del"){
$id=$_GET[id];
$sql=mysql_query("delete from reader where id='$id'");
$sql1=mysql_query("delete from borrow where readerid='$id'");
if($sql){
echo "<script language=javascript>alert('读者信息删除成功！');window.location.href='reader.php';</script>";
}
else{
echo "<script language=javascript>alert('读者信息删除失败！');window.location.href='reader.php';</script>";
}
}?>
<html>
<head>
<meta charset="utf-8">
<link rel="stylesheet" type="text/css" href="css/style.css">
<title>reader</title>
</head>

<body>
<table width="98%" height="487"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td align="center" valign="top">
<?php 
include("lianjie.php");
$sql=mysql_query("select * from reader");
$info=mysql_fetch_array($sql);
$totalnum=mysql_num_rows($sql);
if($info==false){
?> <table width="100%" height="30"  border="0" cellpadding="0" cellspacing="0">
            <tr>
              <td height="36" align="center">暂无读者信息！</td>
            </tr>
          </table>
          <table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td>
      <a href="readeradd.php">添加读者信息</a> </td>
  </tr>
</table>
 <?php 
}else{
$pagesize=30;
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
  ?> <table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="87%">&nbsp;      </td>
<td width="13%">
      <a href="readeradd.php">添加读者信息</a></td>	  
  </tr>
</table>  
  <table width="96%"  border="1" cellpadding="0" cellspacing="0" bordercolor="#FFFFFF" bordercolordark="#D2E3E6" bordercolorlight="#FFFFFF">
  <tr align="center" bgcolor="#e3F4F7">
    <td width="10%">姓名</td>
    <td width="8%">读者类型</td>
    <td width="10%">证件类型</td>
    <td width="18%">证件号码</td>
    <td width="15%">电话</td>
    <td width="15%">E-mail</td>
    <td colspan="2">操作</td>
  </tr>
<?php 
$offset=$pagesize*($page-1); 
$sql="select * from reader order by id asc limit $offset,$pagesize";
$result=mysql_query($sql); 
while ($info=mysql_fetch_array($result)){ 
?>  <tr>  
    <td style="padding:5px;"><a href="reader_info.php?id=<?php echo $info[id]; ?> "><?php echo $info[name];?> </a></td>
    <td style="padding:5px;"><?php echo $info[booktype];?> </td>
    <td align="center"><?php echo $info[paperType];?> </td>
    <td align="center"><?php echo $info[paperNO];?> </td>
    <td>&nbsp;<?php echo $info[tel];?> </td>
    <td align="left">&nbsp;<?php echo $info[email];?> </td>
    <td width="6%" align="center"><a href="readerm.php?id=<?php echo $info[id];?>">修改</a></td>
    <td width="5%" align="center"><a href="?action=del&id=<?php echo $info[id];?> ">删除</a></td>
  </tr>
<?php 
  }
}
?> </table>
  </td>
      </tr>
    </table>

</body>
</html>