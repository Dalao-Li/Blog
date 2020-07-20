# 一、概念

> - 只有使用Innodb数据库引擎的数据库或表才支持事务
> - 事务处理可以用来维护数据库的完整性,保证SQL语句要么全执行,要么全不执行
> - 事务用来管理 INSERT、UPDATE、DELETE 语句

## 1.1 事务的特性

### 原子性(Atomic)

一个事务中的全部操作，要么全部都完成，要么全部不完成.事务在执行过程中发生错误,会被回滚(rollback)到事务开始前的状态

### 一致性(Consistency)

在事务开始之前和事务结束以后，数据库的完整性没有被破坏,表示写入的资料必须完全符合所有的预设规则，这包含资料的精确度、串联性以及后续数据库可以自发性地完成预定的工作

### 隔离性(Isolation)

隔离性可以防止多个事务并发执行时,由于交叉执行而导致对数据进行读写和修改产生不一致的情况.事务隔离分为不同级别,包括**读未提交**(Read uncommitted)、**读提交**(read committed)、**可重复读**(repeatable read)和**串行化**(Serializable)

### 持久性(Durability)

事务处理结束后，对数据的修改就是永久的

## 1.2 事务控制

> - 开始一个事务 : BEGIN 
> - 事务回滚 : ROLLBACK 
> - 事务确认 : COMMIT


# 二、实例

以操作Sqlite3为例



## 2.1 建立表
```sql
/*
 Navicat Premium Data Transfer

 Source Server         : demo
 Source Server Type    : SQLite
 Source Server Version : 3030001
 Source Schema         : main

 Target Server Type    : SQLite
 Target Server Version : 3030001
 File Encoding         : 65001

 Date: 12/07/2020 23:21:40
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for info
-- ----------------------------
DROP TABLE IF EXISTS "info";
CREATE TABLE "info" (
  "id" text NOT NULL,
  "name" text,
  PRIMARY KEY ("id")
);

PRAGMA foreign_keys = true;
```

## 2.2 提交事务

```sql
BEGIN;

INSERT INTO info (id,name) VALUES ('000A-X','WANG-LI');

COMMIT;
```
![](http://cdn.hurra.ltd/img/20200712233125.png)


## 2.3 回滚事务

1. 假设插入新用户,然后撤回的情况
```sql
BEGIN;

INSERT INTO info (id,name) VALUES ('000B-Y','QING-XU');

COMMIT;

BEGIN;

INSERT INTO info (id,name) VALUES ('000C-Z','SONG-LING');

ROLLBACK;
```

![](http://cdn.hurra.ltd/img/20200712235320.png)
可以看到第二条数据并未写入

2. 假设删除某用户,现要撤销删除的操作

```sql
BEGIN;

DELETE FROM info WHERE id = '000B-Y';

ROLLBACK;
```
![](http://cdn.hurra.ltd/img/20200713000345.png)
可以看到数据没有被删除

![](http://cdn.hurra.ltd/img/赞赏码.png)
