<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-10 10:19:22
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-10 11:00:15
-->

## 位置

> /var/log/secure


很多linux的新发行版已经不再使用,改为使用rsyslog.配置目录 /etc/rsyslog.d

## 含义

     
| 月份 | 日期 | 时分秒   | 服务器主机 | 程序(sshd或则su) | 模块                   | 详细信息                                |
| ---- | ---- | -------- | ---------- | ---------------- | ---------------------- | --------------------------------------- |
| Mar  | 10   | 10:51:44 | localhost  | sshd[10616]      | pam_unix(sshd:session) | session opened for user root by (uid=0) |


## 登录

```ini
Mar 10 10:51:44 localhost sshd[10616]: Accepted publickey for root from 192.168.43.231 port 52131 ssh2: RSA SHA256:D2xE2Ju/pNEVJBTGjYCb+kZb+TwclJjxsQFJcfTCnZ4
Mar 10 10:51:44 localhost sshd[10616]: pam_unix(sshd:session): session opened for user root by (uid=0)
```

## 登出

```ini
Mar 10 10:52:12 localhost sshd[10616]: Received disconnect from 192.168.43.231 port 52131:11: disconnected by user
Mar 10 10:52:12 localhost sshd[10616]: Disconnected from 192.168.43.231 port 52131
Mar 10 10:52:12 localhost sshd[10616]: pam_unix(sshd:session): session closed for user root
```

## 切换用户

```ini
Mar 10 10:53:56 localhost su: pam_unix(su:session): session opened for user dalao by (uid=0)
```

## 提示输入密码时取消

```ini
Mar 10 10:53:56 localhost sshd[19046]: Received disconnect from 192.168.43.231: 13: The user canceled authentication.
```

## 密码输入错误

```ini
Aug  8 02:33:28 imzcy sshd[19125]: pam_unix(sshd:auth): authentication failure; logname= uid=0 euid=0 tty=ssh ruser= rhost=192.168.217.10  user=root
Aug  8 02:33:31 imzcy sshd[19125]: Failed password for root from 192.168.217.10 port 57994 ssh2
```



## 密码错误次数太多

```ini
Aug  8 02:33:28 imzcy sshd[19125]: pam_unix(sshd:auth): authentication failure; logname= uid=0 euid=0 tty=ssh ruser= rhost=192.168.217.10  user=root
Aug  8 02:33:31 imzcy sshd[19125]: Failed password for root from 192.168.217.10 port 57994 ssh2
Aug  8 02:34:06 imzcy last message repeated 3 times
Aug  8 02:34:13 imzcy last message repeated 2 times
Aug  8 02:34:47 imzcy sshd[19126]: Disconnecting: Too many authentication failures for root
Aug  8 02:34:47 imzcy sshd[19125]: Failed password for root from 192.168.217.10 port 57994 ssh2
Aug  8 02:34:47 imzcy sshd[19125]: PAM 6 more authentication failures; logname= uid=0 euid=0 tty=ssh ruser= rhost=192.168.217.10  user=root
Aug  8 02:34:47 imzcy sshd[19125]: PAM service(sshd) ignoring max retries; 7 > 3
```