# LinuxWebServer
基于Linux和C++实现的高性能web-server服务器，webbench-1.5压力测试，长短连接综合QPS约1.2w

## 功能
1. 并发模型：基于Reactor模型+线程池，实现One loop per thread，支持多客户端并发连接
2. 事件处理：利用Epoll实现 I/O 多路复用，高效监听和处理客户端连接
3. 内存优化：设计并实现了内存池和LFU缓存，减少内存碎片，提升内存使用效率
4. 动态缓冲：基于STL容器封装自增缓冲，实现分散读/写请求数据
5. 连接管理：基于小根堆实现高效定时器，管理客户端连接时限、清除超时连接
6. 异步日志：基于单例模式和阻塞队列，实现日志高效异步写入

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
