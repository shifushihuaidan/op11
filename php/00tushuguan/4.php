<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>�ޱ����ĵ�</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
<?php 
error_reporting(0);
session_start();?>
<script language="javascript">
function checkForm(form){
	if(form.oldpwd.value==""){
		alert("�������ԭ����!");form.oldpwd.focus();return false;
	}
	if(form.oldpwd.value!=form.holdpwd.value){
		alert("�������ԭ���벻��ȷ������������!");form.oldpwd.value="";
		form.oldpwd.focus();return false;
	}
	if(form.pwd.value==""){
		alert("�������������!");form.pwd.focus();return false;
	}	
	if(form.pwd1.value==""){
		alert("��ȷ��������!");form.pwd1.focus();return false;
	}	
	if(form.pwd.value!=form.pwd1.value){
		alert("����������������벻һ�£�����������!");
		form.pwd.value="";form.pwd1.value="";
		form.pwd.focus();return false;
	}
}
</script>
</head>

<body>


<table width="98%" height="487"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td align="center" valign="top">
 <table width="100%"  border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="84%">&nbsp;      </td>
</tr>
</table>  <form name="form1" method="post" action="kouling_ok.php">
  <table width="47%"  border="0" cellpadding="0" cellspacing="0" bordercolor="#FFFFFF" bordercolordark="#D2E3E6" bordercolorlight="#FFFFFF">
<?php
include("lianjie.php");
$query3=mysql_query("select pwd from reader where id=32");
$info3=mysql_fetch_array($query3);
?>
  <tr align="center">
    <td width="27%" align="left" style="padding:5px;">�������ƣ�</td>
    <td width="73%" align="left">
      <input name="name" type="text" id="name" value="<?php echo $_SESSION[user_username];?>" readonly size="15">    </td>
    <tr>
    <td align="left" style="padding:5px;">ԭ���룺</td>
    <td align="left"><input name="oldpwd" type="password" id="oldpwd" size="15">
      <input name="holdpwd" type="hidden" id="holdpwd" value="<?php echo $info3[password];?>"></td>
    </tr>
    <tr>
      <td align="left" style="padding:5px;">�����룺</td>
      <td align="left"><input name="pwd" type="password" id="pwd" size="15"></td>
    </tr>
    <tr>
      <td align="left" style="padding:5px;">ȷ�������룺</td>
      <td align="left"><input name="pwd1" type="password" id="pwd1" size="15"></td>
    </tr>
    <tr>
      <td height="65" align="left" style="padding:5px;">&nbsp;</td>
      <td><input name="Submit" type="submit" class="btn_grey" value="����" onClick="return checkForm(form1)">
        &nbsp;
        <input name="Submit2" type="reset" class="btn_grey" value="ȡ��"></td>
    </tr>
</table>
</form></td>
      </tr>
    </table>
</body>
</html>