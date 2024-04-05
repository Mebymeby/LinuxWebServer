CFLAGS=-std=c++14 -O2 -Wall -g

TARGET=server
OBJS=$(wildcard ../code/*.cpp ../code/buffer/*.cpp ../code/http/*.cpp ../code/log/*.cpp ../code/pool/*.cpp ../code/server/*.cpp ../code/timer/*.cpp)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $^ -o ../bin/$@  -pthread -lmysqlclient

.PHONY:clean
clean:
	rm -rf ../bin/$(OBJS) $(TARGET)