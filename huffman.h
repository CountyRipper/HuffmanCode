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
        
};