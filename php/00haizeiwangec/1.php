<html>
<head>
<script type="text/javascript">
<!--
var ht=null;
function fun1(){
//1������ajax����XMLHttpResquest
    if(window.ActiveXObject)
	{
		ht=new ActiveXObject("Microsoft.XMLHTTP");//ie7���µ������
	}
	else 
	{
		ht=new XMLHttpRequest();
	}
    alert('��������1');
	var url="chkname.php?user=����"; 
	//alert(http_request.readyState);
    ht.onreadystatechange=function()
    {
		if(ht.readyState==4)
			{
				if(ht.status==200)
				{
				var res=ht.responseText;
				alert('���Ϊ'+res)
				}
			}
	}
   ht.open("GET",url,true);
   ht.send();
}

//-->
</script>
</head>
<body>
<div id="a1" class="">
	111222
</div>
<input type="button" onclick="fun1()" value="����">
</body>
</html>