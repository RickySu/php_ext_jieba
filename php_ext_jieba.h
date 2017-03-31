#ifndef _PHP_EXT_JIEBA_H
#define _PHP_EXT_JIEBA_H

#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif

#ifdef ZTS
    #warning php_ext_jieba module will *NEVER* be thread-safe
    #include <TSRM.h>
#endif

#include <php.h>
#include "common.h"

extern zend_module_entry php_ext_jieba_module_entry;

DECLARE_CLASS_ENTRY(Jieba);
#endif
