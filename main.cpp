#include "huffman.h"

int main(int, char**) {

    vector<char> text;//存放输入文件
    input(text);
    for(int i=0;i<text.size();i++){
        cout<<text[i];
    }
    vector<char> ch;//获取字符信息
    int w[128]={};//权重数组
    int n;//字符个数
    getInfo(text,ch,w,n);//获取文件信息
    HuffmanTree huf1(ch,w,n);
    string encode_str;
    for(int i=0;i<text.size();i++){
        encode_str+=huf1.Encode(text[i]);
    }
    cout<<"encoding finished!"<<endl;//编码完成
    int n1=0;
    for(int i=0;i<n;i++){
        n1+=w[i];
    }
    cout<<"charnumber: "<<n1<<endl;
    output(encode_str);//输出到文件
    //解码文件
    //本次为了方便直接套用原来用来存放到文件的已编码string
    //string teststr=huf1.Encode(' ');
    //cout<<teststr<<endl;
    vector<char> decode_str=huf1.Decode(encode_str);
    for(int i=0;i<decode_str.size();i++){
        cout<<decode_str[i];
    }
    cout<<endl;
    cout<<"decode finished!"<<endl;
    getchar();
    return 0;
}
