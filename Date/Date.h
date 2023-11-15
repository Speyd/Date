#include <iostream>
using namespace std;

class Date {
private:
	int day;
	int mounth;
	int year;
public:

	Date(const int dayP, const int mounthP, const int yearP)
		: day{ dayP }, mounth{ mounthP }, year{ yearP } {}
	Date() :Date{1, 1, 1}{}

	Date(const Date& date) :Date{date.day, date.mounth, date.year} {};

	~Date() { this->day = 0; this->mounth = 0; this->year = 0; }

	friend istream& operator>>(istream& input, Date& date) {

		cout << "Enter day: "; input >> date.day;

		cout << "Enter mounth: "; input >> date.mounth;

		cout << "Enter year: "; input >> date.year;

		return input;
	}

	friend ostream& operator<<(ostream& out, Date& date) {
		
		out << date.day << '.' << date.mounth << '.' << date.year;

		return out;

	}

	friend bool operator==(Date& date1, Date& date2) {
		return date1.day == date2.day && date1.mounth == date2.mounth && date1.year == date2.year;
	}

	friend bool operator!=(Date& date1, Date& date2) {
		return date1.day != date2.day || date1.mounth != date2.mounth || date1.year != date2.year;
	}

	void operator()(Date& date, const int dayP, const int mounthP, const int yearP);

	//++date
	Date& operator++();

	//date++
	Date operator++(int);

	//date +=
	Date& operator+=(const int day);

	//--date
	Date& operator--();

	//date--
	Date operator--(int);

	//date -=
	Date& operator-=(const int day);

	Date& operator=(const Date& copyDate) {

		day = copyDate.day;
		mounth = copyDate.mounth;
		year = copyDate.year;

		return *this;
	}


	friend Date AddDate();
};