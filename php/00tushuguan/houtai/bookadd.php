<!doctype html>
<?php 
session_start();
error_reporting(0);

include("checklogin.php");
include("lianjie.php");
if($_GET[action]=="save"){
$operator=$_SESSION['user_username'];
$bookName=$_POST['bookName'];
$booktype=$_POST['booktype'];
$author=$_POST['author'];
$translator=$_POST['translator'];
$publishing=$_POST['publishing'];
$price=$_POST['price'];
$page=$_POST['page'];
$bookcase=$_POST['bookcase'];
$stock=$_POST['stock'];
$photo=$_POST['photo'];
$tuijian=$_POST['tuijian'];
$bidu=$_POST['bidu'];
$beizhu=$_POST['beizhu'];
$inTime=date("Y-m-d");
if ($tuijian==""){$tuijian=0;}
if ($bidu==""){$bidu=0;}
if($bookName==""){
    echo "<script language='javascript'>alert('图书名称不能为空!');history.back();</script>";
   }  
if($price==""){
    echo "<script language='javascript'>alert('图书定价不能为空!');history.back();</script>";
   }  
if($bookcase==""){
    echo "<script language='javascript'>alert('图书书架不能为空!');history.back();</script>";
   }      
$sql=mysql_query("insert into bookinfo(bookName,booktype,author,translator,publishing,price,page,bookcase,stock,tuijian,bidu,beizhu,inTime,operator )values('$bookName','$booktype','$author','$translator','$publishing','$price','$page','$bookcase','$stock','$tuijian','$bidu','$beizhu','$inTime','$operator')");
if($sql==true){
echo "<script language='javascript'>alert('图书信息添加成功!');history.back();</script>";
}else{
echo "<script language='javascript'>alert('图书信息添加失败!".str_replace("'","‘",mysql_error())."');history.back();</script>";
}
}
?>
<html>
<head>
<meta charset="utf-8">
<title>bookadd</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
<script language="javascript">
function check(form){
	if(form.bookName.value==""){
		alert("请输入图书姓名!");form.bookName.focus();return false;
	}
	if(form.price.value==""){
		alert("请输入图书定价!");form.price.focus();return false;
	}
form.submit();
}
</script>
</head>

<body>
<table width="98%" height="487"  border="0" cellpadding="0" cellspacing="0">
		  <tr>
			<td align="center" valign="top"><table width="100%" height="493"  border="0" cellpadding="0" cellspacing="0">
	  <tr>
    <td align="center" valign="top">
	<form name="form1" method="post" action="?action=save">
	<table width="600" height="441"  border="0" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">
      <tr>
        <td align="center">图书名称：</td>
        <td height="39"><input name="bookName" type="text" id="bookName" size="50">
          * </td>
      </tr>
      <tr>
        <td align="center">图书类型：</td>
        <td>
		<select name="booktype" class="wenbenkuang" id="booktype">
		<?php 
		$sql=mysql_query("select * from booktype");
		$info=mysql_fetch_array($sql);
		do{
		?> 		
        <option value="<?php echo $info[typename];?>"><?php echo $info[typename];?></option>
		<?php }while($info=mysql_fetch_array($sql));?> 
        </select>
		</td>
      </tr>
      <tr>
        <td align="center">作&nbsp;&nbsp;者：</td>
        <td><input name="author" type="text" id="author" size="40"></td>
      </tr>
      <tr>
        <td align="center">译&nbsp;&nbsp;者：</td>
        <td><input name="translator" type="text" id="translator" size="40"></td>
      </tr>
      <tr>
        <td align="center">出&nbsp;版&nbsp;社：</td>
        <td>
		<select name="publishing" class="wenbenkuang" id="publishing">
		<?php
		$sql2=mysql_query("select * from publishing");
		$info2=mysql_fetch_array($sql2);
		do{
		?> 		
        <option value="<?php echo $info2[pubname];?>"><?php echo $info2[pubname];?></option>
		<?php }while($info2=mysql_fetch_array($sql2));?> 
        </select>
		</td>
      </tr>
      <tr>
        <td align="center">价&nbsp;&nbsp;格：</td>
        <td><input name="price" type="text" id="price">(元)</td>
      </tr>
      <tr>
        <td align="center">页&nbsp;&nbsp;码：</td>
        <td><input name="page" type="text" id="page"></td>
      </tr>
      <tr>
        <td align="center">书&nbsp;&nbsp;架：</td>
        <td><select name="bookcase" class="wenbenkuang" id="bookcase">
		<?php
		$sql3=mysql_query("select * from bookcase");
		$info3=mysql_fetch_array($sql3);
		do{
		?> 		
          <option value="<?php echo $info3[name];?>"><?php echo $info3[name];?></option>
			<?php }while($info3=mysql_fetch_array($sql3));?> 
        </select>
          <input name="operator" type="hidden" id="operator" value="<?php echo $info3[name];?>"></td>
      </tr>
      <tr>
        <td align="center">库&nbsp;&nbsp;存：</td>
        <td><input name="stock" type="text" id="stock" value="0">
          （本）</td>
      </tr>
      <tr>
        <td align="center">属性：</td>
        <td><input name="tuijian" type="checkbox" id="tuijian" value="1">
          推荐
            <input name="bidu" type="checkbox" id="bidu" value="1">
            必读</td>
      </tr>
      <tr>
        <td align="center">详细介绍：</td>
        <td><textarea name="beizhu" cols="50" rows="5" id="beizhu"></textarea></td>
      </tr>
      <tr>
        <td align="center">&nbsp;</td>
        <td><input name="Submit" type="button" class="btn_grey" value="保存" onClick="return check(form1)">
        &nbsp;
			<input name="Submit2" type="button" class="btn_grey" value="返回" onClick="history.back();"></td>
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