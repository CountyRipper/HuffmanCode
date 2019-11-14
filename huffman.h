#include<string>
using namespace std;
//huffman树的构造
template <class WeightType,class CharType>
class MyHuffNode{
    public:
        virtual WeightType Weight()=0;//返回节点权值
        virtual bool Isleaf()=0;//判断是否是叶子节点
        virtual MyHuffNode<CharType,WeightType>* left();//返回节点左孩子
        virtual MyHuffNode<CharType,WeightType>* right();//返回节点右孩子
        virtual void SetLeft(MyHuffNode<CharType,WeightType>* child)=0;//设置节点的左孩子
        virtual void SetRight(MyHuffNode<CharType,WeightType>* child)=0;//设置节点右孩子

};

//对于叶子节点的声明
template<class CharType,class WeightType>
class MyLeafNode:public MyHuffNode<CharType,WeightType>{
    private:
        CharType cha;//叶子节点包含的字符
        WeightType weight;//权值

    public:
        MyLeafNode(const CharType &ch,const WeightType &w);//构造函数模板
        virtual ~MyLeafNode(){}//析构函数模板
        CharType Char();//返回叶节点的字符
        WeightType Weight();//返回节点权值
        bool IsLeaf();//判断是否是叶子节点
        MyHuffNode<CharType,WeightType>* Left();//返回节点左孩子
        MyHuffNode<CharType,WeightType>* Right();//返回节点右孩子
        void SetLeft(MyHuffNode<CharType,WeightType>* child)=0;//设置节点的左孩子
        void SetRight(MyHuffNode<CharType,WeightType>* child)=0;//设置节点右孩子

};

//Huffm树内部节点派生模板
template<class CharType,class WeightType>
class MyIntlNode:public MyHuffNode<CharType,WeightType>{
    private:
        MyHuffNode<CharType,WeightType>*lChild;//左孩子
        MyHuffNode<CharType,WeightType>*rChild;//左孩子
        WeightType weight;//权值
    public:
    //  构造函数模板
        MyIntlNode(
            MyHuffNode<CharType,WeightType> *lc,MyHuffNode<CharType,WeightType>*rc);
        virtual ~MyIntlNode(){}//析构函数
        WeightType Weight();//判断返回节点的权值
        bool IsLeaf();//判断是否为叶子节点
        MyHuffNode<CharType,WeightType> *Left();//返回节点的左孩子
        MyHuffNode<CharType,WeightType> *Right();//返回节点的右孩子
        void SetLeft(MyHuffNode<CharType,WeightType>* child)=0;//设置节点的左孩子
        void SetRight(MyHuffNode<CharType,WeightType>* child)=0;//设置节点右孩子
};

//Huffman树的模板

template<class CharType,class WeightType>
class MyHuffmanTree{
    //huffman树数据成员
    protected:
        MyHuffNode<CharType,WeightType>* root;//树根
        string *charCode;//字符编码信息
        MyHuffNode<CharType,WeightType>* pCurNode;//译码时从根节点到叶节点；路径的当前节点
        int leafnum;//叶节点个数
        unsigned int (*CharIndex)(const CharType &);//字符位置映射
    //辅助函数模板
        void CreatCode(MyHuffNode<CharType,WeightType>*r,char code[],int len=0);//生成字符编码
        void Clear(MyHuffNode<CharType,WeightType>*r);//释放以r为根的树所占用的空间

    public:
        MyHuffmanTree(CharType ch[],WeightType w[],int charnum,
        unsigned int (*ChIndex)(const CharType &));//由字符，权值，字符个数，字符位置映射构造Huffman树
        virtual ~MyHuffmanTree();//析构函数
        string Encode(CharType ch);//编码
        
    };