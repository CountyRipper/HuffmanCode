#include <stddef.h>
#include <string>
#include <fstream>

using namespace std;

//原始文件信息：包括字符，出现频率
struct OriginInfo
{
    char ch;//字符
    int f;//出现频率

    OriginInfo();
    OriginInfo(char ch1,int f1){
        ch=ch1; f=f1;
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
//获得需要编码的字符个数
int getOriginCodeNum(ifstream &infile);
//得到原始数据信息：即字符及其出现频率并且按照从小到大排序
void GetCodeInfo(ifstream &infile,OriginInfo *OriginInfo_arr);

template<class CharType>
struct huffmanNode
{
    CharType data;
    huffmanNode<CharType> *leftChild;//左孩子指针域
    huffmanNode<CharType> *rightChild;//右孩子指针域
    huffmanNode<CharType> *parent;//双亲节点
    int Weight;//权值
    int huff_code;//编码值

    //构造函数模板
    huffmanNode();//无参函数构造模板
    huffmanNode(const CharType &ch=NULL,const int &w=0,const int &huffcode=0,
    huffmanNode<CharType> *P = NULL,
    huffmanNode<CharType> *lChild = NULL, huffmanNode<CharType> *rChild = NULL)
};

template<class CharType>
class HuffmanTree{
    protected:
        huffmanNode<CharType> *root;//根节点
        int num;//叶节点(字符)的个数

    public:
    //huffman树的声明方法
        HuffmanTree();
        HuffmanTree(OriginInfo[] O1,int n);//由字符，权值以及个数构造Huffman树
};
