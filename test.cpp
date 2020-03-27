//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	//获取某年某月的天数
//	int GetMonthDay(int year, int month)
//	{
//		static int month_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
//		int day = month_days[month];
//		if (month == 2 &&
//			((year % 4 == 0 && year % 100 != 100) || year % 400 == 0)) {
//			day += 1;
//		}
//		return day;
//	}
//	//打印日期
//	void Print()const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//全缺省参数的构造函数
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		if (month > 0 && month < 13 
//			&& day > 0 && day <= GetMonthDay(year, month)
//			&& year >= 0)
//		{
//			_year = year;
//			_month = month;;
//			_day = day;
//		}
//		else
//		{
//			cout << "日期非法" << endl;
//		}
//	}
//	//拷贝构造函数
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//赋值运算符重载
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	//日期+天数,原日期不变
//	//Date& operator+(int day)
//	//{
//	//	//拷贝构造一个和原日期相等的类，不能直接对原日期进行操作，否则会改变原日期 
//	//	Date ret(*this);   
//	//	ret._day += day;
//	//	while (ret._day > GetMonthDay(ret._year, ret._month))
//	//	{
//	//		ret._day -= GetMonthDay(ret._year, ret._month);
//	//		++ret._month;
//	//		if (ret._month == 13)
//	//		{
//	//			ret._year++;
//	//			ret._month = 1;
//	//		}
//	//	}
//	//	return ret;
//	//}
//
//	Date operator+(int day)
//	{
//		//对+=的复用
//		Date ret(*this);
//		ret += day;
//		return ret;
//	}
//	//日期+=天数，原日期改变 
//	Date& operator+=(int day)
//	{
//		if (day < 0)
//		{
//			*this -= -day;
//			return *this;
//		}
//		_day += day;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			_month++;
//			if (_month == 13)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//	//析构函数，Date类直接用编译器生成的默认析构函数
//
//	//日期-天数
//	Date operator-(int day)
//	{
//		Date ret(*this);
//		ret -= day;
//		return ret;
//	}
//	
//	//日期-=天数
//	Date& operator-=(int day)
//	{
//		if (day < 0)
//		{
//			*this -= -day;
//			return *this;
//		}
//		_day -= day;
//		while (_day <= 0)
//		{
//			--_month;
//			if (_month == 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//		return *this;
//	}
//	// 前置++
//	Date& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//	// 后置++
//	Date operator++(int)
//	{
//		Date tmp(*this);
//		*this += 1;
//		return tmp;
//	}
//	// 后置--
//	Date operator--(int)
//	{
//		Date tmp(*this);
//		*this -= 1;
//		return tmp;
//	}
//	// 前置--
//	Date& operator--()
//	{
//		*this -= 1;
//		return *this;
//	}
//	// >运算符重载
//	bool operator>(const Date& d)
//	{
//		if ((_year > d._year)
//			|| (_year == d._year&&_month > d._month)
//			|| (_year == d._year&&_month == d._month&&_day > d._day))
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	// ==运算符重载
//	bool operator==(const Date& d)
//	{
//		return _year == d._year&&_month == d._month&&_day == d._day;
//	}
//	// >=运算符重载
//	// 实际中这里不加inline也可以，因为直接在类中实现的函数，默认就是inline
//	inline bool operator >= (const Date& d)
//	{
//		return *this > d || *this == d;
//	}
//	// <运算符重载
//	bool operator < (const Date& d)
//	{
//		return !(*this>d);
//	}
//	// <=运算符重载
//	bool operator <= (const Date& d)
//	{
//		return !(*this >= d);
//	}
//	// !=运算符重载
//	bool operator != (const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	// 日期-日期 返回天数
//	//如果*this<flag，返回值为负
//	int operator-(const Date& d)
//	{
//		int flag = -1;
//		Date min = *this;
//		Date max = d;
//		if (*this > d)
//		{
//			flag = 1;
//			min = d;
//			max = *this;
//		}
//		int n = 0;
//		while (min != max)
//		{
//			++n;
//			++min;
//		}
//		return n*flag;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2020, 3, 19);
//
//	Date d2(2020, 3, 23);
//	bool ret = d2 > d1; 
//	cout << ret << endl;
//
//	return 0;
//}


#include <iostream>
using namespace std;
class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date d);
	friend istream& operator>>(istream& _cout, Date& d);

	Date(int year=1990, int month=1, int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}
 
int main()
{
	Date d1(2020, 3, 26);
	Date d2(2020, 3, 27);
	cin >> d1 >> d2;
	cout << d1 << d2;
	return 0;
}