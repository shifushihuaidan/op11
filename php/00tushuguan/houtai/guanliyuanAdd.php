<!doctype html>
<html>
<head>
<title>添加管理员信息</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link href="CSS/style.css" rel="stylesheet">

<script language="javascript">
function check(form1){
	if(form1.name.value==""){
		alert("请输入管理员名称!");form1.name.focus();return false;
	}
	if(form1.pwd.value==""){
		alert("请输入管理员密码!");form1.pwd.focus();return false;
	}
	if(form1.pwd1.value==""){
		alert("请确认管理员密码!");form1.pwd1.focus();return false;
	}		
	if(form1.pwd.value!=form1.pwd1.value){
		alert("您两次输入的管理员密码不一致，请重新输入!");form1.pwd1.focus();return false;
	}
}
</script>
<style>
.bo {
    font-family: Arial, Helvetica, sans-serif;
    font-size:16px;
    color:#666666;
    background:#fff;
    text-align:center;

}

*{
    margin:0;
    padding:0;
}

a {
    color:#1E7ACE;
    text-decoration:none;    
}

a:hover{
	color: #000;
	text-decoration: underline;
	font-size: 16px;
}
h3 {
    font-size:14px;
    font-weight:bold;
}

pre,p {
    color:#1E7ACE;
    margin:4px;
	font-size:13px;
}
input, select,textarea {
    padding:1px;
    margin:2px;
    font-size:11px;
}
.buttom{
    padding:1px 10px;
    font-size:12px;
    border:1px #1E7ACE solid;
    background:#D0F0FF;
}
#formwrapper {
    width:450px;
    margin:-8px auto;
    padding:20px;
    text-align:left;

}

fieldset {
    padding:10px;
    margin-top:0px;
    border:1px solid #1E7ACE;
    background:#fff;
}

fieldset legend {
    color:#1E7ACE;
    font-weight:bold;
    padding:3px 20px 3px 20px;
    border:1px solid #1E7ACE;    
    background:#fff;
}

fieldset label {
    float:left;
    width:120px;
    text-align:right;
    padding:4px;
    margin:1px;
}

fieldset div {
    clear:left;
    margin-bottom:2px;
}

.enter{ text-align:center;}
.clear {
    clear:both;
}
</style>
</head>
<body class="bo">
<div><?php  echo $error_msg ;  ?> </div>
<div id="formwrapper" >
    <form action="guanliyuanok.php" method="post" name="apForm" id="apForm">
    <fieldset>
        <legend>用户添加</legend>
        <div>
        <label for="Name">管理员名称:</label>
        <input type="text" name="name" id="Name" size="20" maxlength="30" />
          *(最多15个字符)<br />    
   		</div>

        <div>
        <label for="password">密码:</label>
        <input type="password" name="pwd" id="password" size="18" maxlength="15" /> 
        *(最多15个字符)<br />
    </div>
    	
        <div>
        <label for="confirm_password">确认密码:</label>
        <input type="password" name="pwd1" id="confirm_password" size="18" maxlength="15" /> 
        *<br />
        <div class="enter">
        <input name="submit" type="submit" class="buttom" value="提交" onClick="check(apForm)"/>
        <input name="quxiao" type="reset" class="buttom" value="取消" onClick="window.close();"/>
    </div>
    </div>
    </fieldset>
    </form>
</div>



</body>
</html>