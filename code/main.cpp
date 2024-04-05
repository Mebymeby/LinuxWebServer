#include <unistd.h>

#include "server/webserver.h"

int main() {
    WebServer server(1316,            // 服务器端口
                     3,               // 设置Epoll工作模式
                     60000,           // 客户端timeout，单位为ms
                     false,           // 优雅退出
                     3306,            // Mysql 端口
                     "root", "root",  // Mysql 用户名、密码
                     "webserver",     // Mysql 数据库名
                     16, 16,          // 数据库连接池、线程池 容量
                     true, 1, 1024);  // 日志开关、等级、异步队列容量

    server.Start();  // WebServer，启动！
}