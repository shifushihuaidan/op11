// JavaScript Document
function showsimple(){
	var conts = document.getElementById("searchtxt").value;
	if(conts!=""){
		open('searchrst.php?act=simple&conts='+conts,'_blank','width=660',false);
	}else{
		alert('查询关键字不能为空！');
		searchform.searchtxt.focus();
		return false;
	}
}
function openwin(){
	open('h_search.php','_blank','width=660',false);
}
function showhsearch(){
	var name= document.getElementById("name").value;
	var model= document.getElementById("model").value;
	var stype= document.getElementById("stype").value;
	if(name == '' && model == '' && stype == ''){
		alert("至少填写一项查询信息");
		return false;
	}
	url = 'searchrst.php?act=high&name='+name+"&model="+model+"&stype="+stype;
	open('searchrst.php?act=high&name='+name+"&model="+model+"&stype="+stype,'_self','width=660',false);
	/*xmlhttp.open("GET",url,true);
	xmlhttp.onreadystatechange = function(){
		if(xmlhttp.readyState == 4){
				var msg = xmlhttp.responseText;
				showme.innerHTML = msg;
			}
	}
	xmlhttp.send(null);*/
}