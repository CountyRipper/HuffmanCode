#include "huffman.h"


//从node[1~cur]中选择 双亲为0，权值最小的两个结点r1,r2
void HuffmanTree::Select(int cur,int &r1,int &r2){
    int min1,min2;
    min1=1;
    for(int i=1;i<=cur;i++){
        if(nodes[i].parent==0&&nodes[i].weight<=nodes[min1].weight){
            min1=i;
        }
    }
    min2=(min1+1)%cur;
    for(int i=1;i<=cur;i++){
        if(nodes[i].parent==0&&nodes[i].weight<=nodes[min2].weight&&i!=min1){
            min2=i;
        }
    }
    r1=min1;
    r2=min2;
}

void HuffmanTree::CreatHuffmanTree(vector<char> ch,int w[],int n){
    Leafnum=n;//叶结点个数
    int Nodenum=2*Leafnum-1;//结点个数
    nodes = new HuffmanTreeNode[Nodenum+1];//nodes[0]未使用
    //LeafCharCodes = new string[n+1];//保存叶子节点的编码信息
    LeafChars.push_back('\0');
    int pos;
    for(pos=1;pos<=n;pos++){
        //存储叶结点信息
        nodes[pos].weight=w[pos-1];//权值
        LeafChars.push_back(ch[pos-1]);//存储字符信息

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
        string CharCode;//暂存叶结点的字符编码信息
        for(unsigned int child=pos,parent =nodes[child].parent;parent!=0;child=parent,parent=nodes[child].parent){
            //从叶结点逆向求编码
            if(nodes[parent].leftChild==child) CharCode.push_back('0');//左儿子为'0'
            else CharCode.push_back('1');//右分支为'1'
        }
        for(int i=0;i<CharCode.size();i++){
            LeafCharCodes[pos].push_back(CharCode[i]);
        }
    }
    curPos = Nodenum;//译码从根节点开始，最后生成的根节点存储在nodes[Nodenum]中
}


HuffmanTree::HuffmanTree(vector<char> ch,int w[],int n){
    CreatHuffmanTree(ch,w,n);
}


string HuffmanTree::Encode(char ch){
    //返回字符编码
    for(int pos=1;pos<=Leafnum;pos++){
        //查找字符位置
        if(LeafChars[pos]==ch) return LeafCharCodes[pos];//找到字符，返回编码
    }
    cout<<"illegal char!"<<endl;
    return NULL;
    //抛出异常
}
//解码，返回原字符串
vector<char> HuffmanTree::Decode(string strCode){
    //对串编码strCode进行译码，返回编码前的字符序列
    vector<char>charlist; //编码前的字符序列
    for(int pos=0;pos<strCode.size();pos++){
        if(strCode[pos]=='0') curPos=nodes[curPos].leftChild; //如果是'0'就往左分支走
        else curPos = nodes[curPos].rightChild;//'1'在右分支

        if(nodes[curPos].leftChild==0&&nodes[curPos].leftChild==0){
            //如果到达叶节点
            charlist.push_back(LeafChars[curPos]);
            curPos=2*Leafnum-1;//curPos返回根节点
        }
    }
    return charlist;//返回编码前字符序列
}


void getInfo(vector<char> ch,int w[],int &n){
    cout<<"Input file:(default: text.txt)"<<endl;
    string filename;
    n=0;
    int num;//文件所有字符个数
    vector<char> char_a;//存储所有文件字符
    char ch0;//用来读取用户输入的单词
    while((ch0=cin.get())!='\n'){
        filename.push_back(ch0);
    }
    if(filename==""){
        filename="text.txt";
    }
    fstream infile;
    infile.open(filename,ios::in);
    char ch1;//读取文件的每个字符
    while((ch1=infile.get())!=EOF){
        char_a.push_back(ch1);
    }
    //获得文件的字符信息
    
}