#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include "iostream"
class Date {
	public:
		int Getmonthday(int year, int month);
		Date(int year = 0 , int month = 1, int day = 1);
		void Print();
		inline bool operator<(const Date& d) {
			if (_year < d._year || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day)) return true;
			else return false;
		};
		inline bool operator==(const Date& d) {
			if (_year == d._year && _month == d._month && _day == d._day) return true;
			else return false;
		};
		inline bool operator<=(const Date& d) {
			if (*this < d || *this == d) return true;
			else return false;
		};
		inline bool operator>(const Date& d) {
			return !(*this <= d);
		};
		inline bool operator>=(const Date& d) {
			return !(*this < d);
		};
		inline bool operator!=(const Date& d) {
			return !(*this == d);
		};
		inline Date operator+(int day) {//最好只修改副本，返回副本，不改变this，eg：d2 = d1 + 10 更符合直觉
			Date ret = *this;
			ret._day += day;
			while (ret._day > Getmonthday(ret._year, ret._month)) {

				ret._day -= Getmonthday(ret._year, ret._month);
				ret._month++;
				if (ret._month == 13) {//月份检测必须紧接在月增加后面，但是一次循环只加一次month，所以不用while，用if（month=13），加在月增加后防止到达13月进入getmonthday时越界
					ret._month -= 12;
					ret._year++;
				}

			}

			return ret;//这个临时变量返回不能引用，但*this返回必须Date&
		}
	private:
		int _year, _month, _day;
};