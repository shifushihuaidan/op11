<html>
<head>
<style type="text/css">
	.a1
	{
		width:300;
		height:300;
		/*border:1 solid red;*/
		margin:0 auto;
	}
	.a2
	{
		width:777;
		height:370;
		/*border:1 solid red;*/
		background-color:281C20;
		background-image:url(./image/4.jpg);
		background-repeat:no-repeat;
		background-attachment:fixed;
		background-position:center;
		color:blue;
	}
</style>
</head>
<body>
<div class="a2">
	<div class="a1">
	<form method="post" action="./index2.php?aa=������">
		���:<input type="text" name="r1"
		placeholder="����׼ȷ�����(����)"
		pattern="^-?[1-9]\d*$" required
		>
		<input type="submit" name="sub" value="��׼��ѯ">
		<br/><br/><br/><br/>
	</form>
	<form method="post" action="./index2.php?aa=������">
		����:<input type="text" name="r1"
		required
		placeholder="����ؼ��ּ���"
		>
		<input type="submit" name="sub" value="ģ����ѯ">
	</form>
</div>
</div>
</body>
</html>