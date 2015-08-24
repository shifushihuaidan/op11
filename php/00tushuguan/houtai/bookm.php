<!doctype html>
<?php 
error_reporting(E_ALL & ~E_NOTICE);
session_start();
include("checklogin.php");
include("lianjie.php");
if(isset($_POST['save'])){
$bid=$_POST[bid];
$operator=$_SESSION['user_username'];
$bookName=$_POST['bookName'];
$booktype=$_POST['booktype'];
$author=$_POST['author'];
$translator=$_POST['translator'];
$publishing=$_POST['publishing'];
$price=$_POST['price'];
$page=$_POST['page'];
$stock=$_POST['stock'];
$bookcase=$_POST['bookcase'];
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
$query=mysql_query("update bookinfo set bookName='$bookName' , booktype='$booktype', author='$author', translator='$translator', publishing='$publishing' , price='$price' , page='$page' , bookcase='$bookcase',stock='$stock',tuijian='$tuijian',bidu='$bidu',beizhu='$beizhu',inTime='$inTime', operator='$operator' where id=$bid");
if($query==true){
echo "<script language='javascript'>alert('图书信息修改成功!');window.location.href='index.php?Tswap=Tb';</script>";
}
else
{
echo "<script language='javascript'>alert('图书信息添加失败!".str_replace("'","‘",mysql_error()).")');window.location.href='book.php';</script>";
}
}
?>
<html>
<head>
<meta charset="utf-8">
<title>bookm</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>

<body>
<table width="98%" height="463"  border="0" cellpadding="0" cellspacing="0">
                    <tr>
                      <td height="441" align="center" valign="top"><table width="100%" height="421"  border="0" cellpadding="0" cellspacing="0">
                          <tr>
                            <td height="421" align="center" valign="top">
                            <form name="form1" method="post" action="">
                                <?php
									$sql=mysql_query("select * from bookinfo  where id=$_GET[id]");
									$info=mysql_fetch_array($sql);
									?>
                                <input type="hidden" name="bid" value="<?php echo $info[id];?>">
                                <table width="600" height="452"  border="0" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF">

                                  <tr>
                                    <td align="center">图书名称：</td>
                                    <td height="35"><input name="bookName" type="text" id="bookName" value="<?php echo $info[bookname];?>" size="50">
                                        <span class="style1">*</span></td>
                                  </tr>
                                  <tr>
                                    <td height="35" align="center">图书类型：</td>
                                    <td><select name="booktype" class="wenbenkuang" id="booktype">
                                        <?php 
											$sql1=mysql_query("select * from booktype");
											$info1=mysql_fetch_array($sql1);
											do{
											?>
                                        <option value="<?php echo $info1[typename];?>" <?php if($info1[typename]==$info[booktype]){?> selected <?php }?>><?php echo $info1[typename];?></option>
                                        <?php }while($info1=mysql_fetch_array($sql1));?>
                                      </select>
                                    </td>
                                  </tr>
                                  <tr>
                                    <td align="center">作&nbsp;&nbsp;者：</td>
                                    <td><input name="author" type="text" id="author" value="<?php echo $info[author];?>" size="40"></td>
                                  </tr>
                                  <tr>
                                    <td height="36" align="center">译&nbsp;&nbsp;者：</td>
                                    <td><input name="translator" type="text" id="translator" value="<?php echo $info[translator];?>" size="40"></td>
                                  </tr>
                                  <tr>
                                    <td height="34" align="center">出&nbsp;版&nbsp;社：</td>
                                    <td><select name="publishing" class="wenbenkuang" id="publishing">
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
                                    <td height="33" align="center">价&nbsp;&nbsp;格：</td>
                                    <td><input name="price" type="text" id="price" value="<?php echo $info[price];?>">
                                      (元)</td>
                                  </tr>
                                  <tr>
                                    <td height="29" align="center">页&nbsp;&nbsp;码：</td>
                                    <td><input name="page" type="text" id="page" value="<?php echo $info[page];?>"></td>
                                  </tr>
                                  <tr>
                                    <td height="34" align="center">书&nbsp;&nbsp;架：</td>
                                    <td><select name="bookcase" class="wenbenkuang" id="bookcase">
                                        <?php
									$sql3=mysql_query("select * from bookcase");
									$info3=mysql_fetch_array($sql3);
									do{
									?>
                                        <option value="<?php echo $info3[name];?>"<?php if($info3[name]==$info[bookcase]){?> selected <?php }?>><?php echo $info3[name];?></option>
                                        <?php }while($info3=mysql_fetch_array($sql3));?>
                                      </select>
                                        <input name="operator" type="hidden" id="operator" value="<?php echo $info3[name];?>"></td>
                                  </tr>
                                  <tr>
                                    <td height="34" align="center">库&nbsp;&nbsp;存：</td>
                                    <td><input name="stock" type="text" id="stock" value="<?php echo $info[stock];?>"></td>
                                  </tr>
                                  <tr>
                                    <td height="39" align="center">属性：</td>
                                    <td><input name="tuijian" type="checkbox" id="tuijian" value="1" <?php if ($info[tuijian]==1){echo "checked";} ?>>
    推荐
      <input name="bidu" type="checkbox" id="bidu" value="1" <?php if ($info[bidu]==1){echo "checked";} ?>>
    必读</td>
                                  </tr>
                                  <tr>
                                    <td height="39" align="center">详细介绍：</td>
                                    <td><textarea name="beizhu" cols="50" rows="5" id="beizhu"><?php echo $info[beizhu];?></textarea></td>
                                  </tr>
                                  <tr>
                                    <td colspan="2" align="center">
                                    <input name="save" type="submit" class="btn_grey" value="保存" >&nbsp;
                                      <input name="Submit2" type="button" class="btn_grey" value="返回" onClick="history.back();"></td>
                                  </tr>
                                </table>
                            </form></td>
                          </tr>
                      </table></td>
                    </tr>
                </table></td>
              </tr>

</body>
</html>