
<html>
    <head>
        <title>海贼王聊天注册界面</title>
    <script>
     function yan()
     {
      document.getElementById("i1").src="yanzhengma.php";
     }
    </script>
	<style type="text/css">
		.a1
	{
    width:100%;
	height:100%;
    background-image:url(./image/121.jpg);
	}
	.a2
	{
	background-image:url(./image/44.jpg);
	//background-position:-730px -430px;
	width:60%;
	height:70%;
	margin:30 auto;
    color:#3399ff;
	}
	</style>
    </head>
    <body>
            <div class="a1">
             <center><h1><strong><font color="#EE82EE">海贼王聊天注册界面</font></strong></h1></center>
				<div class="a2">
				<form action="lianjieshujuku.php" method="post">
                用户名:<input type="text" name="name1" placeholder="用户名随意填写"/><br />
                密码:<input type="password" name="mima" placeholder="不要填汉子"/><br />
                性别:<input type="radio" name="sex">男
                <input type="radio" name="sex">女<br />
                年级:<select name="sel">
                    <option value="1">大一</option>
                    <option value="2">大二</option>
                    <option value="3">大三</option>
                    <option value="4">大四</option>
                </select><br />
               爱好:
                <input type="checkbox" name="aihao[]" value="w"/>游戏
                <input type="checkbox" name="aihao[]" value="d"/>漫画
                <input type="checkbox" name="aihao[]" value="c"/>动漫
                <input type="checkbox" name="aihao[]" value="p"/>其他<br/>
                <textarea name="j" cols="50" rows="5"placeholder="个人签名(不超过40字)"></textarea><br/>
                <img id="i1" src="yanzhengma.php" />
                <input type="text" name="yan" placeholder="4位验证码"/><br />
                <button type="button" onclick="yan()">换一张</button><br />
                <input type="submit" name="sub" value="提交" />
                <input type="reset" name="reset" value="重置">
            </form>	
				</div>
                <p><font color="#EE82EE"><center>作者海贼王</center></font></p>
            </div>
            
    </body>
</html>
