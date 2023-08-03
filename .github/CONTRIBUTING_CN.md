为Remc贡献力量!
======================

感谢您对Remc的贡献! :tada: 我们喜欢收到[拉取请求](https://www.quora.com/GitHub-What-is-a-pull-request)感谢我们社区的错误修复和贡献，以保持Remc的发展。  

我们希望尽可能容易地做出改变。这些指导方针旨在帮助顺利完成这一过程，并使我们能够快速方便地审查和批准您的更改。改进总是受欢迎的! 请使用 [公开问题][issue-tracker] 或 [提交新的PR申请][submit-pr]。最后，这些只是指导方针，而不是规则，所以在必要时使用你的最佳判断。  

如果你是[GitHub][github]的新手，你应该从[GitHub入门](https://help.github.com/en/categories/getting-started-with-github)和Thinkful的[GitHub_PR申请](https://www.thinkful.com/learn/github-pull-request-tutorial/)开始。  



## 语言

因为开发人员是中国人，开发人员要求保留英文或中文的代码库、问题和拉取请求。  

谢谢你的理解。  



## 报告Bug

应该使用错误报告模板在我们的[GitHub问题跟踪器][issue-tracker]上报告错误。  

按照[我如何问一个好问题?][how-to-ask]中的建议。虽然这篇文章是为那些在Stack Overflow上提问的人准备的，但它也适用于编写一份好的bug报告。  



## 请求新功能

功能请求也应该使用功能请求模板发送到我们的[GitHub问题跟踪器][issue-tracker]。  

- 解释你遇到的问题，以及你试图使用当前可用功能解决的任何问题。  

- 解释此新功能的帮助。  

- 如果可能的话，提供一个示例，比如代码片段，显示您的新功能在使用中可能是什么样子。  

此外，[我如何问一个好问题?][how-to-ask]中的许多建议也适用于此。  



## 贡献修复或功能

您已经为Remc创建了一个新的修复程序或功能。这太棒了。 :tada:   

1. 如果您还没有，请创建Remc存储库的分支。  

2. 创建一个主题分支，并在该分支上进行所有更改。  

3. 提交拉取请求，如果基于问题，则使用已执行的问题模板，如果未链接到任何问题，则采用新的问题模板。  

4. 请稍等。Remc只由少数人维护，他们都是在有限的空闲时间内维护的，所以我们可能需要一点时间来审查您的请求。错误修复应该直接合并，而功能通常需要拥有者的批准。  

如果你不确定这意味着什么，请查看Thinkful的[GitHub_PR申请教程](thinkful-pr-tutorial)，了解整个过程。  



### 写一个好的PR申请

- 专注于单个修复或功能。如果您在一个请求中提交多个更改，我们可能会喜欢其中的一些，但会发现其他的问题。当这种情况发生时，我们必须拒绝整个事情。如果您在自己的申请中提交每一项变更，我们将更容易进行审查和批准。  

- 将更改限制为仅实现修复程序或功能所需的内容。特别是，避免使用可能修改代码其他区域格式的样式或格式工具。  

- 使用描述性的提交标题/消息。"实现\<功能\>"或"修复\<错误\>"优于"更新\<文件\>"。  

- 确保您提交的代码在编译和运行时没有问题。当我们设置单元测试和持续集成时，我们还期望pull请求应该通过所有测试。  

- 在适用的情况下，在我们的PR申请模板的相应部分中使用[关键字][github-help-closing-keywords]。  

- 遵循我们的编码约定，我们有意将其保持在最低限度。  



### 代码惯例

- 命名约定：

	- 对于函数，我们使用pascal大小写：**`FunctionName`**。
	- 对于(局部)变量和函数参数，我们使用驼峰大小写：**`variableName`**和**`parameterName`**。

	- 对于类名，我们使用pascal大小写：**`ClassName`**。

	- 对于类变量，我们使用匈牙利表示法：
		- 类成员变量的前缀为"m_"：**`m_ClassMemberVariableName`**。
		- 类静态变量的前缀为"s_"：**`s_ClassStaticVariableName`**。

	- 对于宏，我们使用snake大小写：**`MACRO_NAME`**。
		- 如果它与Remc特别相关，我们添加"REMC_"前缀：**`REMC_MACRO_NAME`**。
		- 如果存在应用程序和引擎的宏，我们会在引擎宏中添加一个额外的"CORE_"前缀：**`REMC_CORE_MACRO_NAME`**。


- 使用制表符进行缩进，而不是空格。

- 如果有疑问，请匹配已存在的代码。


[github]: https://github.com
[how-to-ask]: https://stackoverflow.com/help/how-to-ask
[issue-tracker]: https://github.com/martin-zyb/Remc/issues
[submit-pr]: https://github.com/martin-zyb/Remc/pulls
[thinkful-pr-tutorial]: https://www.thinkful.com/learn/github-pull-request-tutorial/
[github-help-closing-keywords]: https://help.github.com/en/articles/closing-issues-using-keywords