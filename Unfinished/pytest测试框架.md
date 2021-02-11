# Pytest框架


## 安装
```shell
pip install pytest


pip install pytest-html
```


## 测试用例代码


建立test_demo.py文件
```py

'''
Description: 
Version: 1.0
Author: Li Yuanhao
Email: dalao_li@163.com
Date: 2021-02-03 22:57:16
LastEditors: Li Yuanhao
LastEditTime: 2021-02-03 22:58:56
'''

class test_fun:
    def test_func_1(self):
        print('测试用例1')
        assert 1 == 1

    def test_func_2(self):
        print('测试用例2')
        assert 2 == 2

    def test_func_3(self):
        print('测试用例3')
        assert 1 == 3
```