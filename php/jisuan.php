<?php 
if(isset($_POST['de']))
{
$a=$_POST['a'];
$a1=$_POST['b'];
$a2=$_POST['op'];
echo "被加数".$b."<br/>";
echo "加数".$a."<br/>";
switch($a2)
{
   case "+":$c=$a+$a1;
}
echo $c;
echo "<br/>";
}
?>

<html>
    <head>
        <title>海贼王</title>
    </head>
    <body>
            <form action="" method="post">
                <input type="text" name="a" placeholder="用户名随意填写"/><br />
                <input type="mima" name="b" /><br />
               <select name="op">
                    <option value="+">+</option>
                    <option value="-">-</option>
                    <option value="*">*</option>
                    <option value="/">/</option>
                </select><br />
                <input type="submit" name="de" value="等于" />
                <input type="text" name="jg" value="<?php echo $c?>">
            </form>
    </body>
</html>
