
<html>
    <head>
        <title>����������ע�����</title>
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
             <center><h1><strong><font color="#EE82EE">����������ע�����</font></strong></h1></center>
				<div class="a2">
				<form action="lianjieshujuku.php" method="post">
                �û���:<input type="text" name="name1" placeholder="�û���������д"/><br />
                ����:<input type="password" name="mima" placeholder="��Ҫ���"/><br />
                �Ա�:<input type="radio" name="sex">��
                <input type="radio" name="sex">Ů<br />
                �꼶:<select name="sel">
                    <option value="1">��һ</option>
                    <option value="2">���</option>
                    <option value="3">����</option>
                    <option value="4">����</option>
                </select><br />
               ����:
                <input type="checkbox" name="aihao[]" value="w"/>��Ϸ
                <input type="checkbox" name="aihao[]" value="d"/>����
                <input type="checkbox" name="aihao[]" value="c"/>����
                <input type="checkbox" name="aihao[]" value="p"/>����<br/>
                <textarea name="j" cols="50" rows="5"placeholder="����ǩ��(������40��)"></textarea><br/>
                <img id="i1" src="yanzhengma.php" />
                <input type="text" name="yan" placeholder="4λ��֤��"/><br />
                <button type="button" onclick="yan()">��һ��</button><br />
                <input type="submit" name="sub" value="�ύ" />
                <input type="reset" name="reset" value="����">
            </form>	
				</div>
                <p><font color="#EE82EE"><center>���ߺ�����</center></font></p>
            </div>
            
    </body>
</html>
