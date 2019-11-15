#include "huffman.h"

OriginInfo getOriginInfo(string filename){
    fstream infile;
    infile.open(filename);
    infile.seekg(ios::beg);
    char curchar;//文件读取的当前字符数
    int count;//文件计数
    string text;
    char ch1[128];//统计字符元素
    int f1[128]={0};//统计字符出现频率
    while(!infile.eof()){
        curchar=infile.get();
        text+=curchar;
    }

    for(int i=0;i<text.length();i++){
        int flag=0;//用来判定之前是否出现了重复字符，出现了就为1
        for(int j=0;j<i;j++){
            if(text[i]==ch1[j]){
                flag=1;
                break;
            }
        }
        if(!flag){
            ch1[i]=text[i];//如果没有出现就放入ch1数组中
            count++;
        }
    }
    for(int i=0;i<count;i++){
        int count1=0;//标记单个字符频率
        for(int j=0;j<text.length();j++){
            if(text[j]==ch1[i]){
                count1++;
            }
        }
        f1[i]=count1;
    }
    OriginInfo O1(ch1,f1,count);
    //排序O1
    for(int i=count-1;i>0;i--){
        for(int j=i;j>0;j--){
            if(O1.f[j]<O1.f[j-1]){
                //如果频率更小就跟前一个替换
                char tmpchar,tmpf;
                tmpchar = O1.ch[j];
                tmpf = O1.f[j];
                O1.ch[j]=O1.ch[j-1];
                O1.f[j]=O1.f[j-1];
                O1.ch[j-1]=tmpchar;
                O1.f[j-1]=tmpf;
            }
        }
    }
    return O1;
}



template<class CharType>
HuffmanTree<CharType>::HuffmanTree(OriginInfo Origin){
    Leafnum = Origin.num;//获取叶子节点数目
    int Nodesum= 2*Leafnum-1;//总结点数目
    if(Leafnum==1){
        root = new huffmanNode(Origin.ch[0],Origin.f[0]);
    }
    else{
        int curnum=0;
        huffmanNode<CharType> tmpNode1=new huffmanNode(Origin.ch[curnum],Origin.f[curnum],0);
        
    }
}