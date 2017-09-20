###从Google Chrome中删除“由企业策略安装的”扩展名

####1.前言

1. 今天不小心点开了一个垃圾程序，然后就给我的Google Chrome安装了两个插件，其中一个是`Cookies On-Off`本来说手动删除就可以了，谁知道竟然显示是“企业策略安装”，无法删除。只能上网搜索，最终在国外的网站找到了解决方法：

####2.方法

1. 通过`（Win + R）`打开中 windows 的运行框，然后输入`cmd`命令，进入终端模式
2. 在命令提示符下键入（或复制/粘贴）以下命令：

	>1. `rd /S /Q "%WinDir%\System32\GroupPolicyUsers"`
	按回车。
	>2. `rd /S /Q "%WinDir%\System32\GroupPolicy"`
	按回车。
	>3. `gpupdate /force`
	按回车。

3. 运行命令后，应该会看到以下通知：

	>1. 用户策略更新已成功完成。
	>2. 计算机策略更新已成功完成

####3.总结

1. 平常注意，不要裸机运行
2. 要学会解决问题，平常小心防范各种木马
3. 这里只给出了一种方法，还有另外的方法参考下面的链接(如果打不开，证明被墙了) ，[链接点我](https://malwaretips.com/blogs/installed-enterprise-policy-removal/#removal)