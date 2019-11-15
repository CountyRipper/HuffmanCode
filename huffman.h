#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <stddef.h>
#include <string>
#include <fstream>

using namespace std;

//原始文件信息：包括字符，出现频率
struct OriginInfo
{
    char* ch;//字符
    int* f;//出现频率
    int num;//共有多少个字符
    OriginInfo(){
        num=0;
    }
    OriginInfo(char *ch1,int *f1,int n){
        ch=ch1; f=f1; num=n;
    }
};
//编码信息，对于每个字符转换后的前缀码
struct CodeInfo
{
    char ch;//字符
    string strc;//前缀码值
    CodeInfo();
    CodeInfo(char ch1,string s1){
        ch=ch1; strc=s1;
    }
};
//获得需要编码的字符个数,字符及其出现频率并且按照从小到大排序
OriginInfo getOriginInfo(string filename);


template<class CharType>
struct huffmanNode
{
    CharType data;//字符
    huffmanNode<CharType> *leftChild;//左孩子指针域
    huffmanNode<CharType> *rightChild;//右孩子指针域
    huffmanNode<CharType> *parent;//双亲节点
    int Weight;//权值
    char huff_code;//编码值

    //构造函数模板
    huffmanNode();//无参函数构造模板
    huffmanNode(const CharType &ch,const int &w,
    const char &huffcode=0,
    huffmanNode<CharType> *lChild = NULL,
    huffmanNode<CharType> *rChild = NULL){
        data=ch;
        Weight = w;
        huff_code = huffcode;
        leftChild = lChild;
        rightChild = rChild;
    }
};

template<class CharType>
class HuffmanTree{
    protected:
        huffmanNode<CharType> *root;//根节点
        int Leafnum;//叶节点(字符)的个数

    public:
    //huffman树的声明方法
        HuffmanTree();
        HuffmanTree(OriginInfo Origin);//由字符，权值以及个数构造Huffman树
};

#endif
