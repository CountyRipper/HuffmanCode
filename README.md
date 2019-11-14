# HuffmanCode
Huffman code for Data Structure course design

##### 哈夫曼树的构建
哈夫曼树的结构：

采用儿子双亲三指针域结构 rightchild leftchild parent

数据域采用字符值 charType 权值采用 int型(后面再扩展为泛型吧)，以及编码值int(只有0和1)

构造的时候，权重小的在左边，编码值为0，权重大的在右边，编码1

构造提供两组数组，一组是字符，一组是权值，一一对应下标，从<font color=red>小到大</font>排序，同时提供数组个数，保证循环判定条件(需要在getCodeInfo中注意)

先获得前两个字符的，分别生成两个树结点，然后再生成

<font color=red>一定要设置获得叶子节点的函数</font>

##### getInfo1 提供输入文件，返回两组数组，以及字符个数
getCodeInfo(ifstream &infile ,char[] &ch ,char[] &weight)

读入文件所有内容包含空格 声明 charnum=0; 对文件内容按个读取，包含换行符和回车

##### getHufmanCode 得到哈夫曼编码值，用一组结构体数组表示
中序遍历，每次发现是叶子结点就读取char，编码值，保存到结构体数组中

每次遍历的时候会有一个string保存已经遍历过的前缀码值，遍历一遍即可获取完整的Huffman编码结构体数组

##### 编码 对源文件进行编码然后输出到目标文件
这里需要一个单文件`Encode(char ch，struct名 codeInfo[])`函数对单文件编码Encode函数在结构体数组里面查找与ch相同的字符，然后获取其编码值

##### 解码 从源文件按个读取字符然后解码输出到目标文件
这里需要一个`Uncode(string)`,挨个读入前缀码，在结构体数组中进行匹配

##### 主文件控制流程
获取文件(可以通过输入来指定，默认是test.txt)，选择进行编码或者解码(都要输出目标文件)

编码的话，先用getInfo获取文件信息，然后构造Huffman树，然后根据Huffman树获得结构体指针数组CodeInfo,然后再次扫描源文件，挨个进行Encode，输出到目标文件
