GIT命令

* 创建版本库：
  * mkdir filename
  * cd filename
  * pwd 
  * git init 
* 把文件添加到版本库
  * git add filename
  * git commit -m "test"
* 提交修改内容：
  * git add 文件名
  * git status
  * git commit -m "test"
* 关联到远程库learngit：

  * git remote add origin 链接
    添加后，远程库的名字就是origin，这是Git默认的叫法，也可以改成别的，但是origin这个名字一看就知道是远程库,Learngit是github上的仓库名

* 把本地库的所有内容推送到远程库上

  * git push -u origin master实际上是把当前分支`master`推送到远程,第一次写-u，以后就不用了

* 克隆远程库

  * git clone 链接

* 查看远程库信息：git remote -v

* 推送分支：git push origin master(origin是远程库的名称，master是远程库的分支)

* 在本地创建和远程分支对应的分支git checkout -b branch-name origin/branch-name，本地和远程分支的名称最好一致

  * 建立本地分支和远程分支的关联git branch --set-upstream branch-name origin/branch-name；

  
