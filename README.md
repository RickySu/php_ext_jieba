# "結巴" 中文分詞 PHP Extention

這是一個基於 [cppjieba](https://github.com/yanyiwu/cppjieba) 的 PHP extension

功能
========
* 支持三種分詞模式：
* 1）精確模式，試圖將句子最精確地切開，適合文本分析；
* 2）全模式，把句子中所有的可以成詞的詞語都掃描出來，但是不能解決歧義。（需要充足的字典）
* 3) 搜尋引擎模式，在精確模式的基礎上，對長詞再次切分，提高召回率，適合用於搜尋引擎分詞。

編譯需求
========
    g++ (version >= 4.1 is recommended) or clang++;

使用方式
=======

```PHP
<?php
$jieba = new Jieba();
$result = $jieba->cut("他来到了网易杭研大厦", true); //精確模式，使用 hmm
print_r($result);

$bresult= $jieba->cutAll("他来到了网易杭研大厦");  //全模式
print_r($result);

$result = $jieba->cutForSearch("他来到了网易杭研大厦"); //搜尋引擎模式，預設不使用 hmm
print_r($result);
```
