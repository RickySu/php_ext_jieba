#include "jieba.h"

CLASS_ENTRY_FUNCTION_D(Jieba){
    REGISTER_CLASS_WITH_OBJECT_NEW(Jieba, createJiebaResource);
    OBJECT_HANDLER(Jieba).offset = XtOffsetOf(jieba_ext_t, zo);
    OBJECT_HANDLER(Jieba).clone_obj = NULL;
    OBJECT_HANDLER(Jieba).free_obj = freeJiebaResource;
}

static zend_object *createJiebaResource(zend_class_entry *ce) {
    jieba_ext_t *resource;
    resource = ALLOC_RESOURCE(jieba_ext_t);
    zend_object_std_init(&resource->zo, ce);
    object_properties_init(&resource->zo, ce);
    resource->zo.handlers = &OBJECT_HANDLER(Jieba);
    return &resource->zo;
}

static convertArray(zval *array, char **result){
    int i = 0;
    while(result[i] != NULL){
        add_next_index_string(array, result[i]);
        efree(result[i]);
        i++;
    }
    efree(result);
}

void freeJiebaResource(zend_object *object) {
    jieba_ext_t *resource;
    resource = FETCH_RESOURCE(object, jieba_ext_t);
    if(resource->jieba_instance){
        jieba_free(resource->jieba_instance);
    }
    zend_object_std_dtor(&resource->zo);
    efree(resource);
}

PHP_METHOD(Jieba, __construct) {
    jieba_ext_t *resource;
    zval *self = getThis();
    resource = FETCH_OBJECT_RESOURCE(self, jieba_ext_t);
    const char *dictPath, *hmmPath, *userDictPath, *idfPath, *stopWordPath;
    const char *c_dictPath, *c_hmmPath, *c_userDictPath, *c_idfPath, *c_stopWordPath;
    size_t dictPath_len, hmmPath_len, userDictPath_len, idfPath_len, stopWordPath_len;

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS(), "sssss", 
            &dictPath, &dictPath_len,
            &hmmPath, &hmmPath_len,
            &userDictPath, &userDictPath_len,
            &idfPath, &idfPath_len,
            &stopWordPath, &stopWordPath_len
        )){
        return;
    }

    MAKE_C_STR(c_dictPath, dictPath, dictPath_len);
    MAKE_C_STR(c_hmmPath, hmmPath, hmmPath_len);
    MAKE_C_STR(c_userDictPath, userDictPath, userDictPath_len);
    MAKE_C_STR(c_idfPath, idfPath, idfPath_len);
    MAKE_C_STR(c_stopWordPath, stopWordPath, stopWordPath_len);
    resource->jieba_instance = jieba_new(c_dictPath, c_hmmPath, c_userDictPath, c_idfPath, c_stopWordPath);
    efree(c_dictPath);
    efree(c_hmmPath);
    efree(c_userDictPath);
    efree(c_idfPath);
    efree(c_stopWordPath);
}

PHP_METHOD(Jieba, cut) {
    jieba_ext_t *resource;
    char **result;
    zval *self = getThis();
    const char *str = NULL;
    size_t str_len;
    zval result_arr;
    int hmm = 0;
    
    resource = FETCH_OBJECT_RESOURCE(self, jieba_ext_t);

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS(), "s|b", &str, &str_len, &hmm)){
        return;
    }
    
    if(str_len == 0){
        RETURN_FALSE;
    }
    
    array_init(&result_arr);
    
    convertArray(&result_arr, jieba_cut(resource->jieba_instance, str, str_len, hmm));

    RETURN_ZVAL(&result_arr, 0, 0);
}

PHP_METHOD(Jieba, cutAll) {
    jieba_ext_t *resource;
    char **result;
    zval *self = getThis();
    const char *str = NULL;
    size_t str_len;    
    zval result_arr;
    
    resource = FETCH_OBJECT_RESOURCE(self, jieba_ext_t);

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS(), "s", &str, &str_len)){
        return;
    }
    
    if(str_len == 0){
        RETURN_FALSE;
    }
    
    array_init(&result_arr);
    
    convertArray(&result_arr, jieba_cut_all(resource->jieba_instance, str, str_len));

    RETURN_ZVAL(&result_arr, 0, 0);
}


PHP_METHOD(Jieba, cutForSearch) {
    jieba_ext_t *resource;
    char **result;
    zval *self = getThis();
    const char *str = NULL;
    size_t str_len;    
    zval result_arr;
    int hmm = 0;
    
    resource = FETCH_OBJECT_RESOURCE(self, jieba_ext_t);

    if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS(), "s|b", &str, &str_len, &hmm)){
        return;
    }
    
    if(str_len == 0){
        RETURN_FALSE;
    }
    
    array_init(&result_arr);
    
    convertArray(&result_arr, jieba_cut_for_search(resource->jieba_instance, str, str_len, hmm));

    RETURN_ZVAL(&result_arr, 0, 0);
}
