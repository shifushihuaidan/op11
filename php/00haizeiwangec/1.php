<html>
<head>
<script type="text/javascript">
<!--
var ht=null;
function fun1(){
//1，创建ajax对象，XMLHttpResquest
    if(window.ActiveXObject)
	{
		ht=new ActiveXObject("Microsoft.XMLHTTP");//ie7以下的浏览器
	}
	else 
	{
		ht=new XMLHttpRequest();
	}
    alert('这里来了1');
	var url="chkname.php?user=张三"; 
	//alert(http_request.readyState);
    ht.onreadystatechange=function()
    {
		if(ht.readyState==4)
			{
				if(ht.status==200)
				{
				var res=ht.responseText;
				alert('结果为'+res)
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
<input type="button" onclick="fun1()" value="测试">
</body>
</html>