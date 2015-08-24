<!doctype html>
<?php 
session_start();
include("checklogin.php");
include("lianjie.php");
if($_GET['action']=='del'){
$info_del=mysql_query("delete from bookinfo where id=$_GET[id]");
$info_del1=mysql_query("delete from borrow where bookid=$_GET[id]");
  if($info_del){
    echo "<script language='javascript'>alert('图书信息删除成功!');history.back();</script> ";
    }
}
?>
<html>
<head>
<meta charset="utf-8">
<title>book</title>
</head>	

<body>


<table width="98%"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td align="center" valign="top">
		<?php
		$pagesize=30;
		$query=mysql_query("select * from bookinfo ");
		$totalNum=mysql_num_rows($query); //2.查出总共有多少条信息
		$result=mysql_fetch_array($query);
		$pagecount=(int)(($totalNum-1)/$pagesize)+1;  
        if($result==false){
		?> 
          <table width="100%" height="30"  border="0" cellpadding="0" cellspacing="0">
            <tr>
              <td height="36" align="center">暂无图书信息！</td>
            </tr>
          </table>
          <table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td>
      <a href="index.php?Tswap=Tba">添加图书信息</a> 
  </tr>
</table>
 <?php
}else{
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
 <table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="78%">&nbsp;      </td>
	<td width="22%">
      <a href="index.php?Tswap=Tba">添加图书信息</a></td>	  
  </tr>
</table>  
  <table width="98%"  border="1" cellpadding="0" cellspacing="0" bordercolor="#FFFFFF" bordercolordark="#D2E3E6" bordercolorlight="#FFFFFF">
  <tr align="center" bgcolor="#e3F4F7">  
    <td width="26%">图书名称</td>
    <td width="15%">图书类型</td>
    <td width="14%">出版社</td>
    <td width="12%">书架</td>
    <td width="6%">修改</td>
    <td width="5%">删除</td>
  </tr>
<?php 
$offset=$pagesize*($page-1); 
$sql="select * from bookinfo order by id asc limit $offset,$pagesize"; 
$result=mysql_query($sql); 
while ($row=mysql_fetch_array($result)){ 
?> 
  <tr>  
    <td style="padding:5px;"><a href="book_look.php?id=<?php echo $row[id];?>"><?php echo $row[bookname];?></a></td>
    <td style="padding:5px;">&nbsp;<?php echo $row[booktype];?></td>  
    <td style="padding:5px;">&nbsp;<?php echo $row[publishing];?></td>  
    <td style="padding:5px;">&nbsp;<?php echo $row[bookcase];?></td>  
    <td align="center"><a href="index.php?Tswap=Tbm&id=<?php echo $row[id];?>">修改</a></td>
    <td align="center"><a onClick="javascript:return confirm('确定删除该信息吗？无法恢复！');" href="?action=del&id=<?php echo $row[id];?>">删除</a></td>
  </tr>
<?
        }
?>  
</table>
<?php } ?></td>
      </tr>
    </table>
</body>
</html>