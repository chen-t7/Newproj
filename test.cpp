//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	//��ȡĳ��ĳ�µ�����
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
//	//��ӡ����
//	void Print()const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//ȫȱʡ�����Ĺ��캯��
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
//			cout << "���ڷǷ�" << endl;
//		}
//	}
//	//�������캯��
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//��ֵ���������
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
//	//����+����,ԭ���ڲ���
//	//Date& operator+(int day)
//	//{
//	//	//��������һ����ԭ������ȵ��࣬����ֱ�Ӷ�ԭ���ڽ��в����������ı�ԭ���� 
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
//		//��+=�ĸ���
//		Date ret(*this);
//		ret += day;
//		return ret;
//	}
//	//����+=������ԭ���ڸı� 
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
//	//����������Date��ֱ���ñ��������ɵ�Ĭ����������
//
//	//����-����
//	Date operator-(int day)
//	{
//		Date ret(*this);
//		ret -= day;
//		return ret;
//	}
//	
//	//����-=����
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
//	// ǰ��++
//	Date& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//	// ����++
//	Date operator++(int)
//	{
//		Date tmp(*this);
//		*this += 1;
//		return tmp;
//	}
//	// ����--
//	Date operator--(int)
//	{
//		Date tmp(*this);
//		*this -= 1;
//		return tmp;
//	}
//	// ǰ��--
//	Date& operator--()
//	{
//		*this -= 1;
//		return *this;
//	}
//	// >���������
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
//	// ==���������
//	bool operator==(const Date& d)
//	{
//		return _year == d._year&&_month == d._month&&_day == d._day;
//	}
//	// >=���������
//	// ʵ�������ﲻ��inlineҲ���ԣ���Ϊֱ��������ʵ�ֵĺ�����Ĭ�Ͼ���inline
//	inline bool operator >= (const Date& d)
//	{
//		return *this > d || *this == d;
//	}
//	// <���������
//	bool operator < (const Date& d)
//	{
//		return !(*this>d);
//	}
//	// <=���������
//	bool operator <= (const Date& d)
//	{
//		return !(*this >= d);
//	}
//	// !=���������
//	bool operator != (const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	// ����-���� ��������
//	//���*this<flag������ֵΪ��
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