#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
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

		string(const char *str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		string(const string& s)
		{
			//���ռ�ʱ��\0��һ��λ��
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = _size;
		}

		string& operator=(string& s)
		{
			//ע���Ը�ֵ�����s1 = s1;��������ͬһ��ռ��ͷ����� 
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

		void reserve(size_t newcapacity)
		{
			//��������ʱҪ����
			if (newcapacity > _capacity)
			{
				char *newstr = new char[newcapacity + 1];
				strcpy(newstr, _str);

				//�ͷžɿռ䣬���¿ռ���ɿռ�
				delete[] _str;
				_str = newstr;
				_capacity = newcapacity;
			}
		}

		void resize(size_t newcapcity, char ch = '\0')
		{
			//��ԭ�ռ�С����С���� 
			if (newcapcity < _capacity)
			{
				_size = newcapcity;
				_str[_size] = '\0';
			}
			else
			{
				//����������������
				if (newcapcity > _capacity)
				{
					reserve(newcapcity);
				}
				
				for (size_t i = _size; i < newcapcity; i++)
				{
					_str[i] = ch;
				}
				_size = newcapcity;
				//һ��Ҫ�����һ��λ����Ϊ'\0'
				_str[_size] = '\0';
			}
		}
		//β��һ���ַ�
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//ƴ��һ���ַ���
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
	private:
		char *_str;
		size_t _capacity;
		size_t _size;
	};

	
	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}
		return out;
	}
}

int main()
{
	func::string s1("hello");
	func::string s2;
	s2 = s1;
	cout << s1 << endl;
	cout << s2 << endl;

	s1.push_back('x');
	s1.push_back('y');
	s1.append("world");
	s2 += " ";
	s2 += " ";
	s2 += "world";
	cout << s1 << endl;
	cout << s2 << endl;

	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (auto& ch : s2)
	{
		ch += 1;
		cout << ch << " ";
	}
	cout << endl;

	func::string::iterator it1 = s2.begin();
	while (it1 != s2.end())
	{
		*it1 -= 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	return 0;
}