#include "Date.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Date& Date::operator++() {

	++day;

	if (day > 30) {

		day = 1;
		++mounth;

		if (mounth > 12) {

			mounth = 1;
			++year;

		}

	}

	return *this;
}

Date Date::operator++(int) {

	Date tempDate{ *this };
	++day;

	if (day > 30) {

		day = 1;
		++mounth;

		if (mounth > 12) {

			mounth = 1;
			++year;

		}

	}
	return tempDate;
}

Date& Date::operator+=(const int dayP) {

	day += dayP;

	if (day > 30) {

		while (day > 30) {

			day -= 30;
			++mounth;

		}

		if (mounth > 12) {

			while (mounth > 12) {

				mounth -= 12;
				++year;

			}

		}

	}

	return *this;
}

Date& Date::operator--() {

	--day;

	if (day < 1) {

		day = 30;
		--mounth;

		if (mounth < 1) {

			mounth = 12;
			--year;

		}

	}

	return *this;
}

Date Date::operator--(int) {

	Date tempDate{ *this };

	--day;

	if (day < 1) {

		day = 30;
		--mounth;

		if (mounth < 1) {

			mounth = 12;
			--year;

		}

	}

	return tempDate;
}

Date& Date::operator-=(const int dayP) {

	day -= dayP;

	if (day < 1) {

		while (day < 1) {

			day += 30;
			--mounth;

		}

		if (mounth < 1) {

			while (mounth < 1) {

				mounth += 12;
				--year;

			}

		}

    }

	return *this;
}

void Date::operator()(Date& date, int const dayP, int const mounthP, int const yearP) {

	date.day = dayP;
	date.mounth = mounthP;
	date.year = yearP;

}

#pragma region Special_Abilities
void ClearScrean() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tDate" << endl;
}
void Enter() {
	string enter;
	cin.ignore();
	do {
		cout << "Press enter to continue: "; getline(cin, enter);
	} while (!enter.empty());
}
#pragma endregion

bool PrintDate(vector<Date>& dates) {
	
	int size = dates.size();

	if (size != 0) {

		for (int i = 0; i != size; i++) {

			cout << i + 1 << "-th date: " << dates[i] << endl;
			
		}

		return 1;

	}
	else cout << "List dates empty!";

	return 0;
}

int ChoiceDate(vector<Date>& dates) {

	int choiceDate{ 1 }, size = dates.size();

	do {

		if (choiceDate >= 1 && choiceDate <= size)cout << "Enter your choice: ";
		else cout << "There is no such choice!\nEnter your choice again: ";

		cin >> choiceDate;

		ClearScrean();
		PrintDate(dates);

	} while (choiceDate < 1 || choiceDate > size);

	return --choiceDate;

}

Date AddDate() {

	Date tempDate;

	cin >> tempDate;

	if (tempDate.day < 0)tempDate.day *= -1;
	else if (tempDate.day == 0)tempDate.day = 1;

	if (tempDate.mounth < 0)tempDate.mounth *= -1;
	else if (tempDate.mounth == 0)tempDate.mounth = 1;

	if (tempDate.year < 0)tempDate.year *= -1;
	else if (tempDate.year == 0)tempDate.year = 1;

	ClearScrean();
	cout << "Date successfully add!" << endl;

	return tempDate;
}

void DeleteDate(vector<Date>& dates) {

	if (PrintDate(dates) == true) {

		int index = ChoiceDate(dates);
		dates.erase(dates.begin() + index);

		ClearScrean();
		cout << "Date successfully delete!" << endl;

	}

}

void AddDay(vector<Date>& dates) {

	if (PrintDate(dates) == true) {

		int index{ ChoiceDate(dates) }, choice{ 0 };

		do {

			ClearScrean();
			cout << "Add\n[1] - Add 1 day(increment)\n[2] - Add your number of days" << endl;

			if (choice >= 1 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while(choice < 1 || choice > 2);

		ClearScrean();

		if (choice == 1) ++dates[index];
		else if (choice == 2) {

			int day{ 0 };
			cout << "Enter amount day for add: "; cin >> day;
			if (day < 0) day *= -1;

			dates[index] += day;
		
		}

	}

}

void DeleteDay(vector<Date>& dates) {

	if (PrintDate(dates) == true) {

		int index{ ChoiceDate(dates) }, choice{ 0 };

		do {

			ClearScrean();
			cout << "Delete\n[1] - Delete 1 day(increment)\n[2] - Delete your number of days" << endl;

			if (choice >= 1 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 1 || choice > 2);

		ClearScrean();

		if (choice == 1) --dates[index];
		else if (choice == 2) {

			int day{ 0 };
			cout << "Enter amount day for delete: "; cin >> day;
			if (day < 0) day *= -1;

			dates[index] -= day;

		}

	}

}

void IsEqualityDates(vector<Date>& dates) {

	if (PrintDate(dates) == true) {

		int index[2];

		for (int i = 0; i != 2; i++) {

			cout << "You are entering the " << i + 1 <<" date for comparison (this text will disappear after any action)" << endl;

			index[i] = ChoiceDate(dates);

		}

		ClearScrean();

		if (dates[index[0]] == dates[index[1]])cout << "These dates is equal" << endl;
		else if (dates[index[0]] != dates[index[1]])cout << "These dates are not equal" << endl;

	}

}

void AssigningValuesDate(vector<Date>& dates) {

	if (PrintDate(dates) == true) {

		int index[2];

		for (int i = 0; i != 2; i++) {

			if (i == 0)cout << "You are now entering the date that will be changed!" << endl;
			else if (i == 1)cout << "You are now entering the date for which it will be changed!" << endl;

			index[i] = ChoiceDate(dates);

		}
		ClearScrean();

		dates[index[0]] = dates[index[1]];
		cout << "Values assigned successfully!" << endl;

	}
}

void AssigningValues(vector<Date>& dates) {

	if (PrintDate(dates) == true) {

		int index = ChoiceDate(dates), day, mounth, year;
		ClearScrean();

		cout << "Enter day: "; cin >> day;
		if (day < 0)day *= -1;
		else if (day == 0)day = 1;

		cout << "Enter mounth: "; cin >> mounth;
		if (mounth < 0)mounth *= -1;
		else if (mounth == 0)mounth = 1;

		cout << "Enter year: "; cin >> year;
		if (year < 0)year *= -1;
		else if (year == 0)year = 1;

		dates[index](dates[index],day,mounth,year);
		cout << "Values assigned successfully!" << endl;

	}
}

int main() {

	vector<Date> dates;
	int choice{ 0 };

	do {

		do {

			ClearScrean();
			cout << "Action\n[1] - Print all date\n[2] - Add date\n[3] - Delete date\n"
				 << "[4] - Add day\n[5] - Decrease day\n[6] - Equality of dates\n"
				 << "[7] - Assigning a value to another date\n" 
				 << "[8] - Assigning new values\n[0] - Exit" << endl;

			if (choice >= 0 && choice <= 8)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 8);

		ClearScrean();

		switch (choice) {

		case 1: PrintDate(dates); break;
		case 2: dates.push_back(AddDate()); break;
		case 3: DeleteDate(dates); break;
		case 4:AddDay(dates); break;
		case 5:DeleteDay(dates); break;
		case 6:IsEqualityDates(dates); break;
		case 7:AssigningValuesDate(dates); break;
		case 8:AssigningValues(dates); break;
		}

		if (choice != 0)Enter();

	} while (choice != 0);

}