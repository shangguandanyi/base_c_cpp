Vim打开文件有**4种**方式

1. vim 文件路径 -- 打开指定的文件
2. vim +数字 文件路径 -- 打开指定文件，并移动光标到指定行
3. vim +/关键词 文件路径 -- 打开指定文件，并高亮显示关键词
4. vim 文件路径1 文件路径2 文件路径3 -- 同时打开多个文件

#### 命令模式

**光标移动操作**

| 快捷键             | 作用                             |
| ------------------ | -------------------------------- |
| shift+6 或 ^或home | 光标移动到行首                   |
| shift+4 或 $或end  | 光标移动到行尾                   |
| gg                 | 光标移动到首行，并且定位到首字符 |
| G                  | 光标移动到末行，并且定位到首字符 |
| Ctrl+b             | 向上翻屏                         |
| Ctrl+f             | 向下翻屏                         |
| 数字gg             | 表示快速跳到文件数字行行首字符   |

**复制操作**

| 快捷键      | 作用                                 |
| ----------- | ------------------------------------ |
| yy          | 复制光标所在行                       |
| p           | 光标所在行后面粘贴                   |
| 数字yy      | 以光标所在行为准，向下复制指定的行数 |
| Ctrl+v      | 可视块，方向键选中内容               |
| esc（两次） | 退出可视块                           |
| P           | 光标所在行前面粘贴                   |
| V           | 可视行，方向键选中内容               |
| y           | 复制可视内容，不能使用yy             |

**剪切/删除**

| 快捷键 | 作用                                               |
| ------ | -------------------------------------------------- |
| dd     | 剪切/删除光标所在行，下一行上移                    |
| 数字dd | 剪切/删除光标所在行向下剪切/删除指定行，下一行上移 |
| D      | 剪切/删除光标所在当前行，下一行不上移              |
| d^     | 从光标位置删至行首，不包括光标位                   |
| d$     | 从光标位置删至行尾，包括光标位，与D作用相同        |
| dG     | 删除光标所在行以及下面所有行                       |
| dgg    | 删除光标所在行以及上面所有行                       |
| x      | 删除光标所在字符后面的一个字符，3x代表删除3个字符  |
| X      | 删除光标所在字符前面的一个字符，3X代表删除3个字符  |

**撤销/恢复**

| 快捷键  | 作用           |
| ------- | -------------- |
| :u 或 u | 撤销           |
| ctrl+r  | 恢复之前的撤销 |

**光标的快速移动**

| 快捷键        | 作用                                |
| ------------- | ----------------------------------- |
| 数字G         | 快速将光标移动到指定的行数          |
| 数字↑ / 数字↓ | 以当前光标为准，向上或向下移动n行   |
| 数字← / 数字→ | 以当前光标为准，向左或向右移动n字符 |
| :数字 回车    | 末行模式下，移动到指定的行          |

#### 模式间的切换

| 快捷键                   | 作用                   |
| ------------------------ | ---------------------- |
| 按esc(按两下esc或删除：) | 从末行模式进入命令模式 |
| 按：                     | 从命令模式进入末行模式 |

#### 末行模式

| 快捷键   | 作用         |
| -------- | ------------ |
| :w       | 保存文件     |
| :w  路径 | 另存为       |
| :q       | 退出         |
| :wq      | 保存退出     |
| :q!      | 强制退出     |
| :! 命令  | 调用外部命令 |

**搜索**

| 快捷键             | 作用       |
| ------------------ | ---------- |
| 命令模式：/关键词  | 搜索/查找  |
| N                  | 查找上一个 |
| n                  | 查找下一个 |
| :nohl/:noh         | 取消高亮   |
| 末行模式：:/关键词 | 搜索/查找  |

**替换**

| 快捷键                      | 作用                               |
| --------------------------- | ---------------------------------- |
| :s/搜索的关键词/新的内容    | 替换光标所在行的第一处符合的字符串 |
| :s/搜索的关键词/新的内容/g  | 替换光标所在行的全部符合的字符串   |
| :%s/搜索的关键词/新的内容   | 替换所有行的第一处符合的字符串     |
| :%s/搜索的关键词/新的内容/g | 替换所有行的全部符合的字符串       |
| :%s#/sbin/nologin#aaa#g     | 替换特殊符号时自定义分隔符         |
| :%s/\/sbin\/nologin/aaa/g   | 替换特殊符号时加转义字符           |
| :7s/shutdown/SHUTDOWN/g     | 更换第7行的内容                    |

**显示行号**

| 快捷键           | 作用         |
| ---------------- | ------------ |
| :set num/:set nu | 显示行号     |
| :set nonu        | 取消行号显示 |

**末行模式其他功能**

```powershell
临时设置行号
:set number 或 :set nu
永久设置行号
echo "set number" >> /etc/vimrc

:set list 查看控制符

地址定位
:1,5 w /tmp/5.txt 保存前5行内容到/tmp/5.txt
:r /tmp/5.txt     在光标所在行下面读取/tmp/5.txt内容
:3r /tmp/5.txt    在当前文本的第3行后读取/tmp/5.txt内容
:1,8d			  删除文本的1到8行
:nr !command	  在第n行下面读取命令所执行的结果
:n! command		  用命令的执行结果替换第n行的内容
```



**VIM打开多个文件**

| 快捷键       | 作用                                                         |
| ------------ | ------------------------------------------------------------ |
| :files       | 查看当前已经打开的文件名称（%a：表示当前正在打开的文件，#：表示上一个打开的文件） |
| :open 文件名 | 打开指定的文件                                               |
| :bn          | 切换到下一个文件                                             |
| :bp          | 切换到上一个文件                                             |

#### 编辑模式

| 快捷键 | 作用                                                       |
| ------ | ---------------------------------------------------------- |
| i      | 在光标所在字符前开始插入                                   |
| a      | 在光标所在字符后开始插入                                   |
| o      | 在光标所在行的下面另起一新行插入                           |
| I      | 在光标所在行的行首开始插入，如果行首有空格则在空格之后插入 |
| A      | 在光标所在行的行尾开始插入                                 |
| O      | 在光标所在行的上面另起一新行插入                           |
| S      | 删除光标所在行并开始插入                                   |

**不建议使用小键盘**

#### 实用功能

**代码着色**

| 配置       | 作用       |
| ---------- | ---------- |
| syntax on  | 显示着色   |
| syntax off | 不显示着色 |

**VIM中计算器的使用**

在编辑文件时使用计算器

1. 进入编辑模式
2. 按下Ctrl+R
3. 输入=
4. 输入计算内容
5. 按下enter

**VIM的配置**

个人配置文件（~/.vimrc，没有需要创建，以个人配置为准）

全局配置文件（VIM自带，/etc/vimrc）

| 配置      | 作用     |
| --------- | -------- |
| set nu    | 显示行号 |
| syntax on | 显示着色 |

**异常退出**

在编辑文件之后，没有正常的保存退出

解决办法：删除交换文件（编辑过程中产生的临时文件）

**别名机制**

通过别名机制，创建自定义命令

依靠别名映射文件，**~/.bashrc**

`alias cls='clear'`

**退出方式**

vim中退出编辑的文件可以使用`:q`或者`:wq`

还可以使用`:x`



