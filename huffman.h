#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_
#include <iostream>
#include <stddef.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct HuffmanTreeNode{
    //数据成员
    int weight;
    unsigned int parent,leftChild,rightChild;//双亲，左右儿子的数据
    //构造函数模板
    HuffmanTreeNode(){};
    HuffmanTreeNode(int w,int p=0 ,int lChild=0,int rChild=0){
        weight=w;parent=p;leftChild = lChild;rightChild= rChild;
    };//已知双亲，左右儿子，权值

};
//哈夫曼树
class HuffmanTree{
protected:
    //哈夫曼树数据成员
    HuffmanTreeNode *nodes;//存储结点信息；
    vector<char> LeafChars;//叶节点信息；
    string *LeafCharCodes;//叶节点编码信息
    int curPos;//译码时从根节点到叶节点路径的当前结点
    int Leafnum;//叶节点个数

    //辅助函数
    void Select(int cur,int &r1,int &r2);//node[1~cur]中选择双亲为0，权值最小的两个结点r1，r2
    void CreatHuffmanTree(vector<char> ch,int w[],int n);//由字符，权值和字符个数构造哈夫曼树

public:
    //哈夫曼树方法声明以及重载编译系统默认方法
    HuffmanTree(vector<char> ch,int w[],int n);
    ~HuffmanTree();
    string Encode(char ch);//对单个字符进行编码
    vector<char>Decode(string strCode);//对编码串进行解码
    HuffmanTree(const HuffmanTree&copy);//复制构造函数
    HuffmanTree&operator=(const HuffmanTree& copy);//重载赋值构造函数
};

//读取文件信息
void getInfo(vector<char> ch,int w[],int &n,fstream &infile);

#endif