#include <iostream>
#include <string>
using namespace std;

 //size/clear/resize
 void Teststring1()
{
    string s("hello!!!");
    cout << s.size() << endl;
    cout << s.length() << endl;
    cout << s.capacity() << endl;
    cout << s << endl;

    //将s中的字符串清空，只将size清0，不改变底层空间的大小
    s.clear();
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    //将s中的有效字符个数增加到10个，多出位置用'a'进行填充
    //"aaaaaaaa"
    s.resize(10, 'a');
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    //将s中的有效字符增加到15个，多出位置用缺省值'\0'进行填充
    //"aaaaaaaa\0\0\0\0\0"
    //此时s中的有效字符已经增加到15个
    s.resize(15);
    cout << s.size() << endl;
    cout << s.capacity() << endl;
    cout << s << endl;
}

void Teststring2()
{
    string s;
    //测试reserve是否会改变string中的有效元素
    s.reserve(100);
    cout << s.size() << endl;
    cout << s.capacity() << endl;

    //测试reserve参数小于string的底层空间大小时，是否会将空间缩小
    s.reserve(50);
    cout << s.size() << endl;
    cout << s.capacity() << endl;
}

void TestPushBack()
{
    string s;
    size_t sz = s.capacity();
    cout << "making s grow:\n";
    for (int i = 0; i < 100; ++i)
    {
        s.push_back('c');
        if (sz != s.capacity())
        {
            sz = s.capacity();
            cout << "capacity changed: " << sz << '\n';
        }
    }
}

void TestPushBackReserve()
{
    string s;
    s.reserve(100);
    size_t sz = s.capacity();

    cout << "making s grow:\n";
    for (int i = 0; i < 100; ++i)
    {
        s.push_back('c');
        if (sz != s.capacity())
        {
            sz = s.capacity();
            cout << "capacity changed: " << sz << '\n';
        }
    }
}

void Teststring3()
{
    string s("hello world!");
    //3种遍历方式
    //1.for + operator[]
    for (size_t i = 0; i < s.size(); ++i)
    {
        cout << s[i] << " ";
    }
    cout << endl;

    //2.迭代器
    string::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    string::reverse_iterator rit = s.rbegin();
    while (rit != s.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
    //3.范围for
    //for(auto& ch : s)
    //{
    //    cout << ch << endl;
    //}
}

void Teststring4()
{
    string str;
    str.push_back(' ');
    str.append("hello");
    str += 'b';
    str += "it";
    cout << str << endl;
    cout << str.c_str() << endl;

    //获取file的后缀
    string file("string.cpp");
    size_t pos = file.rfind('.');
    string suffix(file.substr(pos, file.size() - pos));
    cout << suffix << endl;

    //npos是string里面的一个静态成员变量
    //static const size_t npos = -1;
    
    //取出url中的域名
    string url("https://www.baidu.com/?tn=78040160_26_pg&ch=8");
    cout << url << endl;
    size_t start = url.find("://");
    if (start == string::npos)
    {
        cout << "invalid url" << endl;
        return;
    }
    start += 3;
    size_t finish = url.find('/', start);
    string address = url.substr(start, finish - start);
    cout << address << endl;

    //删除url的协议前缀
    pos = url.find("://");
    url.erase(0, pos + 3);
    cout << url << endl;

}

int main()
{
    //Teststring1();
    //Teststring2();
    //TestPushBack();
    //TestPushBackReserve();
    //Teststring3();
    Teststring4();
    return 0;
}
