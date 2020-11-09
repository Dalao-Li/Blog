# 一、Map 接口

- Map 是一种键-值对(key-value)集合,其中键对象不允许重复.
- 基本操作有:添加 key-value 键值对"、“获取 key"、“获取 value"、“获取 map 大小"、“清空 map"等基本的 key-value 键值对操作.
- Map 是一个接口不能实例化.
- Map 接口主要有两个实现类：HashMap 类和 TreeMap 类.
- HashMap 类按哈希算法来存取键对象;TreeMap 类可以对键对象进行排序.

# 二、示例

```java
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        Map<Integer, String> m1 = new HashMap<>();
        Map<Integer, String> m2 = new TreeMap<>();

        String[] name = {"Lili", "Len", "Xu"};
        int[] age = {30, 23, 15};

        for(int i = 0 ; i<3;i++){
            m1.put(age[i],name[i]);
            m2.put(age[i],name[i]);
        }
        System.out.println(m1);
        System.out.println(m2);
    }
}
```

![](http://cdn.hurra.ltd/img/20201029201748.png)

# 三、操作

## 遍历

```java
......

for (Map.Entry<Integer, String> entry : m1.entrySet()) {
    int key = entry.getKey();
    String value = entry.getValue();
    System.out.println(key + " "+ value);
}
```

![](http://cdn.hurra.ltd/img/20201029202252.png)

![](http://cdn.hurra.ltd/img/收款码.png)
