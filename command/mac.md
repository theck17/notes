

# 终端优化
* 下载iterm2
```bash
brew cast install iTerm2
```
* Mac系统默认使用dash作为终端，可以使用命令修改默认使用zsh
```bash
chsh -s /bin/zsh
# 如果想修改回默认dash，同样使用chsh命令即可
chsh -s /bin/bash
```

* 替换背景图片
```bash
# 打开路径:iterm2 -> Preferences -> Profiles -> window -> Background Image
# 选择一张自己喜欢的壁纸即可
# 可以通过Blending调节壁纸的透明度: 透明度为0的时候,背景变为纯色(黑色)
```


* 安装Oh my zsh
```bash
# curl 安装方式
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
# wget 安装方式
sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
```
* install PowerLine
```bash
pip install powerline-status --user
```

* install powerFonts
```bash
# git clone
git clone https://github.com/powerline/fonts.git --depth=1
# cd to folder
cd fonts
# run install shell
./install.sh
# 安装好字体库之后，我们来设置iTerm2的字体，具体的操作是:
# iTerm2 -> Preferences -> Profiles -> Text
# 在Font区域选中Change Font，然后找到Meslo LG字体。
```

* 安装配色方案
```bash
git clone https://github.com/altercation/solarized
 
cd solarized/iterm2-colors-solarized/
open .
# 在打开的finder窗口中，双击Solarized Dark.itermcolors和Solarized Light.itermcolors即可安装明暗两种配色：
# 再次进入iTerm2 -> Preferences -> Profiles -> Colors -> Color Presets中根据个人喜好选择.
```

* 安装主题
```bash
git clone https://github.com/fcamblor/oh-my-zsh-agnoster-fcamblor.git
cd oh-my-zsh-agnoster-fcamblor/
./install
# 执行上面的命令会将主题拷贝到oh my zsh的themes.
# 执行命令打开zshrc配置文件，将ZSH_THEME后面的字段改为agnoster
vi ~/.zshrc
```
* 安装高亮插件
```bash
cd ~/.oh-my-zsh/custom/plugins/
 
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git
vim ~/.zshrc
# 找到plugins，此时plugins中应该已经有了git，我们需要把高亮插件也加上,zsh-syntax-highlighting必须在最后一个
# plugins=(
#      git
#      zsh-syntax-highlighting
#    )

# 然后在文件的最后一行添加
source ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
# 保存并退出
source ~/.zshrc
```

* 命令补全

```bash
cd ~/.oh-my-zsh/custom/plugins/
 
git clone https://github.com/zsh-users/zsh-autosuggestions
vim ~/.zshrc

# plugins=(
#      git
#      zsh-autosuggestions
#      zsh-syntax-highlighting
#    )

# 字体不太清晰，与背景颜色太过相近，可以调整一下字体颜色。
# Preferences -> Profiles -> Colors 中有Foreground是标准字体颜色，ANSI Colors中Bright的第一个是补全的字体颜色
```
* 隐藏前缀
```bash
# 在~/.zshrc这个文件中修改，打开后，随便找个位置（最好靠上面一点方便查看）加上一行DEFAULT_USER=$USER即可
```

* 预览
```bash
# 预览code
brew cask install qlcolorcode
#预览Markdown
brew cask install qlmarkdown
# Mac的预览本身足够强大，基于Mac这个功能，很多人开发了非常方便的预览插件，可以利用homebrew方便的下载。有人也总结了一个list，包含各种预览插件
https://github.com/sindresorhus/quick-look-plugins
```
