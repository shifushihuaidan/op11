<?php
class bird {
	public $name;
	public function bird() {
		$this->name="����";
	}
}
class niao extends bird {
	public $color;
	function niao() {
		bird ::bird();
		$this->color="��ɫ";
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