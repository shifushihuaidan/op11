<?php
session_start();
?>
<html>
    <head>
        <meta http-equiv="Content-Type"
        content="text/html; charset=utf-8" /> 
       <style>
           .a1
           {
               border:1 solid red;
               width: 500;
               height: 200;
               margin:20 auto;
           }
       </style> 
    </head>
    <body>
        <div class="a1">
            <form action="" method="post">
                用户名:<input type="text"
                name="uname" required
                placeholder="用户名"
                /><br/>
                密码:<input type="password"
                name="umima" required
                placeholder="密码"
                /><br/>
                验证码:<input type="text" 
                name="yanzhengma"
                />
                <img src="yanzhengma.php" 
                id="i1" 
                onclick="this.src='yanzhengma.php?'
                +Math.random()"
                />
                <label onclick="
                document.getElementById('i1').
                src='yanzhengma.php?'
                +new Date().getTime()"
                >看不清换一张</label>
                <br />
                <input type="submit" name="sub"
                value="登陆"/>
                <input type="reset"/>
            </form>
        </div>
    </body>
</html>
<?php
if(isset($_POST['sub']))
{
	if($_POST['yanzhengma']==$_SESSION['yzm'])
	{
		echo "登陆成功";
	}
	else
	{
		echo "登陆失败";
	}
}
?>