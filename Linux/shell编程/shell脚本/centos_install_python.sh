###
 # @Description: 
 # @Version: 1.0
 # @Author: Li Yuanhao
 # @Email: dalao_li@163.com
 # @Date: 2021-01-16 17:59:34
 # @LastEditors: Li Yuanhao
 # @LastEditTime: 2021-02-19 16:01:02
### 

#!/bin/sh

# 安装依赖
yum -y install gcc zlib* libffi-devel wget

wget https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tar.xz

tar -xvf Python-3.8.0.tar.xz -C /usr/bin

cd /usr/bin/Python-3.8.0

# 检测依赖;定位Python安装位置
./configure --prefix=/usr/bin/python3

# 编译安装
make && make install 

# 修改环境变量
sed -i "s#bin#bin:/usr/bin/python3/bin#g" ~/.bash_profile

# 执行以下命令使对配置的修改生效
source ~/.bash_profile

echo "Python 3.8.0 安装完成;重启后可正常使用"


