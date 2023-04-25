# 简单命令

pwd：显示当前所在目录

ls：显示当前目录下的文件		-l：显示详细信息		-a：显示隐藏文件

cd：切换路径（cd ..返回上一路径）

mkdir：新建目录

rmdir：删除目录

touch：新建文件或更新文件修改时间

cp：复制文件		-r：递归复制所有文件		-f：强制覆盖

rm：删除文件		-r：递归，一般用于删除文件		-f：强制删除不询问是否确定

cat：将文件内容显示到终端，可以显示多个

clear：清除屏幕的显示内容

## 文件属性

<img src="Com_pictrue/image-20230406143439229.png" alt="image-20230406143439229" style="zoom:67%;" />

文件的权限

<img src="Com_pictrue/image-20230406090818501.png" alt="image-20230406090818501" style="zoom:80%;" />

-：表示常规文件

第一个rwx：拥有者的权限，r表示可读，w表示可写，x表示可执行

第二个rwx：同组的其他用户的权限

最后三位：其他用户的权限

可以使用chmod更改权限，可读可写可执行为7，上述图片例子为755

<img src="Com_pictrue/image-20230406091516899.png" alt="image-20230406091516899" style="zoom:67%;" />

chgrp：改变文件所属用户组

chown：改变文件所有者

chmod：改变文件的权限

chmod*改变文件的权限*

文件权限有两种设置方法：数字类型改变权限和符号改变权限。

1. **数字类型改变权限**

首先说明各个权限对应的数字：

① r: 4 或 0

② w: 2 或 0

③ x: 1 或 0

这 3 种权限的取值相加后，就是权限的数字表示。例如：文件 a 的权限为“-rwxrwx---”，它的数值表示为：

① owner = rwx = 4+2+1 = 7

② group = rwx = 4+2+1 = 7

③ others = --- = 0+0 +0 = 0

所以在设置权限时，该文件的权限数字就是 770。使用数值改变文件权限的命令如下：

chmod [-R] xyz 文件或目录

① xyz ： 代表权限的数值，如 770。

② -R ： 以递归方式进行修改，比如修改某个目录下所有文件的属性。

范例：

chmod 777 .bashrc

将文件.bashrc 这个文件的所有权限设置都启用。

2) **符号类型改变文件权限方式**

使用 u、g、o 三个字母代表 user、group、others 3 中身份。此外 a 代表 all，即所有身份。

范例：

chmod u=rwx,go=rx .bashrc

也可以增加或去除某种权限，“+”表示添加权限，“-”表示去除权限：

chmod a+w .bashrc

chmod a-x .bashrc

## find命令	

find 目录名 选项 查找条件 	例子：$find /home/learn -name hello.c

/home/learn表示查找路径	-name表示以名字查找路径	hello.c表示查找的文件名

## grep命令

作用为查找文件中符合条件的字符串

grep [选项] [查找模式] [文件名]	例子：grep hello * -nwr

-n显示行数	-r递归查找	-w全字匹配

## 压缩与解压

gzip和dzip2为压缩命令	gzip -d和dzip -d为解压

tar命令

常用选项

-c：表示创建用来生成文件包

-x：表示提取，从文件包中提取文件

-t：表示查看压缩的文件

-z：使用gzip方式处理，与c结合表示压缩，与x结合表示解压

-j：使用bzip2方式处理，与c结合表示压缩，与x结合表示解压

-v：详细报告tar处理的信息

-f：表示文件，后面接着一个文件名，-C <指定目录>解压到指定目录

<img src="Com_pictrue/image-20230406101133985.png" alt="image-20230406101133985" style="zoom:70%;" />

①：czf表示以gzip方式压缩文件test，并命名为test.tar.gz

②：cjf表示以bzip2方式压缩文件test，并命名为test.tar.bz2

**查看压缩文件**：

$ tar tvf dira.tar.gz

**解压文件**，可以用-C 指定解压到哪个目录：

$ tar xzvf dira.tar.gz //解压到当前目录

$ tar xzvf dira.tar.gz -C /home/book //解压到/home/book

# vi编辑器

<img src="Com_pictrue/image-20230406110208917.png" alt="image-20230406110208917" style="zoom:70%;" />

## 一般模式

进入编辑模式

| 指令 | 描述                                         |
| ---- | -------------------------------------------- |
| i    | 在当前光标所在的字符前面，转为编辑模式       |
| I    | 在当前光标所在的行行首转为编辑模式           |
| a    | 在当前光标所在的字符后面，转为编辑模式       |
| A    | 在光标所在的行行尾转为编辑模式               |
| o    | 在当前光标所在行的下方，新建一行转为编辑模式 |
| O    | 在当前光标所在行的上方，新建一行转为编辑模式 |

快速移动光标

| 指令     | 描述               |
| -------- | ------------------ |
| h        | 光标左移动一个字符 |
| l        | 光标右移一个字符   |
| j        | 光标上移一行       |
| k        | 光标下移一行       |
| ngg      | 光标移动到第n行首  |
| n+       | 光标下移n行        |
| n-       | 光标上移n行        |
| Ctrl + f | 屏幕向下翻一页     |
| Ctrl + b | 屏幕向上翻一页     |

文本操作

yy：复制当前行

nyy：复制n行

p：粘贴

dd：删除光标所在的行

ndd：删除n行

x：删除光标所在位置的字符（只能在字符开头）

u：撤销上一步操作

<img src="Com_pictrue/image-20230406155318977.png" alt="image-20230406155318977" style="zoom:67%;" />

# 系统编程

## 文件IO

​		在对文件进行读写操作前，需要先打开该文件，内核为每个进程维护一个打开文件的列表，该表被称为文件表（file table），该表由一些叫做文件描述符（file descriptors）的非负整数进行索引。列表的每项均包含一个打开文件的信息，其中包括一个指向文件备份inode内存拷贝的指针和元数据（例如文件位置和访问模式等）。用户空间和内核空间都把文件描述符作为每个进程的唯一cookies，打开一个文件返回一个文件描述符，而接下来的操作则把文件描述符作为基本参数。

​		文件描述符由C语言的int类型表示，每个Linux进程都有一个文件打开上限，文件描述符从0开始，直到比上限小1。负数不是合法的文件描述符，所以-1常常被用来表示一个函数不能返回合法的文件描述符。

​		每个进程按照惯例至少有三个打开的文件描述符：0、1和2，除非进行显式关闭它们。文件描述符0是标准输入（stdin）；文件描述符1是标准输出（stdout）；文件描述符2是标准错误（stderr）。

​		文件描述符不仅仅用于普通文件的访问，也用于访问设备文件、管道、目录以及快速用户空间锁、FIFOs和套接字，遵循一切皆文件的理念，任何你能读写的东西都可以用文件描述符来访问。

### 打开文件

​		最基本的访问文件的方法是使用read()和write()系统调用，在一个文件能被访问之前，必须通过open()和creat()系统调用打开它，一旦使用完毕，就应该用close()系统调用来关闭文件。

#### **open()系统调用**

通过open()系统调用来打开一个文件并获得一个文件描述符

```c
#include <sys/types.h>
#include <sys/stat.c>
#include <fcntl.h>

int open(const char *name, int flags);
int open(const char *name, int flags, mode_t mode);
```

open()系统调用将路径名称name给出的文件与一个成功返回的文件描述符相关联，文件位置指针被设定为零，而文件则根据flags给出的标志位打开

#### **open()的flags的参数**

flags参数必须为以下之一：O_RDONLY、O_WRONLY、O_RDWR。这些参数各自指定要用只读、只写、还是读写模式打开文件

例如，下面代码为用只读方式打开文件/home/kidd/madagascar

```c
int fd;//获取文件描述符
fd = open("/home/kidd/madagascar", O_RDONLY);
if(fd == -1)//打开错误
    //error
```

flags参数可以和以下一个或者多个值进行按位或运算，用以修改打开文件请求的行为

| 参数        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| O_APPEND    | 文件将以追加模式下打开，在每次写操作之前，文件位置指针都会被置于文件末尾 |
| O_ASYNC     | 当指定文件可写或者可读时产生一个信号（默认为SIGIO）仅可用于终端和套接字，不可用于文件 |
| O_CREAT     | 当name指定文件不存在时，将由内核来创建，如果文件已经存在，本标志无效，除非给出O_EXCL标志 |
| O_DIRECT    | 打开文件用于直接I/O                                          |
| O_DIRECTORY | 如果name不是一个目录，open()调用将会失败，这个标志用于在opendir()内部使用 |
| O_EXCL      | 在O_CREAT一起给出的时候，如果name给定的文件已经存在，则open()调用失败 |
| O_LARGEFLIE | 给定文件打开时将使用64位偏移量，这样大于2G的文件也能打开     |
| O_NOCTTY    | 如果给出的name指向一个终端设备（/dev/tty）它将不会成为这个进程的控制终端，不常用 |
| O_NOFLLOW   | 如果name是一个符号链接，open()调用会失败，通常会解析该链接并打开目标文件 |
| O_NONBLOCK  | 如果可以，文件将在非阻塞模式下打开，任何其他操作都不会使该进程在I/O中阻塞（sleep） |
| O_SYNC      | 打开文件用于同步I/O，在数据写到磁盘之前写操作不会完成；一般读操作已是同步的，所以无影响 |
| O_TRUNC     | 如果文件存在，且为普通文件并允许读写，将文件的长度截断为0，对于FIFO和终端设备，该参数被省略 |

```c
//使用例子
int fd;
fd = open("/home/teach/pearl", O_WRONLY | O_TRUNC);
if(fd == -1)//打开错误
    //error
```

#### 新文件的权限

当文件创建时，mode参数提供新建文件的权限

| mode参数 | 描述                         |
| -------- | ---------------------------- |
| S_IRWXU  | 所有者拥有读写和执行权限     |
| S_IRUSR  | 所有者拥有读权限             |
| S_IWUSR  | 所有者拥有写权限             |
| S_IXUSR  | 所有者拥有执行权限           |
| S_IRWXG  | 组拥有者有读写和执行权限     |
| S_IRGRP  | 组拥有者有读权限             |
| S_IWGRP  | 组拥有者有写权限             |
| S_IXGRP  | 组拥有者有执行权限           |
| S_IRWXO  | 任何其他人都有读写和执行权限 |
| S_IROTH  | 任何其他人都有读权限         |
| S_IWOTH  | 任何其他人都有写权限         |
| S_IXOTH  | 任何其他人都有执行权限       |

```c
//例子：代码对文件file进行写操作，文件不存在且假定umask为022，将建立权限为0644的文件；存在则长度截短为0
int fd;//获取文件描述符
fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 
          S_IWSUR | S_IRSUR | S_IWFRP | S_IRGRP | S_IROTH);
if(fd == -1)
    //error
```

#### creat()函数

O_WRONLY |O_CREAT|O_TRUNC组合经常使用，以至于专门有个系统调用来实现

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int creat(const char *name, mode_t mode);

//典型creat()调用如下
int fd;
fd = creat(file, 0644);
if(fd == -1);
    //error

//等价于
int fd;
fd = open(file, O_WRONLY | O_CREAT | O_TRUNC， 0664);
if(fd == -1);//error
```

### read()读取文件

用read()来读取文件

```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t len);
```

​		该系统调用从由fd指向的文件的当前偏移量至多读len个字节到buf中，成功将返回buf中的字节数，出错返回-1并设置errno。fd所指文件位置指针将会向前移动，移动长度由之前读取的字节数决定

基本用法比较简单，下面例子从fd所指文件中读取数据并保存到word中，读取字节数等于unsigned long类型大小

```c
unsigned long word;
ssize_t nr;
//read a couple bytes in 'word' from 'fd'
nr = read(fd, &word, sizeof(unsigned long));
if(nr == -1)//error
```

这个不成熟的实现有俩个问题：调用可能没有读完len个字节就返回，而且可能产生某些这段代码本身没有检查和处理的错误

对于read()的调用会有很多可能的结果

- 调用返回一个等于len的值，所有len个被读取字节存储在buf中，结果和预期一致
- 调用返回一个大于0但是小于len的值，读取的字节存入buf，这种情况出现在一个信号打断了读取的过程，或在读取中发生了一个错误，有效字节大于0，但比len字节小少时，或者读入len个字节前已地道EOF。再次进行读取（更新buf和len的值）将读入剩余字节到 buf的剩余空间中
- 调用返回0，标志着EOF，没有可以读入的数据
- 调用堵塞了，因为没有可用的用来读取数据，这在非堵塞模式不会发生
- 调用返回-1，并且errno被设置为EINTR，这表示在读入字节之前收到了一个信号，可以重新进行调用
- 调用返回-1，并且errno被设置为EAGIN，这表示读取会因没有可用的数据而阻塞，而请求应该在之后重开，只在非阻塞模式发生
- 调用返回-1，并且errno被设置不同于EINTER或EAGIN的值，这表示某种更严重的错误

如果想要处理所有错误，并且读入所有len个字节（至少读到EOF），需要一个循环和一些条件语句

```c
ssize_t ret;
while(len != 0 && (ret = read(fd, buf, len)) != 0)
{
    if(ret == -1)
    {
        if(errno == EINTR)
            continue;
        perror("read");
        break;
    }
    len -= ret;
    buf += ret;
}
/*
这段代码处理了五种情况，循环从fd所指的当前文件位置读入len个字节到buf中，读入会一直到读完所有len个字节或者EOF为止
如果读入了多于0个但少于len个字节，从len减去已读字节数，部分增加相应数量的字节数，并重新调用read()
如果调用返回了-1，并且errno等于EINTR，将重新调用且不更新参数
如果调用返回-1，且errno被设置为其他值，将调用perror()来向标准错误打印一条描述并终止循环
*/
```

#### 非阻塞读

​		有时候，我们不希望当没有可读数据时让read()调用阻塞，相反会希望没有可读数据时让调用立即返回，这中情况被称为非阻塞I/O；它允许应用在从不阻塞的状态下进行I/O操作。所以还有一个errno的值需要检查：EAGAIN，如果给出的文件描述在非阻塞模式下打开（open()中的O_NONBLOCK）并且没有可读数据，read()会调用返回-1，且设置errno为EAGAIN，在进行阻塞I/O时，必须检查EAGAIN，否则可能会导致数据缺失，可能会用到下面的代码：

```c
char buf[BUFSIZ];
ssize_t nr;
start;
nr = read(fd, buf, BUFSIZ);
if(nr == -1)
{
    if(errno == EINTR)
        goto start;
    if(errno == EAGAIN)
        ;//resubmit later
    else
        ;//error
}
```



### write()写文件

最常用的写文件的系统调用是write()

```c
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_f count);
```

​		一个write()调用从由文件描述fd引用文件的当前位置开始，将buf中至多count个字节写入文件中，成功时返回写入字节数并更新文件位置，错误时返回-1，并将errno设置为响应的值

```c
//基本用法
const char *buf = "My ship is solid";
ssize_t nr;
//write the string in 'buf' to 'fd'
nr = write(fd, buf, strlen(buf));
if(nr == -1)
    ;//error
```

这种简单的用法并不大合适，调用者需要检查出现部分写的各种可能性

```c
unsigned long word = 1720;
size_t count;
ssize_t nr;

count = sizeof(word);
nr = write(fd, &word, count);
if(nr == -1)
    ;//error, check errno
else if(nr != count)
    ;//possible error, but 'error' not set
```

#### 部分写

​		相对于read()的返回部分读的情况，write()不太可能返回一个部分写的结果，而且write()没有EOF情况，除非发生一个错误，否则write()将保证写入所有的请求。对于普通文件，就不需要循环写；然而对于其他类型可能需要循坏写操作

```c
ssize_t ret, nr;
while(len != 0 && (ret = write(fd, buf, len)) != 0)
{
    if(ret == -1)
    {
        if(errno == EINTR)
            continue;
        perror("write");
        break;
    }
    len -= ret;
    buf += ret;
}
```

#### write()的行为

​		当用户空间应用发起write()系统调用时，Linux内核进行几项检查，然后直接将数据拷贝志一个缓冲区，稍后在后台内核收集所有这些“脏”缓冲区，将其排好序并写入到磁盘中（此过程被称为回写）。而当read()想读取刚刚write()的数据时，不会去硬盘中查找，而是直接到缓冲区查找

​		内核会尝试将延迟写的风险最小化，为保证数据适时写入，内核创立了一种缓存最大时效机制，并将所有脏的缓存在它们超过定时效前写入磁盘，用户可以通过 /proc/sys/vm/dirty_expire_centiseconds 来配置这个值，这个值以十毫秒计（百分之一秒）

### 同步I/O

​		尽管同步I/O是一个重要的主题，但不必担心和延迟写相关的问题，由于写缓冲提供了巨大的性能改进，以至于一些半吊子的“现代”系统都用缓冲区实现了延迟写，然而常有应用想要控制数据被写入磁盘的时间，对于这些需要Linux内核提供了一些选择来允许用性能换取同步操作

#### fsync()和fdatasync()

最简单的确认数据写入磁盘的方法是fsync()系统调用，定义如下

```c
#include <unistd.h>
int fsync(int fd);
```

​		调用fsync()可以保证fd对应文件的脏数据回写到磁盘上，文件描述符fd必须是以写方式打开的，该调用回写数据以及建立的时间戳和inode中的其他属性等元数据，在驱动器确认数据已经全部写入之前不会返回。在将数据写入硬盘缓存时，fsync()是不可能知道数据是否已经在磁盘上，磁盘可能报告数据已经写入，但数据可能还在磁盘驱动器的缓存上

Linux还提供了fdatasync()系统调用

```c
#include <unistd.h>
int fdatasync(int fd);
```

这个系统调用完成的事情和fsync()一样，区别在于它仅写入数据，该调用不保证元数据同步到磁盘上，速度可能较快

两个函数有相同用法：

```c
int ret;
ret = fsync(fd);
//ret = fdatasync(fd);
if(ret == -1)
    ;//error
```

​		这俩调用都不保证任何已经更新的包含该文件的目录项同步到磁盘上，这意味着如果文件链接刚刚被修改过，文件数据可能会成功写入磁盘，但却没有关联到相应的目录项上，导致文件不可访问，为了保证任何对目标项的更新也同步到磁盘上，必须对目录本身也调用fsync()进行同步

#### 返回值和错误码

成功时两个调用都返回0，失败时都返回-1，并将errno设置为以下三个值之一：

EBADF	给定的文件描述符不是一个可以写入的合法描述符

EINVAL	给定的文件描述符对应的对象不支持同步

EIO	在同步时发生了一个底层IO错误，此类错误经常在错误发生处被捕获

​		一般来说，即使是在响应文件系统上实现了fdatasync()而未实现fsync()，在调用fsync()时也会失败，应用可能会在fsync()返回EINVAL时尝试用fdatasync()，如

```c
if(fsymc(fd) == -1)
{
    //if fsync() fails, let's try fdatasync()
    if(errno == EINVAL)
    {
        if(fdatasync(fd) == -1)
            perror("fdatasync");
    }
    else
        perror("fsync");
}
```



#### sync()

sync()系统调用可以用来对磁盘上的所有缓冲区进行同步，效率不高但是被广泛使用

```c
#include <unistd.h>
void sync(void);
```

该函数没有参数，也没有返回值，总是能成功返回并确保所有的韩冲去都能写入磁盘

​		标准中并不要求sync()一直等待所有缓冲去都写到磁盘才返回，只需要调用它来启动整个将缓冲区写入磁盘的过程即可。一般建议多次同步以确保所有数据安全写入磁盘，然而对于linux来说，sync()一定要等到所有缓冲区都写入才返回，因此调用一次sync()就够了

### 直接I/O

​		Linux内核实现了一个复杂和缓存、缓冲以及设备和应用之间的I/O管理的层次结构，一个高性能应用可能希望越过这些复杂的层次结果并进行单独的IO管理，在open()中使用O_DIRECT标志会使内核最小化IO管理的影响，使用该标志时，IO操作将忽略页缓存机制，直接对用户空间缓冲区和设备进行初始化，所有IO将会是同步的

### 关闭文件

程序在完成某个文件的操作后，可以使用close()系统调用将文件描述符和对应的文件解除关联

```c
#include <unistd.c>
int close(int fd);
//close()调用解除了已打开的文件描述符的关联，分离进程和文件的关联，close()调用成功时返回0，错误时返回-1

//用法
if(close(fd) == -1)
    perror("close");
```

需要注意的是，关闭文件和文件被写入磁盘没有关系，如果想保证关闭前写入磁盘仍需要同步IO

### 用lseek()查找

​		lseek()系统调用能够对给定文件描述符引用的文件位置设定指定值，除了更新文件位置，没有其他行为并且不初始化任何IO

```c
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t pos, int origin);
```

lseek()的行为依赖于初始参数，可以为以下值之一：

SEEK_CUR	当前文件位置fd设置为当前值加上pos，pos可以为负值、零或正值，零则返回当前位置

SEEK_END	当前文件位置fd设置为当前文件长度加上pos，pos可以为负值、零或正值，零则设置偏移量为文件末尾

SEEK_SET	当前文件位置fd设置为pos，一个为零的pos设置偏移量为文件起始

调用在成功时返回新文件位置，错误时返回-1并设置适当的errno值

```c
//举例设置文件位置fd为1825
off_t ret;
ret = lseek(fd, (off_t) 1825, SEEK_SET);
if(ret == (off_t) -1)
    ;//error

//或者设置文件位置fd到文件末尾
off_t ret;
ret = lseek(fd, 0, SEEK_END);
if(ret == (off_t) -1)
    ;//error

//由于lseek()返回更新过的文件位置，可以用SEEK_CUR和0来确定文件当前位置
int pos;
pos = lseek(fd, 0, SEEK_CUR);
if(pos == (off_t) -1)
    ;//error
else
    ;//'pos' is the current position of fd
```

lseek()最常见用法是用来定位当前文件的开始和末尾，或者确定某个文件描述符引用的放弃文件位置

#### 错误码

出错时，lseek()返回-1，并将errno设置为下面四个值之一

EBADF				给出的文件描述符没有指向任何打开的文件

EINVAL				origin的值不是SEEK_SET，SEEK_CUR，SEEK_END其中之一，或者最终计算的文件位置为负

EOVERFLOW 	 计算后的文件偏移量不能被off_t表示，这种情况只会发生在32位架构上

ESPIPE				给出的文件描述符关联到一个不能执行查找操作的对象上，例如管道、FIFO或套接字

### 定位读写

Linux提供了俩种read()和write()的变体来替代lseek()，每个调用都以需要读写的文件位置为参数，完成时不修改文件位置

```c
//读形式的调用为pread()
#define _XOPEN_SOURCE 500
#include <unistd.h>
ssize_t pread(int fd, void *buf, size_t count, off_t pos);
```

这个调用从文件描述符fd的pos文件位置读取count个字节到buf中



```c
//写形式的调用为pwrite()
#define _XOPEN_SOURCE 500
#include <unistd.h>
ssize_f pwrite(int fd, const void *buf, size_t count, off_t pos);
```

这个调用从文件描述符fd的pos文件位置写count个字节到buf中

​		除了它们不管当前文件位置，这些调用的行为和read()、write()几乎没有区别，它们使用pos提供的值而不是当前位置，在调用完成后它们不会修改文件位置。俩种定位读写都只能用于考研进行定位操作的文件描述符，pread()和pwrite()与lseek()仍有三点区别：

- 这些调用更加简单易用，尤其是在文件中做反向移动和随机移动这种技巧性很强的操作时
- 当操作完成时不修改文件位置指针
- 避免了任何在使用lseek()时可能出现的潜在竞争，由于线程共享文件描述符，可能在一个线程调用lseek()但未进行读写操作，领一个线程却修改了文件位置，通过pread()和pwrite()来避免产生这样的竞争

#### 错误码

成功时，俩个调用返回读或写的字节数。pread()返回0表示EOF；pwrite()返回0表示调用没有写任何东西

出错时，俩个调用都返回-1并设置errno位相应值，对于pread()任何对read()或lseek()的errno值都可能出现；对于pwrite任何write()或lseek()的errno的值也都可能出现

### 截短文件

Linux提供两个系统调用来截短文件

```c
#include <unistd.h>
#include <sys/types.h>
int ftruncate(int fd, off_t len);
//和
#include <unistd.h>
#include <sys/types.h>
int truncate(const char *path, off_t len);
```

​		俩个系统调用都将文件截短到len指定的长度，ftruncate()系统调用操作一个打开的并且可写的文件描述符fd；truncate()系统调用操作path指定的一个可写文件，二者成功返回0，错误时返回-1并设置errno值

​		这俩系统调用都可以截短len，比源文件小时多于len的数据将被忽略且不可被读取，比原长度长时，扩展出的字节将全部填充为0，俩操作均不修改当前位置的位置

```c
//例子
/*
一个有74字节大小的文件pirate.txt
Edward Teach was a notorious English pirate.
He was nicknamed Blackbeard.
*/
//在同一路径下，运行以下程序
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int ret;
    ret = truncate("./pirate.txt", 45);
    if(ret == -1)
    {
        perror("truncate");
        return -1;
    }
    return 0;
}

/*
结果会产生包含下面45个字节的文件
Edward Teach was a notorious English pirate.
*/
```

​    

### IO多路复用

​		应用程序常常需要在多于一个文件描述符上阻塞，在不使用线程，尤其是独立处理每一个文件的情况下，进程无法在多个文件描述符上同时阻塞，如果文件都准备好被读写的状态，同时操作多个文件描述符没有问题，但一旦在该进程中出现一个未准备好的文件描述符（如被read()调用，但没有读入数据），则这个进程会阻塞，会有可能导致依赖该文件的文件在前者可以被使用之前，后者一直处于不可用状态

I/O多路复用允许应用在多个文件描述符上同时阻塞，并在其中某个可以读写时收到通知，一般来说I/O多路复用的设计遵循以下原则：

- I/O多路复用：当任何文件描述符准备好I/O时告诉我
- 在一个或多个文件描述符就绪前始终处于睡眠状态
- 唤醒：哪个准备好？
- 在不阻塞的情况下处理所有I/O就绪的文件描述符
- 返回第一步重新开始

Linux提供了三种I/O多路复用方案：select、poll和epoll，最后一个为linux特有的高级方法

#### select()

select()系统调用提供了一种实现同步IO多路复用的机制：

```c
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int select(int n, 
           fd_set *readfds,
           fd_set *writefds,
           fd_set *exceptfds,
           struct timeval *timeout);
FD_CLR(int fd, fd_set *set);
FD_ISSET(int fd, fd_set *set);
FD_SET(int fd, fd_set *set);
FD_ZERO(fd_set *set);
```

在指定的文件描述符准备好IO之前或者超过一定的时候限制，select()调用就会阻塞

检测的文件描述符可以分为三类，分别等待不同的事件

- 监测readfds集合中的文件描述符，确认其中是否有可读数据（也就是说，读操作可以无阻塞完成）
- 监测writefds集合中的文件描述符，确认其中是否有一个写操作可以不阻塞的完成
- 监测exceptefds中的文件描述符，确认其中是否有出现异常发生或者出现带外数据

第一个参数n，等于所有集合中文件描述符的最大值+1，调用select()需要找到最大的文件描述符

timeout参数是一个指向timeval结构体指针，定义如下

```c
#include <sys/time.h>
struct timeval
{
    long tv_sec;//seconds
    long tv_usec;//microseconds
}
```

​		如果这个参数不是NULL，即便此时没有文件描述符处于IO就绪状态，select()调用也将在tv_sec秒tv_usec微秒后返回，如果俩个值都是0，调用会立即返回并报告调用时所有事件对于的文件描述符均不可用

​		集合中的文件操作符并不直接操作，而是通过辅助宏来进行管理，大多系统将其实现为位数组，FD_ZORE从指定集合中移除所有文件描述符

```c
//每次使用select()之前，都需要调用该宏
fd_set writefds;
FD_ZERO(&writefds);

//FD_SET向集合中添加一个文件描述符，而FD_CLR从指定集合中移除一个文件描述
FD_SET(fd, &writefds);//add 'fd' to the set
FD_CLR(fd, &writefds);//remove 'fd' from the set

//FD_ISSET测试一个文件描述符在不在给定集合中，在则返回一个非零值，否则返回0
//一般select()调用返回后使用FD_ISSET来检查一个文件描述符是否准备就绪
if(FD_ISSET(fd, &readfds))
    ;//'fd' is readable without blocking
```

##### 返回值和错误码

成功时，select()返回在所有三个集合中IO就绪的文件描述符的数目，如果给出了时限，返回值可能为0，错误时返回-1，errno被设置为以下的值之一：

EBADF		某一个集合中的一个文件描述符非法

EINTR		 等待时捕获了一个信号，可以重新发起调用

EINVAL		参数n是负数，或者给出的时限不合法

ENOMEM	没有足够的内存完成请求

```c
//例子
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#define TIMEOUT 5 /* select timeout in seconds */
#define BUF_LEN 1024 /* read buffer in bytes */

int main (void)
{
	struct timeval tv;
	fd_set readfds;
	int ret;
    
/* Wait on stdin for input. */
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);
    	
/* Wait up to five seconds. */
	tv.tv_sec = TIMEOUT;
	tv.tv_usec = 0;
    
/* All right, now block! */
	ret = select (STDIN_FILENO + 1,
	&readfds,
	NULL,
	NULL,
	&tv);
	if (ret == -1) 
    {
		perror (”select”);
		return 1;
	} 
    else if (!ret)
    {
		printf (”%d seconds elapsed.\n”, TIMEOUT);
		return 0;
	}
/*
* Is our file descriptor ready to read?
* (It must be, as it was the only fd that
* we provided and the call returned
* nonzero, but we will humor ourselves.)
*/
	if (FD_ISSET(STDIN_FILENO, &readfds)) 
    {
		char buf[BUF_LEN+1];
		int len;
	/* guaranteed to not block */
		len = read (STDIN_FILENO, buf, BUF_LEN);
		if (len == -1) 
        {
			perror (”read”);
			return 1;
		}
		if (len) 
        {
			buf[len] = ’\0’;
			printf (”read: %s\n”, buf);
		}
		return 0;
	}
	fprintf (stderr, ”This should not happen!\n”);
	return 1;
}
```

![image-20230416151954608](Com_pictrue/image-20230416151954608.png)

##### pselect()

POSIX定义了直接的方法pselect()，定义如下

```c
#define _XOPEN_SOURCE 600
#include <sys/select.h>

int pselect(int n,
           fd_set *readfds,
           fd_set *writefds,
           fd_set *exceptfds,
           const struct timespec *timeout,
           const sigset_t *sigmask);
FD_CLR(int fd, fd_set *set);
FD_ISSET(int fd, fd_set *set);
FD_SET(int fd, fd_set *set);
FD_ZERO(fd_set, *set);
```

pselect()和select()有三点不同

- pselect()的timeout参数使用了timespec结构，timespec使用秒和纳秒
- pselect()调用并不修改timeout参数，这个参数在后继调用时也不需要重新初始化
- select()调用没有sigmask参数，当这个参数为0，pselect()的行为等于select()

​		添加pselect()到Unix工具箱的主要原因时为了增加sigmask参数，以此来解决信号和等待文件描述符之间的竞争问题。假设一个信号处理程序设置了一个全局标记，进程在每次调用select()前都要检车这个标记，现在假如在检查标记和调用之间接收到信号，应用可能会阻塞，并不再响应信号。pselect()提供了一组可阻塞的信号，阻塞信号直到解除阻塞才会被处理，一旦pselect()返回，内核就恢复旧的信号掩码

#### poll()

poll()系统调用是SystemV的IO多路复用解决方案，它解决了一些select()的不足

```c
#include <sys/poll.h>
int poll(struct pollfd *fds, unsigned int nfds, int timeout);

//与select()使用的三个基于位掩码的文件描述集合不同，poll()使用一个简单的nfds个pollfd结构体组成的数组
#include <sys/poll.h>
struct pollfd
{
    int fd;//file descriptor
    short events;//requested events to watch
    short revents;//returned events witnessed
};
```

每个pollfd结构体指定监视单一的文件描述符，可以传递多个结构体，使得poll监视多个文件描述符，每个结构体的events字段是要监视的文件描述符事件的一组位掩码，用户设置这个字段；revents字段则是发生在该文件描述符上的事件的位掩码。内核在返回时设置这个字段，所有在events字段请求的事件都可能在revents字段中返回。下面为合法的事件：

POLLIN				 没有数据可读

POLLRDNORM	有正常数据可读

POLLRDBAND	 有优先数据可读

POLLPRI			  有高优先级数据可读

POLLOUT			 写操作不会阻塞

POLLWRNORM	写正常数据不会阻塞

POLLBAND		   写优先数据不会阻塞

POLLMSG			 有一个SIGPOLL消息可用

​		另外，如下事件可能在revents中返回

POLLER			给出文件描述符上有错误

POLLHUP		 文件描述符上有挂起事件

POLLNVAL	    给出的文件描述符非法

![image-20230416154300575](Com_pictrue/image-20230416154300575.png)

​		timeout参数指定在任何IO就绪前需要等待事件的长度，以毫秒计，负值表示永远等待，0表示立即返回，列出所有未准备好的IO，这种情况下，poll()轮询一次后立即返回

##### 返回值和错误码

成功时，poll()返回具有非零revents字段的文件描述符个数，超时前没有任何事件发生则返回0，失败返回-1，errno设置为下值：

EBADF			一个或更多结构体中有非法的文件描述符

EFAULT		  指向fds的指针超出了进程地址空间

EINTR			在请求事件发生前收到了一个信号，可以重新调用

EINVAL		   nfds参数超过了RLIMIT_NOFILE值

ENOMEM	   没有足够的内存完成请求

```c
//例子
//要同时检测一个stdin读和一个stdout写是否阻塞
#includ <stdio.h>
#include <unistd.h>
#include <sys/poll.h>
#define TIMEOUT 5 /* poll timeout, in seconds */
int main (void)
{
	struct pollfd fds[2];
	int ret;
    
/* watch stdin for input */
	fds[0].fd = STDIN_FILENO;
	fds[0].events = POLLIN;
    
/* watch stdout for ability to write (almost always true) */
	fds[1].fd = STDOUT_FILENO;
	fds[1].events = POLLOUT;
    
/* All set, block! */
	ret = poll (fds, 2, TIMEOUT * 1000);
    
	if (ret == -1) 
    {
		perror (”poll”);
		return 1;
	}
    
	if (!ret) 
    {
		printf (”%d seconds elapsed.\n”, TIMEOUT);
		return 0;
	}
    
	if (fds[0].revents & POLLIN)
		printf (”stdin is readable\n”);
    if (fds[1].revents & POLLOUT)
		printf (”stdout is writable\n”);
    
	return 0;
}
```

直接运行![image-20230416155859190](Com_pictrue/image-20230416155859190.png)

将一个文件重定向到标准输出![image-20230416155928010](Com_pictrue/image-20230416155928010.png)

##### ppoll()

Linux提供了一个poll()的近似调用——ppoll()，ppoll()和pselect()同源，ppoll()是Linux的专有调用

```c
#define _GNU_SOURCE
#include <sys/poll.h>
int ppoll(struct pollfd *fds,
          nfds_t nfds,
          const struct timespec *timeout,
          const sigset_t *sigmask);
```

像pselect()那样，timeout参数以秒和纳秒计指定了时限，而sigmask参数提供了一组等待处理的信号

### poll()和select()

尽管完成一样的工作，但poll()系统调用要优于select()

- poll()无需使用者计算最大的文件描述符值加一和传递参数
- poll()在应对较大的文件描述符时更具有效率
- select()的文件描述符集合是静态大小的，所以要做出权衡：要么集合很小，限制了select()可以监视文件描述符的最大值；要么较大效率不高，使用poll()则可以创建合适大小的数组
- 若用select()，文件描述符集合会在返回时重新创建，这样每个调用都必须重新初始化它们，poll()系统调用分离了输入（events字段）和输出（revents字段），数组无需改变即可重用

但是select()也有几个不错的地方

- select()的可移植性更好
- select()提供了更好的超时方案：直到微秒级

### 内核内幕

Linux靠虚拟文件系统（VFS），页缓存和页回写三个主要的内核子系统来实现I/O

#### 虚拟文件系统

​		虚拟文件系统（virtual file switch）是一种Linux内核的文件操作的抽象机制，它允许内核在无需了解文件系统类型的情况下，使用文件系统函数和操作文件系统数据。VFS实现这种抽象的方法是使用一种通用文件模型（common file model），它是所有Linux文件系统的基础。基于函数指针和各种面向对象方法，通用文件模型提供了一中Linux内核文件必须遵循的框架，它允许VFS对文件系统发起请求，框架提供了钩子来支持读，建立链接，同步以及其他功能。

​		当一个应用发起一个read()系统调用，C库提供了系统调用的定义，而在编译器调用转化为适当的陷阱态。当一个用户控件进程转入内核态，则转交系统调用处理器处理，最终交给read()系统调用，内核确认文件描述符所对应的对象类型。然后内核调用于相关类型对应的read()函数。对于文件系统而言，这个函数是文件系统代码的一部分，然后该函数继续其工作。

对于系统程序员来说，VFS的影响很重要，程序员不需担心文件所在的文件系统或介质

#### 页缓存

​		页缓存是一种才内存中保存最近在磁盘文件系统上访问过的数据的方式，在内存中保存被请求数据，内核在接下来对相同数据的后续请求可以直接从内存中读取，尽量避免重复磁盘访问

​		页缓存利用了引用局部性（locality of reference）的一种方法——时间局部性（temporal locality），该方法使刚被访问的资源很可能会在不久后再次被访问，由于避免了费时的磁盘访问，内存在第一次访问时缓存数据的开销因而得到了补偿。页缓存是内核寻找文件系统数据的第一目的地，只有缓存中找不到时，内核才会调用存储子系统从磁盘中读取数据。

​		Linux页缓存大小是动态的，随着I/O操作将越来越多的数据带入内存，页缓存也会增大。向磁盘交换一块很少使用的数据，比从页缓存中清除掉一条常常使用且有可能将在下次重读中使用的数据更有意义，Linux内核实现了一些平衡交换数据和清除页缓存的启发方式。交换和缓存间的平衡可以通过/proc/sys/vm/swappiness来调整，这个文件可以在0~100间取值，默认为60，较高的值表示倾向于在内存保留页缓存，较低的值表示倾向于清理页缓存而不是进行交换。

​		引用局部性的另一种形式是空间局部性（sequential locality），是关于数据的连续使用的性质，基于这个原理，内核实现了页缓存预读技术，预读是在每次请求时从磁盘数据中读取更多的数据到页缓存的动作，当内核从磁盘读取一块数据时，也会读取接下来的一俩快数据，一次读取较大的连续数据块时磁盘不需要经常寻道，所以比较有效。和页缓存类似，内核管理预读也是动态的，如果它注意到一个进程持续使用预读来的数据，内核会增加预读窗口，进而预读更多的数据；反之如果内核发现预读没有造成任何有用的命中，它可能减少甚至关闭预读的窗口。

#### 页回写

​		内核使用缓冲区来延迟写操作，当一个进程发起写请求，数据拷贝进一个缓冲区，并将该缓冲区标记为“脏”的，这意味着内存中的可瓯北要比磁盘上的新，如果对同一块数据块有新的写请求，缓冲区会更新数据，最终“脏”缓冲区需要被写入磁盘，将磁盘文件和内存数据同步，这是所谓的回写，以下俩个条件会触发回写

- 当空闲内存少于设定的阈值时，脏的缓冲区会回写到磁盘上，被清理的缓冲区可能被移除来释放内存
- 当一个脏的缓冲区超过设定的阈值时，缓冲区被回写到磁盘，以此来避免数据的不确定性

​		回写由一些叫做pdflush的内核线程操作，可能同时有多个pdflush线程在回写，这么做是为了更好的利用并行性而避免拥堵。拥堵避免机制确保等待向某个块设备进行写操作时，其他的写操作不会被积压下来，如果来自其他块设备有脏缓冲区的存在，其他pdflush线程会充分利用每一块设备。

​		缓冲区在内核中使用buffer_head结构来表示，这个数据结构跟踪各种各样与缓冲区关联的元数据，例如缓冲区干净与否，同时它也维护了一个指向实际数据的指针，这部分数据保存在页缓存中，用这种方式将缓冲子系统和页缓存统一了起来。

Linux中的延迟写和缓冲子系统可以使写操作迅速完成，代价是要冒着在电源故障时丢失数据的风险，为避免这种风险，关键性应用可以使用同步IO进行保存数据

## 缓冲输入输出

​		块作为文件系统的抽象，是IO中最基本的概念，所有磁盘操作都是基于块进行的，因此当请求以块大小整数倍对齐地址时，IO的效率时最理想的。操作系统随着调用次数的增多而急剧下降，如一次读一字节读1024次显然比一次读1024字节效率低。如果长处不是block的整数倍，即便每次以大于快的长度进行一系列操作，其效率也不是最理想的。

### 用户——缓冲IO

​		需要对普通文件执行需要多轻量化IO请求的程序通常使用用户缓冲IO，用户缓冲IO在用户空间而不是内核中完成的，可以在程序中设定，也可以调用标准库透明的执行，通过不同的方法，用户缓冲的主旨也是为了提高操作效率。

![image-20230417142255204](Com_pictrue/image-20230417142255204.png)

通过上表得到使用1024bytes时效率最优，如果块不是磁盘块大小的整数倍，也会导致效率变低，1130字节的请求会产生不对齐的操作，因此比1024字节的请求效率更低。

​		C标准库里提供了标准IO库，其中实现了一个跨平台用户缓冲的解决方案，这个标准IO库使用简单而且功能强大，除了流控制和算术运算等基本支持外，C语言没有对其他功能提供内嵌支持。用户缓冲IO属于文件输入输出，而且是在C标准库中实现，因此打开、关闭、读写文件都是通过C标准库完成，一个程序是用标准IO还是自创的用户缓冲，还是直接系统调用，都需要设计者权衡程序的需求和行为后才能进行决定

​		标准I/O例程并不直接操作文件描述符，取而代之的是它们用自己唯一的标志符，即文件指针（file pointer），C标准库中，文件指针映射到一个文件描述符中，文件指针由FILE类型的指针表示，FILE类型定义在<stdio.h>中。在标准IO中，一个打开的文件叫流（stream），流可以被打开用来读（）输入流、写（输出流）或者二者兼有（输入输出流）

### 打开文件

文件通过fopen()打开以供读写操作

```c
#include <stdio.h>
FILE *fopen(const char *path, const char *mode);
//这个函数根据指定的模式打开文件path，并为它关联一个新的流
```

参数模式mode描述以怎样的方式打开指定文件，它可以是下述字符串之一：

r				打开文件用来读取。流定位在文件的开始处

r+			  打开文件用来读写，流定位在文件开始处

w			   打开文件用来写入，如果文件存在，文件会被清空，如果不存在则创建，流定位在文件的开始处

w+			 打开文件用来读写，如果文件存在，文件会被清空，如果不存在则创建，流定位在文件的开始处

a			    打开文件用来追加模式的写入，文件不存在则创建，流被设置在文件的末尾，所有的写入都会接在文件后

a+			  打开文件用来追加模式的读写，文件不存在则创建，流被设置在文件末尾，所有的写入都会接在文件后

​		给定的模式可能还是字符b，这个值在Linux下通常会被忽略，一些操作系统用不同的方式对待文本和二进制文件，并且b模式指示文件用二进制打开，Linux以相同方式对待文本和二进制文件。

成功时，fopen()返回一个合法的FILE指针，失败时，它返回NULL，而且设置相应的设置errno

```c
//下面的代码打开/etc/manifest以供读取，并将它与一个流关联
FILE *stream;
stream = fopen("/etc/manifest", "r");
if(!stream)
    ;//error
```

#### 通过文件描述符打开文件

函数fdopen()将一个以及打开的文件描述符(fd)转成一个流：

```c
#include <stdio.h>
FILE *fdopen(int fd, const char *mode);
```

fdopen()的可能模式和fopen()一样，而且必须和原来打开文件描述符的模式匹配，可以指定模式w和w+，但是它们不会截断文件，流的位置设置在文件描述符指向的文件位置。一旦文件描述符被转换成一个流，则不应该直接在该文件描述符上进行IO，需要注意的是文件描述符没有被复制，而指示关联了一个新的流，关闭流也会关闭相应的文件描述符。

成功时，fdopen()返回一个合法的文件指针；失败时，返回NULL，例如下面的代码通过open()系统调用打开/home/kidd/map.txt，然后用已有的文件描述符创建一个关联的流：

```c
FILE *stream;
int fd;
fd = open("/home/kidd/map.txt", O_RDONLY);
if(fd == -1)
    ;//error
stream = fdopen(fd, "r");
if(!stream)
    ;//error
```

### 关闭流

fclose()函数关闭一个给定的流：

```c
#include <stdio.h>
int fclose(FILE *stream);
```

所有被缓冲但还没有被写出的数据会被先写出，成功时，fclose()返回0，失败时返回EOF并且设置errno

fcloseall()函数关闭所有的和当前进程相关联的流，包括标准输入，标准输出

```c
#define _GNU_SOURCE
#include <stdio.h>
int fcloseall(void);
//关闭之前，所有的流会被写出，这个函数始终返回0，是Linux特有的函数
```

### 从流中读取数据

​		C标准库实现了多种从流中读取数据的方式：单个字节的读取、单行的读取、二进制数据读取。为了从流中读数据，流必须以恰当的方式打开，除了w或a的模式都可以

#### 单字节读取

通常，理想的输入输出模式是每次简单的读取第一个字符，函数fgetc()可以用来从流中读取单个字符：

```c
#include <stdio.h>
int fgetc(FILE *stream);
```

这个函数从流中读取下一个字符并将该无符号强转为int返回，强转是为了由足够的范围来表示文件结尾符和错误：EOF会被返回

```c
//把这些返回值保存为char是错误的，下例从流中读取单个字符，检查错误，然后以字符方式打印结果
int c;
c = fgetc(stream);//stream指向的流必须以可读模式打开
if(c == EOF)
    ;//error
else
    printf("c = %c\n", char(c));
```

#### 把字符回放入流中

标准输入输出提供了一个将字符放回流的函数，如果你不需要该字符的话，可以将其放回

```c
#include <stdio.h.>
int ungetc(int c, FILE *stream);
```

每次调用会将c强转成一个无符号字符并放回流中，成功时，返回c；失败时返回EOF。随后读取流会返回c，如果多个字符被放入流中，它们会以倒序的方式返回。

#### 按行的读取

函数fgets()从一个给定的流中读取一个字符串

```c
#include <stdio.h>
char *fgets(char *str, int size, FILE *stream);
```

这个函数从流中读取size-1个字节，并把数据存入str中，当所有字节读入时，空字符被存入字符串末尾，当读到EOF或换行符读入结束

```c
//成功时返回str；失败时，返回NULL
char buf[LINE_MAX];
if(!fgets(buf, LINE_MAX), stream)
    ;//error
```

POSIX在<limits.h>中定义了宏LINE_MAX：它是POSIX行控制接口能够处理的输入行的最大长度

#### 读取任意字符串

fgets()基于行的读取通常时有用的

用fgetc()写一个fgets()不难，例如下面的代码片段从流中读取n-1个字节到str中，然后加上一个'\n'：

```c
char *s;
int c;
s = str;
while(--n > 0 && (c = fgetc(stream)) != EOF)
    *s++ = c;
*s = '\0';

//这段程序可以扩展为任意指定的分隔符d处停止
char *s;
int c = 0;
s = str;
while(--n > 0 && (c = fgetc(stream)) != EOF && (*str++ = c) != d);
if(c == d)
    *--s = '\0';
else
    *s = '\0';
```

除了在缓冲区中存入换行符，将d设置为'\n'可以提供和fgets()类似的功能

根据fgets()的实现，这个实现方式可能要慢些，因为它重复调用了很多次fgetc()

#### 读取二进制文件

一些应用程序不只是读取字符，有时候开发者想读写复杂的二进制数据，因此标准输入输出库提供了额函数fread()：

```c
#include <stdio.h>
size_t fread(void *buf, size_t size, size_t nr, FILE *stream);
//调用fread()会从输入流中读取nr个数据，每个数据有size个字节，并将数据放入到buf所指向的缓冲区，文件指针向前移动读出字节长度
```

读入元素的个数（不是读入字节个数）被返回，这个函数通过返回一个比nr小的数表明读取失败或文件结束，在没有ferror()和feof()的情况下，不可能知道这俩种情况的哪一个

```c
//fread()最简单的例子是从给定流中读取一个线性大小的元素
char buf[64];
size_t nr;
nr = fread(buf, sizeof(buf), stream);
if(nr == 0)
    ;//error
```

### 向流中写数据

​		和读取相同，C标准库定义了许多用来将数据写入流中的函数：单个字节的写入，字符串写入，二进制i写入，不同的写入方法对于缓冲IO都适用，为了向流中写数据，流必须以恰当的输出流的模式打开，除了r的所有合法模式

对齐：所有机械设计都有数据对齐的要求。程序员倾向于把内存想成一个简单的字节数组，但是处理器不以字符大小来访问内存，而是以特定的粒度访问，因为每个处理的地址空间都从0地址开始，进程必须从一个特定粒度的整数倍开始读取，因此C变量的存储和访问是要地址对齐的。通常编译器会自动对齐数据，而且对齐是程序员看不见的，在处理结构体，手动执行内存管理，向磁盘二进制数据和进行网络通信时，对齐都非常重要

#### 写入单个字符

与fgetc()相对应的函数是fputc()

```c
#include <stdio.h>
int fputc(int c, FILE *stream);

//用法
if(fputc('p', stream) == EOF)
    ;//error
```

fputc()函数将c表示的字节（强转为一个无符号字符）写入stream指向的流中，成功完成时返回c，否则返回EOF并设置errno

例子为将 ‘p’ 写入流中，这个流必须打开于写入

#### 写入字符串

函数fputs()用来往给定的流中写入一个完整的字符串

```c
#include <stdio.h>
int fputs(const char *str, FILE *stream);
```

fputs()的调用将str指向的字符串的所有非分隔符部分写入stream指向的流中，成功时fputs()返回一个非负整数，失败返回EOF

```c
//该例子为以追加模式打开文件用来写入，将给定的字符串写入相关流中，然后关闭流
stream = fopen("journal.txt", "a");
if(!stream)
    ;//error，创建流失败
if(fputs("The ship is made of wood.\n", stream) == EOF)
    ;//error，向流写入字符串失败
if(fclose(stream) == EOF)
    ;//error，关闭流失败
```

#### 写入二进制数据

如果程序需要写入二进制数据，则单独字符和行并不能满足需求，为了直接存储二进制数据，标准IO提供了fwrite()函数

```c
#include <stdio.h>
size_t fwrite(void *buf, size_t size, size_t nr, FILE *stream);
//调用fwrite()会把buf指向的nr个元素写入到stream中，每个元素长为size，文件指针会向前移动写入的所有字节的长度
```

成功时，会返回写入元素的个数（不是字节的个数），返回小于nr的数表明发生了错误

### 缓冲I/O实例程序

例子：这个程序首先定义了一个结构pirate，然后声明了俩个这个类型的变量，程序初始化其中一个，随后通过一个指向文件dada的输出流将它写入磁盘中，通过一个不同的流，程序直接从data中读取数据存储到pirate结构的另一个实例中，最后程序把这个结构的内容输出到标准输出中

```c
#include <stdio.h>
int main(void)
{
    FILE *in, *out;
    struct pirate
    {
        char name[100];//real name
        unsigned long booty;//in pounds sterling
        unsigned int beard_len;//in inches
    }p, blackbeard = {"Edward Teach", 950, 48};
    
    out = fopen("data", "w");
    if(!out)
    {
        perror("fopen");
        return 1;
    }
    if(!fwrite(&blackbeard, sizeof(struct pirate), 1, out))
    {
        perror("fwrite");
        return 1;
    }
    if(fclose(out))
    {
        perror("fclose");
        return 1;
    }
    
    in = fopen("data", "r");
    if(!in)
    {
        perror("fopen");
        return 1;
    }
    if(!fread(&p, sizeof(struct pirate), 1, in))
    {
        perror("fread");
        return 1;
    }
    if(fclose(in))
    {
        perror("fclose");
        return 1;
    }
    
    printf("name = \"%s\" booty = %lu beard_len = %u\n", p.name, p.booty, p.beard_len);
    return 0;
}
```

运行结果![image-20230417213812733](Com_pictrue/image-20230417213812733.png)

需要牢记的是，因为变量的长度、对齐等等的不同，一个程序的写入的二进制数据对另外一个程序可能是不可读的，就是说不同的程序即使是不同的机器上同一个程序，可能也不能正确的读取fwrite()写入的数据

### 定位流

​		通常，控制当前流的位置是很有用的，可能程序正在读取一个复杂的基于记录的文件，并且需要跳转。必要的时候，流可能需要将设置为文件的初始位置。标准IO提供了一系列功能等价于系统调用lseek()的函数——fseek()函数，操控流指向文件中由offset和whence指定的位置

```c
#include <stdio.h>
int fseek(FILE *stream, long offset, int whence);
//如果whence被设置为SEEK_SET，文件的位置被设置到offset处
//如果whence被设置为SEEK_CUR，文件位置被设置为到当前位置加上offset
//如果whence被设置为SEEK_END，文件位置被设置到文件末尾加上offset
```

成功时，fseek()返回0，清空文件结束标志，并且取消ungetc()操作；错误时，返回-1并且设置相应的errno值

常见的错误由非法流（EBADF）和非法whence参数（EINVAL）

另外标准I/O还提供了fsetpos()函数：

```c
#include <stdio.h>
int fsetpos(FILE *stream, fpos_t *pos);
```

这个函数将流设置到pos处，它和将whence设置为SEEK_SET时的fseek()功能一样，成功时返回0，失败返回-1并且相应的设置errno

标准I/O也提供了rewind()函数

```c
#include <stdio.h>
void rewind(FILE *stream);

//该调用
rewind(stream);
//将位重置到流的初始位置，等价于
fseek(stream, 0, SEEK_SET);
```

此外，它还清空了错误标记，rewind()没有返回值，因此不能直接提供错误信息。如果函数希望获取错误，需要在调用之前清空errno，并且检查这个变量在调用之后是否非零，例如

```c
errno = 0;
rewind(stream);
if(errno)
    ;//error
```

#### 获得流当前位置

与lseek()不同，fseek()不返回更新后的位置，一个单独的接口提供了该功能，ftell()函数返回当前流的位置

```c
#include <stdio.h>
long ftell(FILE *stream);//错误时返回-1，并相应的设置errno

//选择性的，标准输入输出提供了fgetpos()函数：
#include <stdio.h>
int fgetpos(FILE *stream, fpos_t *pos);
//成功时返回0，并且将当前流的位置设置为pos；失败时返回-1并相应的设置errno
```

和fsetpos()一样，fgetpos()只有在复杂文件位置类型的非linux平台上提供

### 清洗一个流

标准IO库提供了一个用来将用户缓冲区写入内核，并且保证所有的数据都通过write写出的函数，fflush()函数提供这一功能

```c
#include <stdio.h>
int fflush(FILE *stream);
```

调用该函数时，stream指向流中的所有未写入的数据会被清洗到内核中，如果stream为空NULL，所有进程打开的流会被清洗掉。成功时fflush()返回0；失败返回EOF并相应的设置errno

​		为了理解fflush()函数的作用，必须理解C函数维持的缓冲区和内核自己拥有的缓冲区的区别，以上提到的所有调用的缓冲区都是通过C函数库来维护的，它们保留在用户空间中，并且运行用户的代码，不执行系统调用。只有当磁盘或其他介质必须被访问时系统调用才会被执行，fflush()只是把用户缓冲的数据写入到内核缓冲区，效果和没有用户缓冲区一样，而且write()是被直接调用的，这不能保证数据能写入物理介质，如果有需要的话使用fsync()，更多的情况是在调用fflush()后，立即调用fsync()：就是说先保证用户缓冲区被写入到内核，然后保证内核缓冲区被写入到磁盘

### 错误和文件结束

​		一些标准的IO接口，例如fread()，向调用这传递失败信息的能力很差，因为没有提供区别错误和EOF的机制，有时候需要区分给定的流出现了错误还是达到了文件结尾，标准IO为此提供了俩个函数，

函数ferror()测试是否在流上设置了错误标志

```c
#include <stdio.h>
int ferror(FILE *stream);
```

​		错误标志由其他响应错误的标准IO函数设置，如果标志被设置，函数返回非零值，否则返回0。

函数feof()测试文件结尾标志是否被设置：

```c
#include <stdio.h>
int feof(FILE *stream);
```

​		当到达文件结尾时，EOF标志会被其他标准IO设置，如果标志被设置了，函数返回非零值，否则返回0，

clearerr()函数位流清空错误和文件结尾标志：

```c
#include <stdio.h>
void clearerr(FILE *stream);
```

​		它没有返回值，而且不会失败。只有在检查error和EOF标志之后才可以调用dlearerr()，因为该操作不可恢复，例如

```c
//'f' is a valid stream
if(ferror(f))
    printf("Error on f !\n");
if(feof(f))
    printf("EOF on f !\n");
clearerr(f);
```

### 获得关联的文件描述符

有时候，从流中获得文件描述符是很方便的，为了获得流的文件描述符，可以使用fileno()

```c
#includ <stdio.h>
int fileno(FILE *stream);
```

成功时，fileno()返回和流相关联的文件描述符，失败时返回-1。只有当给定的流非法时才可能发生这种情况，这时候函数会将errno设置为EBADF。通常不建议混合使用标准输入调用和系统调用，最好在执行获取文件描述符之前对流进行冲洗（fflush()）

### 控制缓冲

​		标准IO实现了对三种用户缓冲，而且为开发者提供了一个用来控制缓冲区大小和类型的接口，不同用户缓冲不同的功能，并适用于不同的场合，下面是一些选项：

**不缓冲**

没有执行用户缓冲，数据直接提交到内核，因为这和用户缓冲对立，这个选项通常不用，标准错误默认是不缓冲的

**行缓冲**

缓冲以行为单位执行，每当遇到换行符，缓冲区被提交到内核，行缓冲对输出到屏幕的流有用，因此它是终端的默认缓冲方式

**块缓冲**

缓冲以块为单位执行，适用于文件，默认的所有和文件相关的流都是块缓冲的，标准IO称块缓冲为全缓冲

​		大部分情况下，默认的缓冲类型是最高效的，然而标准IO也提供了一个用来控制使用的缓冲类型的函数

```c
#include <stdio.h>
int setvbuf(FILE *stream, char *buf, int mode, size_t size);
```

setvbuf()函数设置流的缓冲类型模式，模式必须为以下的一种：

_IONBF	无缓冲

_IOLBF	 行缓冲

_IOFBF	 块缓冲

除了无缓冲情况下buf和size会被忽略，buf可以指向一个size字节大小的缓冲空间，标准IO会用他来执行给定流的缓冲，如果buf为空，缓冲区则由glibc自动分配，setvbuf()函数必须在打开流后，但在执行任何操作前被调用，成功时返回0，错误时返回一个非零值

总的来说，开发者不用操心在流上的缓冲，除了标准错误外，终端是行缓冲的，文件是块缓冲的，而且这样就够了，默认的块缓冲区大小是在<stdio.h>中定义的BUFSIZ，而且通常情况下这是最优的选择

### 线程安全

​		线程就是在同一个进程中执行的多个实例，线程的定义为共享同一个地址空间的多个进程。如果不采取数据同步措施或将数据线程私有化，线程可以任何时间修改共享数据，支持线程的操作系统提供加锁机制来保证线程不会相互干扰，标准IO使用这些机制。

​		标准IO的函数本质上是线程安全，在内部实现中，设置了一把锁，一个锁计时器，和为每个打开的流创建的所有者线程。一个线程要想执行任何IO请求，必须首先获得锁而且成为所有者线程，俩个或多个运行在同一流上的线程不能交替的执行IO操作，因此在单独一个函数调用的上下文中，标准IO是原子的

​		在实际应用中，许多的应用程序需要比单独的函数调用有更强的原子性。如果多个线程正在执行写入请求，应用程序可能希望这些读写请求没有间断的完成，为了达到这个目的，标准IO为独立操纵和流关联的锁提供了一系列函数

#### 手动文件加锁

函数flockfile()会等待流被解锁，然后获得锁，增加锁技术，成为流的所有者线程，然后返回

函数funlockfile()减少与流相关的锁计数

```c
#include <stdio.h>
void flockfile(FILE *stream);

//函数funlockfile()
#include <stdio.h>
void funlockfile(FILE *stream);
```

如果锁计数器达到了0，当前的线程放弃流的所有权，另一个线程现在能够获得锁，这些调用可以嵌套，一个线程可以执行多个flockfile()调用，而流在程序执行相同数量的funlockfile()调用前不会解锁

```c
//ftrylockfile()是flockfile()的非堵塞版本
#include <stdio.h>
int ftrylockfile(FILE *stream);
```

如果当前流加了锁，ftrylockfile()不做任何操作，并立即返回一个非零值，如果当前流没有加锁，它获得锁，增加锁计数，成为流的所有者线程并且返回0

```c
//例子
flockfile(stream);
fputs("List of treasure: \n", stream);
fputs(" (1) 500 gold coins\n", stream);
fputs(" (2) Wonderfully ornate dishware\n", stream);
funlockfile(stream);
```

尽管单独的fputs()操作不会产生竞争，例如我们永远不会有内容打断 “List of treasure” 的输出，另一个线程可能会夹杂在当前线程的俩个fputs()语句中，理想情况下，一个应用程序的多个线程不应该向同一个流提交I/O操作

#### 不加锁流操作

​		手动给流加锁还有另外一个原因，只有应用开发者才能提供更精细和更准确的控制锁，可以将加锁的代价降到最小，并提高执行效率，为此Linux提供了一系列函数，类似于通常的标准IO接口，但是不执行任何操作，实际上为不加锁的标准IO

```c
#define _GNU_SOURCE
#include <stdio.h>

int fgetc_unlocked(FILE *stream);
char *fgets_unlocked(char *str, int size, FILE *stream);
size_t fread_unlocked(void *buf, size_t size, size_t nr, FILE *stream);
int fputs_unlocked(int c, FILE *stream);
int fputs_unlocked(const char *str, FILE *stream);
size_t fwrite_unlocked(void *buf, size_t size, size_t nr, FILE *stream);
int fflush_unlocked(FILE *stream);
int feof_unlocked(FILE *stream);
int ferror_unlocked(FILE *stream);
int fileno_unlocked(FILE *stream);
void clearerr_unlocked(FILE *stream);
```

​		除了它们不检查或获得指定流上的锁，这些函数与相对的加锁函数执行相同的操作，如果需要锁机制，程序员有责任保证手工获得并释放锁，它们都是Linux特有的

### 对标准I/O的反思

​		对标准IO最大的抱怨是双副本的性能影响，当读取数据的时候，标准IO对内核执行read()系统调用，从内核中复制数据到标准IO缓冲区，然后当一个程序通过标准IO执行一个读请求时，数据又被复制一次，这次从标准IO的缓冲区到指定的缓冲区。写入请求时用相反的方式运行：数据先从指定的缓冲空间复制到标准IO缓冲区，然后从标准IO缓冲区通过write()写入到内核

​		一个解决方法是，通过让每一个读请求返回一个指向IO缓冲区指针避免双复本。数据可以直接从标准IO缓冲区中读取，不需要多余的复制，当程序确实需要自己本地缓冲区数据时，总可以手动的执行复制，这个实现需要提供一个释放的接口，允许程序当它们完成缓冲区的一块读取时发出信号

​		写操作较为复杂，当执行一个写请求时，这个实现会记录指针位置，最终当准备好将数据冲洗到内核时再写出数据，通过分散-聚集IO中的writev()函数来实现，完成这个功能只需要一个系统调用

## 高级文件I/O

Linux提供更多的高级IO系统调用：

散布 / 聚集I/O	IO允许在单次调用中同时对多个缓冲区做读取或者写入操作，适合聚集了多个不同数据结构进行统一的IO操作

epoll				   poll()和select()的改进版，在一个程序需要处理数百个文件描述符的时候很有用

内存映射I/O		将文件映射到内存，可以通过简单的内存管理方式来处理文件；适合有特殊要求的IO

文件I/O提示		允许进程将文件IO使用上的一些提示信息提供给内核，能提升IO性能

异步I/O				允许进程发出多个IO请求而且不必等待其完成，适用于不适用线程的情况下处理重负载IO操作

### 散布 / 聚集I/O

​		散布聚集I/O是一种可以在单次系统调用中操作多个缓冲区的IO方法，可以将单个数据流的内容写到多个缓冲区，或者把单个数据流读到多个缓冲区中。这种方法的另一个名字是向量IO，相对的，文件IO中的标准读写系统调用可以被称作线性IO

散布聚集IO与线性IO相比有如下几个优点：

更自然的处理方式	如果数据是分段的，向量IO提供了直观的处理方式

效率  						单个向量IO操作能替代多个线性IO操作

性能						  除了系统调用次数的降低，由于内部优化，向量IO比线性IO提供更好的性能

原子性					   不同于多个线性IO操作，一个进程可以执行单个向量IO操作而且避免了与其他进程交叉操作的风险

#### readv()和writev()

Linux实现了俩个使用散布聚集机制的系统调用

readv()从fd读取count个segment到iov描述的缓冲区中

```c
#include <sys/uio.h>
ssize_t readv(int fd, const struct iovec *iov, int count);
```

write()从iov描述的缓冲区中读取count个segment的数据并写入fd中

```c
#include <sys/uio.h>
ssize_t writev(int fd, const struct iovec *iov, int count);
```

除了操作多个缓冲区外，readv()、writev()的行为和read()、write()一样，每个iovec结构体描述一个独立的缓冲区，我们称为段(segment)

```c
#include <sys/uio.h>
struct iovec
{
    void *iov_base;
    size_t iov_len;
}
```

​		一组segment的集合称为向量（vector），每个段描述了所要读写的缓冲区的地址和长度，readv()在处理下个缓冲区之前会填满当前缓冲区的iov_len个字节。writev()在处理下个缓冲区之前，把当前缓冲区所有iov_len个字节数据输出，俩个函数从iov[0]到iov[1]，知道iov[count-1]来顺序处理这些段

​		操作成功时，readv()和writev()分别返回读写的字节数，返回值等于所有iov_len的和，出错时返回-1并且设置errno。这些调用可能会返回任何read()和write()可能返回的错误，errno也会设置为相同的值此外，标准定义了俩种额外的错误

- 第一种情况，返回值类型为ssize_t，如果iov_len的和大于SSIZE_MAX，则不做处理，返回-1，errno设置为EINVAL
- 第二种情况，POSIX声明count必须大于0，小于IOV_MAX，如果count为0系统调用返回0，如果大于IOV_MAX不做处理返回-1，errno设置为EINVAL

![image-20230419141000290](Com_pictrue/image-20230419141000290.png)

#### writev()示例

一个简单的例子，把一个含有3个段，且每个段包含不同长度的字符串向量写入一个缓冲区

```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>

int main()
{
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;
    char *buf[] = {"The term buccaneer comes from the word boucan.\n", 
                   "A boucan is a wooden frame used for cooking meat.\n",
                   "Buccaneet is the West Indies name for a pirate.\n"};
    fd = open("buccaneer.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }
    
    //fill out three iovec structures
    for(i = 0; i < 3; i++)
    {
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i]+1);
    }
    
    //with a single call, write them all out
    nr = writev(fd, iov, 3);
    if(nr == -1)
    {
        perror("writev");
        return 1;
    }
    
    printf("wrote %d bytes\n", nr);
    if(close(fd))
    {
        perror("close");
        return 1;
    }
    return 0;
}
```



#### rear()示例

用readv()来从前面生成的文本文件读取数据

```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>

int main()
{
    char foo[48], bar[51], baz[49];
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;
    fd = open("buccaneer.txt", O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }
    
    //set up our iovec structures
    iov[0].iov_base = foo;
    iov[0].iov_len = sizeof(foo);
    iov[1].iov_base = bar;
    iov[1].iov_len = sizeof(bar);
    iov[2].iov_base = baz;
    iov[2].iov_len = sizeof(baz);
    
    //read into the structures with a single call
    nr = readv(fd, iov, 3);
    if(nr == -1)
    {
        perror("readv");
        return 1;
    }
    for(i = 0; i < 3; i++)
    {
        printf("%d: %s", i, (char*)iov[i].iov_base);
    }
    if(close(fd))
    {
        perror("close");
        return 1;
    }
    return 0;
}
```



#### 实现

我们可以在用户空间实现一个简单的readv()和writev()

```c
#include <unitd.h>
#include <sys/uio.h>

ssize_t native_writev(int fd, const struct iovec *iov, int count)
{
    ssize_t ret = 0;
    int i;
    for(i = 0; i < count; i++)
    {
        ssize_t nr;
        nr = write(fd, iov[i].iov_base, iov[i].iov_len);
        if(nr == -1)
        {
            ret = -1;
            break;
        }
        ret += nr;
    }
    return ret;
}
```

​		Linux下readv()和writev()作为系统调用实现，在内部使用散布聚集IO，实际上内核里的所有IO都是向量IO，read()和write()是只有一个向量的向量IO，且向量中只有一个段

### Event  Poll接口

​		由于poll()和select()的局限性，Linux内核引入了event poll(epoll)机制，虽然比前俩个实现复杂了很多，epoll解决了它们共有的基本性能问题并增加了一些新的特性。poll()和select()每次调用都要所有被监听的文件描述符，内核必须遍历所有被监听的文件描述符，当这个表很大时，每次调用的遍历就成为了明显的瓶颈

​		epoll()把监听注册从实际监听分离出来，一个系统调用初始化一个epoll上下文，另一个从上下文中加入或删除需要监视的文件描述符，第三个执行真正的事件等待（event wait）

#### 创建一个epoll()实例

使用epoll create()创建一个epoll上下文

```c
#include <sys/epoll.h>
int epoll_create(int size);
```

调用成功，epoll_create()创建一个epoll实例，返回与该实例关联的文件描述符，这个文件描述符和真正的文件没有关系，仅仅是为了后续调用使用epoll而创建的，size参数告诉内核需要监听的文件描述符数目，但不是最大值，传递一个适当的近似值会带来性能的提升，但不需要确切的数字，出错时返回-1，设置errno为下列值之一：

EINVAL	 size不是正数

ENFILE	 系统达到打开文件数的上限

ENOMEN  没有足够的内存来完成该次操作

```c
//一个标准的调用
int epfd;
epfd = epoll_create(100);//plan to watch ~100 fds
if(epfd < 0)
    perror("epoll_create");
```

epoll_create()返回的文件描述符需要调用close()关闭

#### 控制epoll

epoll_ctl()可以向指定的epoll上下文加入或删除文件描述符

```c
#include <sys/epoll.h>
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

//头文件<sys/epoll.h>中定义了epoll event结构体
struct epoll_event
{
    __u32 events;
    union
    {
        void *ptr;
        int fd;
        __u32 u32;
        __u64 u64;
    }data;
};
```

​		epoll ctl()成功调用将关联epoll()实例和epfd，参数op指定对fd要进行的操作，event参数描述epoll更具体的行为

以下为参数op的有效值：

EPOLL_CTL_ADD	把fd指定的文件添加到epfd指定的epoll实例监听集中，监听event中定义的事件

EPOLL_CTL_DEL	把fd指定的文件从epfd指定的epoll监听集中删除

EPOLL_CTL_MOD   使用event改变在已有fd上的监听行为

​		epoll events结构体中的events参数列出了在给定文件描述符上监听的事件，多个事件可以使用位或运算同时指定，以下为有效值：

EPOLLERR			文件出错，即使没有设置，这个事件也是被监听的

EPOLLET			   在监听文件上开启边沿出发，默认行为是水平触发

EPOLLHUP			文件被挂起，即使没有设置，这个事件也是被监听的

EPOLLIN				文件未阻塞，可读

EPOLLONESHOT  在一次事件产生并处理后，文件不再被监听，必须使用EPOLL_CTL_MOD指定新的事件以便重新监听文件

EPOLLOUT			文件未阻塞，可写

EPOLLPRI			 高优先级的带外数据可读

​		event_poll中data字段由用户使用，确认监听事件后，data会被返回给用户，通常将event.data.fd位设定fd，这样就能知道哪个文件描述符触发事件。成功epoll_ctl()返回0，失败返回-1，并设置errno为以下值：

EBADF			epfd不是一个有效epoll实例，或者fd不是有效文件描述符

EEXIST		   op为EPOLL_CTL_ADD，但是fd已经和epfd关联

EINVAL			epfd不是一个epoll实例，epfd和fd相同，或者op无效

ENOENT		 op是EPOLL_CTL_MOD，或者EPOLL_CTL_DEL，但是fd没有与epfd关联

ENOMEN		没有足够内存完成进程的请求

EPERM		   fd不支持epoll

```c
//在epfd实例中加入一个fd指定的监听文件
struct epoll_event event;
int ret;
event.data.fd = fd;//return the fd to us later
event.events = EPOLLIN | EPOLLOUT;
ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
if(ret)
    perror("epoll_ctl");

//修改epfd中的fd上的一个监听事件
struct epoll_event event;
int ret;
event.data.fd = fd;//return the fd to us later
event.events = EPOLLIN;
ret = epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &events);
if(ret)
    perror("epoll_ctl");

//从epfd中移除fd上的一个监听事件
struct epoll_event event;
int ret;
event.data.fd = fd;//return the fd to us later
event.events = EPOLLIN;
ret = epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &event);
if(ret)
    perror("epoll_ctl");
```

需要注意到的是，op为EPOLL_CTL_DEL时，因为没有设置事件掩码，event参数可以为NULL

#### 等待epoll事件

epoll_wait()等待给定epoll实例关联的文件描述符上的事件

```c
#include <sys/epoll.h>
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
```

对于epoll_wait()的调用等待epoll实例epfd中的文件fd上的事件，时限为timeout毫秒，成功返回，events指向包含epoll_event结构体的内存，且可以有maxevents个事件。返回值是事件数，出错返回-1，并将errno设置为以下值

EBADF		epfd是无效文件描述符

EFAULT	   进程对events指向的内存无写权限

EINTR		 系统调用在完成前被信号中断

EINVAL	   epfd不是有效epoll实例，或者maxevents小于0

如果timeout为0，即使没有事件发生，调用也立即返回0，如果timeout为-1，调用将一直等待到有事件发生。当调用返回，epoll_event结构体中的events字段描述了发生的事件，data字段包含了所有用户在调用epoll_ctl()前的设置

```c
//一个完整的epoll_wait()例子
#define MAX_EVENTS 64
struct epoll_event *events;
int nr_events, i, epfd;
events = malloc(sizeof(struct epoll_event) *MAX_EVENTS);
if(!events)
{
    perror("malloc");
    return 1;
}

nr_events = epoll_wait(epfd, events, MAX_EVENTS, -1);
if(nr_events < 0)
{
    perror("epoll_wait");
    free(event);
    return 1;
}
for(i = 0;i < nr_events; i++)
    printf("event = %ld on fd = %d\n", events[i].events, events[i].data.fd);
//We now can, per events[i].events, operate on events[i].data.fd without blocking
free(events);
```



### 存储映射

​		除了标准文件IO，内核提供了另一种IO方式，允许应用程序将文件映射到内存中，即内存和文件中的数据一一对应，程序员可以直接通过内存访问文件，就像操作内存的数据块一样，甚至可以写入内存数据区，然后通过透明的映射机制将文件写入磁盘，Linux实现了mmpap()系统调用，该调用将对象映射到内存中，mmap()在IO中将文件映射到内存中

#### mmap()

mmap()调用请求内核将fd表示的文件中从offset处开始的len个字节数据映射到内存中。如果包含addr，表明优先使用addr为内存中的开始地址。访问权限由prot指定，flags指定了其他的操作行为

```c
#include <sys/mman.h>
void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
```

addr参数高数内核映射文件的最佳地址，仅仅只是提示，而不是强制要求，大部分时候传递0，该调用返回内存映射区域的开始地址，prot参数描述了对内存区域所请求的访问权限，如果是PROT_NONE，此时映射区域无法访问，也可以是下面标志位的比特位的或运算值

PROT_READ		页面可读

PROT_WRITE	  页面可写

PROT_EXEC		页面可执行

要求的访存权限不能和打开文件的访问模式冲突，例如如果程序以只读方式打开文件，prot不能设置为PROT_WRITE

![image-20230419190126786](Com_pictrue/image-20230419190126786.png)

flag参数描述了映射的类型和一些行为，其值为以下值按二进制或运算的值

MAP_FIXED		告诉mmap()把addr作为强制性要求，如果内核无法映射文件到指定地址，调用失败。如果地址和长度指定的内存和已							有的映射由重叠区域，重叠区原有的内容被丢弃，用新内容填充

MAP_PRIVATE    映射区不共享，文件映射采用了写时拷贝，进程对内存的任何改变不会影响真正的文件或者其他进程的映射

MAP_SHARED    和所有其他映射该文件的进程共享映射内存，对内存的写操作等效于写文件，读操作会受到其他进程写操作的影响

​		当你映射了一个文件描述符时，描述符引用计数增加，因此如果你映射文件后关闭文件，你的进程依然可以访问该文件，当取消映射或者进程终止时，对应的文件引用计数会减1

```c
//用只读方式映射fd所指向的文件，从第一个字节开始，长度为len个字节
void *p;
p = mmap(0, len, PROT_READ, MAP_SHARED, fd, 0);
if(p == MAP_FAILED)
    perror("mmap");
```

##### 页大小

​		页时内存中允许具有不同权限和行为的最小单元，因此页时内存映射的基本块，同时也是进程地址空间的基本块。mmap()调用操作页，addr和offst参数都必须按页大小对齐，也就是必须为页大小的整数倍。所以，映射区域时整数倍个页，如果len参数不能按页对齐映射区域延申到下个空页，多出来的内存，即最后一个有效字节和映射区域边界用0填充，该区域的读操作都将返回0。

**sysconf()**：标准POSIX规定的获得页大小的方法是通过sysconf()，它将返回一系列系统特定的信息

```c
#include <unistd.h>
long sysconf(int name);
```

调用sysconf()返回name的值，如果name无效返回-1，出错时errno被设置为EINVAL，因为-1对一些情况来说是有效值，明智的做法是在调用前清空errno并在调用后检查其值

POSIX定义了SC_PAGESIZE，大小为一个页面的字节大小，因此的到页大小为：

```c
long page_size = sysconf(_SC_PAGESIZE);
```

**getpagesize()**：linux也提供getpagesize()函数来获得页大小

```c
#include <unistd.h>
int getpagesize(void);

//调用getpagesize()将返回页按字节计数的大小
int page_size = getpagesize();
```

**页大小**：页大小由<asm/pages.h>中的宏PAGE_SIZE定义，因此获得页大小的方法也可以为

```c
int page_size = PAGE_SIZE;
```

不同于前俩种方法，该方法是编译时获得页大小，而不是运行时，一个二进制文件应该能在给定体系结构下的所有机型上运行，即一次编译，到处运行。硬编码页大小则会终结这种可能性，因此应该在运行时确定页的大小，目前来看sysconf()是最好的选择。

##### 返回值和错误码

调用成功，mmap()返回映射区的地址，失败时返回MAP_FAILED，并设置相应的errno，mmap()不返回0

可能的errno值：

EACESS			给定的文件描述符不是普通文件，或者打开模式和prot或flags冲突

EAGAIN			 文件已经被文件锁锁定

EBADF			  给定文件描述符无效

EINVAL			 addr、len、off中的一个或多个无效

ENFILE			 打开文件数达到了系统上限

ENODEV		   文件所在的文件系统不支持存储映射

ENOMEM 		 没有足够的内存

EOVERFLOW    addr+len的结果超过了地址空间大小

EPERM			  设定了PROT_EXEC，但是文件系统以不可执行方式挂载

相关信号

​		俩个和映射区域相关的信号

SIGBUS			当进程试图访问一块已经无效的映射区域时，该信号产生，比如文件在映射后被截短

SIGSEGV		 当进程试图写一块只读的映射区域时，该信号产生

#### munmap()

Linux提供munmap()来取消mmap()的映射

```c
#include <sys/mman.h>
int munmap(void *addr, size_t len);
```

​		munmap()移除进程地址空间addr开始，len字节长的内存中的所有页面的映射，当映射被解除时，之前关联的内存区域不再有效，如果视图访问会产生SIGSEGV信号。通常，munmap()的参数是上次mmap()调用的返回值和其参数len

调用成功返回0，失败返回-1，errno被设置为相应的值，唯一标准的errno值为EINVAL，表明一个或多个参数无效

```c
//该实例解除了内存中[addr, addr+lrn]区间内所有页的映射
if(munmap(addr, len) == -1)
    perror("munmap");
```

#### 存储映射例子

```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
    struct stat sb;
    off_t len;
    char *p;
    int fd;
    if(argc < 2)
    {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }
    
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }
    if(fstat(fd, &sb) == -1)
    {
        perror("fstat");
        return 1;
    }
    if(!S_ISREG(sb.st_mode))
    {
        fprintf(stderr, "%s is not a file\n", argv[1]);
        return 1;
    }
    
    p = mmap(0, sb.st_size, PORT_READ, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }
    if(close(fd) == -1)
    {
        perror("close");
        return 1;
    }
    
    for(len = 0; len < sb.st_size; len++)
        putchar(p[len]);
    if(munmap(p, sb.st_size) == -1)
    {
        perror("munmap");
        return 1;
    }
    
    return 0;
}
```

fstat()返回给定文件的信息，S_ISREG()宏可以检查这些信息，这样能够在映射前确保给定文件是个普通文件，例子是传递一个文件名作为程序参数，打开文件确保其为普通文件，映射后关闭文件，按字节打印文件到标准输出后取消映射

#### mmap()的优点

相对于read()、write()，使用mmap()处理文件有很多优点

- 使用read()或write()系统调用需要从用户缓冲区进行数据读写，而使用映射文件进行操作，可以避免多余的数据拷贝
- 除了潜在的页错误，读写映射文件不会带来系统调用和上下文切换的开销，就像直接操作内存一样简单
- 当多个进程映射同一个对象到内存中，数据在进程间共享，只读和写共享的映射在全体都是共享的
- 在映射对象中搜索只需要一般的指针操作，而不必使用lseek()

所以，mmap()是很多应用的明智选择

#### mmap()的缺陷

使用mmap()时需要注意

- 映射区域的大小通常是页大小的整数倍，因此映射文件大小和页大小的整数倍之间有空间浪费
- 存储映射区域必须在进程地址空间内
- 创建和维护映射以及相关的内核数据结构有一定的开销，通过消除读写时不必要的拷贝可以忽略该开销

基于以上原因，处理大文件或者在文件大小恰好被page大小整除了优势很明显

#### 调整映射大小（mremap）

Linux提供了mremap()来扩大或减少已有映射大小，这是Linux特有的

```c
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/mman.h>
void *mremap(void *addr, size_t old_sizem, size_t new_size, unsigned long flags);
```

​		mremap()将映射区域[ addr, addr+old size )的大小增加或减少到new_size，依赖进程地址空间的可用大小和flags，内核可以同时移动映射区域。flags参数的值可以是0或者MREMAO_MAYMOVE，这意味着为了执行调整指定的大小，内核可以根据需求移动映射区域，如果内核可以移动映射，一个较大规模的大小调整操作就可能成功。

返回值和错误码

调用成功，mremap()返回指向新映射区域的指针，失败则返回MAP_FAILED并设置errno：

EAGAIN			内存区域被锁，不能调整大小

EFAULT			 给定范围内的一些页不是进程地址空间内的有效页，或者在重新映射给定页时出现问题

EINVAL			  一个参数无效

ENOMEM		  给定范围如果不进行移动则无法扩展，或者进程地址空间内没有足够空闲空间

glibc等库经常使用mremap()实现高效的realloc()，可以通过它调整一块由malloc()分配的内存，例如

```c
void *realloc(void *addr, size_t size)
{
    size_t old_size = look_up_mapping_size(addr);
    void *p;
    p = mremap(addr, old_size, len, MREMAP_MAYMOVE);
    if(p == MAP_FAILED)
        return NULL;
    return p;
}
```

这段代码只在所有malloc()操作是唯一的匿名映射时有效，即使如此，这段代码也能作为展示尽量提高性能的有用样例，这个例子假设程序员已经写了一个look_up_mapping_size()函数，GNU C library使用mmap()及其相关的函数来进行内存分配

#### 改变映射区域的权限（mprotect)

POSIX定义了mprotect()，允许程序改变已有内存区域的权限

```c
#include <sys/mman.h>
int mprotect(const void *addr, size_t len, int prot);
```

调用mprotect()会改变[ addr, addr+len )区域内页的访问权限，addr是页对齐的，prot参数和mmap()的prot参数有同样的值：PROT_NONE、PROT_READ、PROT_WRITE、PROT_EXEC，这些值不是累加的，如果一区域可读prot值设置为PROT_WRITE，调用后该区域为只写。在Linux上mprotect()可以操纵任意区域的内存

返回值和错误码

调用成功，mprotect()返回0，失败返回-1，，设置errno为以下值之一

EACCESS		内存不能设置prot所请求的权限，例如视图将一个只读打开的文件映射为可写

EINVAL			 addr无效或者没有页对齐

ENOMEM		 内核没有足够空间满足请求，或者请求区域内有页面不是进程地址空间内的有效部分

#### 使用映射机制同步文件（msync）

POSIX提供了一个使用存储映射机制并与fsync()等价的系统调用

```c
#include <sys/mman.h>
int msync(void *addr, size_t len, int flags);
```

​		使用msync()可以将mmap()生成的映射在内存中的任何修改回写到磁盘，达到同步内存中的映射和被映射文件的目的，具体来说是文件或者文件的子集在内存中的映射从addr开始的len长度字节被写回到磁盘，addr参数必须是页对齐的，通常是mmap()调用的返回值

​		不调用msync()，无法保证在映射取消前，修改过的映射会被写回到硬盘，这点和write()不同，被write()修改的缓冲区被保存在一个队列中等待被写回，当写入内存映射时，进程直接修改内核页缓存中的文件页，而无需经过内核，内核不会立即同步页缓存到硬盘

flag参数控制同步操作的行为，它的值为以下值的二进制或操作：

MS_ASYNC			指定同步操作异步发生，更新操作需要由系统调度，msync()会立即返回，不用等待write()操作完成

MS_INVALIDATE	指定该块映射的其他所有拷贝都将失败，未来对该文件任意映射的操作将直接同步到磁盘

MS_SYNC			   指定同步操作必须同步进行，msync()直到所有页写回磁盘后返回

MS_ASYNC和MS_SYNC必须指定其一，二者不能共用

```c
//用法示例
if(msync(addr, len, MS_ASYNC) == -1)
    perror("msync");
//该例子是异步的将文件的映射区域[addr, addr+len)同步到磁盘
```

调用成功，msync()返回0，失败返回-1并设置为以下值之一

EINVAL		flags参数同时设置了MS_SYNC和MS_ASYNC，设置了除以上三个合法参数外的其他参数或者没有页对齐

ENOMEM	指定的内存区域没有被映射，按POSIX规定，Linux在请求同步一块部分解除映射的内存时，将返回ENOMEM但是这样可能					会同步一些无效区域

#### 映射提示（madvise）

​		Linux提供了madvise()系统调用，可以让进程在如何访问映射区域上给内核一定的提示；内核会据此优化自己的行为，尽量更好的利用映射区域；内核一般会动态调整自己的行为，通常即便在没有明确的提示时也能保证较好的性能，但是恰当的提示信息可以确保一定负载下获得所需的缓存和执行正确操作的预读

调用会指示内核如何对起始地址为addr，长度为len的内存映射区域进行操作

```c
#include <sys/mman.h>
int madvise(void *addr, size_t len, int advice);
```

如果len为0，内核将所有起始地址为addr的映射使用该提示信息，参数advice可以是下列之一

MADV_NORMAL		   对给定的内存区域，应用程序没有特殊提示，按正常方式操作

MADV_RANDOM		   应用程序将以随机顺序访问指定区域的页

MADV_SEQUENTIAL    应用程序意图从低地址到高地址顺序访问指定范围的页

MADV_WILLNEED		应用程序将很快访问指定范围的页

MADV_DONTNEED	  应用程序短期内不会访问指定范围内的页

​		内核得到提示后正在采取的行为和具体的实现是相关的：POSIX仅仅制定了提示含义，没有规定具体的行为，内核以如下方式处理

MADV_NORMAL		   内核行为照常，进行一定程度的预读

MADV_RANDOM		   内核不做预读，每次物理读操作只读取最小量的数据

MADV_SEQUENTIAL    内核大量预读

MADV_WILLNEED		内核将给定的页预读进内存

MADV_DONTNEED	  内核释放所有和给定页相关的资源，丢弃所有被修改的，为同步写回的页，后续对映射数据访问会使数据重新载				 					  入内存

```c
//典型用法
int ret;
ret = madvise(addr, len, MADV_SEQUENTIAL);
if(ret < 0)
    perror("madvise");
//该调用告诉内核，进程意图连续访问内存区域[addr, addr+len)
```

![image-20230421103047691](Com_pictrue/image-20230421103047691.png)

返回值和错误码

调用成功。madvise()返回0；失败时返回-1，设置errno为相应值，以下为有效错误值

EAGAIN			内核内部资源不可用，进程可以重试

EBADF			 区域存在，但是没有映射文件

EINVAL			参数len是负数，addr不是页对齐的，advice参数无效，或者页面被锁，或以MADV_WILLNEED操作引起的内部IO错误

ENOMEM		给定的区域不是进程地址空间的有效映射，或者设置MADV_WILLNEED但是没有足够内存可供分配



### 普通文件I/O提示

​		上面的操作为如何给内核提供存储映射的操作提示，以下内容为在普通文件IO时，如何给内核提供操作提示，Linux提供了俩个满足要求的函数：posix_fadvise()和readahead()

#### posix_fadvise()

该函数由POSIX 1003.1-2003定义

```c
#include <fcntl.h>
int posix_fadvise(int fd, off_t offset, off_t len, int advice);
```

​		调用posix_fadvise()会给出内核在文件fd[ offset, offset+len )范围内操作提示，如果len为0，则该提示会作用于区间[ offset, length of file ]。一般用法时设置len和offset为0，从而使设置应用到整个文件

advice的可用选项和madvise()类似，是以下选择的其中之一：

POSIX_FADV_NORMAL			 应用程序在给定文件的给定区域没有特殊要求，但正常情况处理

POSIX_FADV_RANDOM			应用程序在给定范围内趋向于随机访问

POSIX_FADV_SEQUENTIAL	  应用程序在给定范围内趋向于从低地址到高地址顺序访问

POSIX_FADV_WILLNEED		  应用程序可能在最近访问指定范围

POSIX_FADV_NOREUSE		   应用程序可能在最近访问指定范围，但只访问一次

POSIX_FADV_DONTNEED		 应用程序最近可能不会访问给定范围

​		和madvise()一样，内核对这些提示的处理因不同的实现而有区别，下面的内核的处理方式

POSIX_FADV_NORMAL			 内核行为如常，有适量预读行为

POSIX_FADV_RANDOM			 内核禁止预读，每次物理读操作尽可能读取最少的数据

POSIX_FADV_SEQUENTIAL	  内核大量预读，读取预读窗口俩被长度的数据

POSIX_FADV_WILLNEED		   内核开始预读，并将指定页读到内存中

POSIX_FADV_NOREUSE		    当前，其行为和POSIX_FADV_WILLNEED行为一致，为了可能改变

POSIX_FADV_DONTNEED		 内核丢弃所有缓存的数据

```c
//该代码要求内核随机、无序访问fd代表的文件
int ret;
ret = posix_fadvise(fd, 0, 0, POSIX_FADV_RANDOM);
if(ret == -1)
    perror("posix_fadvise");
```

返回值和错误码

调用成功返回0，失败返回-1，设置errno为下列值

EBADF	文件描述符无效

EINVAL	advice无效，文件描述符指向一个管道，或者设定选项无法应用到给定的文件

#### readahead()

​		posix_fadvise()是新内核加入的系统调用，在此之前，readahead()可用完成posix_fadvise()试用POSIX_FADV_WILLNEED选项的同样功能，readahead()是Linux独有的

```c
#include <fcntl.h>
ssize_t readahead(int fd, off64_t offset, size_t count);
```

readahead()调用将读入fd表示的文件[ offset, offset+count )区域到页缓存中

返回值和错误码

调用成功返回0，失败返回-1，设置errno为下列值

EBADF		文件描述符无效

EINVAL	    文件描述符对应的文件不支持预读

#### 经济适用的操作提示

​		通过向内核传递一些操作提示，一些普通应用的效率会提升

​		在读取一个文件的大部分内容时，进程可用通过设置POSIX_FADV_WILLNEED要求内核把文件预读到页缓存中，IO操作将在后台异步进行，当应用最终要访问文件时，访问操作可以立即返回，不会被阻塞

​		相反的，在读取或写入大量数据后，检查可以设置POSIX_FADV_DONTNEED要求内核丢弃缓存中的内容，大量的流操作会填满页缓冲区，如果进程不会再次访问这些数据，意味着缓冲区充斥了过量的数据，会导致没有空间保存有用的数据，因此对于视频流一类的应用，需要定期的请求将数据从缓存中清除

​		一个进程试图读取整个文件时，设置POSIX_FADV_SEQUENTIAL要求内核大量预读；相反的，如果一次进程直到自己将随机访问文件，设置POSIX_FADV_RANDOM，告诉内核预读无用

#### Synchronized、Synchronous及Asynchours操作

​		同步（synchronous）写操作在数据全写到内核缓冲区之前是不会返回的；同步（synchronous）读操作在数据写到应用程序在用户空间的缓冲区之前是不会返回的。相反，异步（asynchronous）写操作在用户空间还有数据时可能就返回了；异步（asynchronous）读操作在数据准备好之前可能就返回了。也就是说操作不会被放入操作队列以便在稍后进行。

​		一个同步的操作（synchronized）要比同步（synchronous）操作的限制更多，也更加安全。同步（synchronized）写操作把数据写回磁盘。确保硬盘上的数据和内核缓冲区中的是同步的；同步（synchronized）的读操作总是返回最新的数据（有可能从硬盘中读取）

​		总的来说同步（synchronous）和异步（asynchronous）指IO操作在返回前是否等待某些事件返回。而术语同步（synchronized）和异步（asynchronized）准确的指定了某个事件必须发生

​		通常Unix的写操作是同步（synchronous）和非同步的（nonsynchronized）；读操作是同步（synchronous）和同步的（synchronized）

![image-20230421150736629](Com_pictrue/image-20230421150736629.png)

​		因为读取旧数据没有意义，读操作通常是同步的（synchronized）。这样的操作既可以是同步的（synchronous），也可以是异步的（asynchronous）的

![image-20230421150900496](Com_pictrue/image-20230421150900496.png)

异步IO

执行异步IO需要内核在底层的支持，Linux实现了aio，aio库通过一系列函数来实现异步IO提交以及在完成时收到通知

```c
#include <aio.h>
//asynchronous I/O control block
struct aiocb
{
    int aio_filedes;//file descriptor
    int aio_lio_opcode;//operation to perform
    int aio_reqprio;//request priority offset
    volatile void *aio_buf;//pointer to buffer
    size_t aio_nbytes;//length of operation
    struct sigevent aio_sigevent;//signal number and value
    
    //internal, private members follow
}
int aio_read(struct aiocb *aiocbp);
int aio_write(struct aiocb *aiocbp);
int aio_error(const struct aiocb *aiocbp);
int aio_return(struct aiocb *aiocbp);
int aio_cancel(int fd, struct aiocb *aiocbp);
int aio_fsync(int op, struct aiocb *aiocbp);
int aio_suspend(const struct aiocb *const cblist[], int n, const struct timespec *timeout);
```

### I/O调度器和I/O性能

​		在现代系统中，硬盘和系统其他部分的性能差距很大，而且还在增大，硬盘性能最糟糕的部分时执行seek操作的时候，在此过程中磁头从磁盘的一个部分移动到另一个部分。当了解了硬盘和系统其他部分的性能差距，可以发现等待IO操作按他们请求顺序完成将会是非常原始和低效的，因此现代操作系统内部实现了IO调度器。通过管理IO请求的顺序和次数使磁盘寻道次数和移动距离最小化，IO调度器尽力将硬盘访问的性能损失控制在最小

#### 磁盘寻址

​		磁盘基于用柱面（cylinders），磁头（heads）和扇区（section）几何寻址方式来获取数据，这种方式也被称为CHS寻址，每个磁盘都是由多个盘片组成的，每个盘片包括一个磁盘，一个主轴和一个读写头，可以把每个盘片看作一个CD，磁盘上所有盘片看作一摞CD，每个盘片分成很多环状的磁道，每个磁道分为整数倍个扇区

​		要确定某块特定数据单元在磁盘上的位置，驱动程序需要直到三个值：柱面、磁头和扇区，柱面值确定了数据在哪个磁道上，如果把盘片放成一摞，磁道上所有盘片上确定了一个柱面，也就是说一个柱面代表了所有盘片上离盘中心相同距离的磁道。磁头值表明了准确的磁头，现在搜索定位到了单个盘片的单个磁道，磁盘驱动然后利用扇区找到磁道上准确的扇区。搜索结束，磁盘知道了数据的位置，然后定位读写头到正确的盘片上正确的磁道，从正确的商扇区读写

​		现代操作系统不会直接操作磁盘的柱面、磁头和扇区。它可以直接使用块号（即逻辑块寻址LBA）访问磁盘，硬盘驱动程序转换块号到正确的CHS地址，很自然的，块到CHS的映射是连续的：物理块n和逻辑块n+1是物理上相邻的。文件系统存在于软件层，它们操作自己的操作单元，即逻辑块，其大小必须是物理块大小的整数倍，换句话说文件系统的逻辑块映射到一个或多个硬盘物理块

#### 调度器功能

​		IO调度器实现了俩个基本操作：合并（merging）和排序（sorting）。

​		合并（merging）操作是将俩个或多个相邻的IO请求的过程合并为一个。考虑两次请求，一次读取5号块，另一次读取6和7上的数据，这些请求被合并为一个对块5到7的操作，总的IO吞吐量可能一样，但是IO的次数减少了一半

​		排序（sorting）是选取俩个操作中相对更重要的一个，并按块号递增的排序重新安排等待的IO请求。比如说IO操作要求访问块号52，109和7，IO调度这三个请求以7、52、109的顺序进行排序，如果一个请求现在要访问81，它将会被插到访问52和109中间，然后IO调度器会按它们在队列中的顺序排列。这方式使得磁盘头移动距离最小

#### 改进读请求

​		每次读请求必须返回最新的数据，因此当请求的数据不在页缓存中时，读请求在数据从磁盘读出前会一直阻塞，将这种性能损失称为读延迟（read latency）。

​		一个典型的程序可能在短时间有几个IO请求，因为每个请求都分别进行同步，稍后的请求将依赖于前面的请求；这和其险恶请求形成了鲜明的对比，写请求在短时间内不需要发起任何的IO操作。从用户空间程序角度看，写操作不会受硬盘性能的影响，写操作只有在和读操作组合使用的时候才会引起问题：因为写操作的数据流，它们可以吸引内核和硬盘的注意

如果IO调度器以插入的顺序来对请求排序，可能会无限期的推迟对较远块的访问请求，比如一直有50-60块之间的请求会导致109块的访问请求一直不被调度到，所以IO调度器使用一种机制避免“饿死”的发生

**Deadline I/O调度器**

​		Deadline I/O调度器是为了解决传统的电梯调度算法的问题。Linus电梯算法维护了一个经过排序的IO等待列表，队列首的IO请求是下一个被调度的。Deadline IO调度器保留了这个队列，为了改进增加了俩个新的队列：读FIFO队列和写FIFO队列，队列中的项按请求提交事件排序。读FIFO队列只包含读请求，写FIFO队列只包含写请求。FIFO队列中每个请求都设置了一个过期时间。当一个FIFO队列头的请求超过了所在队列的过期时间时，IO调度停止从标准IO队列中调度请求，转而调度这个FIFO队列的队首请求。

​		按这种方式，Deadline I/O调度器在IO请求上加入了最后期限，虽然不能保证在过期时间前调度IO请求，但是一般都在过期时间左右调度请求，因此Deadline I/O调度器能提供很好的吞吐量，而且不会让任一请求等待过长时间

**Anticipatory I/O调度器**

​		Deadline I/O调度器表现很好，但不是完美的。当面对众多独立的读请求时，问题依然会出现，每一个读请求在前一个请求返回后才会执行，当应用程序得到数据，准备运行并提交了下一个读请求时，IO调度程序以及去处理其他的请求了，这样导致了每次搜素都要进行不必要的寻道操作。如果存在一个方法使IO调度器预知对磁盘同一部分的访问，将在下一次请求中提交，就可以等待下次的读，而不必往复进行查找定位。

​		anticipatory I/O调度器的工作原理很清楚，它像Deadline一样开始，但具有预测机制，当一个读操作被提交，anticipatory I/O调度器在它终止期限前调度它，不同于Deadline，anticipatory I/O调度器会等待6毫秒，如果应该程序在这期间内对硬盘同一部分发出另一次读请求，读请求立即被相应，anticipatory I/O调度器继续等待。如果6毫秒没有收到读请求，anticipatory I/O调度器确认预测错误，然后返回进行正常操作。

**CFQ I/O调度器**

​		尽管方法上有所区别，但Complete Fair Queuing（CFQ） I/O调度器和上述调度器程序的目标是相同的，使用CFQ时，每个进程都有自己的队列，每个队列分配一个时间片，IO调用程序使用轮转方式访问并处理队列中的请求，直到队列的时间片耗尽或所有的请求都被处理完成。后一种情况，调度器会空转一段时间（默认10毫秒），等待当前队列中新的请求，预测成功IO调度器避免了查找操作；预测无效则处理下一个进程的队列

​		每个进程的队列中，同步（synchronized）的请求被赋予了比非同步请求更高的优先级。因为进程队列设置，CFQ调度器对所有进程都是公平的，同时提供了优秀的全局性能，CFQ调度器适合高负载的情况，并且是这种情况下的第一选择

**Noop I/O调度器**

​		Noop I/O调度程序是目前最简单的调度器，无论什么情况，它都不进行排序操作，只是简单的合并，一般用在不需要对请求排队有特殊的设备上。

### 优化I/O的性能

因为磁盘IO相比系统其他部分很慢，同时IO系统又是现代计算机很重要的一部分，因此IO性能的提升十分重要，减少IO操作的次数，实现块对齐的IO或者使用用户空间缓冲，利用高级IO的优点例如向量IO、定位IO、异步IO，都是系统编程过程中需要经常考虑的重要步骤

​		一些关键任务和IO操作频繁的应用程序，可以使用额外的技巧来优化性能，即使linux内核也利用高级IO调度器减少磁盘寻道次数，用户空间的程序可以使用类似的方式，事项更多的性能提升

#### 用户空间的I/O调度

​		进行大量IO调用的IO密集型应用可以通过使用类似于Linux IO调度器的方法，来对挂起的IO请求进行排序和合并，进而获得更多的性能提升，当有一个程序会产生大量的请求，尤其请求会遍布整个磁盘时，最好在提交前对其进行排序，确保它们有序提交给IO调度器，这样将带来很大的性能提升

​		对于同样的信息，用户空间的程序和内核不见得有同样的访问权限，在IO调度器的最底层，请求已经是以物理块的形式进行组织，对物理块进行排序是麻烦的，但是在用户空间，请求是以文件和文件偏移的形式存在的，用户应用程序必须获取信息，对文件系统的布局进行适当的猜测，为了使IO请求能以有利于寻址操作的顺序提交，用户空间程序可以做不同的处理，可以按照以下方式进行排序：

1、完整路径

2、inode编号

3、文件的物理块

##### 按路径排序

​		**按路径排序**：这是最简单的，也是效率最低的接近块排序的方法，在大部分文件系统采用的布局算法中，每个目录里的文件倾向于在磁盘上相邻分布。同一个目录中的文件，如果在间隔很短的时间内一次创建，相邻的几率更大。按路径排序，粗略接近文件在磁盘上的物理分布，在同一目录下的文件显然比在文件系统完全不同俩部分的俩个文件有更大的概率邻近分布。

这种分布的缺点就是没有考虑文件系统的碎片，如果文件系统碎片很多，按路径排序的作用小。即便忽略了碎片，按路径排序也只能说接近实际的物理块顺序。优点是至少所有文件系统都是可用的，空间局限性显示使用路径排序至少有中等精确度，此外该种排序最容易实现

##### 按inode排序

​		**按inode排序**：inode是Unix中包含和文件唯一相关的元信息的结构，一个文件可能占用多个物理块，但只有一个inode，其中包含文件大小、权限、所有者等信息。每个文件都有一个inode与其关联，这个inode是由数字来唯一标识，使用inode排序比路径排序更有效。

考虑如下关系：文件 i 的inode序号   <   文件 j 的inode序号

通常情况下意味着：文件 i 的物理块   <   文件 j 的物理块

可以通过stat()系统调用来获得inode序号，获取每个参与IO请求的文件的inode序号，然后以inode序号的升序方式对每个请求进行排序

```c
//输出给定文件的inode编号
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//get_inode - returns the inode of the file associated
//with the given file descriptor, or -1 on failure
int get_inode(int fd)
{
    struct stat buf;
    int ret;
    ret = fstat(fd, &buf);
    if(ret < 0)
    {
        perror("fstat");
        return -1;
    }
    return buf.st_ino;
}

int main(int argc, char *argv[])
{
    int fd, inode;
    if(argc < 2)
    {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }
    
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        perror("open");
	}
    
    inode = get_inode(fd);
    printf("%d\n", inode);
    return 0;
}
//get_inode()函数可以很容易的在程序中使用
```

​		按inode编号排序有以下的优点：inode编号容易获取、容易排序、和文件的物理布局很接近，主要的缺点是碎片会降低接近的成都，接近的程度只是估算，在非Unix系统上也不够准确，无论如何，使用inode进行排序都是在用户空间IO请求调度中最常用的方法

##### 按物理块排序

​		**按物理块排序**：使用物理块进行排序，最好的方法是设计你自己的电梯算法，逻辑块是文件系统最小的分配单元，每个文件被分割成若干逻辑块。逻辑块大小和文件系统无关；每个逻辑块对应一个物理块，所以我们可以通过确定逻辑块数，来确定它们对应的物理块，并在此基础上进行排序

​		内核提供了通过文件逻辑块获得物理块的方法，通过ioctl()系统调用，使用FIBMAP命令

```c
ret = ioctl(fd, FIBMAP, &block);
if(ret < 0)
    perror("ioctl");
```

这里，fd是所请求文件的文件描述符，block是我们确定其物理块号的逻辑块。调用成功返回，block赋值为物理块号，逻辑块号从0开始索引，与文件相关，如果文件由8个逻辑块组成，有效值为0到7。获得逻辑块的映射需要两步：第一步确定文件中块的数量，可以通过stat()调用完成；第二步对每个逻辑块，我们用ioctl()调用获得与它相关的物理块

```c
//通过命令行传递文件进行相关操作，获得逻辑块号
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/fs.h>

//get_block - for the file associated with the given fd, returns
//the physical block mapping to logical_block
int get_block(int fd, int logical_block)
{
    int ret;
    ret = ioctl(fd, FIBMAP, &logical_block);
    if(ret < 0)
    {
        perror("ioctl");
        return -1;
    }
    return logical_block;
}

//get_nr_blocks - returns the number of logical blocks
//consumed by the file associated with fd
int get_nr_blocks(int fd)
{
    struct stat buf;
    int ret;
    ret = fstat(fd, &buf);
    if(ret < 0)
    {
        perror("fstat");
        return -1;
    }
    return buf.st_blocks;
}

//print_blocks - for each logical block consumed by the file
//associated with fd, prints to standard out the tuple
void print_blocks(int fd)
{
    int nr_blocks, i;
    nr_blocks = get_nr_blocks(fd);
    if(nr_blocks < 0)
    {
        fprintf(stderr, "get_nr_blocks failed !\n");
        return;
    }
    if(nr_blocks == 0)
    {
        printf("no allocated blocks\n");
        return;
    }
    else if(nr_blocks == 1)
        printf("1 block\n\n");
    else
        printf("%d blocks\n\n", nr_blocks);
    
    for(i = 0; i < nr_blocks; i++)
    {
        int phys_block;
        phys_block = get_block(fd, i);
        if(phys_block < 0)
        {
            fprintf(stderr, "get_block failed !\n");
            return ;
        }
        if(!phys_block)
            continue;
        printf("(%u, %u)", i, phys_block);
    }
    putchar('\n');
}

int main(int argc, char *argv[])
{
    int fd;
    if(argc < 2)
    {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }
    
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return 1;
    }
    print_blocks(fd);
    return 0;
}
```

​		因为文件是趋向于连续的，所有根据每个逻辑块排序是，我们的IO请求会比较难，按给定文件的第一个逻辑块排序则比较好一些，所以get_nr_blocks()并不是必要的，我们的程序可以根据get_block(fd, 0)的返回值进行排序

FIBMAP的缺点是它需要CAP_SYS_RAWIO的能力——root权限，所以没有root权限的程序无法使用这种方法。这种方法的好处在于，它返回了文件所在的真实物理块号，这正是排序所真正需要的，即使把所有对同一文件的IO请求基于一个块地址排序，这种方法也很接近最优结果，遗憾的是需要root权限，这对大部分应用都不切实际。

## 进程管理

​		进程是Unix系统中仅次于文件的基本抽象概念，当目标代买执行的时候，进程不仅仅包含汇编代码，它由数据、资源、状态和一台虚拟的计算机组成。在进程的创建上，Unix采取了一种有趣和少见的处理方法：它将进程的创建和加载一个新的二进制镜像分离，虽然大多时候这俩任务都是顺序执行的，但区分之后就可以由更多的余地对俩种操作进行管理。在大多数操作系统只是简单的提供了一个系统调用创建进程的情况下，这种方式还是保留了下来，Unix提供了俩个系统调用fork和exec。

### 进程ID

​		每一个进程都由一个唯一的标识符标识，即进程ID，简称pid。系统保证某一时刻每个pid是唯一的。本质上来说，大多数代码会假设内核不会重用已经用过的pid。空闲进程（idle process）——当没有其他进程在运行时，内核所运行的进程，其pid为0。在启动后讷河运行的第一个进程称为init进程，它的pid是1。一般来说linux中init进程就是init程序。

除非用户显性的指定内核所要运行的程序，否则内核就必须寻找一个适合的init程序，Linux内核会以以下顺序进行尝试

1. /sbin/init : init最有可能存在的地方
2. /etc/init : 另一个可能的地方
3. /bin/init : init一个可能存在的位置
4. /bin/sh : Bourne shell的所在位置，当内核没有找到init时，内核会尝试运行它

​		在以上侯选位置中，第一被发现的会被当作init运行，如果所有尝试都失败了内核会发出panic挂起系统。在内核交出控制之后，init会接着完成后续的启动过程，典型的情况是init会初始化系统，启动各种服务和启动登录进程

#### 分配进程ID

​		缺省情况下，内核将进程ID的最大值限制为32768，这是为了和老的Unix系统建通，系统管理员可以设置/proc/sys/kernel/pid_max的值来突破这个缺省限制

​		内核分配进程ID是以严格的线性函数方式进行的，如果17是当前进程id的最高值，那么18就是分配给新进程的值，即便当新进程运行时，上一个pid为17的进程已经不运行了，直到内核分配pid达到最大值前，内核是不会重用以前已经分配过的值。因而，尽管Linux在相当长的一段时间内不会保证同一个进程ID的唯一性，但Linux分配pid的方式在短期内至少是稳定的并保证了pid值的唯一性

#### 进程体系

​		创建新进程的那个进程称为父进程，新进程称为子进程，每个进程都是由其他进程创建的（init进程除外），因此每个子进程都有一个父进程，这个关系保存在每个进程的父进程ID号（ppid）中。每个进程都被一个用户和组所拥有，这中从属关系是用来实现访问控制的，对于内核来说，用户和组仅仅是一些整数值，通过/etc/passwd和/etc/group两个文件，这些整数被映射成人们易读的形式。每个子进程都继承了父进程的用户和组。

​		每个进程都是某个进程组的一部分，它简单的表明了自己和其他进程之间的关系，但是不要和上面的用户、组的概念混淆，子进程通过属于其父进程所在的那个线程组。此外当shell建立了一个管道，所有与管道有关的命令都是同一个进程组的。进程组使得与管道相关的进程间发送和获取信息变得很容易，这同样也适用于管道中的子进程。

#### pid_t

​		编程时，进程ID是由pid_t这种数据类型来表示的，它定义在<sys/types.h>中，它具体的C语言类型是与机器架构相关的，并且任何C语言标准都没有定义它，但是在Linux中，它通常是C语言中的int类型

#### 获得进程ID和父进程ID

```c
//getpid()用返回调用进程的ID
#include <sys/types.h>
#include <unistd.h>
pid_t getpid(void);

//getppid()返回调用进程的父进程ID
#include <sys/types.h>
#include <unistd.h>
pid_t getppid(void);

//这俩个系统调用都不会返回一个错误代码，但使用时是无关紧要的
printf("My pid = %d\n", getpid());
printf("Parent's pid = %d\n", getppid());
```

​		尽管在Linux系统上我们假设pid_t是int类型使用是安全的，但是这破坏了数据抽象的目的，并且可能会产生移植性的问题，不幸的是，这和C语言中大多数typedefs一样，没有一种便携的打印pid_t的方式存在，而且从技术角度上来说，我们需要一样pid_to_int()函数，但是没有，至少对于printf()来说，吧pid_t当作一个整数来处理是很常见的

### 运行新进程

​		在Unix中，载入内存并执行程序映像的操作与创建一个新进程的操作是分离的，Unix有一系列系统调用是可以将二进制文件的程序映像载入内存，替换原先进程的地址空间，并开始运行它，这个过程称为运行一个新的程序，而相应的系统调用称为exec系统调用。

​		同时，另一个不同的系统调用是创建一个新的进程，它基本上就是复制父进程，通常情况下新的进程会立刻执行一个新的程序，完成创建新的进程这种行为叫做派生（fork），完成这个功能的系统调用就是fork()。这俩种操作——首先fork，即创建新的进程；然后运行，即将一个镜像载入——要求在新的进程中运行新的程序。

#### exec系列系统调用

​		其实没有单一的exec系统调用，它们由基于单个系统调用的一组exec函数构成，最简单的一个是execl()

```c
#include <unistd.h>
int execl(const char *path, const char *arg, ……);
```

对execl()的调用会将path所指的路径的映像载入内存，替换当前进程的映像，arg是它的第一个参数，省略号表示可变长度的参数列表——execl()是可变参数（variadic）的，这就是说额外的参数会在后面一个接着一个，但参数列表必须是以NULL结尾

```c
//用/bin/vi替代当前运行的程序
int ret;
ret = execl("/bin/vi", "vi", NULL);
if(ret == -1)
    perror("execl");
```

注意，我们遵循了Unix的习俗，用“vi”作为第一个参数，当fork/exec进程时，shell会把路径的最后一个成分，即“vi”，放入新进程的第一个参数argv[0]，这样一个程序就能检测到argv[0]，从而得知二进制映像文件的名字。很多时候，用户会看到一些系统工具有不同的名字，实际上这些名字都是指向一个程序的硬链接，所以程序需要第一个参数来决定它的具体的行为。

```c
//一个例子是，如果想编辑/home/kidd/hooks.txt，可以执行以下代码
int ret;
ret = execl("/bin/vi", "vi", "/home/kidd/hooks.txt", NULL);
if(ret == -1)
    perror("execl");
```

​		通常情况下execl()不会返回，成功的调用会以跳到新的程序的入口点作为结束，而刚刚被运行的代码是不会存在于进程的地址空间中的，但错误发生时，execl()返回-1，并且设置errno的值，指示出了什么样的错误，execl()成功调用不仅仅会改变地址空间和进程的映像，还会改变进程的一些属性：

- 任何挂起的信号都会丢失
- 捕捉的任何信号会还原为缺省的处理方式，因为信号处理函数已经不存在于地址空间中了
- 任何内存的锁定会丢失
- 多数线程的属性会还原的缺省值
- 多数关于进程的统计信息会复位
- 与进程内存相关的任何数据都会丢失，包括映射的文件
- 包括C语言库的一些特性等独立存在于用户空间的数据都会丢失

​		也有许多进程的属性不会改变，例如pid、父进程的pid、优先级、所属的用户和组，通常打开的文件描述符也通过exec继承下来，如果新的进程知道原进程打开的文件描述符的话，这意味着新的进程可以访问原先进程所打开的文件，然而这通常不是理想的处理方法，所以实际操作中一般会在exec调用前关闭打开的文件，也可以通过fcntl()来让内核自动完成。

##### 其他的exec系列系统调用

除了execl()还有五个系统调用

```c
#include <unistd.h>
int execlp(const char *file, const char *arg, ……);
int execle(const char *path, const char *arg, ……, char *const envp[]);
int execv(const char *path, char *const argv[]);
int execvp(const char *filename, char *const argv[]);
int execve(const char *filename, char *const argv[], char *const envp[]);
```

​		字母 **l** 和 **v** 分别表示是以列表方式或者数组方式提供，字母 **p** 意味着在用户PATH环境变量中寻找可执行文件。只要出现在用户路径中，带p的exec函数可以简单的只提供文件名，最后 **e** 表示会提供给新进程以新的环境变量。尽管技术上没有理由要做出省略，但exec函数中没有一个同时可以搜索路径和使用环境变量的函数，可能是因为带p的exec函数主要用于shell，因为在shell所执行的进程通常会从shell继承环境变量

​		除了需要构造一个数据并用它代替列表作为参数传递之外，使用数组作为参数的exec函数基本上没有什么区别，使用数组作为参数使得可以运行时动态构造参数，和可变长参数一样，数组必须以NULL结尾

```c
//下面代码片段使用execvp()来执行vi
const char *args[] = {"vi", "/home/kidd/hooks.txt", NULL};
int ret;
ret = execvp("vi", args);
if(ret == -1)
    perror("execvp");
```

在Linux中，它们当作只有一个是真正的系统调用，其他都是在C语言库中封装的函数，因为处理变长参数的系统调用难以实现，并且用户的路径仅存在于用户空间，所以execve()是唯一的选择，它的原型和用户使用时是一样的。

##### 错误返回值

成功调用时，exec调用不会返回，当失败时返回-1，并且把errno设置为下值之一：

E2BIG			参数列表（arg）或者环境变量（envp）长度过长

EACCESS	  没有在path所指向的路径中的搜索权限；path指向的文件不是一个普通文件；目标文件不是可执行的；path或文件所在的						文件体系以不可执行（noexec）的方式挂载

EFAULT		   给定的指针是无效的

EIO				  发生底层I/O错误

EISDIR			 路径path的最后一部分或者解释器为目录

ELOOP			系统在解析path时遇到了太多的符号链接

EMFILE		    调用进程打开的文件数达到上限

ENFILE			 打开文件时遇到了系统级别（system-wide）的限制

ENOENT		  目标路径或文件不存在，或者所需要的共享库不存在

ENOEXEC	    目标文件不是一个有效的二进制可执行文件或者是其他体系结构上的可执行格式

ENOMEM		  内核没有足够的内存来执行新的程序

ENOTDIR		  path中除最后一部分之外的某个部分不是目录

EPERM			  path或文件位于的文件系统是被挂载为nosuid，但用户不是root用户且path或文件被设置为suid或sgid位

ETXTBSY		   目标文件被其他进程以写入方式打开了

#### fork()系统调用

创建一个和当前进程映像一样的进程可以通过fork()系统调用

```c
#include <sys/types.h>
#include <unistd.h>
pid_t fork(void);
```

​		成功调用fork()会创建一个新的进程，它几乎和调用fork()的进程一模一样，这俩个进程会继续运行，调用者从fork()返回后，就好像没有什么特别的事情发生过。新的进程称为原来进程的**子进程**，原来进程称为**父进程**，在子进程中，成功的fork()调用会返回0，在父进程中fork()返回子进程的pid，除了必要的一些方面，父进程和子进程之间的每个方面都十分相近：

- 显然子进程的pid是新分配的，与父进程的不同
- 子进程的ppid会设置成父进程的pid
- 子进程中的资源统计信息（Resource statistics）会清零
- 任何挂起的信号会清除，也不会被子进程继承
- 任何文件锁都不会被子进程所继承

调用出错时，不会创建子进程，fork()返回-1，同时会设置相应的errno的值，有俩种errno的值，它们有三种可能的意义：

EAGAIN		内核申请一些资源时失败，例如新的pid，或者达到了PLIMIT_NPROC设置的资源限制

ENOMEM 	 没有足够的内核内存来满足所请求的操作

```c
//fork()的用法
pid_t pid;
pid = fork();
if(pid > 0)
    printf("I am the parent of pid = %d\n", pid);
else if(!pid)
    printf("I am the baby!\n");
else if(pid == -1)
    perror("fork");
```

​		最常见的fork()用法是创建一个新的进程，然后载入二进制映像——想象一下shell为用户创建一个新进程或者一个进程创建了一个辅助进程。第一种情况下，派生（fork）了新的进程，而这个子进程会执行一个新的二进制可执行文件的映像，这种派生加执行的方式很常见也很简单

```c
//该例为创建了一个新的进程来运行/bin/windlass
pid_t pid;
pid = fork();
if(pid == -1)
    perror("fork");
if(!pid)
{
    const char *args[] = {"windlass", NULL};
    int ret;
    ret = execv("/bin/windlass", args);
    if(ret == -1)
    {
        perror("execv");
        exit(EXIT_FAILURE);
    }
}
//除了创建一个子进程外，父进程会没有任何改变的继续运行下去，execv()会使子进程去运行/bin/windlass
```

##### 写时复制

​		早期Unix系统中，创建进程比较原始，当调用fork时，内核会把所有的内部数据结构复制一份，复制进程的页表项，然后把父进程的地址空间中的内容逐页复制到子进程的地址空间中，但从内核角度来说，逐页的复制方式是十分耗时的。现代的Unix系统采取了更多的优化，采用了写时复制的方法，而不是对父进程空间进行整体复制

​		写时复制是一种采用了惰性优化方式来避免复制时的系统开销，它的前提简单：如果有多个进程要读取它们之间的那部分资源的副本，那么复制是不必要的，每个进程只要保存一个指向这个资源的指针就可以了， 只要没有进程去修改自己的副本，就存在着这样的幻觉：每个进程好像独占了那个资源。如果一个进程要修改自己的那份资源“副本“，那么就会复制那份资源，并把复制的那份提供给进程。不过其中的复制对进程来说是透明的，这个进程可以修改复制后的资源了，同时对其他进程仍然共享那份没有修改过的资源。这就是名字的由来：在写入时进行复制

​		写时复制的主要好处在于：如果进程从来不需要修改资源，则不需要进行复制，惰性算法的好处就在于它们尽量推迟代价高的操作，直到必要时才去执行。在使用虚拟内存的情况下，写时复制（Copy-on-write）是以页为基础进行的，所有只要进程不修改它全部的地址空间，那么就不必复制整个地址空间，在fork()调用结束后，父进程和子进程都相信它们有一个自己的地址空间，但其实它们共享父进程的原始页，接下来的页又可以被其他的父进程或子进程共享。

​		写时复制在内核中的实现非常简单，与内核相关的数据结构可以被标记为只读和写时复制，如果有进程试图修改一个页，就会产生一个缺页中断，内核处理缺页中断处理方式就是对该页进行一次透明复制，这时会清除页面的COW属性，表示它不再被共享。在调用fork()时，写时复制有很大优势，因为大量的fork之后都会跟着执行exec，那么复制整个父进程地址空间的内容到子进程的地址空间完全是浪费时间；如果子进程立刻执行一个新的二进制可执行文件的映像，它先前的地址空间就会被交换出去，写时复制可以对这种情况进行优化。

##### vfork

在实现写时复制之前，Unix的设计者就一直关注在fork后立刻执行exec所造成的地址空间浪费，所以引入了vfork()系统调用

```c
#include <sys/types.h>
#include <unistd.h>
pid_t vfork(void);
```

​		除了子进程必须要执行一次对exec的系统调用，或者调用_exit()退出，对vfork()的成功调用所产生的结果和fork()是一样的。vfork()会挂起父进程直到子进程终止或者运行了一个新的可执行文件的映像，通过这种方式，vfork()避免了地址空间的按页复制，在这个过程中，父进程和子进程共享相同的地址空间和页表项（不使用写时复制），实际上vfork()只完成了一件事：复制内部的内核数据结构，因此子进程也就不能修改地址空间中的任何内存。

​		vfork()是一个历史遗留产物，Linux本不应该实现它，需要注意的是，vfork()比fork()快，因为它没有进行页表项的复制。严格来说，没有一个vfork()实现是没有问题的：因为直到子进程确认要做什么或者退出之前，父进程将被一直挂起。

### 终止进程

终止当前进程的标准函数

```c
#include <stdlib.h>
void exit(int status);
```

​		对exit()的调用通常会执行一些基本的终止进程的步骤，然后通知内核终止这个进程，这个函数没有任何办法返回一个错误值——实际上它也从不返回，因此没有理由在exit()之后再执行任何的指令。status参数用来标示进程退出的状态，其他进程可以检测这个值，具体来说，status & 0377这个值会返回给父进程。EXIT_SUCCESS和EXIT_FAILURE俩个宏分别表示成功和失败，而且是可以移植的。在Linux种，0通常表示成功；非0值表示失败。

```c
//进程成功的退出时，只需要简单的写上
exit(EXIT_SUCCESS);
```

在终止进程之前，C语言函数执行以下关闭进程的工作

1. 以在系统中注册的逆序来调用由 atexit() 或 on_exit() 注册的函数
2. 清空所有已打开的标准I/O流
3. 删除由 tmpfile() 创建的所有临时文件

这些步骤完成了在用户空间中所需要做的事情，这样exit()就可以调用_exit()来让内核处理终止进程的剩余工作了

```c
#include <unistd.h>
void _exit(int status);
```

​		当进程退出时，内核会清理进程所创建的、不在用到的任何资源，这包括：申请的内存、打开的文件和System V的信号量。清理完成后，内核销毁进程，并告知父进程其子进程的终止。应用程序可以直接调用_exit()，这通常不合适的：许多应用需要做一些在完全退出过程中所需要的清理工作，例如清空stdout流。

其他终止进程的方式：终止进程的典型方式不是通过明确的使用一个函数调用，而是采用跳转到程序结尾处的方式，在C语言中，这发生在main()函数返回时，然而这种方式依然还是进行了系统调用：编译器会简单的在最后的代码中插入一个_exit()。在main()函数返回时明确给出一个状态值，或者调用exit()，这是一个良好的编程习惯，shell会根据这个返回值来判断命令是否执行成功。注意，成功时的返回是exit(0)，或者是从main()函数返回0

#### atexit()

atexit()用来注册一些在进程结束时要调用的函数

```c
#include <stdlib.h>
int atexit(void (*function)(void));
```

​		对atexit()的成功调用会把指定的函数注册到进程正常结束时调用的函数中，如果进程调用了exec，所注册的函数列表会被清除（因为这些函数不存在于新进程的地址空间中），如果进程是通过信号而结束的，这些注册的函数也不会被调用。要注册的函数必须是无参数的，也没有返回值，它的原型应该像这样 void  my_function(void);

​		函数调用的顺序是和注册的顺序相反的，也就是这些函数存储在栈中，以后进先出的方式调用（LIFO）。注册的函数不能调用exit()，否则会引起无限的递归调用。如果需要提前结束进程，应该调用_exit()。一般不推荐这样做，因为这样的会使得一些重要的函数不会被调用到。

POSIX标准要求atexit()至少支持注册ATEXIT_MAX这个函数，而这个值至少是32，具体的值可以通过sysconf()得到，参数是_SC_ATEXIT_MAX

```c
long atexit_max;
atexit_max = sysconf(_SC_ATEXIT_MAX);
printf("atexit_max = %ld\n", atexit_max);

//成功时，atexit()返回0，错误时返回-1
//这是一个简单的例子
#include <stdio.h>
#include <stdlib.h>
void out(void)
{
    printf("atexit() succeeded !\n");
}

int main(void)
{
    if(atexit(out))
        fprintf(stderr, "atexit() failed !\n");
    return 0;
}
```

#### on_exit()

SunOS 4 定义自己的一个和atexit()等价的函数on_exit()，Linux的glibc提供了对它的支持

```c
#include <stdlib.h>
int on_exit(void(*function)(int, void *), void *arg);

//这个函数的工作方式和atexit()一样，只是注册的函数原型不同
void my_funtion(int status, void *arg);
```

参数status是传给exit()的值或者是main()函数返回的值，arg是传给on_exit()的第二个参数，必须小心的是当调用注册函数时，要保证arg所指的内存空间必须是有效的

#### SIGCHLD

​		当一个进程子进程终止时，内核会向其父进程发送SIGCHILD信号。缺省情况下会省略此信号量，父进程也不会有任何的动作，进程也可以通过signal()或者sigaction()系统调用来有选择的处理这个信号。

​		SIGCHILD信号可能会在任何时候产生，也会在任何时候被传递给父进程，这是因为子进程的终止是和父进程异步的，通常情况下，父进程都希望能更多的了解子进程的终止，或显式的等待子进程的终止。

### 等待终止的子进程

​		用信号通知父进程是可以的，但是很多时候父进程想知道关于子进程终止的更多信息，例如子进程的返回值。如果在终止进程中，子进程完全消失了，就没有给父进程留下任何可以来了解子进程的东西。所以Unix的设计者做出了这样的决定：如果一个子进程在父进程之前结束，内核应该把子进程设置为一个特殊的状态，处于这种状态的进程叫做僵死（zombie）进程，进程只保留最小的概要信息——一些保存着有用信息的内核数据结构，僵死的进程等待父进程来查询自己的信息（这叫做在僵死进程上等待），只要父进程获取了子进程的信息，子进程就会消失，否则则一直保持僵死状态。

Linux内核提供了一些接口来了解已经终止的子进程的信息，其中最简单的是wait()

```c
#include <sys/types.h>
#include <sys/wait.h>
pid_t wait(int *status);
```

​		wait()返回已终止子进程的pid，或者返回-1表示出错，如果没有子进程终止，调用者会被阻塞直到一个子进程终止。如果子进程终止了，它就会立刻的返回，因此相应子进程死亡的wait()调用，会以非阻塞的方式返回，错误时errno有俩种可能的值

ECHILD		调用进程没有任何子进程

EINTR		   等待子进程结束时，收到了一个信号，wait()提前返回了

​		如果status不是NULL，那么它包含了一些关于子进程的附加信息，因为POSIX允许实现时可以在status定义一些合适的bit位来表示附加信息，POSIX标准提供了一些宏来解释这些信息

```c
#include <sys/wait.h>
int WIFEXITED(status);
int WIFSIGNALED(status);
int WIFSTOPPED(status);
int WIFCONTINUED(status);
int WEXITSTATUS(status);
int WTERMSIG(status);
int WSTOPSIG(status);
int WCOREDUMP(status);
```

​		前俩个宏会根据子进程的结束情况，可能会返回真（一个非零值），如果进程正常结束了——也就是进程调用了\_exit()，第一个宏WIFEXITED返回真，这种情况下WEXITSTATUS返回传递给_exit()的低八位。如果信号引发进程的终止，WIFSIGNALED返回真，在这种情况下WTERMSIG返回引起进程终止的那个信号的编号，如果进程收到信号时发生了主存信息转储（dumped core），WCOREDUMP就返回true。

​		如果子进程停止了或继续执行，WIFSTOPPED和WIFCONTINUED分别返回真，这些是通过ptrace()系统调用追踪的，只有当实现了一个调试器时，这些才有用，尽管有waitpid()，但它们也是可以用来使用作业控制。wait()一般用来获取子进程的终止信息，如果WIFSTOPPED返回真，WSTOPSIG就返回使得进程停止的那个信号的编号。

```c
//使用wait()来确定其子进程所发发生的事
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int status;
    pid_t pid;
    if(!fork())
        return 1;
    
    pid = wait(&status);
    if(pid == -1)
        perror("wait");
    printf("pid = %d\n", pid);
    
    if(WIFEXITED(status))
        printf("Normal termination with exit status = %d\n", WEXITSTATUS(status));
    if(WIFSIGNALED(status))
        printf("Killed by signal = %d %s\n", WTERMSIG(status), WCOREDUMP(status) ? " (dumped core)" : "");
    if(WIFSTOPPED(status))
        printf("Stopped by signal = %d\n", WSTOPSIG(status));
    if(WIFCONTINUED(status))
        printf("Continued\n");
    
    return 0;
}
```

​		这个程序中，创建一个子进程，它会立刻退出，父进程随后调用wait()来获取子进程的状态，父进程会打印子进程的pid以及结束信息，这例中，子进程的结束是从main()返回的，所以可能看到以下的输出

```
$ ./wait
pid = 8529
Normal termination with exit status = 1
```

 		如果子进程的结束不是从main()返回，而是使他调用abort()——这会使子进程会向自己发送一个SIGABRT信号，会看到以下的输出

```
$ ./wait
pid = 8678
Killed by signal = 6
```

#### 等待特定进程

​		监视子进程的行为是很重要的，通常一个进程可能有很多子进程，但不需要等待所有子进程的结束，父进程只想等待其中一个特定的子进程，一种解决方式是多次调用wait()，每次根据返回值判断是不是那个特定的进程，如果知道需要等待进程的pid，可以使用waitpid()系统调用

```c
#include <sys/types.h>
#include <sys/wait.h>
pid_t waitpid(pit_t pid, int *status, int options);
```

比起wait()，waitpid()是一个更加强大的系统调用，它额外的参数可以用来微调，参数pid是需要等待的一个或多个进程的pid，它的值可以是下面四种情况之一：

< -1		等待所有这样的子进程，它们的组ID是参数pid的绝对值，如-500表示等待所有进程组500中的所有子进程

-1		   等待任一子进程，这和wait()等效

0			等待与调用进程处于同一进程组的任一进程

\> 0		 等待进程pid等于传入值的那个子进程，例如传入500表示等待pid为500的子进程

参数status的作用和wait()中的那个参数是一样的，并且前面的宏也是可以使用的，参数options是零或多个下面选项”按“二进制或运算结果

WNOHANG		如果要等待的子进程已经结束，或者停止，或者处于继续运行的状态，则waitpid()不会阻塞立刻返回

WUNTRACED	如果设置该位，即便是调用进程没有跟踪子进程，WIFSTOPPED也一样被设置

WCONTINUED  如果设置该位，即便是调用进程没有跟踪子进程，WIFSTOPPED也一样被设置

调用成功时，waitpid()返回状态发生改变的那个进程pid，如果设置了WNOHANG参数，那么等待的那个特定进程的状态没有改变就会返回0。发生错误时返回-1并且设置errno的值为下列三之一

ECHILD		参数pid所指定的进程不存在，或者不是调用者的子进程

EINTR		  没有设置WNOHANG，而且等待过程中收到了一个信号

EINVAL		参数options不合法

```c
//假设程序想得到pid为1742的子进程的返回值，但如果子进程没有结束，父进程就会立刻返回
int status;
pid_t pid;
pid = waitpid(1742, &status, WNOHANG);
if(pid == -1)
    perror("waitpid");
else
{
    printf("pid == %d\n", pid);
    if(WIFEXITED(status))
        printf("Normal termination with exit status = %d\n", WEXITSTATUS(status));
    if(WIFSIGNALED(status))
        printf("Killed by signal = %d %s\n", WTERMSIG(status), WCOREDUMP(status) ? " (dumped core)" : "");
}

//可以注意到，下面wait()用法和这样使用waitpid()是一样的
wait(&status);
waitpid(-1, &status, 0);
```

#### 其他等待子进程的方法

​	作为应用程序来说，它们希望有更多等待子进程的方式，Linux提供了waitid()

```c
#include <sys/wait.h>
int waitid(idtype_t idtype, id_t id, siginfo_t *info, int options);
```

​		和wait()与waitpid()一样，waitid()作用是等待子进程的结束和了解子进程状态改变的信息（终止、停止或者继续运行），它有更多的选项，但是这是以增加复杂性为代价的。与waitpid()一样，waitid()允许程序员指定所要等待的子进程，但是为了完成这项工作，waitid()需要两个参数，参数idtype和id用来指定要等待的子进程，这和waitpid()中的pid参数作用一样，idtype的值是下面三个中的一个：

P_PID	等待pid的值是id的子进程

P_GID	等待进程组ID是id那些子进程

P_ALL	等待所有子进程，参数id被忽略

​		参数id是少见的id_t类型，这种类型代表着一种通用的ID号，因为将来可能增加idtype的值，所以引入这个类型，这样新加入的idtype值也可以被包容进去，id_t类型足够大，保证了可以保存任何类型的pid_t值，在Linux上可以把他当作pid_t使用

参数options是以下一个或者多个选项进程二进制”或“运算的结果

WEXITED			调用进程会等待结束的子进程（有id和idtyp指定）

WSTOPPED		调用进程会等待收到了信号而停止了执行的子进程

SCONTINUED	 调用进程会等待收到了信号而继续执行的子进程

WNOHANG		  调用进程不会阻塞，如果没有子进程结束，它会立刻返回

WNOWAIT			调用进程不会移除满足条件的子进程的僵死状态，调用进程可能会在将来继续等待

​		成功时，waitid()会填充参数infop，但是它必须指向一个有效的siginfo_t类型，siginfo_t结构体的具体成员是与实现相关的。但是还是有一些成员是在waitpid()调用之后还是有效的，也就是成功的调用会保证下面的成员会被填充

si_pid		子进程的pid

si_uid		子进程的uid

si_code	 根据子进程的状态是被信号所终止、杀死、停止或者继续执行而分别设置CLD_EXITED、CLD_KILLED、CLD_STOPEED或				  者CLD_CONTINUED中的一个

si_signo 	设置为SIGCHLD

si_status	如果设置si_code是CLD_EXITED，它是子进程的退出值，否则它是引起状态改变的那个信号的编码

​		当成功时，waitid()返回0，错误时，返回-1，errno会被设置成下列值之一

ECHLD		由id和idtype确定的进程不存在

EINTR		  一个信号打断了子进程的执行，但是在options里没有设置WNOHANG

EINVAL		options参数不合法，或者id和idtypes的组合不合法

​		waitid()提供了比wait()和waitpid()更多有用的语义，尤其是可以从siginfo_t结构体获取的信息时很有用的，如果不需要这些信息，那么应该选择更简单的函数，这样可以被更多系统所支持

#### 创建并等待一个新进程

​		ANSI和POSIX都定义了一个用于创建新进程并等待它结束的函数——可以把他想象成是同步创建进程，如果一个进程创建了新的进程然后就立刻开始等待它的结束，那么使用下面的函数就很合适：

```c
#define _XOPEN_SOURCE
	WEXITSTATUS, etc.
#include <stdlib.h>
int system(const char *command);
```

​		system()之所以这样命名是因为进程同步创建一般被称为”交付系统运行“，使用system()来运行一个简单的工具程序或者shell脚本是很常见的，大多数都是希望得到工具程序或者脚本的返回值。对system()的调用会使得由参数command指定的程序的得到执行，而且程序可以得到相应的参数。”/bin/sh -c“ 会作为前缀加到command参数前面，这样才会使整个参数传递给shell。

​		成功时，返回值是执行命令得到的返回状态，如同wait()的返回值一样，接下来执行命令的返回值会通过WEXITSTATUS得到，如果对 /bin/sh 自己的调用失败了，那么从WEXITSTATUS得到的值和调用exit(127)的返回值是一样的，也可能调用的命令返回了127，但是没有办法来检测是不是shell自己发生了错误返回127.system()调用失败时返回-1。

如果参数command是NULL且 /bin/sh 是可用的，system()返回一个非零的值，其他情况返回0。在命令执行的过程中，SIGCHILD信号是被阻塞的，而且SIGINT和SIGQUIT信号会被忽略，实现对SIGINT和SIGQUIT信号的忽略有好几种实现方式，特别是system()在循环中被调用，循环中调用system()需要保证子进程的退出状态要被正确检测，例如

```c
do
{
    int ret;
    ret = system("pidof rudderd");
    if(WIFSIGNALED(ret) && (WTERMSIG(ret) == SIGINT || WTERMSIG(ret) == SIGQUIT))
        break;
}while(1);
```

​		利用fork()、exec系统调用和waitpid()实现了一个system()是非常有效的练习，这是一个简单的实现

```c
/*
my_system - synchronously spawns and waits for the command
"/bin/sh -c <cmd>"
Return -1 on error of any sort, or the exit code from the launched process
Does not block or ignore any signals
*/
int my_system(const char *cmd)
{
    int status;
    pid_t pid;
    pid = fork();
    if(pid == -1)
        return -1;
    else if(pid == 0)
    {
        const char *argv[4];
        argv[0] = "sh";
        argv[1] = "-c";
        argv[2] = cmd;
        argv[3] = NULL;
        execv("/bin/sh", argv);
        exit(-1);
    }
    if(waitpid(pid, &status, 0) == -1)
        return -1;
    else if(WIFEXITED(status))
        return WEXITSTATUS(status);
    return -1;
}
```

​		这个例子不像正式的system()，它没有阻塞或者禁止任何信号，根据你程序的情况，可能是好事也可能是坏事，但至少要保证SIGINT信号不能被阻塞，因为这样可以按照用户的意愿随时终止命令的执行。一个较好的实现可用将额外的指针作为参数，当参数为非空时，代表不同的错误，例如可能加入fork_failed和shell_failed

#### 僵死进程

​		正如前面提到的，一个进程已经终止了，但是父进程还在等待获得它的状态，那么这个进程就叫做僵死进程，僵死进程还会消耗一些系统资源，尽管很少——仅仅能描述进程曾经的状态，这些保留的资源主要是为了父进程查询子进程的状态时提供相应的信息，一旦父进程得到了想要的信息，内核就会清除这些信息，僵死进程就不存在了。

​		如果父进程在子进程结束之前就结束了呢？无论何时，只要有进程结束了，内核就hi遍历它的所有子进程，并且将它们的父进程重新设置为init进程。这保证了系统不会存在没有父进程，init进程会周期性等待所有子进程，确保不会有长时间存在的僵死进程——没有鬼魂进程。因而当父进程在子进程之前结束了，那么init进程会被指定为这些子进程的父进程，从而确保他们会完全的退出。这种安全措施也意味着生命周期短的进程没有必要等待它所有的子进程结束。

### 用户和组

​		进程使用户和组相关联的，用户ID和组ID分别用C语言的uid_t和gid_t这俩个类型表示，数字表示和可读字符串之间的映射关系（例如root用户的uid是0）是通过用户空间的 /etc/passwd 和 /etc/group 两个文件完成的，内核只处理数字表示。

​		在Linux系统中，一个进程的用户ID和组ID代表这个进程可以执行哪些操作，进程必须以合适的用户和组运行，许多进程是以root用户运行的，热而最好的方式是采取“最小权限”的原则，它意味着进程要尽可能的以最小的权限来运行，这个要求是动态变化的：如果进程在前期需要以root用户的权限运行，而在后面不需要了，那么它就应该在后期尽可能的放弃root权限。许多进程——特别是那些不需要root权限来执行一些操作时——经常需要操作自己的ID或者组ID。

#### 实际用户ID、有效用户ID和保存设置用ID

​		实际上，与进程相关的用户ID有4个而不是1个，它们是：实际用户ID、有效用户ID、保存设置的用户ID、文件系统用户ID。

​		**实际用户ID**是运行这个进程的那个用户的uid，这个用户的uid会被设置为父进程的实际用户ID，并且在exec系统调用中不会发生变化，一般情况下登录进程会将用户登录的那个shell的实际用户ID设置为用户的ID，并且这个用户所有进程的实际用户ID都会继承这个值。

​		**有效用户ID**是当前进程所使用的用户ID，权限验证一般是使用这个值，初始时这个ID等于实际用户ID，因为创建进程时子进程会继承父进程的有效用户ID。更进一步的说，exec系统调用不会改变有效用户ID。但是在exec调用过程中，实际用户ID和有效用户ID的主要区别就出现了：通过setuid(suid)程序，进程可以改变自己的有效用户ID，准确来说，有效用户ID被设置为拥有此程序文件拥有者的用户ID。

​		**保存设置用户ID**是进程原先的有效用户ID。当创建进程时，子进程会从父进程继承保存设置的用户ID，对于exec系统调用来说，内核会把保存设置的用户ID设置为有效用户ID，从而在exec系统调用过程中保存了一份有效用户ID的记录，非特权用户不能改变保存设置的用户ID的值，超级用户可以把它设置为实际用户ID的值。

​		有效用户ID的作用是：它是检查进程权限过程中使用的用户ID，实际用户ID和保存设置的用户ID像是代理或者一个潜在的用户ID值，它的作用是允许非root进程在这些用户ID之间相互切换，实际用户ID是真正运行程序的有效用户id。保存设置的用户ID是在执行suid程序前的有效用户id。

#### 改变实际用户ID和保存设置的用户ID

用户ID和组ID是通过下面的俩个系统调用设定的

```c
#include <sys/types.h>
#include <unistd.h>
int setuid(uid_t uid);
int setgid(gid_t gid);
```

​		setuid()用来设定当前进程的有效用户ID，如果进程当前的有效用户ID是0（root），那么实际用户ID和保存设置的用户ID的值也会被同时设置，root用户可以为uid提供任何值，从而将所有三种用户ID的值设置为uid。非root用户只允许将实际用户ID和保存设置的用户ID设置为uid。调用成功时，setuid()返回０，错误时返回-1，并把errno设置为下面的值之一

EAGAIN		uid的值和实际用户ID的值不同，把实际用户ID的值改变为uid会导致此用户超过NPROC的限制

EPERM		 不是root用户，uid既不是有效用户ID也不是保存设置的用户ID

前面的讨论对组依然适用，只需要把setuid()替换为setgid()，把uid替换为gid

#### 改变有效用户和组ID

Linux提供了俩个POSIX所定义的函数来改变当前进程的有效用户id和组ID的值

```c
#include <sys/types.h>
#include <unistd.h>
int seteuid(uid_t euid);
int setegid(gid_t egid);
```

​		seteuid()的调用将有效用户ID的值设置为euid，root用户可以为euid提供任何值，而非root用户只能将有效用户ID设置为有效用户ID或者是保存设置的用户ID。成功时seteuid返回0，失败时返回-1，并把errno设置为EPERM。它表示当前进程的所有者不是root用户，并且euid的值既不等于实际用户ID也不等于保存设置的用户ID。

​		对于非root用户来说，seteuid()和setuid()是一样的，所以总是调用seteuid()是不错的选择，如果进程要以root权限来运行，使用setuid()更加合适。前面的讨论对组也适用，只需要把seteuid()替换成setegid，把euid替换成egid。

#### 操作用户ID 组ID的首选方法

​		非root用户应该使用seteuid()来设置有效用户ID，如果有root权限的进程希望改变三种用户ID，那么应该用setuid()；而只是想临时改变有效用户ID，那么最好使用seteuid()。这些函数较为简单，它们的行为遵从POSIX中的定义，并且在适当的时候考虑用一下保存设置的用户ID。

对保存设置的用户ID的支持

​		保存设置的用户ID是POSIX 2001中出现的，仅为Linux编写的从程序可以放心使用保存设置的用户id，为较老版本的unix编写的程序在引用保存用户设置的用户ID或组ID之前需要检查一下_POSIX_SAVED_IDS宏

#### 获取用户ID和组ID

下面俩个系统调用分别返回实际用户ID和组ID

```c
#include <unistd.h>
#include <sys/types.h>
uid_t getuid(void);//返回实际用户ID
gid_t getgid(void);//返回组ID

//它们不能失败，相应下面的俩个系统调用分别返回有效用户ID和组ID
#include <unistd.h>
#include <sys/types.h>
uid_t geteuid(void);
gid_t getegid(void);
//这两个系统调用同样不能失败
```

### 会话和进程组

​		每个进程都属于某个进程组，进程组是由一个或多个相互间有关联的进程组成的，它的目的是为了进行作业控制，进程组的主要特征就是信号可以发送给进程组中的所有进程：这个信号可以使同一个进程组中的所有进程终止、停止或者继续运行。每个进程组都由进程组ID（pgid）唯一标识，并且有一个组长进程，进程组ID就是组长进程的pid，只要某个进程组还有一个进程存在，则该进程组就存在，即使组长进程终止了，该进程组依然存在

​		当有新的用户登录计算机，登录进程就会为这个用户创建一个新的会话，这个会话中只有用户的登录shell一个进程，登录shell作为会话首进程（session leader）。会话首进程的pid就被作为会话的ID，一个会话就是一个或多个进程组的集合，会话囊括了登录用户的所有活动，并且分配给用户一个控制终端（contrling terminal），控制终端是一个用于处理用户IO的tty设备。

​		进程组提供了向其中所有进程发送信号的机制，这使得作业控制和其他的shell功能变得很容易，同时会话则将登录与控制终端联系起来，会话中的进程组分为一个前台进程组和零个或多个后台进程组。当用户退出终端时，向前台进程组中的所有进程发送SIGQUIT信号；当出现网络中断的情况时，向前台进程组终端所有进程发送SIGHUP信号；当用户敲入终止键（一般为从Ctrl + C），向前台进程组中的所有进程发送SIGINT信号。因此，会话可以更容易的管理终端以及在shell上的登录行为。

​		在一个指定的系统中，存在着多个会话：每个用户的登录都是一个会话，还有一些与用户登录会话无关的进程也是会话（例如守护进程），守护进程会创建自己的会话，避免与其他存在的会话产生关系。这些会话都包含一个或多个进程组，并且每个进程组至少有一个进程，而有多个进程的进程组通常是用来完成作业控制的。

```
$ cat ship-inventory.txt | grep booty | sort 
```

以上这样一条shell命令会产生由三个进程组成的一个进程组，以这种方式shell可以向三个进程同时发送信号，因为用户直接敲入这条命令，结尾没有使用“&”，所以其是一个前台进程组，下图显示了会话、进程组、进程和控制终端之间的关系

![image-20230425140142910](Com_pictrue/image-20230425140142910.png)

​		Linux提供了几个用来获取和设置与一个进程相关的会话进程组的接口，它们主要是为了shell服务，但是也可用于守护进程之类的进程，因为守护进程不希望与其他会话和进程组扯上关系

#### 与会话相关的系统调用

在登陆时，shell会创建新的会话。这是通过一个特殊的系统调用完成的，用它可以很容易创建一个会话

```c
#include <unistd.h>
pid_t setsid(void);
```

​		假设调用进程不是某个进程组组长进程，调用setsid()会创建新的会话，调用进程就是这个会话的唯一进程，也是新会话的首进程，但是它没有控制终端，调用也同时在这个会话创建了一个进程组，调用进程成为了组长进程，也是进程组唯一的进程，新会话ID和进程组ID被设置为调用进程的pid

​		也就是说，setsid()创建的新会话，并在其中创建了一个新的进程组，而且使得调用进程称为新会话的首进程和新进程组的组长进程，对于守护进程来说，这十分有用，因为它不想是任何已存在会话的成员，也不想拥有控制终端；对于shell来说它也十分有用，因为shell希望为每一个登录的用户创建新的会话。

​		成功调用，setsid()返回新会话的会话ID，错误时返回-1，并把errno设置为EPREM，表示调用进程是当前进程的组长进程。创建一个新的进程，终止父进程从而可以使任何进程不成为组长进程

```c
pid_t pid;
pid = fork();
if(pid == -1)
{
    perror("fork");
    return -1;
}
else if(pid != 0)
    exit(EXIT_SUCCESS);

if(setsid() == -1)
{
    perror("setsid");
    return -1;
}
```

​		虽然获得当前进程的会话ID不是很常用，但是有提供该函数

```c
#define _XOPEN_SOURCE 500
#include <unistd.h>
pid_t getsid(pid_t pid);
```

​		对getsid()的调用会返回pid进程的会话ID，如果参数pid是0，就返回调用进程的会话ID，错误时返回-1，而errno的唯一可能值是ESRCH，表示pid不代表任何进程。getsid()很少使用，且主要用于诊断问题：

```c
pid_t sid;
sid = getsid(0);
if(sid == -1)
    perror("getsid");//should not be possible
else
    printf("My session id = %d\n", sid)
```

#### 与进程组相关的系统调用

setpgid()将pid进程的进程组设置为pgid

```c
#define _XOPEN_SOURCE 500
#include <unistd.h>
int setpgid(pid_t pid, pid_t pgid);
```

如果pid是0，则使用调用者的pid，如果gpid是0，则将pid进程的进程ID设置为进程组ID

成功时返回0，必须依赖几个条件

- pid代表的进程必须是调用者或者是其子进程，而且子进程没有调用过exec函数，并且pid进程和调用者在同一个会话中
- pid进程不能是会话首进程
- 如果pgid已经存在，那么必须与调用者在同一个会话中
- pgid非负

错误时返回-1，并设置errno为下列值

EACCESS	pid进程是调用进程的子进程，且调用进程使用了exec函数

EINVAL		 pgid小于0

EPERM		 pid进程是会话首进程，或者是与调用者不在同一个会话中的另一个进程，也可能是试图将进程放置到一个不在同一会话的					  进程组中

ESRCH		 pid不是当前进程或0或当前进程的子进程

```c
//不是很常用，通过会话获得进程的进程组ID
#define _XOPEN_SOURCE 500
#include <unistd.h>
pid_t getpgid(pid_t pid);
```

getpgid()返回pid进程的进程组ID，如果pid是0，返回当前进程的进程组ID，出错时返回-1，而errno的唯一值ERSCH，表示pid是一个非法的进程标识符，与getsid()类似，getpgid()也主要用于诊断错误

```c
pid_t pgid;
pgid = getpgid(0);
if(pgid == -1)
    perror("getpgid");//should not be possible
else
    printf("My process group id = %d\n", pgid);
```

### 守护进程

​		守护进程运行在后台，不与任何控制终端相关联，守护进程通常在系统启动时就运行，它们以root用户运行或者其他特殊的用户（例如apache和postfix），并处理一些系统级的任务，习惯上守护进程的名字通常以d结尾（如crond和sshd），对于守护进程有两个基本要求：它必须是init进程的子进程；并且不与任何控制终端相关联

​		一般来说，进程可以通过以下步骤成为守护进程

1. 调用fork()，创建新的进程，它会是将来的守护进程
2. 在守护进程的父进程中调用exit()，保证了祖父进程确认父进程已经结束，还保证了父进程不再继续运行，守护进程不是组长进程
3. 调用setsid()，使得守护进程有一个新的进程组和新的会话，两者都把它作为首进程，这也保证它不会与控制终端相关联（因为进程刚刚创建了新的会话，同时也就不会为其关联一个控制终端）
4. 用chdir()将当前工作目录改为根目录，因为前面调用了fork()创建了新进程，它所继承来的当前工作目录可能是文件系统的任何地方，而守护进程通常在系统启动时运行，同时不希望一些随机目录保持打开状态，会阻止管理员卸载守护进程工作目录所在的文件系统
5. 关闭所有的文件描述符，不需要继承任何打开的文件描述符，对于无法确认的文件描述符，让它们继续处于打开状态
6. 打开0、1、2号文件描述符（标准输入、标准输出、标准错误），把它们重定向到 /dev/null

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>

int main(void)
{
    pid_t pid;
    int ip;
    
    //create new process
    pid = fork();
    if(pid == -1)
        return -1;
    else if(pid != 0)
        exit(EXIT_SUCCESS);
    
    //create new session and process group
    if(setsid() == -1)
        return -1;
    
    //set the working directory to the root directory
    if(chdir("/") == -1)
        return -1;
    
    //close all open file--NR_OPEN is overkill, but works
    for(i = 0; i < NR_OPEN; i++)
        close(i);
    
    //redirect fd's 0,1,2 to /dev/null
    open("/dev/null", O_RDWR);//stdin
    dup(0);					//stdout
    dup(0);					//stderror
    
    //do its daemon thing
    return 0;
}
```

​		许多Unix系统在它们的C函数库中提供了daemon()函数来完成这些工作

```c
#include <unistd.h>
int daemon(int nochdir, int noclose);
```

如果nochdir非零，就不会将工作目录改为根目录，如果noclose非零，就不关闭所有打开的文件描述符，如果父进程设置了守护进程的这些属性，那么这些参数是很有用的，通常这些参数会设为0。成功时返回0，失败时返回-1，errno设置为fork()或者setsid()的错误代码之一

## 高级进程管理

​		上面内容为创建、控制、销毁进程的内核接口，下面内容为进程调度器及其调度算法，然后为高级进程管理接口

### 进程调度

​		进程调度器是内核中决定哪个进程可以运行的组件，是把有限资源分配给进程的内核子系统，在作出决策的过程中，调度器纪要最大化处理器效率，又要让多个进程同时运行、互不影响。

​		就绪进程，最重要的特征是该进程是非阻塞的。进行用户交互、大量读写文件、响应IO、网络事件的进程会花费大量事件来等待资源可用，在相当长的时间内无法转为就绪状态（长是相对于指令运行的事件而言），因此就绪进程首先应该是非阻塞的，一个就绪进程还必须至少有部分时间片（调度器分配给内存的运行时间）。内核用一个就绪队列维护所有的就绪进程，一旦某进程耗光它的时间片，内核就将其移出队列，知道所有就绪进程都耗光时间片才考虑将其放回队列。

​		如果只有一个就绪进程（甚至没有），调度器就没有意义，只有在进程数多于处理器时，调度器才能体现它的价值，这种情况下，显然有一些进程会等待其他进程运行：决定那个进程运行，何时运行，运行多长时间也就成了调度器的基本责任。一个操作系统能在单处理机上交错运行多个进程，就称该操作系统是“多任务”的，在多处理机上，多任务操作系统允许进程在不同处理器上并行执行任务。

​		多任务操作系统分为俩大类：协同式和抢占式，Linux实现了后一种形式的多任务，调度器口可以要求一个进程停止运行，处理器转而运行另一个进程，这种中止正在运行的进程的行为叫做抢占，进程在被抢占前所运行的时间称为进程时间片。

​		在协同多任务系统中，一个进程持续运行直到它自发停止，我们称进程自发停止的行为为让出，理想情况下，会经常发生进程让出，但操作系统绝不可强制要求其让出，因此一个损坏的程序可能运行很长时间甚至导致整个系统死掉。Linux调度算法采用抢占多任务机制，支持多处理器，处理器亲和度，非一致内存访问（NUMA），实时进程和用户自定义优先级等特性。

#### 大O记法

![image-20230425224256842](Com_pictrue/image-20230425224256842.png)

​		O(1)也就表示解决问题的代价小于常数c，这就带来极好的保证：无论系统中有多少进程，Linux进程调度器表现如一，对于调度器来说，选择一个新的进程来来运行至少需要迭代一次进程队列，因而O(1)算法对性能非常重要，在稍简单些的调度器中，随着进程数量的增长，进程队列的迭代会成为潜在的瓶颈，在最好情况下，也会给进程调度带来不确定性。

#### 时间片

Linux分配给进程的时间片长短对于系统行为和性能非常重要，如果时间片太长，进程必须等待很长时间才能运行，这减少了运行的并行性，用户会察觉到明显的延迟；相反的，时间片太短，大量时间会花费在进程调度上，程序的时间局部性等也不能得到保证。因而确定合适的时间片绝非易事，一些系统给予进程长时间片，希望最大化系统吞吐率和整体表现；另一些系统给予较短的时间片，希望获得优秀的交互性能。

注意：进程不一定要在一次运行中耗光所有时间片，一个被分配100ms时间片的进程，可能运行20ms就因为等待键盘输入等资源而阻塞，此时调度器就会临时把该进程移出就绪队列；当资源可用后，这个例子中式键盘缓冲区不为空，调度器会唤醒进程，进程会继续运行耗光剩下的80ms或者有一次阻塞。

#### IO约束进程VS处理器约束进程

持续的消耗所有可用时间片称为 “处理器约束进程” 。这类进程渴望CPU时间，消耗掉调度器分配的全部时间，最简单的例子就是无限循环，其他例子包括科学计算，数学演算。

另一方面，多数时间处于等待资源的阻塞状态的进程称为 “IO约束进程” 。IO约束进程经常发起或等待文件IO，阻塞在键盘输入，或者用户移动鼠标，IO阻塞程序的例子包括文件实用程序，比如cp或者mv，它们除了请求内核执行IO操作外几乎什么都不做

​		处理器约束程序和IO约束程序得益于调度器对于不同程序类型所采用的不同行为，处理器约束程序得到尽可能长的时间片，从而最大化缓存命中率，尽快完成任务。相反的，IO约束程序不需要长时间片，因为它们一般在发出IO请求和阻塞在内核资源前只会运行很短的一段时间。然而，IO约束程序也能从调度器的持久关注中获益，被唤醒的越快，可调度的IO请求越多，程序越能充分利用系统硬件。

​		平衡处理器约束程序和IO约束程序式不同需要绝非易事，Linux调度器试图识别和优先对待IO约束程序：频繁IO程序增加优先级，处理器约束程序减少优先级。实际上，很多应用程序是处理器约束和IO约束的混合体，音频视频解码编码就是一个好例子，许多游戏也是如此，因此对于一个给定的程序，不总是能够判断它的倾向，在任意时间进程都可能有不同的表现。
