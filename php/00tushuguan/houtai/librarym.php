<!doctype html>

<?php  
error_reporting(0); 
session_start();
include("lianjie.php");
if($_POST[Submit]!=""){
$libraryname=$_POST[libraryname];
$curator=$_POST[curator];
$tel=$_POST[tel];
$address=$_POST[address];
$email=$_POST[email];
$url=$_POST[url];
$createDate=$_POST[createDate];
$introduce=$_POST[introduce];
$bbs=$_POST[bbs];
$query=mysql_query("update library set libraryname='$libraryname',curator='$curator',tel='$tel',address='$address',email='$email',url='$url',createDate='$createDate',introduce='$introduce',bbs='$bbs'");
if($query==true){
	echo "<script language=javascript>alert('图书馆信息修改成功！');history.back();</script>";
}else{
	echo "<script language=javascript>alert('图书馆信息修改失败！');history.back();</script>";
}
}
?>
<html>
<head>
<meta charset="utf-8">
<title>无标题文档</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
<script language="javascript">
function checkForm(form){
	for(i=0;i<form.length;i++){
		if(form.elements[i].value==""){
			alert("请将图书馆信息填写完整!");
			form.elements[i].focus();
			return false;
		}
	}
}
</script>
</head>

<body>
	<table width="776" border="0" align="center" cellpadding="0" cellspacing="0" class="tableBorder">
	<td>
	<table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td valign="top" bgcolor="#FFFFFF"><table width="99%" height="510"  border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF" class="tableBorder_gray">
  <tr>
    <td height="510" valign="top" style="padding:5px;"><table width="98%" height="487"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td align="center" valign="top">
 <table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="84%">&nbsp;      </td>
</tr>
</table>  <form name="form1" method="post" action="">
<?php 
$sql=mysql_query("select * from library");
$info=mysql_fetch_array($sql);
?>
  <table width="58%"  border="0" cellpadding="0" cellspacing="0" bordercolor="#FFFFFF" bordercolordark="#D2E3E6" bordercolorlight="#FFFFFF">
  <tr align="center">
    <td width="20%" align="left" style="padding:5px;"> 图书馆名称： </td>
    <td width="80%" align="left">
      <input name="libraryname" type="text" id="libraryname" value="<?php echo $info[libraryname];?>" size="30">
    
    </td>
    <tr>
    <td align="left" style="padding:5px;"> 馆长： </td>
    <td align="left"><input name="curator" type="text" id="curator" size="30" value="<?php echo $info[curator];?>" ></td>
    </tr>
    <tr>
      <td align="left" style="padding:5px;"> 联系电话： </td>
      <td align="left"><input name="tel" type="text" id="tel" size="30" value="<?php echo $info[tel];?>"></td>
    </tr>
    <tr>
      <td align="left" style="padding:5px;"> 联系地址： </td>
      <td align="left"><input name="address" type="text" id="address" size="30" value="<?php echo $info[address];?>"></td>
    </tr>
    <tr>
      <td align="left" style="padding:5px;"> E-mail： </td>
      <td align="left"><input name="email" type="text" id="email" size="30" value="<?php echo $info[email];?>"></td>
    </tr>
    <tr>
      <td align="left" style="padding:5px;"> 图书馆网址： </td>
      <td align="left"><input name="url" type="text" id="url" size="30" value="<?php echo $info[url];?>"></td>
    </tr>
    <tr>
      <td align="left" style="padding:5px;"> 建馆时间： </td>
      <td align="left"><input name="createDate" type="text" id="createDate" size="30" value="<?php echo $info[createDate];?>"></td>
    </tr>
    <tr>
      <td height="84" align="left" style="padding:5px;"> 图书馆简介： </td>
      <td align="left"><textarea name="introduce" cols="50" rows="5" class="wenbenkuang" id="introduce"><?php echo $info[introduce];?></textarea></td>
    </tr>
    <tr>
      <td height="65" align="left" style="padding:5px;">公告：</td>
      <td><textarea name="bbs" cols="50" rows="5" class="wenbenkuang" id="bbs"><?php echo $info[bbs];?></textarea></td>
    </tr>
    <tr>
      <td height="65" align="left" style="padding:5px;">&nbsp;</td>
      <td>        &nbsp;
          <input name="Submit" type="submit" class="btn_grey" id="Submit" value="保存" onClick="return checkForm(form1)">
          <input name="Submit2" type="reset" class="btn_grey" id="Submit2" value="取消"></td></tr>
</table>
</form></td>
      </tr>
    </table>
</td>
  </tr>
</table></td>
  </tr>
</table>
</td>
  </tr>
</table>
</body>
</html>