# 概念

- 定义: 外键另一表的主键,可重复,可为空,用于数据约束

> - 一个表中的 `FOREIGN KEY` 指向另一个表中的 `PRIMARY KEY`
> - `FOREIGN KEY` 约束用于预防破坏表之间连接的动作。
> - `FOREIGN KEY` 约束能防止`非法数据插入外键列`，因为外键必须是它指向的那个表中的值之一

# 实例

Stu表
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

Stu表
| **s_id**      | s_name |
| ------------- | ------ |
| 2017-XAB-3653 | 李五句 |
| 2017-XAB-3663 | 崔大机 |
| 2017-XAB-3669 | 武杀朱 |


Course表
| **c_id**  | c_name   |
| --------- | -------- |
| AV-170001 | 结构力学 |
| AV-275455 | 量子力学 |
| AV-999900 | 流体力学 |



Score表中的s_id列指向Stu表中的s_id列

Stu表中的s_id列是其`PRIMARY KEY`

Score表中的s_id列是Score表的`PRIMARY KEY`



Score表中的c_id列指向Course表中的c_id列

Course表中的c_id列是其`PRIMARY KEY`

Score表中的c_id列是Score表的`PRIMARY KEY`

若向Score表中插入一行数据,其中s_id,c_id值必须在Stu表,Course表中已经存在,否则会报错



# 演示

1. 向Score表中插入李五句的量子力学成绩97分

```sql
INSERT INTO Score (s_id,c_id,score) VALUES ('2017-XAB-3653','AV-275455',97);
```

![](http://cdn.hurra.ltd/img/20201005170211.png)

可以看到插入是没有问题的,因为这条语句中的s_id,c_id的值都在Stu与Course表中存在


2. 若现在李五句有门课编号为BV-000001,成绩为80分,现在尝试插入Score表中

![](http://cdn.hurra.ltd/img/20201005170512.png)

显示插入错误,因为c_id = BV-000001在其指向的Course表中不存在,产生了约束错误

3. 若现在有位同学编号为X-47-W,其量子力学成绩为80分,现在尝试插入Score表中

![](http://cdn.hurra.ltd/img/20201005170843.png)

同样显示因为外键约束错误,插入失败,因为s_id的值在Stu表中不存在

![](http://cdn.hurra.ltd/img/赞赏码.png)
