#include <iostream>
#include <assert.h>
#include <string.h>
//#include <string>
using namespace std;

namespace func
{
    class string
    {
    public:
        typedef char* iterator;
    
        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }
        //构造函数
        string(const char* str = "")
            :_size(strlen(str))
        {
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        //析构函数
        ~string()
        {
            delete[] _str;
            _str = NULL;
            _size = _capacity = 0;
        }
        //拷贝构造
        string(const string& s)
        {
            //开空间时给\0预留一个位置
            _str = new char[s._size + 1];
            strcpy(_str,s._str);
            _size = s._size;
            _capacity = _size;
        }
        //赋值运算符重载
        string& operator=(string& s)
	    {
            //注意自赋值情况，s1 = s1;不处理会把同一空间释放两次
            if (this != &s)
            {
                delete[] _str;
                _str = new char[s._size + 1];
                strcpy(_str, s._str);
                _size = s._size;
                _capacity = _size;
            }
            return *this;
        }

        size_t size() const
        {
            return _size;
        }
        
        size_t capacity() const
        {
            return _capacity;
        }

        void reserve(size_t newcapacity)
        {
            //新容量大时才增容
            if (newcapacity > _capacity)
            {
                char *newstr = new char[newcapacity + 1];
                strcpy(newstr, _str);

                //释放旧空间，把新空间给旧空间
                delete[] _str;
                _capacity = newcapacity;
            }
        }

        void resize(size_t newcapacity, char ch = '\0')
        {
            //比原空间小，减小容量
            if (newcapacity < _capacity)
            {
                _size = newcapacity;
                _str[_size] = '\0';
            }
            else
            {
                //容量不够时进行扩容
                if (newcapacity > _capacity)
                {
                    reserve(newcapacity);
                }

                for (size_t i = _size; i < newcapacity; i++)
                {
                    _str[i] = ch;
                }
                _size = newcapacity;
                _str[_size] = '\0';
            }
        }
        //尾插一个字
        void push_back(char ch)
        {
            if (_size == _capacity)
            {
                if (_capacity == 0)
                {
                    reserve(2);
                }
                else
                {
                    reserve(_capacity * 2);
                }
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }
        //拼接一个字符串
        void append(const char *str)
        {
            size_t len = strlen(str);
            if (_size + len >= _capacity)
            {
                reserve(_size + len);
            }
            strcpy(_str + _size, str);
            _size += len;
        }
        //在pos位置上插入字符c
        string& insert(size_t pos, char c)
        {
            assert(pos < _size);
            if (_size == _capacity)
            {
                reserve(_capacity * 2);
            }
            for (size_t i = _size; i >= pos; --i)
            {
                _str[i + 1] = _str[i];
            }

            _str[pos] = c;
            ++_size;
            return *this;
        }
        //中间插入字符串
        string& insert(size_t pos, const char* str)
        {
            assert(pos < _size);
            size_t len  = strlen(str);

            if (_size + len > _capacity)
            {
                reserve(_size + len);
            }

            for (size_t i = _size; i >= pos; --i)
            {
                _str[i + len] = _str[i];
            }
            strncpy(_str + pos, _str, len);
            _size += len;
            return *this;
        }
        //删除pos位置上的元素
        string& erase(size_t pos = 0, size_t len = npos)
        {
            assert(pos < _size);
            if (pos + len >= _size)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                strcpy(_str + pos, _str + pos + len);
                _size -= len;
            }
            return *this;
        }
        //返回字符串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0)
        {
            const char *p = strstr(_str + pos, s);
            if (p == NULL)
            {
                return npos;
            }
            else
            {
                return p - _str;
            }
        }
        
        void swap(string& s)
        {
            if (_capacity < s._capacity)
            {
                this->reserve(s._size);
                string tmp(s);
                strcpy(s._str, _str);
                strcpy(_str, tmp._str);
                s._size = _size;
                _size - tmp._size;
            }
            else if (_capacity == s._capacity)
            {
                string tmp(s);
                strcpy(s._str, _str);
                strcpy(_str, tmp._str);
            }
            else
            {
                s.reserve(_size);
                string tmp(*this);
                strcpy(_str, s._str);
                strcpy(s._str, tmp._str);
                _size = s._size;
                s._size = tmp._size;
            }
        }

        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        string& operator+=(const char *str)
        {
            append(str);
            return *this;
        }

        char& operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }

        const char& operator[](size_t pos) const
        {
            assert(pos < _size);
            return _str[pos];
        }

        bool operator<(const string& s)
        {
            return strcmp(_str, s._str) < 0 ? true : false;
        }

        bool operator==(const string& s)
        {
            return strcmp(_str, s._str) == 0 ? true : false;
        }

        bool operator>(const string& s)
        {
            return !operator<(s);
        }

        bool operator<=(const string& s)
        {
            return operator<(s) || operator==(s);
        }

        bool operator>=(const string& s)
        {
            return operator==(s) || operator>(s);
        }

        bool operator!=(const string& s)
        {
            return !operator==(s);
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        bool empty() const
        {
            if (*_str == '\0')
            {
                return true;
            }
            return false;
        }

        const char* c_str() const
        {
            return _str;
        }

    private:
        char* _str;
        size_t _capacity;
        size_t _size;
        static size_t npos;
    };

    size_t string::npos = -1;

    ostream& operator<<(ostream& out, const string& s)
    {
        for (size_t i = 0; i < s.size(); ++i)
        {
            out << s[i];
        }
        return out;
    }
    istream& operator>>(istream& in, string& s)
    {
        while(1)
        {
            char ch = in.get();
            if (ch == '\0')
            {
                break;
            }
            else
            {
                s += ch;
            }
        }
        return in;
    }
}

void TestString()
{
    func::string s1 = "hello world";
    func::string s2(s1);
    func::string s3;
    s3 = s2;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    s1.push_back('h');
    s1.push_back('h');
    s1.push_back('h');
    s1.push_back('h');
    s1.push_back('h');
    s2.append("hello");
    s3 += "world";
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    
    s1.insert(5, 'd');
    s1.insert(5, 'd');
    s1.insert(5, 'd');
    s1.insert(5, 'd');
    s1.insert(5, 'd');
    s2.insert(5, "hello");
    s3.insert(5, "world");
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    s1.erase(5, 10);
    s2.erase(5, 10);
    s3.erase(5, 10);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
}

int main()
{
    TestString();
    return 0;
}
