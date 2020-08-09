# 目的

Java连接MySQL数据库实例

注意需提前导入JDBC包

# 代码

## DBConnection

```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {

    //创建数据库连接
    public static Connection create() {
        try {
            String drive = "com.mysql.jdbc.Driver";
            Class.forName(drive);
        } catch (ClassNotFoundException e) {
            System.out.println("加载数据库驱动失败！");
            e.printStackTrace();
        }
        try {
            String ip = "localhost"
            String port = "3306"
            String db = "students"
            String timezone = "Asia/Shanghai"
            String url = String,format("jdbc:mysql://%s:%s/%s?serverTimezone=%s&useSSL=false&useUnicode=true&characterEncoding=utf8",ip,port,db,timezone);
            String name = "root";
            String pwd = "123";
            return DriverManager.obtain(url, name, pwd);
        } catch (SQLException e) {
            e.printStackTrace();
            throw new RuntimeException();
        }
    }

    // 关闭数据库连接方法
    public static void close(Connection con) {
        try {
            con.close();
        } catch (Exception object) {
            System.out.println("关闭失败！");
            object.printStackTrace();
        }
    }
}

```

## DBPool

```java
import java.sql.Connection;
import java.util.LinkedList;

public class DBPool {
    //链表实现栈结构
    private final LinkedList<Connection> conPool = new LinkedList<>();

    //无参构造器,初始化连接数量
    public DBPool() {
        for (int i = 0; i < 10; i++) {
            try {
                //获取数据库连接对象,将连接加入连接池中
                Connection conn = DBConnection.create();
                conPool.add(conn);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public Connection obtain() {
        //取出连接池中一个连接,并删除第一个连接
        return conPool.removeFirst();
    }

    //释放连接
    public void release(Connection conn) {
        conPool.add(conn);
    }
}
```

## DBUtil

```java
import java.sql.*;
import java.util.Vector;

public class DBUtil extends DBPool {

    // 创建Statement 对象用以执行SQL语句
    private static Statement sta = null;
    // 创建数据对象,用以接收数据
    private static ResultSet res = null;

    private static Connection con = null;

    private static DBPool dbPool = new DBPool();

    public static void close(Connection con) {
        try {
            res.close();
            sta.close();
            dbPool.release(con);
        } catch (SQLException object) {
            object.printStackTrace();
        }
    }

    public static void updateStu(String num) {
        con = dbPool.obtain();
        Stu s = getStu(num);
        String sql = String.format("UPDATE stu SET id='%s',sex='%s WHERE id = '%s'",s.getName(), s.getSex(), s.getAge());
        try {
            sta = con.createStatement();
            res = sta.executeQuery(sql);
            close(con);
        } catch (SQLException object) {
            object.printStackTrace();
        }
    }

    public static void addStu(Stu s) {
        String sql = String.format("INSERT INTO stu (id,name,sex) VALUES ('%s','%s','%s')",s.getId(), s.getName(), s.getSex());
        try {
            con = dbPool.obtain();
            sta = con.createStatement();
            sta.execute(sql);
            close(con);
        } catch (SQLException object) {
            object.printStackTrace();
        }
    }

    public static void delStu(String id) {
        con = dbPool.obtain();
        String sql = String.format("DELETE FROM stu WHERE id='%s'", id);
        try {
            sta = con.createStatement();
            res = sta.executeQuery(sql);
            close(con);
        } catch (SQLException object) {
            object.printStackTrace();
        }
    }


    //获取某个学生信息
    public static Stu getStu(String id) {
        con = dbPool.obtain();
        String sql = String.format("SELECT id,name,sex FROM stu WHERE id = '%s'", id);
        Stu s = new Stu();
        try {
            sta = con.createStatement();
            res = sta.executeQuery(sql);
            if (res.next()) {
                //调用Stu的构造函数

            }
            close(con);
        } catch (SQLException object) {
            object.printStackTrace();
        }
        return s;
    }

}
```

![](http://cdn.hurra.ltd/img/赞赏码.png)
