**xargs**

1. 给命令传递参数的一个过滤器，也是组合多个命令的一个工具
2. 可以将管道或标准输入（stdin）数据转换成命令行参数，也能够从文件的输出中读取数据
3. 也可以将单行或多行文本输入转换为其他格式，例如多行变单行，单行变多行
4. 默认的命令是 echo，这意味着通过管道传递给 xargs 的输入将会包含换行和空白，不过通过 xargs 的处理，换行和空白将被空格取代
5. 是一个强有力的命令，它能够捕获一个命令的输出，然后传递给另外一个命令

之所以能用到这个命令，关键是由于很多命令(find、rm、mkdir、ls)不支持|管道来传递参数，而日常工作中有这个必要，所以就有了 xargs 命令，例如：

```powershell
find /sbin -perm +700 |ls -l       #这个命令是错误的
find /sbin -perm +700 |xargs ls -l   #这样才是正确的

echo "one two three" | xargs mkdir # 等同于mkdir one two three
```

**xargs**后面的命令默认是**echo**

```powershell
$ xargs
# 等同于
$ xargs echo
```

**xargs 一般是和管道一起使用**

**命令格式**

`somecommand | xargs [-options] [command]`

| 参数                      | 说明                                                         |
| ------------------------- | ------------------------------------------------------------ |
| -a file                   | 从文件中读入作为 stdin                                       |
| -e flag                   | 注意有的时候可能会是-E，flag必须是一个以空格分隔的标志，当xargs分析到含有flag这个标志的时候就停止 |
| -p                        | 当每次执行一个argument的时候询问一次用户                     |
| -n num 后面加次数         | 表示命令在执行的时候一次用的argument的个数，默认是用所有的   |
| -t                        | 表示先打印命令，然后再执行                                   |
| -i 或者是-I               | 这得看linux支持了，将xargs的每项名称，一般是一行一行赋值给 {}，可以用 {} 代替 |
| -r no-run-if-empty        | 当xargs的输入为空的时候则停止xargs，不用再去执行了           |
| -s num 命令行的最大字符数 | 指的是 xargs 后面那个命令的最大命令行字符数                  |
| -L num                    | 从标准输入一次读取 num 行送给 command 命令                   |
| -d delim 分隔符           | 默认的xargs分隔符是回车，argument的分隔符是空格，这里修改的是xargs的分隔符 |
| -x                        | exit的意思，主要是配合-s使用                                 |
| -P 修改最大的进程数       | 默认是1                                                      |

**实例**

```powershell
xargs 用作替换工具，读取输入数据重新格式化后输出

# 将标准输入转为命令行参数
echo "hello world" | xargs echo # hello world

# 定义一个测试文件，内有多行文本数据，多行输入单行输出
cat test.txt | xargs # a b c d e f g h i j k l m n o p q r s t u v w x y z

# -n参数指定每次将多少项，作为命令行参数
xargs -n 1 find -name

# 每两个参数运行一次echo命令
echo {0..9} | xargs -n 2 echo

# -n 选项多行输出
cat test.txt | xargs -n3

# -d参数更改分隔符 -e参数表示解释转义字符
 echo -e "a\tb\tc" | xargs -d "\t" echo # abc

# -d 选项可以自定义一个定界符
echo "nameXnameXnameXname" | xargs -dX # name name name name

# 结合 -n 选项使用
echo "nameXnameXnameXname" | xargs -dX -n2

# -p参数打印出要执行的命令，询问用户是否要执行
echo 'one two three' | xargs -p touch # touch one two three ?...

# -t参数打印出最终要执行的命令，然后直接执行，不需要用户确认
echo 'one two three' | xargs -t rm # rm one two three

读取 stdin，将格式化后的参数传递给命令
# 假设一个命令为 sk.sh 和一个保存参数的文件 arg.txt
# !/bin/bash
# sk.sh命令内容，打印出所有参数。
echo $*
# arg.txt文件内容
cat arg.txt 
# aaa
# bbb
# ccc
# args的一个选项-I，使用-I指定一个替换字符串{}，这个字符串在xargs扩展时会被替换掉，当-I与xargs结合使用，每一个参数命令都会被执行一次
cat arg.txt | xargs -I {} ./sk.sh -p {} -l
# -p aaa -l
# -p bbb -l
# -p ccc -l

# 复制所有图片文件到 /data/images 目录下
ls *.jpg | xargs -n1 -I {} cp {} /data/images

-I指定每一项命令行参数的替代字符串
cat foo.txt | xargs -I file sh -c 'echo file; mkdir file' # 输出并创建目录foo.txt里的内容

xargs 结合 find 使用
# 由于xargs默认将空格作为分隔符，所以不太适合处理文件名，因为文件名可能包含空格。
# find命令有一个特别的参数-print0，指定输出的文件列表以null分隔。然后，xargs命令的-0参数表示用null当作分隔符。
find /path -type f -print0 | xargs -0 rm # 删除/path路径下的所有文件

# 用rm删除太多的文件时候，可能得到一个错误信息：/bin/rm Argument list too long. 用xargs去避免这个问题
find . -type f -name "*.log" -print0 | xargs -0 rm -f

# 找出所有TXT文件以后，对每个文件搜索一次是否包含字符串abc
find . -name "*.txt" | xargs grep "abc"

# 查找所有的jpg文件，并且压缩它们
find . -type f -name "*.jpg" -print | xargs tar -czvf images.tar.gz

# 如果标准输入包含多行，-L参数指定多少行作为一个命令行参数
xargs -L 1 find -name

# 每行运行一次echo命令，所以echo命令执行了三次
echo -e "a\nb\nc" | xargs -L 1 echo
```