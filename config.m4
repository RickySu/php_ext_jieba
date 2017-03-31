PHP_ADD_INCLUDE("$srcdir/thirdparty/cppjieba/include")
PHP_ADD_INCLUDE("$srcdir/thirdparty/cppjieba/deps")

PHP_ARG_ENABLE(php_ext_jieba, whether to enable php_ext_jieba support,
Make sure that the comment is aligned:
[ --enable-php_ext_jieba Enable php_ext_jieba support])

if test "$PHP_PHP_EXT_JIEBA" != "no"; then

  MODULES="
      php_ext_jieba.c
      src/jieba.c
      src/cppjieba_bridge.cc
  "

  PHP_NEW_EXTENSION(php_ext_jieba, $MODULES, $ext_shared)  
fi

PHP_REQUIRE_CXX()

PHP_SUBST(PHP_EXT_JIEBA_SHARED_LIBADD)
