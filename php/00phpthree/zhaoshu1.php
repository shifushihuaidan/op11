<?php
include("./admin1/mycon.php");
function alertMes($mes,$url)
{
	echo "<script>alert('{$mes}');</script>";
	echo "<script>window.location='{$url}';</script>";
}
?>
<html>
<head>
<style type="text/css">
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
		/*border:0px;*/
    }
    table th{
        background-color:E3F4F7;
	}
	table tr{
        border:1px solid 0A5F93;
	}
</style>
</head>
<body>

<div class="a2">
<table width="777" height="290" border="1"> 
<th>������</th>
<th>ͼ������</th>
<th>ͼ������</th>
<th>������</th>
<th>���</th>
<th>����</th>
<th>����</th>
<?php
$s1=$_POST['r1'];
$p = '/^-?[1-9]\d*$/';
//echo $s1;
if (preg_match($p, $s1)) 
{
    //echo "����׼ȷ��ѯ";
	$sql="select * from book where bid='".$s1."'";
}
else
{
	$s2='%'.$s1.'%';
	$sql="select * from book where bname  like 
	'".$s2."'";
}
//$sql="select * from book";
$res=mysql_query($sql);
if($res&&mysql_num_rows($res))
{
	while ($row = mysql_fetch_assoc($res)) 
	{
		echo "<tr>";
		echo "<td>".$row['bid']."</td>";
		echo "<td>".$row['bname']."</td>";
        echo "<td>".$row['btype']."</td>";
		echo "<td>".$row['chubanshe']."</td>";
		echo "<td>".$row['shujia']."</td>";
		echo "<td>".$row['shuliang']."</td>";
?>
<td>
<a href="index2?aa=����&id=<?php echo 
$row['bid']?>&shuliang=<?php echo 
$row['shuliang']?>">����</a>
</td>
<?php
		echo "</tr>";
	}
}
else
{
	alertMes("�Բ���û����ص���","index2.php?aa=����");
}
?>
</table>
</div>
</body>
</html>

