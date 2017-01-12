--TEST--
Call function with sample\SampleClass instance as argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
$o = new sample\SampleClass('Test');
sample\test($o);
?>
--EXPECT--
Argument is an sample\SampleClass.
