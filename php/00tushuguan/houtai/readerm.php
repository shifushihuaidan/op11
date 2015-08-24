<!doctype html>
<html>

<?php
error_reporting(0);
 session_start();
 include("checklogin.php");
include("lianjie.php");
if($_POST[Submit]!=""){
$id=$_POST['readerid'];
$username=$_POST['username'];
$pwd1=$_POST['pwd1'];
$pwd2=$_POST['pwd2'];
$name=$_POST['name'];
$sex=$_POST['sex'];
$vocation=$_POST['vocation'];
$birthday=$_POST['birthday'];
$paperType=$_POST['paperType'];
$paperNO=$_POST['paperNO'];
$tel=$_POST['tel'];
$email=$_POST['email'];
$remark=$_POST['remark'];
$booktype=$_POST['booktype'];

if($username==""){
   echo "<script language=javascript>alert('用户名不能为空！');history.back();</script>";
   } 
if($pwd1==""){
   echo "<script language=javascript>alert('登录密码不能为空！');history.back();</script>";
 }
if($pwd1!=$pwd2){
   echo "<script language=javascript>alert('两次密码输入不一致！');history.back();</script>";
 } 
if($name==""){
   echo "<script language=javascript>alert('读者姓名不能为空！');history.back();location.href='reader.php';</script>";
   }  
if($paperNO==""){
   echo "<script language=javascript>alert('读者证件号码不能为空！');history.back();location.href='reader.php';</script>";
   } 
$sql=mysql_query("update reader set username='$username',pwd='$pwd1', name='$name',sex='$sex',vocation='$vocation',birthday='$birthday',paperType='$paperType',paperNO='$paperNO',tel='$tel',email='$email',remark='$remark',booktype='$booktype' where id='$id'");
if($sql==true){
echo "<script language='javascript'>alert('读者信息修改成功!');window.location.href='reader.php';</script>";
}
else{
echo "<script language='javascript'>alert('图书信息添加失败!".str_replace("'","‘",mysql_error())."');history.back();</script>";
}
}
?>
<script language="javascript">
function check(form){
	if(form.name.value==""){
		alert("请输入读者姓名!");form.name.focus();return false;
	}
	if(form.paperNO.value==""){
		alert("请输入证件号码!");form.paperNO.focus();return false;
	}
}
</script>
<head>
<meta charset="utf-8">
<title>readerm</title>
<link rel="stylesheet" type="text/css" href="css/style.css">

</head>

<body>

<table width="98%" height="487"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td align="center" valign="top"><table width="100%" height="493"  border="0" cellpadding="0" cellspacing="0">
  <tr>
<?php 
  include("lianjie.php");
	$query=mysql_query("select * from reader where id='$_GET[id]'");
	$result=mysql_fetch_array($query);
?>


    <td align="center" valign="top">	<form name="form1" method="post" action="?">
      <table width="600" height="426"  border="0" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
        <tr>
          <td align="center">用户名</td>
          <td height="25"><input name="username" type="text" id="username" value="<?php echo $result[username];?>">
    * </td>
        </tr>
        <tr>
          <td align="center">密码</td>
          <td height="23"><input name="pwd1" type="password" id="pwd1" value="<?php echo $result[pwd];?>">
    * </td>
        </tr>
        <tr>
          <td align="center">确认密码</td>
          <td height="24"><input name="pwd2" type="password" id="pwd2" value="<?php echo $result[pwd];?>">
    * </td>
        </tr>
        <tr>
          <td width="173" align="center">姓名：</td>
          <td width="427" height="29">
            <input name="name" type="text" value="<?php echo $result[name];?>">
        * 
        <input name="readerid" type="hidden" id="readerid" value="<?php echo $result[id];?>"></td>
        </tr>
        <tr>
          <td width="173" align="center">性别：</td>
          <td height="27">
		  <input name="sex" type="radio" class="noborder" id="radiobutton"  value="男" <?php if($result[sex]=="男"){?> checked <?php }?>>男
          <input name="sex" type="radio" class="noborder" value="女" <?php if($result[sex]=="女"){?> checked <?php }?>>女
		</td>
        </tr>
        <tr>
          <td align="center">读者类型：</td>
          <td>
            <select name="booktype" class="wenbenkuang" id="booktype">
<?php
  $sql=mysql_query("select * from readertype");
  $info=mysql_fetch_array($sql);
  do{
?>
              <option value="<?php echo $info[name];?>" <?php if($result[booktype]==$info[name]){?> selected<?php }?>><?php echo $info[name];?></option>
              <?php
}while($info=mysql_fetch_array($sql));
?>
                        </select>
          </td>
        </tr>
        <tr>
          <td align="center">职业：</td>
          <td><input name="vocation" type="text" id="vocation" value="<?php echo $result[vocation];?>"></td>
        </tr>
        <tr>
          <td align="center">出生日期：</td>
          <td><input name="birthday" type="text" id="birthday" value="<?php echo $result[birthday];?>"></td>
        </tr>
        <tr>
          <td align="center">有效证件：</td>
          <td>
		<select name="paperType" class="wenbenkuang" id="paperType">
             <option value="身份证" <?php if($result[paperType]=="身份证"){?> selected <?php }?>>身份证</option>
              <option value="学生证" <?php if($result[paperType]=="学生证"){?>  selected <?php }?>>学生证</option>
              <option value="军官证" <?php if($result[paperType]=="军官证"){?>  selected <?php }?>>军官证</option>
              <option value="工作证" <?php if($result[paperType]=="工作证"){?>  selected <?php }?>>工作证</option>
         </select></td>
        </tr>
        <tr>
          <td align="center">证件号码：</td>
          <td><input name="paperNO" type="text" id="paperNO" value="<?php echo $result[paperNO];?>">
        * </td>
        </tr>
        <tr>
          <td align="center">电话：</td>
          <td><input name="tel" type="text" id="tel" value="<?php echo $result[tel];?>"></td>
        </tr>
        <tr>
          <td align="center">E-mail：</td>
          <td><input name="email" type="text" id="email" value="<?php echo $result[email];?>" size="50">
                        </td>
        </tr>
        <tr>
          <td align="center">备注：</td>
          <td><textarea name="remark" cols="50" rows="5" class="wenbenkuang" id="remark"><?php echo $result[remark];?></textarea></td>
        </tr>
        <tr>
          <td align="center">&nbsp;</td>
          <td><input name="Submit" type="submit" class="btn_grey" value="保存" onClick="return check(form1)">
&nbsp;
        <input name="Submit2" type="button" class="btn_grey" value="返回" onClick="history.back()"></td>
        </tr>
      </table>
    </form></td>
  </tr>
</table></td>
      </tr>
    </table>


</body>
</html>