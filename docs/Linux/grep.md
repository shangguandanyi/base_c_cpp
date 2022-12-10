**grep**

用于查找文件里符合条件的字符串

```powershell
# 语法
grep [-abcEFGhHilLnqrsvVwxy][-A<显示行数>][-B<显示列数>][-C<显示列数>][-d<进行动作>][-e<范本样式>][-f<范本文件>][--help][范本样式][文件或目录...]
```

| 参数                                              | 说明                                                         |
| ------------------------------------------------- | ------------------------------------------------------------ |
| -a 或 --text                                      | 不要忽略二进制的数据。                                       |
| -A<显示行数> 或 --after-context=<显示行数>        | 除了显示符合范本样式的那一列之外，并显示该行之后的内容。     |
| -b 或 --byte-offset                               | 在显示符合样式的那一行之前，标示出该行第一个字符的编号。     |
| -B<显示行数> 或 --before-context=<显示行数>       | 除了显示符合样式的那一行之外，并显示该行之前的内容。         |
| -c 或 --count                                     | 计算符合样式的列数。                                         |
| -C<显示行数> 或 --context=<显示行数>或-<显示行数> | 除了显示符合样式的那一行之外，并显示该行之前后的内容。       |
| -d <动作> 或 --directories=<动作>                 | 当指定要查找的是目录而非文件时，必须使用这项参数，否则grep指令将回报信息并停止动作。 |
| -e<范本样式> 或 --regexp=<范本样式>               | 指定字符串做为查找文件内容的样式。                           |
| -E 或 --extended-regexp                           | 将样式为延伸的正则表达式来使用。                             |
| -f<规则文件> 或 --file=<规则文件>                 | 指定规则文件，其内容含有一个或多个规则样式，让grep查找符合规则条件的文件内容，格式为每行一个规则样式。 |
| -F 或 --fixed-regexp                              | 将样式视为固定字符串的列表。                                 |
| -G 或 --basic-regexp                              | 将样式视为普通的表示法来使用。                               |
| -h 或 --no-filename                               | 在显示符合样式的那一行之前，不标示该行所属的文件名称。       |
| -H 或 --with-filename                             | 在显示符合样式的那一行之前，表示该行所属的文件名称。         |
| -i 或 --ignore-case                               | 忽略字符大小写的差别。                                       |
| -l 或 --file-with-matches                         | 列出文件内容符合指定的样式的文件名称。                       |
| -L 或 --files-without-match                       | 列出文件内容不符合指定的样式的文件名称。                     |
| -n 或 --line-number                               | 在显示符合样式的那一行之前，标示出该行的列数编号。           |
| -o 或 --only-matching                             | 只显示匹配PATTERN 部分。                                     |
| -q 或 --quiet或--silent                           | 不显示任何信息。                                             |
| -r 或 --recursive | 此参数的效果和指定"-d recurse"参数相同。 |
| -s 或 --no-messages | 不显示错误信息。 |
| -v 或 --invert-match | 显示不包含匹配文本的所有行。 |
| -V 或 --version | 显示版本信息。 |
| -w 或 --word-regexp | 只显示全字符合的列。 |
| -x --line-regexp | 只显示全列符合的列。 |
| -y | 此参数的效果和指定"-i"参数相同。 |

**grep常用用法**

```shell
[root@www ~]# grep [-acinv] [--color=auto] '搜寻字符串' filename
选项与参数：
-a ：将 binary 文件以 text 文件的方式搜寻数据
-c ：计算找到 '搜寻字符串' 的次数
-i ：忽略大小写的不同，所以大小写视为相同
-n ：顺便输出行号
-v ：反向选择，亦即显示出没有 '搜寻字符串' 内容的那一行！
--color=auto ：可以将找到的关键词部分加上颜色的显示喔！
```
**grep 可以使用 --color=auto 来将关键字部分使用颜色显示，可以在 ~/.bashrc 内加上这行：『alias grep='grep --color=auto'』再以『 source ~/.bashrc 』来立即生效即可**

**Linux 里利用 grep 和 find 命令查找文件内容**

```powershell
从文件内容查找与正则表达式匹配的行
grep –e "正则表达式" 文件名

查找时不区分大小写
grep –i "被查找的字符串" 文件名

查找匹配的行数
grep -c "被查找的字符串" 文件名

从根目录开始查找所有扩展名为 .log 的文本文件，并找出包含 "ERROR" 的行
find / -type f -name "*.log" | xargs grep "ERROR"

从当前目录开始查找所有扩展名为 .in 的文本文件，并找出包含 "thermcontact" 的行
find . -name "*.in" | xargs grep "thermcontact"
```

**实例**

```powershell
从文件内容查找匹配指定字符串的行
grep "被查找的字符串" 文件名

# 在当前目录中，查找后缀有 file 字样的文件中包含 test 字符串的文件，并打印出该字符串的行
grep test *file 

# 将/etc/passwd，有出现 root 的行取出来
grep root /etc/passwd
或
cat /etc/passwd | grep root

在当前目录里第一级文件夹中寻找包含指定字符串的 .in 文件
grep "thermcontact" /.in

以递归的方式查找符合条件的文件
# 查找指定目录/etc/acpi 及其子目录（如果存在子目录的话）下所有文件中包含字符串"update"的文件，并打印出该字符串所在行的内容
grep -r update /etc/acpi

# 在当前目录搜索带'energywise'行的文件
grep 'energywise' *

# 在当前目录及其子目录下搜索'energywise'行的文件
grep -r 'energywise' *

# 在当前目录及其子目录下搜索'energywise'行的文件，但是不显示匹配的行，只显示匹配的文件
grep -l -r 'energywise' * 

从文件内容查找不匹配指定字符串的行
grep –v "被查找的字符串" 文件名

# 查找文件名中包含 test 的文件中不包含test 的行
grep -v test *test*

# 将/etc/passwd，将没有出现 root 的行取出来
grep -v root /etc/passwd

# 将/etc/passwd，将没有出现 root 和nologin的行取出来
grep -v root /etc/passwd | grep -v nologin

查看符合条件的行及行号
grep -n '2019-10-24 00:01:11' *.log

# 将/etc/passwd，有出现 root 的行取出来,同时显示这些行在/etc/passwd的行号
grep -n root /etc/passwd

```

**grep与正规表达式**

```powershell
字符类
# [] 里面不论有几个字节，都代表某『一个』字节
grep -n 't[ae]st' regular_express.txt // test 或 tast

# 字符类的反向选择 [^] ：如果想要搜索到有 oo 的行，但不想要 oo 前面有 g
grep -n '[^g]oo' regular_express.txt

#  oo 前面不要小写字节
grep -n '[^a-z]oo' regular_express.txt

# 取得有数字的那一行
grep -n '[0-9]' regular_express.txt

行首与行尾字节 ^ $
# 行首字符：如果我想要让 the 只在行首列出
grep -n '^the' regular_express.txt

# 列出开头是小写字节的那一行
grep -n '^[a-z]' regular_express.txt

# 不想要开头是英文字母
grep -n '^[^a-zA-Z]' regular_express.txt
^ 符号，在字符类符号(括号[])之内与之外是不同的！ 在 [] 内代表『反向选择』，在 [] 之外则代表定位在行首的意义！

# 行尾结束为小数点 (.) 的那一行
grep -n '\.$' regular_express.txt
小数点具有其他意义，必须要使用转义字符

# 找出空白行
grep -n '^$' regular_express.txt

任意一个字节 . 与重复字节 *
. (小数点)：代表『一定有一个任意字节』的意思；
* (星号)：代表『重复前一个字符， 0 到无穷多次』的意思，为组合形态

# 找出 g??d 的字串，亦即共有四个字节， 起头是 g 而结束是 d
grep -n 'g..d' regular_express.txt

# 列出至少要有两个(含) o 以上
grep -n 'ooo*' regular_express.txt
因为 * 代表的是『重复 0 个或多个前面的 RE 字符』的意义， 因此，『o*』代表的是：『拥有空字节或一个 o 以上的字节』

# 字串开头与结尾都是 g，但是两个 g 之间仅能存在至少一个 o ，亦即是 gog, goog, gooog.... 等等
grep -n 'goo*g' regular_express.txt

# 如果我想要找出 g 开头与 g 结尾的行，当中的字符可有可无
grep -n 'g.*g' regular_express.txt

# 找出『任意数字』的行
grep -n '[0-9][0-9]*' regular_express.txt

限定连续 RE 字符范围 {}
可以限制一个范围区间内的重复字节数
因为 { 与 } 的符号在 shell 是有特殊意义的，因此， 我们必须要使用字符  \ 

# 找到两个o的字串
grep -n 'o\{2\}' regular_express.txt

# 找出g后面接2到5个o ，然后再接一个g的字串
 grep -n 'go\{2,5\}g' regular_express.txt
 
 # 2个o以上的 goooo....g，除了可以是gooo*g，也可以是
 grep -n 'go\{2,\}g' regular_express.txt
 
 扩展grep(grep -E 或者 egrep)，增加了额外的正则表达式元字符集
 
 # 打印所有包含NW或EA的行
 egrep 'NW|EA' testfile
 
 # 对于标准grep，如果在扩展元字符前面加\，grep会自动启用扩展选项-E
 grep 'NW\|EA' testfile
 
 # 搜索所有包含一个或多个3的行
 egrep '3+' testfile
 grep -E '3+' testfile
 grep '3\+' testfile 
 
 # 搜索所有包含0个或1个小数点字符的行
 egrep '2\.?[0-9]' testfile 
 grep -E '2\.?[0-9]' testfile
 grep '2\.\?[0-9]' testfile 
 首先含有2字符，其后紧跟着0个或1个点，后面再是0和9之间的数字。

# 搜索一个或者多个连续的no的行
 egrep '(no)+' testfile
 grep -E '(no)+' testfile
 grep '\(no\)\+' testfile
 
不使用正则表达式
fgrep 查询速度比grep命令快，但是不够灵活；它只能找固定的文本，而不是规则表达式。

# 在一个文件或者输出中找到包含星号字符的行
fgrep  '*' /etc/profile
for i in /etc/profile.d/*.sh ; do
或
grep -F '*' /etc/profile
for i in /etc/profile.d/*.sh ; do
```