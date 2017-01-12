#include "php_sample.h"

#include <zend_exceptions.h>

#define SAMPLE_NS "sample"
#define SAMPLE_CLASS_NAME "SampleClass"

/*
 1. Here is no macro for classes in a namespace and they can not use constants. Let's define one.
*/
#define SAMPLE_ARG_OBJ_INFO_NS(pass_by_ref, name, ns, classname, allow_null) \
  { #name, ns "\\" classname, IS_OBJECT, pass_by_ref, allow_null, 0 },

static zend_class_entry *php_sample_class_entry;
const zend_function_entry php_sample_class_functions[] = {
  PHP_FE_END
};

ZEND_BEGIN_ARG_INFO(ArgInfo_sample_test, 0)
    /*
      2. use the new macro to provide the argument information
    */
    ZEND_ARG_OBJ_INFO_NS(0, e, SAMPLE_NS, SAMPLE_CLASS_NAME, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(sample_test)
{
  zval *e;

  ZEND_PARSE_PARAMETERS_START(1, 1)
    /*
      3. the ZPP API expects the zend class entry variable
    */
  	Z_PARAM_OBJECT_OF_CLASS(e, php_sample_class_entry)
  ZEND_PARSE_PARAMETERS_END();

  php_printf("Argument is an %s\\%s.\n", SAMPLE_NS, SAMPLE_CLASS_NAME);
}

const zend_function_entry php_sample_functions[] = {
  ZEND_NS_NAMED_FE(SAMPLE_NS, test, ZEND_FN(sample_test), ArgInfo_sample_test)
  PHP_FE_END
};

PHP_MINIT_FUNCTION(sample)
{
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(
      ce, SAMPLE_NS, SAMPLE_CLASS_NAME, php_sample_class_functions
    );
    php_sample_class_entry = zend_register_internal_class(&ce TSRMLS_CC);
}

zend_module_entry sample_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_SAMPLE_EXTNAME,
  php_sample_functions, /* Functions */
  PHP_MINIT(sample), /* MINIT */
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
