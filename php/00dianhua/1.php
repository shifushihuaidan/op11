<?php
$link=mysql_connect('localhost','root','root') or die("���ݿ��ʧ��");
mysql_set_charset("gbk");
mysql_select_db('cx') or die("ʧ��");
?>
<html>
<head>
<meta charset=" gbk">
<center>
���н��Ҳ�ѯ
</center>
<style type="text/css">
.a
{border:1 solid red;
 width:799;
 height:459;
 margin:0 auto;
}	
.b
{border:1 solid green;
 width:799;
 height:199;
 margin:0 auto;
}	
.c
{border:1 solid blue;
 width:799;
 height:257;
 margin:0 auto;
}	
</style>

</head>
<body>
<div class="a">
<div  class="b">
<form method="post" action="">
<input type="text" name="js">
<input type="submit" value="��ѯ" name="sub">
</form>

</div>
<div class="c">
<table width="799" height="257">
<th>����</th>	
<th>�������</th>	
<?php
if(isset($_POST['sub']))
{
	$js=$_POST['js'];
	$sql=" select * from cx where js ='".$js."'";
	$res=mysql_query($sql);
	if($res && mysql_num_rows($res))
	{
	while($row=mysql_fetch_assoc($res))
		{
	      echo "<tr>";
		  echo "<td>".$row['js']."</td>";
		  if($row['kx']==1)
		  echo "<td>"."������ռ"."</td>";
		  else
			  echo "<td>"."���ҿ���"."</td>";
	    }
	}
	?>
	<?php
}
?>
</table>
</div>

</div>
</body>
</html>