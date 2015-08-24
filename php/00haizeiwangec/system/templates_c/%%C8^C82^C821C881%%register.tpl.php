<?php /* Smarty version 2.6.28, created on 2014-12-27 05:30:33
         compiled from register.tpl */ ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo $this->_tpl_vars['title']; ?>
</title>
<link rel="stylesheet" href="css/reg.css"/>

<?php echo '
<script type="text/javascript">
<!--
var ht=null;
function fun1(){
//1，创建ajax对象，XMLHttpResquest
    if(window.ActiveXObject)
	{
		ht=new ActiveXObject("Microsoft.XMLHTTP");//ie7以下的浏览器
	}
	else 
	{
		ht=new XMLHttpRequest();
	}
        //alert(\'这里来了1\');
	var url="chkname.php?user="+document.getElementById("name").value; 
	//alert(http_request.readyState);
    ht.onreadystatechange=function()
    {
		if(ht.readyState==4)
			{
				if(ht.status==200)
				{
				var msg = ht.responseText;			
				if(msg == \'2\'){
					name1.innerHTML="<font color=#FF0000>用户名被占用！</font>";
					return false;
				}else if(msg == \'1\'){
					name1.innerHTML="<font color=green>恭喜您，可以注册!</font>";
					form.c_name.value = "yes";
					
				}else{
					name1.innerHTML="<font color=green>"+msg+"</font>";
				}
				}
			}
	}
   ht.open("GET",url,true);
   ht.send();
}
//-->
</script>
'; ?>

</head>
<script language="javascript" src="js/createxmlhttp.js"></script>
<script language="javascript" src="js/check.js"></script>
<body onLoad="javascript:register.name.focus()">
<table width="500" border="0" align="center" cellpadding="0" cellspacing="0">
 <form id="register" name="register" action="reg_chk.php" method="post" >
 	<tr>
    	<td colspan="5" align="center" valign="middle"><h2>新用户注册</h2></td>
    </tr>
    <tr>
      <td width="95" height="25"><div align="right">用户名：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="name" name="name" type="text" onBlur="fun1()"  onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'" required/><input id="c_name" name="c_anme" type="hidden" value="not" >&nbsp;<font color="red">*</font></td>
      <td height="25"><div id="name1"><font color="#999999">请输入用户名</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right">注册密码：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="pwd1" name="pwd1" type="password" required onBlur="javascript:chkpwd1(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/>&nbsp;<font color="red">*</font></td>
      <td width="183"><div id="pwd11"><font color="#999999">请输入密码</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right">确认密码：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="pwd2" name="pwd2" type="password" required onBlur=" javascript:chkpwd2(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/>&nbsp;<font color="red">*</font></td>
      <td height="25"><div id="pwd21"><font color="#999999">确认密码</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right">密保问题：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="question" name="question" required type="text" onBlur="javascript:chkquestion(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/>&nbsp;<font color="red">*</font></td>
      <td height="25"><div id="question1"><font color="#999999">请填写密码保护问题</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right" >密保答案：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="answer" name="answer" required type="text" onBlur="javascript:chkanswer(register)"  onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/>&nbsp;<font color="red">*</font></td>
      <td height="25"><div id="answer1"><font color="#999999">请填写密码保护答案</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right" >真实姓名：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="realname" name="realname" required type="text" onBlur="javascript:chkrealname(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/>&nbsp;<font color="red">*</font></td>
      <td height="25"><div id="realname1"><font color="#999999">请填写真实姓名</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right" >移动电话：</div></td>
      <td height="25" colspan="3">&nbsp;

          <input id="tel" type="text" name="tel" required onBlur="javascript:chktel(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/>&nbsp;<font color="red">*</font></td>
      <td height="25"><div id="tel1"><font color="#999999">请输入移动电话</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right">QQ号码：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="qq" type="text" name="qq" required onBlur="javascript:chkqq(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/></td>
      <td height="25"><div id="qq1"><font color="#999999">请输入QQ号</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right">E-mail：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="email" type="text" name="email" required onBlur="javascript:chkemail(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/></td>
      <td height="25"><div id="email1"><font color="#999999">请输入Email</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right">邮&nbsp;&nbsp;编：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="code" type="text" name="code" required onBlur="javascript:chkcode(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut= "this.style.backgroundColor='#e8f4ff'"/></td>
      <td height="25"><div id="code1"><font color="#999999">请输入邮编</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right">联系地址：</div></td>
      <td height="25" colspan="3">&nbsp;
          <input id="address" type="text" name="address" required onBlur="javascript:chkaddress(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/>&nbsp;<font color="red">*</font></td>
      <td height="25"><div id="address1"><font color="#999999">请输入联系地址</font></div></td>
    </tr>
    <tr>
      <td height="25"><div align="right">验证码：</div></td>
      <td width="77" height="25">&nbsp;
        <input id="yzm" type="text" name="yzm" size="8" required onBlur="javascript:chkyzm(register)" onMouseOver="this.style.backgroundColor='#ffffff'" onMouseOut="this.style.backgroundColor='#e8f4ff'"/>
      <input name="yzm2" type="hidden" value="" /></td>
      <td width="82" align="center" valign="middle"><script>yzm(register)</script></td>
      <td width="63"><a href="javascript:code(register)">看不清</a></td>
      <td height="25"><div id="yzm1"><font color="#999999">输入验证码</font></div></td>
    </tr>
    <tr>
      <td height="49" colspan="2">&nbsp;
          <input type="submit" value="提交"/>
        &nbsp;&nbsp;
      <input type="reset" value="重写" /></td>
      <td height="49" colspan="3"><div style="color:#FF0000">带“*”号的为必填项</div></td>
    </tr>
  </form>
</table>
</body>
</html>