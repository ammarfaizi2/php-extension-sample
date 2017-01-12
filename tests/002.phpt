--TEST--
Call function with optional argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
try {
  sample\test(new stdClass);
} catch (Error $e) {
  echo $e->getMessage();
}
?>
--EXPECT--
Argument 1 passed to sample\test() must be an instance of Exception, instance of stdClass given
