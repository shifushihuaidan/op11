<?php
include("mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
?>
<html>
<head>
<style type="text/css">
	.a1
	{
		width:120;
		height:30;
		/*border:1 solid red;*/
		margin:0 200 0 650;
	}
	a 
	{
		text-decoration:none;
	}
	.a2
	{
		
		width:777;
		height:300;
		/*border:1 solid red;*/
	}
	table {
        border-collapse:collapse;
        border-spacing:0;
        border:1px solid 0A5F93;
    }
    table td {
        border-color:0A5F93;
        text-align:center;
    }
    table th{
        background-color:E3F4F7;
	}
</style>
</head>
<body>
��ǰλ��:
<a href="#">ϵͳ����</a>��
<a href="index1.php?aa=������">����ԱȨ������</a>
<div class="a1">
	<a href="#">��ӹ���Ա��Ϣ</a>
</div>
<div class="a2">
<table width="777" height="290" border="1"> 
<th>����Ա����</th>
<th>ϵͳ����</th>
<th>���߹���</th>
<th>ͼ�鵵������</th>
<th>ͼ��黹</th>
<th>ϵͳ��ѯ</th>
<th>Ȩ������</th>
<th>����</th>
<?php
$sql="select * from user";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
 {
		while ($row = mysql_fetch_assoc($res)) 
       { 
			//print_r($row);
			//echo "<br/>";
			echo "<tr>";
			echo "<td>".$row['uname']."</td>";
            
?>
<td>
<input type="checkbox" name="x1" value="1"
disabled
<?php if($row['us']=="1") echo "checked";?>
/>
</td>
<td>
<input type="checkbox" name="x2" value="1"
disabled
<?php if($row['udg']=="1") echo "checked";?>
/>
</td>
<td>
<input type="checkbox" name="x3" value="1"
disabled
<?php if($row['utg']=="1") echo "checked";?>
/>
</td>
<td>
<input type="checkbox" name="x4" value="1"
disabled
<?php if($row['uth']=="1") echo "checked";?>
/>
</td>
<td>
<input type="checkbox" name="x5" value="1"
disabled
<?php if($row['usc']=="1") echo "checked";?>
/>
</td>
<td>
<a href="#">Ȩ������</a>
</td>
<td>
<a href="#">ɾ��</a>
</td>
<?php
echo "</tr>";
	  }
 }
?>
</table>
</div>
</body>
</html>