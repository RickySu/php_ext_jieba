#include "cppjieba_bridge.h"

using namespace std;

const char* const DICT_PATH = "./dict/jieba.dict.utf8";
const char* const HMM_PATH = "./dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "./dict/user.dict.utf8";
const char* const IDF_PATH = "./dict/idf.utf8";
const char* const STOP_WORD_PATH = "./dict/stop_words.utf8";

static inline char **buildResult(vector<string> words){
    char **result;
    result = (char **) ecalloc(words.size()+1, sizeof(char *));
    for(unsigned i = 0; i < words.size(); i++  ){
        result[i] = (char *) ecalloc(1, words[i].length() + 1);
        words[i].copy(result[i], words[i].length());
    }
    return result;
}

void * jieba_new() {
    cppjieba::Jieba *jieba;
    jieba = new cppjieba::Jieba(
        DICT_PATH,
        HMM_PATH,
        USER_DICT_PATH,
        IDF_PATH,
        STOP_WORD_PATH
    );
    return (void *) jieba;
}

void jieba_free(void *jieba_instance) {
    cppjieba::Jieba *jieba = (cppjieba::Jieba *) jieba_instance;
    delete jieba;
}

char **jieba_cut(void *jieba_instance, const char *str, size_t len, int hmm) {
    vector<string> words;
    cppjieba::Jieba *jieba = (cppjieba::Jieba *) jieba_instance;
    string s;
    s.append(str, len);
    jieba->Cut(s, words, hmm == 1);
    return buildResult(words);
}

char **jieba_cut_all(void *jieba_instance, const char *str, size_t len) {
    vector<string> words;
    cppjieba::Jieba *jieba = (cppjieba::Jieba *) jieba_instance;
    string s;
    s.append(str, len);
    jieba->CutAll(s, words);
    return buildResult(words);
}

char **jieba_cut_for_search(void *jieba_instance, const char *str, size_t len, int hmm) {
    vector<string> words;
    cppjieba::Jieba *jieba = (cppjieba::Jieba *) jieba_instance;
    string s;
    s.append(str, len);
    jieba->CutForSearch(s, words, hmm == 1);
    return buildResult(words);
}
