---
title: 'Git'
date: 2019-07-08 14:31:21
tags: [Git]
published: true
hideInList: false
feature: /post-images/git.jpeg
---
# GIT命令

- 查看commitid：git rev-parse HEAD

- 创建版本库：

  - mkdir 文件夹名
  - cd 文件夹名
  - pwd 
  - git init 

- 把文件添加到版本库

  - git add 文件名
  - git commit -m "说明"

- 查看仓库当前状态：git status

- 查看具体修改的内容：git diff 文件名

- 提交修改内容：

  - git add 文件名
  - git status
  - git commit -m "说明"

- 查看提交历史：git log --pretty=online

- 退回到上一个版本：git reset --hard HEAD

- 查看历史命令：

  - git reflog 以便确定要回到未来的哪个版本

- 管理修改

  - cat filename 命令显示版本库对象的内容，类型及大小信息
  - 用git diff HEAD -- filename命令可以查看工作区和版本库里面最新版本的区别

- 撤销修改

  - `git checkout -- filename`可以丢弃工作区的修改，其实是用版本库里的版本替换工作区的版本，无论工作区是修改还是删除，都可以“一键还原”

    用命令`git reset HEAD filename`可以把暂存区的修改撤销掉（unstage），重新放回工作区

- 删除文件：git rm filename

- 关联到远程库learngit：

  ```
  git remote add origin git@github.com:wkh19960317/learngit.git
  添加后，远程库的名字就是origin，这是Git默认的叫法，也可以改成别的，但是origin这个名字一看就知道是远程库,Learngit是github上的仓库名
  ```

- 把本地库的所有内容推送到远程库上

  - git push -u origin master实际上是把当前分支`master`推送到远程,第一次写-u，以后就不用了

- 克隆远程库

  - git clone git@github.com:wkh19960317/learngit.git

- 分支管理

  - 创建dev分支方法1：git checkout -b dev(创建并切换)

  - 创建dev分支方法2： git branch dev git checkout dev

  - 查看当前分支：git branch

  - 切换回master分支：git checkout master

  - 合并指定分支到当前分支：`git merge dev` 

    ​        git merge --no-ff -m "merge with no-ff" dev

    ​               --no-ff表示禁用Fast forward

  - 删除dev分支：
    git branch -d dev
    git branch -D dev（强行删除）

  - 解决冲突：
    git log --graph命令可以看到分支合并图

  - 保存工作现场：git stash

  - 查看保存的工作现场：git stash list

- 恢复工作现场：

  - 一是用git stash apply恢复，但是恢复后，stash内容并不删除，你需要用git stash drop来删除；
  - 另一种方式是用git stash pop，恢复的同时把stash内容也删了：
  - 恢复指定的工作现场：git stash apply stash@{0}

   

- 查看远程库信息：git remote -v

   

- 推送分支：git push origin master(origin是远程库的名称，master是远程库的分支)

  如果推送失败，先用git pull抓取远程的新提交(分支)

   

- 在本地创建和远程分支对应的分支git checkout -b branch-name origin/branch-name，本地和远程分支的名称最好一致

  建立本地分支和远程分支的关联git branch --set-upstream branch-name origin/branch-name；

   

- 标签

  - 创建标签：git tag <tagname>
  - 创建有说明的标签：git tag –a <tagname> –m “说明文字”
  - 查看所有标签：git tag
  - 查看标签信息：git show <tagname>
  - 删除标签：git tag –d <tagname>
  - 删除远程标签：git push origin :refs/tags/<tagname>
  - 推送某个标签到远程：git push origin <tagname>
  - 一次性推送所有标签：git push origin –tag