--TEST--
Call function with optional argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
$e = new Exception('Test');
sample\test($e);
?>
--EXPECT--
Argument is an Exception.
