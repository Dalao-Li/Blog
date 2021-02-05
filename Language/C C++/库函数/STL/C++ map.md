# 定义

```c
//定义一个map
template <class T,class V>

map<T,V> m;

//迭代器
map<T,V>::iterator it;
```

# 用法

## 添加

- 增加键值对 : **`insert(make_pair(<key>,<value>))`** 或者 **`m[<key>] = <value>`**

## 取值

- 取得键为 key 的对应值 : **`m[<key>]`**

## 查询

- 查找 key 是否存在 : **`iteraotr find(<key>)**`\*\* 若为 end()即不存在

## 删除

- 删除键为 key 的键值对 : **`erase(<key>)`**

## 遍历

```c
for(map<T,V>::iterator it=m.begin(); it!=m.end(); it++) {
	key  = it->first , value = it->second;
}

```

![](https://cdn.hurra.ltd/img/收款码.png)
