#include "php_ext_jieba.h"

PHP_MINIT_FUNCTION(php_ext_jieba);
PHP_MSHUTDOWN_FUNCTION(php_ext_jieba);
PHP_MINFO_FUNCTION(php_ext_jieba);

zend_module_entry php_ext_jieba_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    "php_ext_jieba",
    NULL,
    PHP_MINIT(php_ext_jieba),
    PHP_MSHUTDOWN(php_ext_jieba),
    NULL,
    NULL,
    PHP_MINFO(php_ext_jieba),
#if ZEND_MODULE_API_NO >= 20010901
    "0.1",
#endif
    STANDARD_MODULE_PROPERTIES
};

#if COMPILE_DL_PHP_EXT_JIEBA
ZEND_GET_MODULE(php_ext_jieba)
#endif

PHP_MINIT_FUNCTION(php_ext_jieba) {
    CLASS_ENTRY_FUNCTION_C(Jieba);
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(php_ext_jieba) {
    return SUCCESS;
}

PHP_MINFO_FUNCTION(php_ext_jieba) {
    php_info_print_table_start();
    php_info_print_table_header(2, "php_ext_jieba support", "enabled");
    php_info_print_table_end();
}
