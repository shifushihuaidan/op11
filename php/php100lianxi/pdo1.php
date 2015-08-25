<meta charset="UTF-8">
<?php 
$pdo=new PDO("mysql:host=localhost;dbname=op","root","root");
$sql="select * from aa";
$pdo->query("set names utf8");
$rs=$pdo->query($sql);
/*while($row=$rs->fetch())
{
    print_r($row);echo "<br/>";
}*/
echo "<hr>";
print_r($rs->fetchall());
?>