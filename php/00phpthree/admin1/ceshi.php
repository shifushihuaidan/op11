<?php
/*include("mycon.php");
$t='shujia';
$a1="��׿���2";
$a2="���";
$sql="insert into shujia values ('".$a1."','".$a2."')";
echo $sql;
$res=mysql_query($sql);
if($res)
{
	echo "����ɹ�";
}
else
{
	echo "����ʧ��";
}*/
$name="��������";
$mima="����";
$sql="select * from user where uname='";
$sql.=$name."' and umima= '".$mima."'";
echo $sql;
?>
<td>
<input type="checkbox" name="x1" value="1"
checked="<?php if($row['us']=="1") echo "checked";?>"
/>
</td>
<td>
<input type="checkbox" name="x2" value="1"
checked="<?php if($row['udg']=="1") echo "checked";?>"
/>
</td>
<td>
<input type="checkbox" name="x3" value="1"
checked="<?php if($row['utg']=="1") echo "checked";?>"
/>
</td>
<td>
<input type="checkbox" name="x4" value="1"
checked="<?php if($row['uth']=="1") echo "checked";?>"
/>
</td>
<td>
<input type="checkbox" name="x5" value="1"
checked="<?php if($row['usc']=="1") echo "checked";?>"
/>
</td>