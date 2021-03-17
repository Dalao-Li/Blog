<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-08 11:18:17
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-17 00:25:44
-->

![](https://cdn.hurra.ltd/img/20210308111903.png)

## 安装
```sh
docker run -u root -itd \
  -p 8080:8080 \
  -p 50000:50000 \
  -v jenkins-data:/var/jenkins_home \
  -v /var/run/docker.sock:/var/run/docker.sock \
  jenkinsci/blueocean
```

![](https://cdn.hurra.ltd/img/20210308113221.png)

![](https://cdn.hurra.ltd/img/20210308113523.png)