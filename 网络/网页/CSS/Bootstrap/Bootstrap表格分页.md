- [技术](#技术)
- [效果](#效果)
- [一、过程](#一过程)
  - [1.1 前端](#11-前端)
  - [1.2 后端代码](#12-后端代码)

# 技术

> 前端 : Bootstrap + JQuery + SweetAlert2  
> Web 框架 : Flask

# 效果

![](https://cdn.hurra.ltd/img/20200708224302.png)

<center>每页显示一定量数据</center>

![](https://cdn.hurra.ltd/img/20200708224344.png)

![](https://cdn.hurra.ltd/img/20200708224537.png)

<center>按关键字显示数据</center>

![](https://cdn.hurra.ltd/img/20200708234616.png)

<center>点击表格后显示被点击行的信息</center>

# 一、过程

## 1.1 前端

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <title></title>
    <link
      rel="stylesheet"
      href="https://cdn.staticfile.org/twitter-bootstrap/4.3.1/css/bootstrap.min.css"
    />
    <script src="https://cdn.staticfile.org/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://cdn.staticfile.org/popper.js/1.15.0/umd/popper.min.js"></script>
    <script src="https://cdn.staticfile.org/twitter-bootstrap/4.3.1/js/bootstrap.min.js"></script>
    <link
      rel="stylesheet"
      type="text/css"
      href="https://www.huangwx.cn/css/sweetalert.css"
    />
    <script
      type="text/javascript"
      src="https://www.huangwx.cn/js/sweetalert-dev.js"
    ></script>
    <!-- Latest compiled and minified CSS -->
    <link
      rel="stylesheet"
      href="https://unpkg.com/bootstrap-table@1.16.0/dist/bootstrap-table.min.css"
    />
    <!-- Latest compiled and minified JavaScript -->
    <script src="https://unpkg.com/bootstrap-table@1.16.0/dist/bootstrap-table.min.js"></script>
    <!-- Latest compiled and minified Locales -->
    <script src="https://unpkg.com/bootstrap-table@1.16.0/dist/locale/bootstrap-table-zh-CN.min.js"></script>
  </head>
  <body>
    <div style="text-align: center;">
      <h2>Bootstrap表格分页示例</h2>
    </div>

    <table class="table table-hover" id="demoTable">
      <thead>
        <tr>
          <th>学号</th>
          <th>姓名</th>
          <th>年龄</th>
          <th>性别</th>
        </tr>
      </thead>
      <tbody>
        {% for i in data %}
        <tr>
          <td>{{ i.num }}</td>
          <td>{{ i.name }}</td>
          <td>{{ i.age }}</td>
          <td>{{ i.sex }}</td>
        </tr>
        {% endfor %}
      </tbody>
    </table>
  </body>
  <script>
    //实现表格分页
    $("#demoTable").bootstrapTable({
      //点击行事件,element为被点击行的tr元素对象
      onClickRow: function (row, $element) {
        $element.each(function () {
          //获取所有td的值
          var tds = $(this).find("td");
          var num = tds.eq(0).text();
          var name = tds.eq(1).text();
          var age = tds.eq(2).text();
          var sex = tds.eq(3).text();
          swal({
            title: "用户信息",
            text: "学号:" + num + "  姓名:" + name,
            type: "info",
          });
        });
      },
      //首页页码
      pageNumber: 1,
      //是否显示分页条
      pagination: true,
      //一页显示的行数
      pageSize: 5,
      //是否开启分页条无限循环
      paginationLoop: false,
      //选择每页显示多少行
      pageList: [5, 10, 20],
      //启用关键字搜索框
      search: true,
    });
  </script>
</html>
```

## 1.2 后端代码

```py
from flask import Flask, render_template

app = Flask(__name__)


class Stu:
    def __init__(self, num, name, age, sex):
        self.num = num
        self.name = name
        self.age = age
        self.sex = sex

# 生成测试数据
def creat_data():
    data = []
    data.append(Stu('100001', '王某某', 18, '男'))
    data.append(Stu('100002', '李某某', 18, '男'))
    data.append(Stu('100003', '许某某', 18, '男'))
    data.append(Stu('100004', '林某某', 18, '男'))
    data.append(Stu('100005', '刘某某', 19, '男'))
    data.append(Stu('100006', '陈某某', 20, '女'))
    data.append(Stu('100007', '曲某某', 17, '男'))
    data.append(Stu('100008', '周某某', 18, '男'))
    data.append(Stu('100009', '欧某某', 17, '女'))
    data.append(Stu('100010', '钟某某', 18, '男'))
    data.append(Stu('100011', '楚某某', 18, '男'))
    data.append(Stu('100012', '王某某', 18, '女'))
    data.append(Stu('100013', '宋某某', 18, '男'))
    data.append(Stu('100014', '江某某', 18, '男'))
    data.append(Stu('100015', '秦某某', 18, '男'))
    data.append(Stu('100016', '史某某', 19, '男'))
    data.append(Stu('100017', '泰某某', 18, '女'))
    data.append(Stu('100018', '程某某', 16, '男'))
    data.append(Stu('100019', '毛某某', 16, '男'))
    data.append(Stu('100020', '赵某某', 19, '男'))
    data.append(Stu('100021', '钱某某', 18, '男'))
    data.append(Stu('100022', '孙某某', 18, '女'))
    data.append(Stu('100023', '武某某', 20, '男'))
    data.append(Stu('100024', '崔某某', 18, '男'))
    data.append(Stu('100025', '康某某', 18, '女'))
    data.append(Stu('100026', '郑某某', 18, '女'))
    data.append(Stu('100027', '邓某某', 22, '男'))
    data.append(Stu('100028', '江某某', 23, '男'))
    data.append(Stu('100029', '王某某', 18, '男'))
    data.append(Stu('100038', '王某某', 18, '男'))
    return data


@app.route('/')
def hello_world():
    data = creat_data()
    return render_template('index.html', data=data)


if __name__ == '__main__':
    app.run()
```

![](https://cdn.hurra.ltd/img/收款码.png)
