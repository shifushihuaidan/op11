<!doctype html>
<html>
<?php 
error_reporting(0);  
session_start();
  include("houtai/lianjie.php");
if($_POST[Submit]!=""){
$username=$_POST['username'];
$pwd1=$_POST['pwd1'];
$pwd2=$_POST['pwd2'];
$name=$_POST['name'];
$sex=$_POST['sex'];
$booktype=$_POST['booktype'];
$vocation=$_POST['vocation'];
$birthday=$_POST['birthday'];
$paperType=$_POST['paperType'];
$paperNO=$_POST['paperNO'];
$tel=$_POST['tel'];
$email=$_POST['email'];
$createDate=date("Y-m-d");
$operator=$_POST['operator'];
$remark=$_POST['remark'];
if($username==""){
   echo "<script language=javascript>alert('�û�������Ϊ�գ�');history.back();</script>";
   } 
if($name==""){
   echo "<script language=javascript>alert('������������Ϊ�գ�');history.back();</script>";
   }
if($pwd1==""){
   echo "<script language=javascript>alert('��¼���벻��Ϊ�գ�');history.back();</script>";
 }
if($pwd1!=$pwd2){
   echo "<script language=javascript>alert('�����������벻һ�£�');history.back();</script>";
 }  
if($birthday==""){
   echo "<script language=javascript>alert('�������ղ���Ϊ�գ�');history.back();</script>";
   }   
if($paperNO==""){
   echo "<script language=javascript>alert('����֤�����벻��Ϊ�գ�');history.back();</script>";
   }    
$sql=mysql_query("insert into reader (username,pwd,name,sex,booktype,vocation,birthday,paperType,paperNO,tel,email,createDate,operator,remark) values('$username','md5($pwd)','$name','$sex','$booktype','$vocation','$birthday','$paperType','$paperNO','$tel','$email','$createDate','$operator','$remark')");
if($sql==true){
echo "<script language=javascript>alert('������Ϣ��ӳɹ���');history.back();location.href='duzhe.php';</script>";
}
else{
echo "<script language='javascript'>alert('������Ϣ���ʧ��!".str_replace("'","��",mysql_error())."');history.back();</script>";
}
} 
 ?>
<head>
<meta charset="utf-8">
<title>readeradd</title>
<link rel="stylesheet" type="text/css" href="houtai/css/style.css">
<style type="text/css">
	body
	{
	background-color:281C20;
	background-image:url(./image/1.jpg);
	background-repeat:no-repeat;
	background-attachment:fixed;
	background-position:center;
	}
</style>
</head>

<body>

<table width="98%" height="487"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td align="center" valign="top"><table width="100%" height="493"  border="0" cellpadding="0" cellspacing="0">
  <tr>
    <td align="center" valign="top">
	<form name="form1" method="post" action="?">
	<table width="600" height="343"  border="0" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td align="center">�û���</td>
        <td height="25"><input name="username" type="text" id="username">
* </td>
      </tr>
      <tr>
        <td align="center">����</td>
        <td height="18"><input name="pwd1" type="password" id="pwd1">
* </td>
      </tr>
      <tr>
        <td align="center">ȷ������</td>
        <td height="17"><input name="pwd2" type="password" id="pwd2">
* </td>
      </tr>
      <tr>
        <td width="173" align="center">������</td>
        <td width="427" height="23">
          <input name="name" type="text"> 
          *         </td>
      </tr>
      <tr>
        <td width="173" align="center">�Ա�</td>
        <td height="19"><input name="sex" type="radio" class="noborder" id="radiobutton" value="��" checked>
          <label for="radiobutton">�� </label>
          <label>
          <input name="sex" type="radio" class="noborder" value="Ů">
          Ů</label></td>
      </tr>
      <tr>
        <td align="center">�������ͣ�</td>
        <td>
		<select name="booktype" class="wenbenkuang" id="booktype">
<?php
  $sql=mysql_query("select * from readertype");
  $info=mysql_fetch_array($sql);
  do{
?> 		
				
          <option value="<?php echo $info[name];?>"><?php echo $info[name];?></option>
<?php
}while($info=mysql_fetch_array($sql));
?> 
        </select>        </td>
      </tr>
      <tr>
        <td align="center">ְҵ��</td>
        <td><input name="vocation" type="text" id="vocation"></td>
      </tr>
      <tr>
        <td align="center">�������ڣ�</td>
        <td><input name="birthday" type="text" id="birthday" onFocus="setday(this)">
          *</td>
      </tr>
      <tr>
        <td align="center">��Ч֤����</td>
        <td><select name="paperType" class="wenbenkuang" id="paperType">
          <option value="���֤" selected>���֤</option>
          <option value="ѧ��֤">ѧ��֤</option>
          <option value="����֤">����֤</option>
          <option value="����֤">����֤</option>
          </select></td>
      </tr>
      <tr>
        <td align="center">֤�����룺</td>
        <td><input name="paperNO" type="text" id="paperNO"> 
          * </td>
      </tr>
      <tr>
        <td align="center">�绰��</td>
        <td><input name="tel" type="text" id="tel"></td>
      </tr>
      <tr>
        <td align="center">E-mail��</td>
        <td><input name="email" type="text" id="email" size="50">
          <input name="operator" type="hidden" id="operator" value="<?php echo $_SESSION['user_username'];?>"></td>
      </tr>
      <tr>
        <td align="center">��ע��</td>
        <td><textarea name="remark" cols="50" rows="5" class="wenbenkuang" id="remark"></textarea></td>
      </tr>
      <tr>
        <td align="center">&nbsp;</td>
        <td><input name="Submit" type="submit" class="btn_grey" value="����" onClick="return check(form1)">
&nbsp;
<input name="Submit2" type="button" class="btn_grey" value="����" onClick="history.back()"></td>
      </tr>
    </table>
	</form>
	</td>
  </tr>
</table></td>
      </tr>
    </table>



</body>
</html>