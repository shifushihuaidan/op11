<?php /* Smarty version 2.6.28, created on 2014-12-27 06:16:10
         compiled from forminfo.tpl */ ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo $this->_tpl_vars['title']; ?>
</title>
<link rel="stylesheet" href="../../css/table.css" />
<link rel="stylesheet" href="css/table.css" />
</head>
<body>
  <?php unset($this->_sections['for_id']);
$this->_sections['for_id']['name'] = 'for_id';
$this->_sections['for_id']['loop'] = is_array($_loop=$this->_tpl_vars['formarr']) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
$this->_sections['for_id']['show'] = true;
$this->_sections['for_id']['max'] = $this->_sections['for_id']['loop'];
$this->_sections['for_id']['step'] = 1;
$this->_sections['for_id']['start'] = $this->_sections['for_id']['step'] > 0 ? 0 : $this->_sections['for_id']['loop']-1;
if ($this->_sections['for_id']['show']) {
    $this->_sections['for_id']['total'] = $this->_sections['for_id']['loop'];
    if ($this->_sections['for_id']['total'] == 0)
        $this->_sections['for_id']['show'] = false;
} else
    $this->_sections['for_id']['total'] = 0;
if ($this->_sections['for_id']['show']):

            for ($this->_sections['for_id']['index'] = $this->_sections['for_id']['start'], $this->_sections['for_id']['iteration'] = 1;
                 $this->_sections['for_id']['iteration'] <= $this->_sections['for_id']['total'];
                 $this->_sections['for_id']['index'] += $this->_sections['for_id']['step'], $this->_sections['for_id']['iteration']++):
$this->_sections['for_id']['rownum'] = $this->_sections['for_id']['iteration'];
$this->_sections['for_id']['index_prev'] = $this->_sections['for_id']['index'] - $this->_sections['for_id']['step'];
$this->_sections['for_id']['index_next'] = $this->_sections['for_id']['index'] + $this->_sections['for_id']['step'];
$this->_sections['for_id']['first']      = ($this->_sections['for_id']['iteration'] == 1);
$this->_sections['for_id']['last']       = ($this->_sections['for_id']['iteration'] == $this->_sections['for_id']['total']);
?>
<table width="400" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td height="25" colspan="4" align="center" valign="middle" class="first">订单查看 </td>
  </tr>

  <tr>
    <td width="75" height="25" align="center" valign="middle" class="left">订单号：</td>
    <td height="25" align="left" valign="middle" class="right"><?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['formid']; ?>
</td>
    <td height="25" align="center" valign="middle" class="right">订单时间：</td>
    <td height="25" align="left" valign="middle" class="right"><?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['formtime']; ?>
</td>
  </tr>
  
  <tr>
    <td width="75" height="25" align="center" valign="middle" class="left">下单人：</td>
    <td width="125" height="25" class="center"><?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['vendee']; ?>
</td>
    <td width="75" height="25" align="center" valign="middle" class="center">收货人：</td>
    <td width="125" height="25" class="right"><?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['taker']; ?>
</td>
  </tr>
  <tr align="center" valign="middle">
    <td width="75" height="25" class="left">邮编：</td>
    <td width="125" height="25" align="left" class="center"><?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['code']; ?>
</td>
    <td width="75" height="25" align="center" valign="middle" class="center">电话：</td>
    <td width="125" height="25" align="left" class="right"><?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['tel']; ?>
</td>
  </tr>
  <tr align="center" valign="middle">
    <td width="75" height="25" class="left">地址：</td>
    <td height="25" colspan="3" align="left" class="right"><?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['address']; ?>
</td>
  </tr>
  <tr align="center" valign="middle">
    <td width="75" height="25" class="left">送货方式：</td>
    <td width="125" height="25" align="left" class="center"><?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['del_method']; ?>
</td>
    <td width="75" height="25" align="center" valign="middle" class="center">付款方式：</td>
    <td width="125" height="25" align="left" class="right"><?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['pay_method']; ?>
</td>
  </tr>
</table>



<p>&nbsp;</p>
<table width="500" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td height="30" colspan="5" align="center" valign="middle" class="first">订单内容</td>
  </tr>
  <tr>
    <td width="100" height="25" align="center" valign="middle" class="left">商品名</td>
    <td width="100" height="25" align="center" valign="middle" class="center">数量</td>
    <td width="100" height="25" align="center" valign="middle" class="center">价格</td>
    <td width="100" height="25" align="center" valign="middle" class="center">价格折率</td>
    <td width="100" height="25" align="center" valign="middle" class="right">合计</td>
  </tr>
  <tr>
<?php $_from = $this->_tpl_vars['commname']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['key'] => $this->_tpl_vars['item']):
?>
    <td height="25" align="center" valign="middle" class="left"><?php echo $this->_tpl_vars['item']; ?>
</td>
    <td height="25" align="center" valign="middle" class="center"><?php echo $this->_tpl_vars['commnumber'][$this->_tpl_vars['key']]; ?>
</td>
    <td height="25" align="center" valign="middle" class="center"><?php echo $this->_tpl_vars['commagoprice'][$this->_tpl_vars['key']]; ?>
&nbsp;元</td>
    <td align="center" valign="middle" class="center"><?php echo $this->_tpl_vars['commfold'][$this->_tpl_vars['key']]; ?>
&nbsp;折</td>
    <td align="center" valign="middle" class="right"><?php echo $this->_tpl_vars['commagoprice'][$this->_tpl_vars['key']]*$this->_tpl_vars['commnumber'][$this->_tpl_vars['key']]; ?>
&nbsp;元</td>
  </tr>
<?php endforeach; endif; unset($_from); ?>
<tr>
	<td colspan="5" height="25" align="right" valign="middle">总消费：<?php echo $this->_tpl_vars['formarr'][$this->_sections['for_id']['index']]['total']; ?>
&nbsp;元</td>
</tr>
</table>
  <?php endfor; endif; ?>
<p>&nbsp;</p>

</body>
</html>