--TEST--
Call function with object (Exception) argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
$e = new Exception('Test');
sample\test($e);
?>
--EXPECT--
Argument is an Exception.
