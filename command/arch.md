* 设置字体

  ```shell
  # setfont /usr/share/kbd/consolefonts/LatGrkCry-12x22.psfu.gz(文件名)
  ```

* 更改键盘布局

  控制台键盘布局默认为 `us`（美式键盘映射）。列出所有可用的键盘布局，可以使用：

  ```shell
  # ls /usr/share/kbd/keymaps/**/*.map.gz
  ```

  如果您想要更改键盘布局，可以将一致的文件名添加进，但请省略路径和扩展名。比如，要添加 German键盘布局：

  ```shell
  # loadkeys de-latin1
  ```

  大写锁定换成ESC，ESC换成大写锁定，这里文件名可以随便起一个

  ```shell
  # vim keys.conf
  i
  keycode 1 = Caps_Lock
  keycode 58 = Escape
  :wq
  # loadkeys keys.conf
  ```

* 配置网络

  ```shell
  # ip link 查看互联网设备
  # ip link set 设备名
  # iwlist wlan0(设备名) scan 扫描wifi
  # iwlist wlan0(设备名) scan ｜ grep ESSID 过滤结果
  # wpa_passwphrase 网络 密码 > 文件名  生成一个网络配置文件
  # wpa_supplicant -c 文件名 -i wlan0(设备名) & shift+7 链接网络并后台运行
  # dhcpcd & shift+7 分配一个ip地址并后台运行
  ```

### 更新系统时间

可以先使用 `timedatectl status` 检查服务状态，查看时间是否准确。
 如果时间有问题，使用 timedatectl 确保系统时间是准确的：

```shell
# timedatectl set-ntp true
```

### 建立硬盘分区

1、查看磁盘情况

磁盘若被系统识别到，就会被分配为一个 块设备，如 /dev/sda 或者 /dev/nvme0n1。可以使用 lsblk 或者 fdisk 查看存储设备情况：

```shell
# fdisk -l
```

结果中以 `rom`，`loop` 或者`airoot` 结束的可以忽略。

2、分区方案

对于选择安装系统的磁盘，采用如下分配方案基本满足需求：

- 一个根分区（挂载在根目录，必须）/；
- 一个home分区 （建议进行分区）；
- 交换分区，`Swap`可以在一个独立的分区上设置，也可以直接建立 `交换文件`；
- 如果使用UEFI/GPT 模式引导，必须有一个 EFI 引导分区（如果安装了其他UEFI引导的系统，则记下其EFI分区路径。如果是全新的硬盘则需要新建一个EFI的引导分区）

3、建立分区

建立分区，可以使用 fdisk 或 parted。例如使用 fdisk进入分区状态

#### 分区示例

|  挂载点  |     分区      | [分区类型](https://en.wikipedia.org/wiki/Partition_type) |   建议大小   |
| :------: | :-----------: | :------------------------------------------------------: | :----------: |
|  `/mnt`  | `/dev/sd*X*1` |                          Linux                           |   剩余空间   |
| `[SWAP]` | `/dev/sd*X*2` |                  Linux swap (交换空间)                   | 大于 512 MiB |

|          挂载点           |     分区      | [分区类型](https://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_type_GUIDs) |   建议大小   |
| :-----------------------: | :-----------: | :----------------------------------------------------------: | :----------: |
| `/mnt/boot` 或 `/mnt/efi` | `/dev/sd*X*1` | [EFI 系统分区](https://wiki.archlinux.org/index.php/EFI_system_partition_(简体中文)) | 260–512 MiB  |
|          `/mnt`           | `/dev/sd*X*2` |                   Linux x86-64 根目录 (/)                    |   剩余空间   |
|         `[SWAP]`          | `/dev/sd*X*3` |                    Linux swap (交换空间)                     | 大于 512 MiB |

```shell
# fdisk /dev/sda
# m
# p 查看分区
# g 新建分区lable
# n 新建分区：新建一个
# w 写入硬盘
# 格式化分区
# mkfs.ext4 /dev/sda1  （请将的sdxY替换为刚创建的分区）
# 挂在分区
# mount /dev/sdxY /mnt （请将sdxY替换为之前创建的根分区）
UEFI：系统引导512M，swap1G，其他分为主分区
# w 写入硬盘
# 格式化分区
# mkfs.fat -F32 /dev/sda1(引导分区)
# mkfs.ext4 /dev/sda2(主分区)
# mkswqp /dev/sda3(swap分区)
# swapon /dev/sda3
# 挂在分区，swap不需要挂载
# mount /dev/sda2 /mnt
# mkdir /mnt/boot
# mount /dev/sda2 /mnt/boot
```

**注意: **如果需要需要创建多级存储例如 LVM、disk encryption 或 RAID，请在此时完成。

1. 建立分区表：先执行`# fdisk /dev/sda`，之后按 `o`建立分区表
2. 进行分区（一般建立 `/ , /swap , /home`三个分区）：执行 `n` ，依次选择主分区、扩展分区，第几分区，起始扇区，结束扇区或者直接使用 `+30G`设置分区为30G大小。
3. 如需修改分区类型：执行`t`，将swap分区类型改为`Linux Swap`类型。
4. 保存分区。保存之前可输入`p`查看分区结果，确认无误执行`w`保存分区。

### 配置pacman文件，改源

```shell
# vim /etc/pacman.conf
#color 去掉前面的#，可以在安装时获得彩色提示
[core][extra][community]为软件源文件的路径
:wq
# vim /etc/pacman.d/mirrorlist
Server = http://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch
Server = http://mirrors.zju.edu.cn/archlinux/$repo/os/$arch
Server = http://mirrors.163.com/archlinux/$repo/os/$arch
Server = http://mirrors.cqu.edu.cn/archlinux/$repo/os/$arch
```

### 安装基本系统

使用`pacstrap`脚本，安装 `base` ，`base-devel`包组：

```shell
# pacstrap /mnt base base-devel linux linux-firmware dhcpcd
linux-firmware 虚拟机可以不安装
# genfstab -U /mnt >> /mnt/etc/fstab   生成 fstab文件
# nano /mnt/etc/fstab  检查一下生成的 /mnt/etc/fstab 文件是否正确
```

`base-devel`也可以在`#Chroot`之后使用`pacman` 手动安装软件包或组：

```shell
# pacstrap -i /mnt base base-devel
```

### Chroot

Change root到新安装的系统：

```shell
# arch-chroot /mnt
```

### 时区

设置时区

```shell
# ln -sf /usr/share/zoneinfo/Region/City /etc/localtime
```

例如：

```shell
# ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
```

运行 `hwclock`以生成 `/etc/adjtime`：

```shell
# hwclock --systohc
```

这个命令假定硬件时间已经被设置为 *UTC时间* 。

### 本地化

本地化的程序与库若要本地化文本，都依赖 *Locale*，后者明确规定地域、货币、时区日期的格式、字符排列方式和其他本地化标准等等。在下面两个文件设置：`locale.gen` 与 `locale.conf`。
 `/etc/locale.gen` 是一个仅包含注释文档的文本文件。指定您需要的本地化类型，只需移除对应行前面的注释符号（`＃`）即可，建议选择带 `UTF-8` 的项：

```shell
# nano /etc/locale.gen
或
# exit 退出 arch-chroot /mnt
# vim /mnt/etc/locale.gen
```

> en_US.UTF-8 UTF-8
>  zh_CN.UTF-8 UTF-8
>  zh_TW.UTF-8 UTF-8

接着执行 `locale-gen` 以生成 locale 讯息，`/etc/locale.gen` 会生成指定的本地化文件。：

```shell
# arch-chroot /mnt
# locale-gen
```

创建 `locale.conf` 并编辑 `LANG` 这一 *变量*，比如：

```shell
# nano /etc/locale.conf
或
# exit 退出 arch-chroot /mnt
# vim /mnt/etc/locale.conf
```

> LANG=en_US.UTF-8

**Tip:** 将系统 locale 设置为 `en_US.UTF-8`，系统的 Log 就会用英文显示，这样更容易问题的判断和处理。**不推荐**在此设置任何中文 locale，会导致 TTY 乱码。
 另外，如果你需要修改*键盘布局*，并想让这个设置持续生效，编辑`vconsole.conf`，例如：

```shell
# nano /etc/vconsole.conf
```

> KEYMAP=de-latin1

### 主机名

要设置 `hostname`，将其 *添加* 到 `/etc/hostname`，*myhostname* 是需要的主机名：

```shell
# nano /etc/hostname
or
# exit 退出 arch-chroot /mnt
# vim /mnt/etc/hostname
```

> myhostname

并且添加 *对应的信息* 到 `hosts`：

```shell
# nano /etc/hosts
or
# exit 退出 arch-chroot /mnt
# vim /mnt/etc/hosts
```

> 127.0.0.1  localhost
>  ::1     localhost
>  127.0.1.1   myhostname.localdomain  myhostname

如果机器有一个永久的 IP 地址，请使用这个 IP 而不是 `127.0.1.1`。

### Root 密码

设置 Root 密码 ：

```shell
# arch-chroot /mnt
# passwd
```

### 安装引导程序

你需要安装 Linux 引导程序以在安装后启动系统，你可以使用的的引导程序在 *启动加载器* 中，请选择一个并且安装并配置它，比如 *GRUB* 。
 如果你使用 Intel 或者 AMD 的 CPU，那么需要 *启用微码更新* 。

```shell
# arch-chroot /mnt
# pacman -S grub efibootmgr intel-ucode os-prober
# mkdir /boot/grub
# uname -m 查看系统架构
BIOS方式
# grub-install --target=i386-pc /dev/sda
非BIOS方式
# grub-install --target=x86_64-efi --efi-directoryy=/boot
```

>此步骤出现异常时，重新挂在分区，我这个虚拟机只创建了一个分区
>
>error
>
>this GPT partition label contains no BIOS Boot Partition;embedding won't be possible
>embedding is not possible, GRUB can only be install in this setup by using blocklists.However,blocklists are unreliable and their use is discouraged
>will not processd with blocklists

#### 安装`Intel-ucode`（非`Intel`CPU可以跳过此步骤）

直接`pacman`安装：

```shell
# arch-chroot /mnt
# pacman -S intel-ucode
```

#### 安装`Bootloader`

经常听说很多人因为引导问题导致系统安装失败，多数是因为教程没有统一或是过时的教程引起的，这里只要按照步骤来其实是不难的。

这里我们安装最流行的`Grub2`。**（如果曾经装过`Linux`，记得删掉原来的`Grub`，否则不可能成功启动）**

- 首先安装`os-prober`和`ntfs-3g`这两个包，它可以配合`Grub`检测已经存在的系统，自动设置启动选项。

  ```shell
  # pacman -S os-prober ntfs-3g
  ```

##### **如果为BIOS/MBR引导方式：**

- 安装`grub`包：

  ```shell 
  # pacman -S grub
  ```

- 部署`grub`：

  ```shell
  # grub-install --target=i386-pc /dev/sdx （将sdx换成你安装的硬盘）
  ```

  注意这里的`sdx`应该为硬盘（例如`/dev/sda`），**而不是**形如`/dev/sda1`这样的分区。

- 生成配置文件：

  ```shell
  # grub-mkconfig -o /boot/grub/grub.cfg
  ```

##### **安装一些工具**

```shell 
# pacman -S neovim vi zsh wpa-supplicant dhcpcd
```

##### **重启**

```shell 
# reboot
用root登陆
重启之后不能上网需要分配一个ip
# dhcpcd & 7

```

### **简单配置**

```shell
用root登陆
重启之后不能上网需要分配一个ip
# dhcpcd & 7
更新
# pacman -Syyu
安装一些东西
# pacman -S man
# pacman -S base-devel
添加用户
# useradd -m -G wheel colin
# passwd colin
# visudo    删掉wheel组的#
:wq
退出root用户，用colin用户登陆
exit
colin

```

### **安装界面**：deepin

````shell
# sudo pacman -S xorg xorg-server
# sudo pacman -S deepin deepin-extra
# pacman -Qs lightdm
# vim /etc/lightdm/lightdm.conf
去掉批注：# greeter-session=example-gtk-gnome
修改为：greeter-session=lightdm-deepin-greeter
:wq
# sudo systemctl enable lightdm  设置开机启动登陆界面
# sudo systemctl start lightdm  立即启动登陆界面
````

### **配置**

```shell
# sudo pacman -S firefox
# sudo pacman -S git
github搜索安装yay
# git clone https://aur.archlinux.org/yay.git --depth=1
# cd yay
# makepkg -si
# pacman -Qs yay
# yay -S google-chrome
```

### **没网**

```shell
# dhcpcd &7
```

### **中文乱码**

```shell
# pacman -S wqy-zenhei ttf-fireflysung
```

# 问题

  ```shell
1、error: failed to commit transaction(confilcting files)
deepin-screen-recorder:usr/bin/deepin-screenshot exist in filesystem(owner by deepin-screenshot) Errors occurred, no packages were upgraded.ed

sudo pacman -Syu --overwrite /usr/bin/deepin-screenshot 
  ```

