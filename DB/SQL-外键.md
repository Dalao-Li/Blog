# 概念

外键是另一表的主键,可重复,可为空,用于数据约束

> - 一个表中的 `FOREIGN KEY` 指向另一个表中的 `PRIMARY KEY`
> - `FOREIGN KEY` 约束用于预防破坏表之间连接的动作。
> - `FOREIGN KEY` 约束能防止`非法数据插入外键列`，因为外键必须是它指向的那个表中的值之一

# 实例

Stu 表

```sql
CREATE TABLE `Stu`  (
  `s_id` varchar(255)  NOT NULL,
  `s_name` varchar(255) ,
  PRIMARY KEY (`s_id`) USING BTREE
);
```

```sql
CREATE TABLE `Course`  (
  `c_id` varchar(255)  NOT NULL,
  `c_name` varchar(255) ,
  PRIMARY KEY (`c_id`) USING BTREE
);
```

```sql
CREATE TABLE `Score`  (
  `r_id` int(0) NOT NULL AUTO_INCREMENT,
  `s_id` varchar(255),
  `c_id` varchar(255),
  `score` int(0),
  PRIMARY KEY (`r_id`) USING BTREE,
  INDEX `s_id`(`s_id`) USING BTREE,
  INDEX `c_id`(`c_id`) USING BTREE,
  CONSTRAINT `c_id` FOREIGN KEY (`c_id`) REFERENCES `Course` (`c_id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `s_id` FOREIGN KEY (`s_id`) REFERENCES `Stu` (`s_id`) ON DELETE RESTRICT ON UPDATE RESTRICT
);
```

数据

Stu 表
| **s_id** | s_name |
| ------------- | ------ |
| 2017-XAB-3653 | 李五句 |
| 2017-XAB-3663 | 崔大机 |
| 2017-XAB-3669 | 武杀朱 |

Course 表
| **c_id** | c_name |
| --------- | -------- |
| AV-170001 | 结构力学 |
| AV-275455 | 量子力学 |
| AV-999900 | 流体力学 |

Score 表中的 s_id 列指向 Stu 表中的 s_id 列

Stu 表中的 s_id 列是其`PRIMARY KEY`

Score 表中的 s_id 列是 Score 表的`PRIMARY KEY`

Score 表中的 c_id 列指向 Course 表中的 c_id 列

Course 表中的 c_id 列是其`PRIMARY KEY`

Score 表中的 c_id 列是 Score 表的`PRIMARY KEY`

若向 Score 表中插入一行数据,其中 s_id,c_id 值必须在 Stu 表,Course 表中已经存在,否则会报错

# 演示

1. 向 Score 表中插入李五句的量子力学成绩 97 分

```sql
INSERT INTO Score (s_id,c_id,score) VALUES ('2017-XAB-3653','AV-275455',97);
```

![](http://cdn.hurra.ltd/img/20201005170211.png)

可以看到插入是没有问题的,因为这条语句中的 s_id,c_id 的值都在 Stu 与 Course 表中存在

2. 若现在李五句有门课编号为 BV-000001,成绩为 80 分,现在尝试插入 Score 表中

![](http://cdn.hurra.ltd/img/20201005170512.png)

显示插入错误,因为 c_id = BV-000001 在其指向的 Course 表中不存在,产生了约束错误

3. 若现在有位同学编号为 X-47-W,其量子力学成绩为 80 分,现在尝试插入 Score 表中

![](http://cdn.hurra.ltd/img/20201005170843.png)

同样显示因为外键约束错误,插入失败,因为 s_id 的值在 Stu 表中不存在

![](http://cdn.hurra.ltd/img/收款码.png)
