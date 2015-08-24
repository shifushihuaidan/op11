<?php
class bird {
	public $name;
	public function bird() {
		$this->name="Ñà×Ó";
	}
}
class niao extends bird {
	public $color;
	function niao() {
		bird ::bird();
		$this->color="ºÚÉ«";
	}
	function show() {
		echo $this->name;
		echo "<hr/>";
        echo $this->color;
	}
}
$a=new niao();
$a->show();
?>