#include "huffman.h"

template<class CharType>
//从node[1~cur]中选择 双亲为0，权值最小的两个结点r1,r2
void HuffmanTree<CharType>::Select(int cur,int &r1,int &r2){
    int min1,min2;
    min1=1;
    for(int i=1;i<=cur;i++){
        if(nodes[i].parent==0&&nodes[i].weight<=nodes[min1].weight){
            min1=i;
        }
    }
    min2=(min1+1)%cur;
    for(int i=1;i<=cur;i++){
        if(nodes[i].parent==0&&nodes[i].weight<=nodes[min2]&&i!=min1){
            min2=i;
        }
    }
    r1=min1;
    r2=min2;
}






template<class CharType>
void HuffmanTree<CharType>::CreatHuffmanTree(CharType ch[],int w[],int n){
    Leafnum=n;//叶结点个数
    int Nodenum=2*Leafnum-1;//结点个数
    nodes = new HuffmanTreeNode[Nodenum+1];//nodes[0]未使用
    LeafChars = new CharType[n+1];//LeafChars[0]没有使用
    LeafCharCodes = new string[n+1];//保存叶子节点的编码信息
    int pos;
    for(pos=1;pos<=n;pos++){
        //存储叶结点信息
        nodes[pos].weight=w[pos-1];//权值
        LeafChars[pos]=ch[pos-1];//存储字符信息

    }
    //建立huffman树
    for(pos=n+1 ;pos<=Nodenum;pos++){
        int r1,r2;
        Select(pos-1,r1,r2);
        //选择双亲为0，权值最小的两个结点r1,r2

        //合并r1,r2为根的树
        nodes[r1].parent=nodes[r2].parent=pos;//给r1,r2的双亲赋值
        nodes[pos].leftChild=r1;//左孩子
        nodes[pos].rightChild=r2;//右孩子
        nodes[pos].weight=nodes[r1].weight+nodes[r2].weight;//pos权值为r1和r2权值之和

    }
    for(pos=1;pos<=n;pos++){
        //求n个叶结点的
        list<char> CharCode;//暂存叶结点的字符编码信息
        for(unsigned int child=pos,parent =nodes[child].parent;parent!=0;child=parent,parent=nodes[child].parent){
            //从叶结点逆向求编码
            if(nodes[parent].leftChild==child) CharCode.push_back('0');//左儿子为'0'
            else CharCode.push_back('1');//右分支为'1'
        }
        for(int i=0;i<CharCode.size();i++){
            LeafCharCodes[pos].push_back(CharCode[i]);
        }
    }

}