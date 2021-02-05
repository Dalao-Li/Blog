<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-17 18:20:42
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-05 11:25:13
-->


## UI 设计

运行 design 软件,建立 main.ui 文件

## PY 代码转换

使用 PyUIC 转换为 main.py

## 运行

新建 run.py 文件,内容为

```py
import sys

#PyQt5中使用的基本控件都在PyQt5.QtWidgets模块中
from PyQt5.QtWidgets import QApplication, QMainWindow

#导入designer工具生成的main模块
from main import Ui_MainWindow

class MyMainForm(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super(MyMainForm, self).__init__(parent)
        self.setupUi(self)

if __name__ == "__main__":

    # 固定的,PyQt5程序都需要QApplication对象.sys.argv是命令行参数列表,确保程序可以双击运行
    app = QApplication(sys.argv)
    # 初始化
    myWin = MyMainForm()
    # 将窗口控件显示在屏幕上
    myWin.show()
    # 程序运行,sys.exit方法确保程序完整退出.
    sys.exit(app.exec_())
```
