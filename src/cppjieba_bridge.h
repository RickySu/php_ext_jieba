#ifndef _CPP_JIEBA_BRIDGE_H
#define _CPP_JIEBA_BRIDGE_H
#include "../php_ext_jieba.h"

#ifdef __cplusplus
#include <cppjieba/Jieba.hpp>
extern "C" {
#endif

void *jieba_new();
void jieba_free(void *jieba_instance);
char **jieba_cut(void *jieba_instance, const char *str, size_t len, int hmm);
char **jieba_cut_all(void *jieba_instance, const char *str, size_t len);
char **jieba_cut_for_search(void *jieba_instance, const char *str, size_t len, int hmm);
#ifdef __cplusplus
}
#endif

#endif
