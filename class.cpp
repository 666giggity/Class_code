#define _CRT_SECURE_NO_WARNINGS 1
#include "class.h"
Date::Date(int year , int month , int day ) {
	if (year >= 0 && month > 0 && month < 13 && day <= Getmonthday(year,month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
};
int Date::Getmonthday(int year,int month) {
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) && month == 2) return 29;
	else return a[month];
};
void Date::Print() {
	cout << _year << " "<< _month << " "<< _day;
}

int main()
{

	cout<<"请按照 年 月 日 输入日期"<<endl;
	int year, month, day , time;
	cin >> year >> month >> day;
	Date d(year, month, day);
	cout << "请输入间隔时间" << endl;
	cin >> time;
	Date d1;
	d1 = d + time;
	d1.Print();
	return 0;
}