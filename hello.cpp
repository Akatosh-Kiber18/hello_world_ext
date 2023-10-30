#include "php_hello.h"

PHP_FUNCTION(hello_world) {
    php_printf("Hello, world!\n");
}

zend_module_entry hello_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_HELLO_EXT_NAME,
    NULL,         /* Functions */
    NULL,         /* MINIT */
    NULL,         /* MSHUTDOWN */
    NULL,         /* RINIT */
    NULL,         /* RSHUTDOWN */
    NULL,         /* MINFO */
    PHP_HELLO_EXT_VERSION,
    STANDARD_MODULE_PROPERTIES
};

static const zend_function_entry hello_functions[] = {
    PHP_FE(hello_world, NULL)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(hello) {
    return SUCCESS;
}

#ifdef COMPILE_DL_HELLO
ZEND_GET_MODULE(hello)
#endif
