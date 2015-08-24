<?php

//$str = "1我 2是 3谁 4你   5又是谁";
/*$a=explode(" ",$str);
print_r($a);
echo "<br/>";
$b=array_reverse($a);
$c=count($b);
print_r($c);
echo "<br/>";
print_r($b);
echo "<br/>";
for($i=0;$i<$c;$i++)
{
	echo $b[$i];
	echo "<br/>";
	if($i==3)
	{
		break;
	}
}


//去掉数组的空格的函数
function array_remove_empty(& $arr, $trim = true)   
{   
    foreach ($arr as $key => $value) 
	    {   
         if (is_array($value)) 
			{   
              array_remove_empty($arr[$key]);   
            } 
		 else 
			{   
              $value = trim($value);   
              if ($value == '')
				{   
              unset($arr[$key]);   
                } 
			  elseif ($trim) 
				  {   
              $arr[$key] = $value;   
                  }   
            }   
        }   
}  

$str[0]=1234;
$str[1]="";
$str[2]=1231;
$str[3]="";
$str[4]=23231;
var_dump($str);
echo "<br/>";
array_remove_empty($str);
print_r($str);

date_default_timezone_set('Etc/GMT-8');     //这里设置了时区
$a=date("Y-m-d h:i:sa");
echo "现在时间是".$a;
*/
/*$a="123aaw";
$b=md5($a);
echo $b;*/
/*$link=mysql_connect('localhost','root','0794444944') or die("数据库连接失败Error:".mysql_errno().":".mysql_error());
	mysql_set_charset('utf8');
	mysql_select_db('opliao') or die("指定数据库打开失败");
   if(!$link) echo "失败!";
    else echo "连接数据库成功!";*/
	/*$name="孩子饿";
	$mima="0088";
$sql="insert into yonghu(name,mima) values ('".$name."','".$mima."');";
echo $sql;*/
          /*$mima=md5($_POST['mima']);
	     $nam=$_POST['name1'];
		 echo "密码".$mima;
		 echo "用户名".$nam;
$sql="insert into yonghu(name,mima) values ('".$nam."','".$mima."');";
echo $sql;
	*/
	$b=md5(079444);
    echo $b;
?>