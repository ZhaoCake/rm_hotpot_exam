# RM二轮考核——CPP部分试题思考题回答

data 和 operation 都不止能举例要求的100和4个，是否数据和操作都是可动态扩展修改的。
data可以在参数传入的参数部分进行修改，操作可以继续定义之后添加到函数vector中用函数指针调用。

关于改变传入data的参数，使用了命令行参数来做，比如

先假设编译命令为最简单的

```bash
g++ random_operations.cpp
```

那么生成的就是 `a.out`。

下面在后面加需要的数据个数即可

```bash
./a.out 32
```

结果为：

```
product: 85643.20
variance: 3.25
mean:   1.46
product: 85643.20
mean:   1.46
product: 85643.20
variance: 3.25
sum:    46.71
mean:   1.46
mean:   1.46
variance: 3.25
product: 85643.20
variance: 3.25
product: 85643.20
product: 85643.20
variance: 3.25
sum:    46.71
variance: 3.25
sum:    46.71
^C检测到ctrl+c退出!
```

等。

但由于我使用了时间作为生成随机数的随机数种子，所以同样的data个数结果不会相同。

这样做似乎结果就变得不可复现了，但是如果有复现需求的话，可以将使用的随机数种子即时间戳记录在日志文件里。题目没有这样的要求，故暂且不做。
