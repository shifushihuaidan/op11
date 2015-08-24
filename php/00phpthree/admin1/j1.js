
	var cl=0;
	var t1=600;
	var bb=0;
	function open1(id)
	{
		if(bb)
			bb.style.visibility='hidden';
		bb=document.getElementById(id)
		bb.style.visibility='visible';
	}
	function close()
	{
		if(bb)
		bb.style.visibility='hidden';
	}
	function closetime()
	{
		cl = window.setTimeout(close, t1); 
	}
	function clodetime()
	{
		if(cl)
		{
			window.clearTimeout(cl);
			cl = 0;
		}
	}
	document.onclick=close;
	function st()
   {
		var to=new Date();
		var y=to.getFullYear();
		var m1=to.getMonth()+1;
        var d=to.getDate();
		var h=to.getHours();
		var m=to.getMinutes();
		var s=to.getSeconds();
		document.getElementById('b5').innerHTML
			=y+"Äê"+m1+"ÔÂ"+d+"ÈÕ"+
			h+":"+m+":"+s;
		t=setTimeout(st,500);
	}