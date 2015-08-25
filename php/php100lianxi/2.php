<?php
if(isset($_POST['sub']))
{
    print_r($_FILES['file1']);
    echo "<hr>";
    $file=$_FILES['file1'];
    $name=$file['name'];
    $tmp_name=$file['tmp_name'];
    //echo $file;
    if (move_uploaded_file($tmp_name,'up/'.$name))
    {
        echo "上传成功";
    }
}
?>
<html>
    <head>
        <meta charset="UTF-8" />
    </head>
    <body>
        <form action="" method="post"
        enctype="multipart/form-data"
        >
           <input type="file" name="file1"/>
           <input type="submit" value="上传"
           name="sub"/> 
        </form>
    </body>
</html>