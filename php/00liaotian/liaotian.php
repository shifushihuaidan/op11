<?php
session_start();
$nn=$_SESSION['name1'];
?>
<html>
<head>
<title>����ҳ��</title>

<style type="text/css">
	.a1
	{
    width:100%;
	height:100%;
    background-image:url(./image/9.jpeg);
    background-repeat:no-repeat;
    background-attachment:fixed;
    background-position:center;
	}
	.a2
	{
	width:60%;
	height:50%;
	margin:30 auto;
    background-color:gray;
	}
    .a3
	{
    margin:30 auto;
	width:60%;
	height:30%;
    background-color:gray;
	}
</style>
<script>
function test()
{
 window.location.replace(location.href) 
}
	</script>
</head>
<body>
<?php
//ȥ������Ŀո�ĺ���
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
?>
<div class="a1">
    <h1><center><font color="#EE82EE">�������������</font></center></h1>
	<div class="a2" id="a22">
	<?php
   /*$bruce=readfile("./aa.txt");
   echo $bruce;*/
   
   $filename='./aa.txt';
   /*$str = file_get_contents($filename);
   echo $str;*/
   $str=file($filename);
   array_remove_empty($str);
   $b=array_reverse($str);
   $c=count($b);
   print_r($c);
   echo "<br/>";
  //print_r($b);
   for($i=0;$i<$c;$i++)
   {
	echo  $b[$i];
	echo "<br/>";
	if($i==5)
	{
		break;
	}
   }
   ?>
	</div>
	<div class="a3">
	<form method="post" action="">
		<textarea id="b1" name="hua" cols="50" rows="5" placeholder="��˵�Ļ�">
		</textarea><br/>
		<input type="submit"value="������Ϣ"/></input>
	</form>
        <input type="button"  value="ˢ����Ϣ" onclick="test()"/></input>
    	<?php
		date_default_timezone_set('Etc/GMT-8');     //����������ʱ��
        $a=date("Y-m-d h:i:sa");
		$w=$a.$nn.':'.$_POST[hua];
        fun($w);
		?>
		</div>
	</div>
<p><font color="#EE82EE"><center>���ߺ�����</center></font></p>
</div>
<?php
function fun($word)
{
$filename = './aa.txt';
$fp = fopen($filename, 'a');
fwrite($fp, $word."\n"); 
fclose($fp); 
}
?>
</body>
</html>