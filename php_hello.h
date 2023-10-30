#include <php.h>

#ifndef PHP_HELLO_H
#define PHP_HELLO_H 1

#define PHP_HELLO_EXT_NAME "hello"
#define PHP_HELLO_EXT_VERSION "1.0"

PHP_FUNCTION(hello_world);

extern zend_module_entry hello_module_entry;

#endif
