#include "huffman.h"

template<class CharType>
HuffmanTree<CharType>::HuffmanTree(OriginInfo O1[],int n){
    num = n;//获取叶子节点数目
    int m= 2*n-1;//总结点数目
    root = new huffmanNode<CharType>();//生成根节点
    for(int i=0;i<n;i++){
        if(i==0){
            huffmanNode<CharType> *tmp1= new huffmanNode<CharType>(O1[i].)
        }
    }
}