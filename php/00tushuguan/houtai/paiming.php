<!doctype html>
<?php 
error_reporting(0);
include("checklogin.php");
include("lianjie.php");
?>

<html>
  <head>
<meta charset="utf-8">
<title>paiming</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
    <table width="738"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td height="148" valign="top">
        <table width="738"  border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td width="753" height="44" background="Images/main_booksort.gif">&nbsp;</td>
          </tr>
          <tr>
            <td height="72" valign="top" background="Images/main_booksort_1.gif">
            <table width="740"  border="1" cellpadding="0" cellspacing="0" bordercolor="#FFFFFF" bordercolordark="#D2E3E6" bordercolorlight="#FFFFFF">
              <tr align="center">
                <td width="4%" height="25">排名</td>
                <td width="22%">图书名称</td>
                <td width="11%">图书类型</td>
                <td width="9%">书架</td>
                <td width="13%">出版社</td>
                <td width="15%">作者</td>
                <td width="8%">定价(元)</td>
                <td width="8%">借阅次数</td>
              </tr>
              <?php
			  		$sql=mysql_query("select * from (select bookid,count(bookid) as degree from borrow group by bookid) as borr  order by borr.degree desc limit 10");
					$info=mysql_fetch_array($sql);
					$i=1;
					if ($info==false){
					echo"没有借阅排名信息";
					}
					else{
					do{
					$sql1=mysql_query("select * from bookinfo where id=$info[bookid]");
					$info1=mysql_fetch_array($sql1);
					?>
              <tr>
                <td height="25" align="center"><?php echo $i;?></td>
                <td style="padding:5px;"><?php echo $info1[bookname];?></td>
                <td style="padding:5px;"><?php echo $info1[booktype];?></td>
                <td align="center">&nbsp;<?php echo $info1[bookcase];?></td>
                <td align="center">&nbsp;<?php echo $info1[publishing];?></td>
                <td align="center"><?php echo $info1[author];?></td>
                <td align="center"><?php echo $info1[price];?></td>
                <td align="center"><?php echo $info[degree];?></td>
              </tr>
              <?php 
				 $i=$i+1;
				 }while($info=mysql_fetch_array($sql));
				 }
				?>
            </table></td>
          </tr>
          <tr>
            <td height="19" background="Images/main_booksort_2.gif">&nbsp;</td>
          </tr>
        </table>
          </td>
      </tr>
    </table>
      <p>&nbsp;</p>
</html>