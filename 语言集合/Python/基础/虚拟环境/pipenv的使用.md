<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-22 21:58:02
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-31 22:09:10
-->

# Pipenv概念

Python 依赖管理工具,pip 和 virtualenv 的组合体,基于 Pipfile 的依赖记录方式,用于替代 requirements.txt.

pipenv 会自动管理虚拟环境和依赖文件,并且提供一系列命令和选项来实现各种依赖和环境管理相关的操作.它更方便、完善和安全.

# 安装

```sh
pip install pipenv
```

# 命令

## 创建

```shell
pipenv install
```

- 若项目目录中虚拟环境未创建且无 Pipfile 文件,将安装虚拟环境并创建 Pipfile 文件

- 若项目目录中虚拟环境未创建且有 Pipfile 文件,将根据 Pipfile 文件来安装相应 python 版本和依赖包

- 若项目目录中虚拟环境已创建且有 Pipfile 文件,将根据 Pipfile 文件来安装依赖包

使用 pipenv 创建虚拟环境,自动生成一个`随机的`虚拟环境目录名

如果在 `windows 系统`下执行命令,生成的虚拟环境在 C:\Users\用户名\.virtualenvs 文件夹下.

虚拟环境目录名的前缀是创建环境时所在的项目目录名,如在 myblog 目录下执行命令,虚拟环境的目录名称就是 myblog-<随机字符串>

## 进入

```shell
pipenv shell
```

## 安装

```shell
pipenv install requests
```

不管是否激活虚拟环境,都可以执行 pipenv install 库名来安装.

- 查看已经安装模块

```
pipenv graph
```

## 卸载

```
pipenv uninstall requests
```

- 全部卸载

```sh
pipenv uninstall --all
```

## 显示目录信息 即路径

```sh
pipenv --venv
```

## 显示虚拟环境的信息

```sh
pipenv --where
```

## 通过 requirements.text 安装模块

```
pipenv install -r requirements.txt
```
