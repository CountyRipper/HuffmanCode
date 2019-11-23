#include "huffman.h"


//从node[1~cur]中选择 双亲为0，权值最小的两个结点r1,r2
void HuffmanTree::Select(int cur,int &r1,int &r2){
    r1=r2=0;
    for(int pos=1;pos<=cur;pos++){
        //查找权值最小的两个
        if(nodes[pos].parent!=0)continue;
        if(r1==0){
            //r1为空,将pos赋值给r1
            r1=pos;
        }
        else if(r2==0){
            r2=pos;
        }
        else if(nodes[pos].weight<nodes[r1].weight){
            r1 =pos;
        }
        else if(nodes[pos].weight<nodes[r2].weight){
            r2 =pos;
        }
    }
    /*int min1,min2;
    int i=1;
    while(nodes[i].parent!=0&&i<=cur){
        i++;
    }
    min1 = nodes[i].weight;
    r1=i;
    i++;
    while(nodes[i].parent!=0&&i<=cur){
        i++;
    }
    //对找到的两个节点比较大小
    if(nodes[i].weight<min1){
        min2=min1;
        r2=r1;
        min1=nodes[i].weight;
        r1=i;
    }
    else{
        min2 = nodes[i].weight;
        r2 = i;
    }
    for(int j=i+1;j<=cur;j++){
        //如果有父节点就跳过
        if(nodes[j].parent!=0){
            continue;
        }
        //如果比最小的还小将min2=min1，min1和r1获得该值
        if(nodes[j].weight<min1){
            min2=min1;
            r2=r1;
            min1=nodes[j].weight;
            r1=j;
        }
        //如果介于两者之间，将min2和r2赋值
        else if(nodes[j].weight>=min1&&nodes[j].weight<min2){
            min2=nodes[j].weight;
            r2=j;
        }
    }*/
}

void HuffmanTree::CreatHuffmanTree(vector<char> &ch,int w[],int n){
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
        //cout<<r1<<","<<r2<<","<<pos<<endl;
        //合并r1,r2为根的树
        nodes[r1].parent=nodes[r2].parent=pos;//给r1,r2的双亲赋值
        nodes[pos].leftChild=r1;//左孩子
        nodes[pos].rightChild=r2;//右孩子
        nodes[pos].weight=nodes[r1].weight+nodes[r2].weight;//pos权值为r1和r2权值之和
    }
    LeafCharCodes.push_back("");
    for(pos=1;pos<=n;pos++){
        //求n个叶结点的
        string CharCode;//暂存叶结点的字符编码信息
        for(unsigned int child=pos,parent =nodes[child].parent;parent!=0;child=parent,parent=nodes[child].parent){
            //从叶结点逆向求编码
            if(nodes[parent].leftChild==child) CharCode+='0';//左儿子为'0'
            else CharCode+='1';//右分支为'1'
        }
        reverse(CharCode.begin(),CharCode.end());
        LeafCharCodes.push_back(CharCode);
    }
    curPos = Nodenum;//译码从根节点开始，最后生成的根节点存储在nodes[Nodenum]中
}


HuffmanTree::HuffmanTree(vector<char> &ch,int *w,int n){
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

        if(nodes[curPos].leftChild==0&&nodes[curPos].rightChild==0){
            //如果到达叶节点
            charlist.push_back(LeafChars[curPos]);
            curPos=2*Leafnum-1;//curPos返回根节点
        }
    }
    return charlist;//返回编码前字符序列
}


void getInfo(vector<char>&text, vector<char> &ch,int *w,int &n){
    n=0;
    //int num;//文件所有字符个数
    
    //获得文件的字符信息
    //ch.push_back(text[0]);//把最开始的字符加入ch
    for(int i=0;i<text.size();i++){
        bool flag=true;
        for(int j=0;j<ch.size();j++){
            if(text[i]==ch[j]) flag= false;
        }
        if(flag){
            ch.push_back(text[i]);
        }
    }
    n=ch.size();//获取字符数量
    //获取int w[]
    //w = new int[n];
    for(int i=0;i<ch.size();i++){
        char test_char=ch[i];
        int char_num=0;
        for(int j=0;j<text.size();j++){
            //如果相等，数量加一
            if(text[j]==test_char) char_num++;
        }
        w[i]=char_num;
    }
}

void input(vector<char> &text){
    char ch0;//用来保存每一个文件字符
    string filename;//文件名
    cout<<"Input file:(default: test.txt)"<<endl;
    while((ch0=cin.get())!='\n'){
        filename.push_back(ch0);
    }
    if(filename==""){
        filename="test.txt";
    }
    fstream infile;
    infile.open(filename,ios::in);
    char ch1;//读取文件的每个字符
    while((ch1=infile.get())!=EOF){
        text.push_back(ch1);
    }
    infile.close();//关闭文件
}

void output(string encode_str){
    string filename;//文件名
    cout<<"Output file:(default: text_encode.txt)"<<endl;
    char ch0;
    while((ch0=cin.get())!='\n'){
        filename.push_back(ch0);
    }
    if(filename==""){
        filename="text_encode.txt";
    }
    fstream ofile;
    ofile.open(filename,ios::out);//按输出方式打开，要么新建，要么清空
    for(int i=0;i<encode_str.size();i++){
        ofile<<encode_str[i];
    }
    cout<<"Output file:"<<filename<<endl;
}