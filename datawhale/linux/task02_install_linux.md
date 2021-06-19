# 安装Linux

> 虚拟机：Vmware
>
> Linux版本：Ubuntu-20.04.1

## 换源

Ubuntu 默认的软件源是境外的，速度上会有些问题，可以在「Software & Updates」(软件和更新)中选择国内的镜像。

## 更新包

```
# 更新本地包数据库
sudo apt update

# 更新所有已安装的包（也可以使用 full-upgrade）
sudo apt upgrade

# 自动移除不需要的包
sudo apt autoremove
```

| 命令                          | 描述                                                       |
| ----------------------------- | ---------------------------------------------------------- |
| apt autoclean                 | 将已删除软件包的.deb安装文件从硬盘中删除                   |
| apt clean                     | 同上，但会把已安装的软件包的安装包也删除掉                 |
| apt autoremove                | 删除为了满足其他软件包的依赖而安装，但现在不再需要的软件包 |
| apt remove [软件包名]         | 删除已安装的软件包（保留配置文件）                         |
| apt --purge remove [软件包名] | 删除已安装包（不保留配置文件）                             |

## 中文输入法

```
# 安装
sudo apt install ibus-libpinyin 
sudo apt install ibus-clutter
```

接着在应用程序中找到「Language Support」(语言支持)，更改「Keyboard input method system」(键盘输入法系统)为「IBUS」。重启系统，然后在**Settings>Region & Language>Input Sources（设置>区域与语言>输入源）**中新增「Chinese(Intelligent Pinyin)」(中文(智能拼音))就可以使用中文输入法了。

## ZSH

```
# 安装 zsh
apt install zsh

# 将 zsh 设置为系统默认 shell
sudo chsh -s /bin/zsh

# 自动安装，如果你没安装 git 需要先安装 git
wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | sh

# 或者也可以选择手动安装
git clone git://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh
cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc
```

## 软件安装

### deb

> 基于 Debian 操作系统 (UBUNTU) 的 DEB 软件包管理工具－ Dpkg，全称为 Debian Package，是一个可以安装、构建、删除及管理 Debian 软件包的命令行工具，用来制作 Debian 包的工具，同时也可以查看、解压 Debian 包。

```linux

安装一个Debian安装包，就像是你手动下载的文件（其中-i等价于--install）
dpkg -i <package.de>
安装一个目录下面所有的软件包
dpkg -R /path/name

释放软件包，但是不进行配置
dpkg –unpack package_file 如果和-R一起使用，参数可以是一个目录

列出<package.deb>的内容中包含的文件结果（其中-c等价于--contents）
dpkg -c <package.deb>

从<package.deb>中提取包裹信息的详细信息，包括软件名称、版本以及大小等（其中-l等价于--info）
dpkg -l <package.deb>

移除一个已安装的包裹 保留其配置信息（软件名称可通过dpkg -I命令查看，其中-r等价于--remove）
dpkg -r <package>

完全清除一个已安装的包裹。和 remove 不同的是，remove 只是删掉数据和可执行文件，purge 另外还删除所有的配制文件。
dpkg -P <package>

丢失所有的Uninstall的软件包信息
dpkg –forget-old-unavail

删除软件包的Avaliable信息
dpkg –clear-avail

列出<package>安装的软件包安装的所有文件（软件名称可通过dpkg -I命令查看，其中-L等价于--listfiles）
dpkg -L <package>

查看<package>软件包的信息（软件名称可通过dpkg -I命令查看，其中-l等价于--list）
dpkg -l <package>

显示已安装包裹的详细信息。同时请看 apt-cache 显示 Debian 存档中的包裹信息，以及 dpkg -I 来显示从一个 .deb 文件中提取的包裹信息。（软件名称可通过dpkg -I命令查看，其中-s等价于--status）
dpkg -s <package>


重新配制一个已经安装的包裹，如果它使用的是 debconf (debconf 为包裹安装提供了一个统一的配制界面)。
dpkg -reconfigure <package>
重新配置和释放软件包
dpkg –configure package_file 如果和-a一起使用，将配置所有没有配置的软件包

替代软件包的信息
命令行：dpkg –update-avail <Packages-file>

合并软件包信息
dpkg –merge-avail <Packages-file>
比较同一个包的不同版本之间的差别
dpkg –compare-versions ver1 op ver2
从软件包里面读取软件的信息
dpkg -A package_file

```

### rpm

```
rpm -i <package.rpm>
```

> - `rpm -i example.rpm `安装 `example.rpm` 包；
> - `rpm -iv example.rpm` 安装 `example.rpm` 包并在安装过程中显示正在安装的文件信息；
> - `rpm -ivh example.rpm` 安装 `example.rpm` 包并在安装过程中显示正在安装的文件信息及安装进度；

查询指令：

```linux
rpm -q …
```

- `a` 查询所有已经安装的包以下两个附加命令用于查询安装包的信息；
- `i` 显示安装包的信息；
- `l` 显示安装包中的所有文件被安装到哪些目录下；
- `s` 显示安装版中的所有文件状态及被安装到哪些目录下；

以下两个附加命令用于指定需要查询的是安装包还是已安装后的文件：

- `p` 查询的是安装包的信息；
- `f` 查询的是已安装的某文件信息；

> 使用举例：
>
> - `rpm -qa | grep tomcat4` 查看 `tomcat4` 是否被安装；
> - `rpm -qip example.rpm` 查看 `example.rpm` 安装包的信息；
> - `rpm -qif /bin/df` 查看`/bin/df` 文件所在安装包的信息；
> - `rpm -qlf /bin/df` 查看`/bin/df` 文件所在安装包中的各个文件分别被安装到哪个目录下；

```
rpm -U 需要升级的包
```



## systemctl

```linux
使某服务自动启动
systemctl enable httpd.service
使某服务不自动启动
systemctl disable httpd.service
检查服务状态
systemctl status httpd.service （服务详细信息） systemctl is-active httpd.service （仅显示是否 Active)
显示所有已启动的服务
systemctl list-units --type=service
启动某服务
systemctl start httpd.service
停止某服务
systemctl stop httpd.service
重启某服务
systemctl restart httpd.service
```

彻底关闭防火墙：

```
sudo systemctl status firewalld.service
sudo systemctl stop firewalld.service          
sudo systemctl disable firewalld.service
```

参考自：[DataWhale](https://github.com/datawhalechina/team-learning-program/blob/master/Linux/2.Linux%E5%AE%89%E8%A3%85.md)、[少数派](https://sspai.com/post/60411#!)

