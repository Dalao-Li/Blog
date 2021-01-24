# 一、问题描述

![](http://cdn.hurra.ltd/img/20200829232106.png)

当前为每行增加了一个 checkbox 控件,希望其动态生成"checkout+序号"的 id,方便后期对选择的行进行操作

# 二、实现过程

对 html 代码修改如下

```html
<td>
  <div class="checkbox">
    <label>
      <!-- {{i.id}}为后端传来的该行对应序号值-->
      <input type="checkbox" id="checkbox{{ i.id }}" />
    </label>
  </div>
</td>
```

此处为 jinja 模板,其他如 JSP 等等与此大同小异

# 三、实现效果

![](http://cdn.hurra.ltd/img/20200829232740.png)

![](http://cdn.hurra.ltd/img/收款码.png)
