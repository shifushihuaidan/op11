<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>bookjadd</title>
<?php 
include("lianjie.php");
if(isset($_POST['submit'])){
$casename=$_POST[name];
if($casename==""){
	echo "<script language='javascript'>alert('请输入书架名称！');window.opener.location.reload();window.close();</script>";}
else{
$query_ins=mysql_query("insert into bookcase(name) values('$casename')");
if($query_ins){
	echo "<script language='javascript'>alert('成功添加书架名称！');window.opener.location.reload();window.close();</script>";
}else{
	echo "<script language='javascript'>alert('书架名称添加操作失败！".str_replace("'","‘",mysql_error())."');window.opener.location.reload();window.close();</script>";
} 
}
}?>
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

<div id="formwrapper" >
    <form action="" method="post" name="apForm" id="apForm">
    <fieldset>
        <legend>书架添加</legend>
        <div>
        <label for="Name">书架名称:</label>
        <input type="text" name="name" id="Name" size="20" maxlength="30" />
          *(最多15个字符)<br />    
   		</div>
        <div class="enter">
        <input name="submit" type="submit" class="buttom" value="提交" />
        <input name="quxiao" type="reset" class="buttom" value="取消" onClick="window.close();"/>
    </div>
    </fieldset>
    </form>
</div>
</body>
</html>