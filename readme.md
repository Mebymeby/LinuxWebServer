# LinuxWebServer
基于Linux和C++实现的高性能web-server服务器，webbench-1.5压力测试可达1.2wQPS

## 功能
1. 使用 IO 复用技术Epoll+非阻塞socket+线程池实现多线程Reactor高并发模型
2. 使用正则与状态机解析HTTP请求报文，实现处理静态资源的请求，支持get和post请求方式
3. 使用STL容器封装自动增长的buffer缓冲区，实现分散读/写HTTP请求数据
4. 使用基于小根堆实现的定时器管理客户端连接时间，用于调整连接时限、清除超时的非活动连接等
5. 使用基于阻塞队列实现的异步日志系统，用于记录服务器运行状态
6. 使用数据库连接池，减少服务器与数据库建立、关闭连接的开销，并保证线程安全

## 开发环境
* Ubuntu 18.4
* C++ 14
* MySql 5.7

## 目录树
```
.
├── bin            编译后的可执行文件
│   └── server
├── build          项目build包
│   └── Makefile
├── code           源码文件夹
│   ├── buffer     缓冲区
│   ├── http       http连接管理
│   ├── log        异步日志
│   ├── pool       线程池与数据库连接池
│   ├── server     服务器reactor
│   ├── timer      定时器
│   └── main.cpp   服务器入口
├── log            日志文件夹
├── resources      网页静态资源(参考他人开源项目)
│   ├── index.html
│   ├── image
│   ├── video
│   ├── js
│   └── css
├── test           单元测试
│   ├── Makefile
│   └── test.cpp
├── webbench-1.5   压力测试
├── Makefile
├── LICENSE
└── readme.md
```


## 项目启动
需要先配置好对应的数据库
```bash
// 建立yourdb库
create database yourdb;

// 创建user表
USE yourdb;
CREATE TABLE user(
    username char(50) NULL,
    password char(50) NULL
)ENGINE=InnoDB;

// 添加数据
INSERT INTO user(username, password) VALUES('name', 'password');
```

```bash
make
./bin/server
```

## 单元测试
```bash
cd test
make
./test
```

## 压力测试（本地回环，远程测试需要改变 IP:port）
```bash
./webbench-1.5/webbench -c 100 -t 10 http://127.0.0.1:1316/
./webbench-1.5/webbench -c 1000 -t 10 http://127.0.0.1:1316/
./webbench-1.5/webbench -c 5000 -t 10 http://127.0.0.1:1316/
./webbench-1.5/webbench -c 10000 -t 10 http://127.0.0.1:1316/
...
```