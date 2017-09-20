###Sublime Text3--打造完美的Markdown编辑器

- **注意：**由于在前面已经讲过了插件的安装和一些配置、操作等，这里就不在赘述。
> 不了解的请移步：[Sublime Text3--插件安装](http://blog.csdn.net/xingerr/article/details/70231554 "Sublime Text3--插件安装")

####1.所需的插件

- [Markdown Editing](https://packagecontrol.io/packages/MarkdownEditing "Markdown Editing")
> 提供辅助提示，比如输入 *，编辑器应当自动补上一个 *，并使光标保持在两 * 之间，

	> 又比如应当支持选中一段文字快捷键添加链接

- [Markdown Extended](https://packagecontrol.io/packages/Markdown%20Extended "Markdown Extended")
> 让 Markdown 格式在 Sublime 中支持高亮

- [Monokai Extended](https://packagecontrol.io/search/Monokai%20Extended "Monokai Extended")
> 提供主题支持 Markdown 的高亮（包括 Markdown 代码块内的代码）

- [MarkdownTOC](https://packagecontrol.io/packages/MarkdownTOC "MarkdownTOC")
> 编写 heading 较多的长文档，希望能够自动生成目录方便跳转，MarkdownTOC 可以帮助我们实现

- [Table Editor](https://packagecontrol.io/packages/Table%20Editor "Table Editor")
> 键入表格是个体力活，Table Editor 可以帮助我们减轻工作量

- [OmniMarkupPreviewer](https://packagecontrol.io/packages/OmniMarkupPreviewer "OmniMarkupPreviewer")
> 提供了LaTex的数学公式渲染的支持，用浏览器打开以后支持浏览器的实时渲染和更新预览

####2.插件的配置(默认都是在:Setting - User)
- [MarkdownTOC]:

```json
{
  "default_autolink": true,
  "default_bracket": "round",
  "default_depth": 0
}
```

- [OmniMarkupPreviewer]

```json
{
    "renderer_options-MarkdownRenderer":
    {
        "extensions": ["tables", "fenced_code", "codehilite"],
    	"parser": "markdown",
    	"enabled_parsers": ["markdown"]
	}
}
```

- **注意：**这个插件在配置完成后，有可能会出现无法使用，并且报错：

`404错误预览...“buffer_id（29）无效（关闭或不支持的文件格式）”`
(我就是这个错)

> 1.这里给出解决方案(上面的配置文件已经好了)：
>> 1.如上面的配置去掉了原文件 `"extensions": ["tables", "strikeout", "fenced_code", "codehilite"]`的**"strikeout"**		
>> 2.找到python-markdown Sublime Text3的包。
>>> Mac: `subl "/Users/<username>/Library/Application Support/Sublime Text 3/Packages/OmniMarkupPreviewer/OmniMarkupLib/Renderers/libs/mdx_strikeout.py"`

>> 用以下makeExtension()方法替换方法：
`def makeExtension(*args, **kwargs):
    return StrikeoutExtension(*args, **kwargs)`
保存，退出并重新加载升级文本。

> 3.链接：<https://github.com/timonwong/OmniMarkupPreviewer/issues/85>

- [OmniMarkupPreviewer]续：

	1.打开OmniMarkupPreviewer的默认配置文件Setting-Default    
	2.查看参数：		
	`"server_host": "127.0.0.1",` (开启预览服务的 IP 地址, 默认为 localhost)		
	`"html_template_name": "github",` (预览使用的模板名称，默认为 Github)		
	`"browser_command": [],` (预览默认为跟随系统默认浏览器，[“open”, “-a”, “Google Chrome”, “{url}”]亦可利用这样的格式进行指定)		
	`"ignored_renderers": ["LiterateHaskellRenderer"],`(忽略/关闭的标记语言渲染器)		
	`"mathjax_enabled": false,`(公式的渲染使用了MathJax库，所以需要在OmniMarkupPreviewer的设置中，将”mathjax_enabled”设置为“true”)

####快捷键
- [MarkdownEditing]
> Option + Command + K - 插入链接；	
Option + Command + V - 粘贴为链接格式；		
Shift + Command + K - 插入图片。

- 快捷键设定
> 自己没有其他的快捷键，所以就不写了	
> 大家可以自己设定快捷键(自行Google)

####参考文章
- <http://webcache.googleusercontent.com/search?q=cache:http://www.itwendao.com/article/detail/75735.html>
- <https://blog.mariusschulz.com/2014/12/16/how-to-set-up-sublime-text-for-a-vastly-better-markdown-writing-experience>