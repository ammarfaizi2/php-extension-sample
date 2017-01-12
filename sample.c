#include "php_sample.h"

#include <zend_exceptions.h>

#define SAMPLE_NS "sample"

/*
  1. define the argument class by name

  validate with 'php -re sample'
*/
ZEND_BEGIN_ARG_INFO(ArgInfo_sample_test, 0)
    ZEND_ARG_OBJ_INFO(0, e, Exception, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(sample_test)
{
  zval *e;

  ZEND_PARSE_PARAMETERS_START(1, 1)
    /*
     2. Fetch the argument and provide the zend class entry for validation
     */
  	Z_PARAM_OBJECT_OF_CLASS(e, zend_ce_exception)
  ZEND_PARSE_PARAMETERS_END();

  php_printf("Argument is an Exception.\n");
}

const zend_function_entry php_sample_functions[] = {
  ZEND_NS_NAMED_FE(SAMPLE_NS, test, ZEND_FN(sample_test), ArgInfo_sample_test)
  PHP_FE_END
};

zend_module_entry sample_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_SAMPLE_EXTNAME,
  php_sample_functions, /* Functions */
  NULL, /* MINIT */
  NULL, /* MSHUTDOWN */
  NULL, /* RINIT */
  NULL, /* RSHUTDOWN */
  NULL, /* MINFO */
  PHP_SAMPLE_EXTVER,
  STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAMPLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(sample)
#endif
