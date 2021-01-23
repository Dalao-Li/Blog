# 概念

- Pipfile 文件是 TOML （什么是 toml 格式中文）格式而不是 requirements.txt 这样的纯文本。

- 一个项目对应一个 Pipfile，支持开发环境与正式环境区分。默认提供 default 和 development 区分。
  提
- 供版本锁支持，存为 Pipfile.lock

# 创建

```sh
pipenv install
```

若项目中有 requirements.txt 文件,则生成对应内容的 Pipfile 文件与 Pipfile.lock 文件

# 内容

```sh
# 库安装源
[[source]]
url = "https://pypi.python.org/simple"
verify_ssl = true
name = "pypi"

# 用于开发环境的包
[dev-packages]
watchdog = "*"
faker = "*"

# 运行程序需要的包
[packages]
bootstrap-flask = "*"
flask-moment = "*"
flask-sqlalchemy = "*"
python-dotenv = "*"
flask-wtf = "*"
flask = "*"

# python版本
[requires]
python_version = "3.6"
```

# 实例

- 全部安装  
  进入 demo 目录,创建虚拟环境

![](http://cdn.hurra.ltd/img/20210122224056.png)

打开 Pipfile 文件,修改为

```sh
[[source]]
url = "http://mirrors.aliyun.com/pypi/simple/"
verify_ssl = true
name = "pypi"

[packages]
flask = "*"


[dev-packages]
gunicorn = "*"

[requires]
python_version = "3.8"
```

安装,查看安装的包
![](http://cdn.hurra.ltd/img/20210122224537.png)

可以看到 Flask 包已经安装

---

- 部分安装

安装开发环境下的包： 通常有一些 Python 包只在你的开发环境中需要，而不是在生产环境中，例如单元测试包。 Pipenv 使用--dev 标志区分两个环境。 加 --dev 表示包括 Pipfile 的 dev-packages 中的依赖

> 安装包记录是在[dev-packages] 部分，或是[packages] 部分。  
> 在安装时，指定`--dev`参数，则只安装[dev-packages]下的包；若安装时不定指定--dev 参数，只会安装[packages] 包下面的模块。

另建立文件夹 demo2,内建立 Pipfile 文件

```sh
[[source]]
url = "http://mirrors.aliyun.com/pypi/simple/"
verify_ssl = true
name = "pypi"

[packages]
jieba = "*"

[dev-packages]
faker = "*"

[requires]
python_version = "3.8"

```

若输入 pipenv install 则只会安装[packages] 下的包

![](http://cdn.hurra.ltd/img/20210123141415.png)

若输入 pipenv install --dev 则安装项目的所有依赖项(包括dev)

![](http://cdn.hurra.ltd/img/20210123141743.png)
