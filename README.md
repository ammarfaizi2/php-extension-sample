# php-extension-sample
PHP Extension Feature Samples

This repository is a collection of sample features for a php extension. 
Each branch implements a single feature. Basically I add my tests as branches 
as I am learning and experimenting.

The minimum version is PHP 7. I am not going to implement BC for older versions.

## class attach struct

Attach data to a Zend object using a struct. This is internal data an can not be seen from
the PHP userland unless exposed explicitly.
