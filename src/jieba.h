#ifndef _JIEBA_H
#define _JIEBA_H
#include "../php_ext_jieba.h"
#include "cppjieba_bridge.h"

CLASS_ENTRY_FUNCTION_D(Jieba);


ZEND_BEGIN_ARG_INFO(ARGINFO(Jieba, cut), 0)
ZEND_ARG_INFO(0, str)
ZEND_ARG_INFO(0, hmm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(ARGINFO(Jieba, cutForSearch), 0)
ZEND_ARG_INFO(0, str)
ZEND_ARG_INFO(0, hmm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(ARGINFO(Jieba, cutAll), 0)
ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

typedef struct {
    void *jieba_instance;
    zval object;
    zend_object zo;
} jieba_ext_t;

static zend_object *createJiebaResource(zend_class_entry *class_type);
void freeJiebaResource(zend_object *object);

PHP_METHOD(Jieba, __construct);
PHP_METHOD(Jieba, cut);
PHP_METHOD(Jieba, cutAll);
PHP_METHOD(Jieba, cutForSearch);

DECLARE_FUNCTION_ENTRY(Jieba) = {
    PHP_ME(Jieba, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(Jieba, cut, ARGINFO(Jieba, cut), ZEND_ACC_PUBLIC)
    PHP_ME(Jieba, cutAll, ARGINFO(Jieba, cutAll), ZEND_ACC_PUBLIC)
    PHP_ME(Jieba, cutForSearch, ARGINFO(Jieba, cutForSearch), ZEND_ACC_PUBLIC)
    PHP_FE_END
};

#endif
