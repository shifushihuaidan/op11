// JavaScript Document
//删除确认
//**********************************************
var xmlHttp;
function createXmlHttpRequestObject(){
  if(window.ActiveXObject){
         try{
	        xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
	         }catch(e){
	                    xmlHttp=false;
			           }
 }else{
         try{
             xmlHttp= new XMLHttpRequest();
             }catch(e){
                        xmlHttp=false;
		               }
       }
  if(!xmlHttp)
         alert("return Object create Or Error Infomation");
  else
         return xmlHttp;
}

function del(form,id){
createXmlHttpRequestObject();
  if(!window.confirm('是否要删除数据??')){
		
	}else{
	var rd = id;
    var url = 'delcomms.php?rd='+rd;
    xmlHttp.open("GET",url,true);
    xmlHttp.setRequestHeader("Content-Type","application/x-www-form-urlencoded;");
    xmlHttp.onreadystatechange=SataHandler;
    xmlHttp.send(null);
    }
}

function SataHandler(){
 if(xmlHttp.readyState==4 && xmlHttp.status==200){
	  var msg= xmlHttp.responseText; 
	  if(msg!=1){
		       alert('删除失败'+msg);
		  }else{
		       alert('删除成功');
			   location=('showcommo.php');
			  }
  }
}

//************************************************
//全部选择/取消
function alldel(form){
	var leng = form.chk.length;
	if(leng==undefined){
	   if(!form.chk.checked)
	   		form.chk.checked=true;
	 }else{  
       for( var i = 0; i < leng; i++)
	    {
			if(!form.chk[i].checked)
	      		form.chk[i].checked = true;
	    }
	 } 
	return false;
}
// 反选
function overdel(form){
	 var leng = form.chk.length;
	 if(leng==undefined){
	   if(!form.chk.checked)
	   		form.chk.checked=true;
		else
			form.chk.checked=false;
	 }else{  
       for( var i = 0; i < leng; i++)
	    {
			if(!form.chk[i].checked)
	      		form.chk[i].checked = true;
			else
				form.chk[i].checked = false;
	    }
	 } 
	return false;
}
//修改
function modi(key){
	window.open('modifycommo.php?key='+key,'_blank','',false);
}