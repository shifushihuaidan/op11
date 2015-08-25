<?php
    include_once("smarty/Smarty.class.php");
    $smt=new Smarty();
    $smt->caching=FALSE;
    $smt->config_dir="smarty/Config_File.class.php";
    $smt->template_dir="./templates";
    $smt->cache_dir="./cache";
    $smt->compile_dir="./compile";
    
    $smt->left_delimiter="{";
    $smt->right_delimiter="}";
?>