<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>canshu</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>

<body>

<table width="99%" height="403"  border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#FFFFFF" class="tableBorder_gray">
  <tr>
    <td height="401" valign="top" style="padding:5px;">
    <table width="98%" height="239"  border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td height="239" align="center" valign="top">
 			<table width="100%"  border="0" cellspacing="0" cellpadding="0">
  				<tr>
    				<td width="84%">&nbsp;      </td>
				</tr>
			</table>  
			<form name="form1" method="post" action="pwd_ok.php">
  				<table width="47%"  border="0" cellpadding="0" cellspacing="0" bordercolor="#FFFFFF" bordercolordark="#D2E3E6" bordercolorlight="#FFFFFF">
				<?php
						include("lianjie.php");
						$query3=mysql_query("select pwd from manager where name='$_SESSION[user_username]'");
						$info3=mysql_fetch_array($query3);
				?>
  					<tr align="center">
    					<td width="27%" align="left" style="padding:5px;">办证费：</td>
    					<td width="73%" align="left">
      						<input name="zheng" type="text" value="120" readonly size="8"> （元）   </td>
    					<tr>
    						<td align="left" style="padding:5px;">有效期限：</td>
    						<td align="left"><input name="time" type="text" size="8" value="12">（月）
                            </td>
    					</tr>

    					<tr>
      					<td height="65" align="left" style="padding:5px;">&nbsp;</td>
      					<td><input name="Submit" type="submit" class="btn_grey" value="保存" onClick="return checkForm(form1)">
        				&nbsp;
        					<input name="Submit2" type="reset" class="btn_grey" value="取消">
                         </td>
    					</tr>
				</table>
				</form></td>
      </tr>
    </table>
</td>
  </tr>
</table>

</body>
</html>