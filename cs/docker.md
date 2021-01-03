---
title: 'Docker'
date: 2019-07-08 14:53:18
tags: [Docker]
published: true
hideInList: false
feature: /post-images/docker.png
---
[TOC]



# Docker命令

### 帮助命令：

查看版本：docker version

查看容器信息：docker info

帮助命令：docker --help

------

### 镜像命令：

运行镜像：docker run 镜像名

> -p 主机端口:docker容器端口
>
> -P 随机分配端口
>
> i:交互
>
> t:终端

列出本机上的镜像：docker images [options]

> -a：列出本地所有的镜像（含中间镜像层）
>
> -q：只显示当前镜像ID
>
> -qa：显示所有镜像ID
>
> --digests：显示镜像的摘要信息
>
> --no-trunc：显示完整的镜像信息

查询镜像：docker search [options] 镜像名

> --no-trunc：显示完整的镜像描述
>
> -s：列出收藏值不小于指定值镜像   docker search -s 30 tomcat
>
> --automated：只列出automatedbuild类型的镜像

拉去镜像：docker pull 镜像名[:tags]

删除镜像：docker rmi -f [options] 镜像名或者ID[:tags]

> -f：强制删除
>
> 删除多个镜像：docker rmi -f 镜像名1:TAG 镜像名2:TAG
>
> 删除全部镜像：docker rmi- f $(docker images -qa)

------

### 容器命令：

> 有镜像才能创建容器

新建并启动容器：docker run [options] IMAGE [COMMAND] [AGR] 

> OPTIONS说明（常用）：有些是一个减号，有些是两个减号
>
> --name="容器新名字": 为容器指定一个名称；
>
> -d: 后台运行容器，并返回容器ID，也即启动守护式容器；
>
> **-i：以交互模式运行容器，通常与 -t 同时使用；**
>
> **-t：为容器重新分配一个伪输入终端，通常与 -i 同时使用；**
>
> -P: 随机端口映射；
>
> -p: 指定端口映射，有以下四种格式
>
> ​      ip:hostPort:containerPort
>
> ​      ip::containerPort
>
> ​      hostPort:containerPort
>
> ​      containerPort
>
> 启动交互式容器：docker run -it 容器名 /bin/bash 

列出当前所有正在运行的容器：docker ps [OPTIONS]

> -a :列出当前所有正在运行的容器+历史上运行过的
>
> -l :显示最近创建的容器。
>
> -n：显示最近n个创建的容器。
>
> -q :静默模式，只显示容器编号。
>
> --no-trunc :不截断输出。

退出容器：

> 容器停止退出：exit
>
> 容器不停止退出：ctrl+P+Q

启动容器：docker start 容器ID或者容器名

重启容器：docker restart 容器ID或者容器名

停止容器：docker stop 容器ID或者容器名

强制停止容器：docker kill 容器ID或者容器名

删除已停止的容器：docker rm 容器ID

> 一次性删除多个容器：
>
> docker rm -f $(docker ps -a -q)
>
> docker ps -a -q | xargs docker rm

#### 重要命令

启动守护式容器：docker run -d 容器名

> \#使用镜像centos:latest以后台模式启动一个容器
>
> docker run -d centos
>
> 问题：然后docker ps -a 进行查看, 会发现容器已经退出
>
> 很重要的要说明的一点: Docker容器后台运行,就必须有一个前台进程.
>
> 容器运行的命令如果不是那些一直挂起的命令（比如运行top，tail），就是会自动退出的。
>
> 这个是docker的机制问题,比如你的web容器,我们以nginx为例，正常情况下,我们配置启动服务只需要启动响应的service即可。例如
>
> service nginx start
>
> 但是,这样做,nginx为后台进程模式运行,就导致docker前台没有运行的应用,
>
> 这样的容器后台启动后,会立即自杀因为他觉得他没事可做了.
>
> 所以，最佳的解决方案是,将你要运行的程序以前台进程的形式运行

查看容器日志：docker logs -f -t --tail 容器ID

> docker run -d centos /bin/sh -c "while true;do echo hello zzyy;sleep 2;done"
>
> -t 是加入时间戳
>
> -f 跟随最新的日志打印
>
> --tail 数字 显示最后多少条

查看容器内运行的进程：docker top 容器ID

查看容器内部细节：docker inspect 容器ID

进入正在运行的容器并以命令行交互：

- docker exec -it 容器ID bashShell
- 重新进入docker attach 容器ID

> attach 直接进入容器启动命令的终端，不会启动新的进程
>
> exec 是在容器中打开新的终端，并且可以启动新的进程

从容器内拷贝文件到主机上：docker cp  容器ID:容器内路径 目的主机路径

# docker镜像

## 特点

Docker镜像都是只读的
当容器启动时，一个新的可写层被加载到镜像的顶部。
这一层通常被称作“容器层”，“容器层”之下的都叫“镜像层”。

## 总结

attach    Attach to a running container                 # 当前 shell 下 attach 连接指定运行镜像

build     Build an image from a Dockerfile              # 通过 Dockerfile 定制镜像

commit    Create a new image from a container changes   # 提交当前容器为新的镜像

cp        Copy files/folders from the containers filesystem to the host path   #从容器中拷贝指定文件或者目录到宿主机中

create    Create a new container                        # 创建一个新的容器，同 run，但不启动容器

diff      Inspect changes on a container's filesystem   # 查看 docker 容器变化

events    Get real time events from the server          # 从 docker 服务获取容器实时事件

exec      Run a command in an existing container        # 在已存在的容器上运行命令

export    Stream the contents of a container as a tar archive   # 导出容器的内容流作为一个 tar 归档文件[对应 import ]

history   Show the history of an image                  # 展示一个镜像形成历史

images    List images                                   # 列出系统当前镜像

import    Create a new filesystem image from the contents of a tarball # 从tar包中的内容创建一个新的文件系统映像[对应export]

info      Display system-wide information               # 显示系统相关信息

inspect   Return low-level information on a container   # 查看容器详细信息

kill      Kill a running container                      # kill 指定 docker 容器

load      Load an image from a tar archive              # 从一个 tar 包中加载一个镜像[对应 save]

login     Register or Login to the docker registry server    # 注册或者登陆一个 docker 源服务器

logout    Log out from a Docker registry server          # 从当前 Docker registry 退出

logs      Fetch the logs of a container                 # 输出当前容器日志信息

port      Lookup the public-facing port which is NAT-ed to PRIVATE_PORT    # 查看映射端口对应的容器内部源端口

pause     Pause all processes within a container        # 暂停容器

ps        List containers                               # 列出容器列表

pull      Pull an image or a repository from the docker registry server   # 从docker镜像源服务器拉取指定镜像或者库镜像

push      Push an image or a repository to the docker registry server    # 推送指定镜像或者库镜像至docker源服务器

restart   Restart a running container                   # 重启运行的容器

rm        Remove one or more containers                 # 移除一个或者多个容器

rmi       Remove one or more images             # 移除一个或多个镜像[无容器使用该镜像才可删除，否则需删除相关容器才可继续或 -f 强制删除]

run       Run a command in a new container              # 创建一个新的容器并运行一个命令

save      Save an image to a tar archive                # 保存一个镜像为一个 tar 包[对应 load]

search    Search for an image on the Docker Hub         # 在 docker hub 中搜索镜像

start     Start a stopped containers                    # 启动容器

stop      Stop a running containers                     # 停止容器

tag       Tag an image into a repository                # 给源中镜像打标签

top       Lookup the running processes of a container   # 查看容器中运行的进程信息

unpause   Unpause a paused container                    # 取消暂停容器

version   Show the docker version information           # 查看 docker 版本号

wait      Block until a container stops, then print its exit code   # 截取容器停止时的退出状态值

## Docker镜像加载原理

docker的镜像实际上由一层一层的文件系统组成，这种层级的文件系统UnionFS。

bootfs(boot file system)主要包含bootloader和kernel, bootloader主要是引导加载kernel, Linux刚启动时会加载bootfs文件系统，在Docker镜像的最底层是bootfs。这一层与我们典型的Linux/Unix系统是一样的，包含boot加载器和内核。当boot加载完成之后整个内核就都在内存中了，此时内存的使用权已由bootfs转交给内核，此时系统也会卸载bootfs。

rootfs (root file system) ，在bootfs之上。包含的就是典型 Linux 系统中的 /dev, /proc, /bin, /etc 等标准目录和文件。rootfs就是各种不同的操作系统发行版，比如Ubuntu，Centos等等。 

对于一个精简的OS，rootfs可以很小，只需要包括最基本的命令、工具和程序库就可以了，因为底层直接用Host的kernel，自己只需要提供 rootfs 就行了。由此可见对于不同的linux发行版, bootfs基本是一致的, rootfs会有差别, 因此不同的发行版可以公用bootfs。

 

# docker容器数据卷

# dockerFile解析

# docker常用安装

# 本地镜像发布到阿里云