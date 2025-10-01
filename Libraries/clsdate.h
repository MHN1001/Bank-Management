#pragma once

#pragma warning(disable :  4996) 
#include <iostream>
#include "clsString.h"
#include <ctime>
#include <string>
#include <vector>
using namespace std;


class clsdate
{
private:

	short _day, _month, _year;

	//for constractor number 4

public:


	clsdate()
	{
		time_t Time = time(0);
		tm* time_now = localtime(&Time);

		_year = time_now->tm_year + 1900;
		_month = time_now->tm_mon + 1;
		_day = time_now->tm_mday;
	}
	clsdate(string ddmmyyyy)
	{
		vector <string> Vdate;
		Vdate = clsString::Split(ddmmyyyy, "/");

		_day = stoi(Vdate[0]);
		_month = stoi(Vdate[1]);
		_year = stoi(Vdate[2]);
	}
	clsdate(short day, short month, short year)
	{
		_day = day;
		_month = month;
		_year = year;
	}
	clsdate(short  numberOfDaysInYear, short year)
	{
		clsdate date = ConvertTotalDaysInYearToDate(numberOfDaysInYear, year);

		_day = date.day;
		_month = date.month;
		_year = date.year;
	}


	void SetDay(short day)
	{
		_day = day;
	}
	short getday()
	{
		return _day;
	}
	_declspec(property(get = getday, put = SetDay)) short day;

	void Setmonth(short month)
	{
		_month = month;
	}
	short getmonth()
	{
		return _month;
	}
	_declspec(property(get = getmonth, put = Setmonth)) short month;

	void Setyear(short year)
	{
		_year = year;
	}
	short getyear()
	{
		return _year;
	}
	_declspec(property(get = getyear, put = Setyear)) short year;


	clsdate ConvertTotalDaysInYearToDate(short Total_days, short year)
	{
		clsdate date;
		short dayRemeinder = Total_days;
		short numberOFDaysIInMonth = 0;

		date.year = year;
		date.month = 1;

		while (true)
		{
			numberOFDaysIInMonth = TotalDaysInMonth(year, date.month);

			if (dayRemeinder > numberOFDaysIInMonth)
			{
				dayRemeinder -= numberOFDaysIInMonth;
				date.month++;
			}

			else
			{
				date.day = dayRemeinder;
				break;
			}
		}
		return date;
	}


	static string DateToString(clsdate date)
	{
		return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date._year) + "\n";
	}
    string DateToString()
	{
		return DateToString(*this);
	}


	void print()
	{
		cout << DateToString();
	}


	static clsdate GetSystemDate()
	{
		time_t Time = time(0);
		tm* time_now = localtime(&Time);

		short day, month, year;

		day = time_now->tm_mday;
		month = time_now->tm_mon + 1;
		year = time_now->tm_year + 1900;

		return clsdate(day, month, year);
	}


	static bool IsLeapYear(short year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_year);
	}



	static short TotalDaysInMonth(short year, short month)
	{
		if (month < 1 && month > 12)
		{
			return 0;
		}

		short NumberOfDaysInMonth_arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return month == 2 ? IsLeapYear(year) ? 29 : 28 : NumberOfDaysInMonth_arr[month - 1];
	}
	short TotalDaysInMonth()
	{
		return TotalDaysInMonth(_year, _month);
	}



	static short DayOfWeekOrder(short Year, short Month, short Day)
	{
		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_year, _month, _day);
	}



	static string DayName(short DayOrder)
	{
		string DaysOfWeek_arr[7] = { "Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday" };

		return DaysOfWeek_arr[DayOrder];
	}
	string DayName()
	{
		return DayName(_day);
	}


	static string MonthNumberToMonthName(short month)
	{
		string MonthsNames_arr[13] = { "","January", "February", "March", "April", "May",
									   "June", "July", "August", "September", "October",
									   "November", "December" };

		return MonthsNames_arr[month];
	}
	string MonthNumberToMonthName()
	{
		return  MonthNumberToMonthName(_month);
	}


	static void MonthCalendar(short year, short month)
	{
		short FirstDayInMonth = DayOfWeekOrder(year, month, 1);
		short LastDayInMonth = TotalDaysInMonth(year, month);


		printf("\n\n  --------------%s--------------\n\n", MonthNumberToMonthName(month).c_str());
		printf("  sun  mon  tue  wed  thu  fri  sat\n");

		short i;
		for (i = 0; i < FirstDayInMonth; i++)
		{
			printf("     ");
		}

		for (short j = 1; j <= LastDayInMonth; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n  ----------------------------------\n");
	}
	void MonthCalendar()
	{
		MonthCalendar(_year, _month);
	}



	static void YearCalendar(short year)
	{
		printf("\n  ------------------------------------\n");
		printf("\n  ----------Calendar - %d-----------\n", year);
		printf("\n  ------------------------------------\n\n");

		for (short month_loop = 1; month_loop <= 12; month_loop++)
		{
			MonthCalendar(year, month_loop);
		}

		return;
	}
	void YearCalendar()
	{
		YearCalendar(_year);
	}


	static short TotalDaysFromTheBeginningOfYear(short Year, short Month, short Day)
	{
		short DayCounter = 0;

		for (short month_loop = 1; month_loop <= Month - 1; month_loop++)
		{
			DayCounter += TotalDaysInMonth(Year, month_loop);

		}

		DayCounter += Day;

		return DayCounter;
	}
	short TotalDaysFromTheBeginningOfYear()
	{
		TotalDaysFromTheBeginningOfYear(_year, _month, _day);
	}


	static clsdate AddDaysIntoOriginalDate(int daysToAdd, clsdate& date)
	{

		short Remainingdays = daysToAdd + TotalDaysFromTheBeginningOfYear(date.day, date.month, date.day);

		short DaysInMonth = 0;

		date.month = 1;

		while (true)
		{
			DaysInMonth = TotalDaysInMonth(date.year, date.month);


			if (Remainingdays > DaysInMonth)
			{

				Remainingdays -= DaysInMonth;
				date.month++;

				if (date.month > 12)
				{
					date.month = 1;
					date.year++;
				}

			}

			else
			{
				date.day = Remainingdays;
				break;

			}
		}
		return date;
	}
	void AddDaysIntoOriginalDate(int daysToAdd)
	{
		AddDaysIntoOriginalDate(daysToAdd, *this);
	}


	static bool IfDate1beforDate2(clsdate date1, clsdate date2)
	{
		return  (date2.year > date1.year) ? true : ((date2.year == date1.year) ? (date2.month > date1.month ? true : (date2.month == date1.month ? date2.day > date1.day : false)) : false);
	}
	bool IfDate1beforDate2(clsdate date2)
	{
		return IfDate1beforDate2(*this, date2);
	}


	static bool IfDate1lEqualToDate2(clsdate date1, clsdate date2)
	{
		return  (date2.year == date1.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
	}
	bool IfDate1lEqualToDate2(clsdate date2)
	{
		return IfDate1lEqualToDate2(*this, date2);
	}


	static bool IfDate1AfterDate2(clsdate date1, clsdate date2)
	{
		return !IfDate1beforDate2(date1, date2) && !IfDate1lEqualToDate2(date1, date2);
	}
	bool IfDate1AfterDate2(clsdate date2)
	{
		return IfDate1AfterDate2(*this, date2);
	}


	static clsdate IncraseDateByOneDay(clsdate& date)
	{
		if (IfItIsLastDayIndMonth(date))
		{
			if (IfItIsLastMonthInYear(date))
			{
				date.day = 1;
				date.month = 1;
				date.year++;
			}
			else
			{
				date.day = 1;
				date.month += 1;
			}
		}
		else
		{
			date.day += 1;
		}
		return date;
	}
	void AddOneDay()
	{
		IncraseDateByOneDay(*this);
	}


	//test
	static int DifferencesBetweenTwoDatesInDays(clsdate date1, clsdate date2, bool includeEndDay = false)
	{
		int DaysConter = 0;

		while (IfDate1beforDate2(date1, date2))
		{
			DaysConter++;
			IncraseDateByOneDay(date1);
		}

		return includeEndDay ? ++DaysConter : DaysConter;
	}
	int DifferencesBetweenTwoDatesInDays(clsdate date2, bool includeEndDay = false)
	{
		return  DifferencesBetweenTwoDatesInDays(*this, date2, includeEndDay);
	}


	static int yourAgeInDays(clsdate date1)
	{
		clsdate date2 = GetSystemDate();
		return DifferencesBetweenTwoDatesInDays(date1, date2, true);
	}
	int yourAgeInDays()
	{
		clsdate date2 = GetSystemDate();
		return DifferencesBetweenTwoDatesInDays(*this, date2, true);
	}


	static clsdate IncraseDateByXDay(clsdate& date, short DayToIncrase)
	{
		while (DayToIncrase > 0)
		{
			IncraseDateByOneDay(date);
			DayToIncrase--;
		}

		return date;
	}
	void IncraseDateByXDay(short DayToIncrase)
	{
		IncraseDateByXDay(*this, DayToIncrase);
	}


	static clsdate IncraseDateByOneWeek(clsdate& date)
	{
		return IncraseDateByXDay(date, 7);
	}
	void IncraseDateByOneWeek()
	{
		IncraseDateByOneWeek(*this);
	}


	static clsdate IncraseDateByXWeek(clsdate& date, short weeksToIncraes)
	{
		while (weeksToIncraes > 0)
		{
			IncraseDateByOneWeek(date);
			weeksToIncraes--;
		}
		return date;
	}
	void IncraseDateByXWeek(short weeksToIncraes)
	{
		IncraseDateByXWeek(*this, weeksToIncraes);
	}


	static clsdate IncraseDateByOneMonth(clsdate& date)
	{
		if (date.month == 12)
		{
			date.year++;
			date.month = 1;
		}
		else
		{
			date.month++;
		}

		//check

		short totalDaysIncurrentmonth = TotalDaysInMonth(date.year, date.month);
		if (date.day > totalDaysIncurrentmonth)
		{
			date.day = totalDaysIncurrentmonth;
		}

		return date;
	}
	void IncraseDateByOneMonth()
	{
		IncraseDateByOneMonth(*this);
	}


	static clsdate IncraseDateByXMonth(clsdate& date, short monthToIncrase)
	{
		while (monthToIncrase > 0)
		{
			IncraseDateByOneMonth(date);
			monthToIncrase--;
		}
		return date;
	}
	void  IncraseDateByXMonth(short monthToIncrase)
	{
		IncraseDateByXMonth(*this, monthToIncrase);
	}


	static clsdate IncraseDateByOneyear(clsdate& date)
	{
		date.year += 1;
		return date;
	}
	void IncraseDateByOneyear()
	{
		IncraseDateByOneyear(*this);
	}



	static clsdate IncraseDateByXYear(clsdate& date, short yearToIncrase)
	{
		date.year += yearToIncrase;
		return date;
	}
	void IncraseDateByXYear(short yearToIncrase)
	{
		IncraseDateByXYear(*this, yearToIncrase);
	}


	static clsdate IncraseDateByOneDecade(clsdate& date)
	{
		date.year += 10;
		return date;
	}
	void IncraseDateByOneDecade()
	{
		IncraseDateByOneDecade(*this);
	}


	static clsdate IncraseDateByXDecades(clsdate& date, short DecadesToIncrase)
	{
		date.year += (10 * DecadesToIncrase);
		return date;
	}
	void IncraseDateByXDecades(short DecadesToIncrase)
	{
		IncraseDateByXDecades(*this, DecadesToIncrase);
	}


	static clsdate IncraseDateByOneCentury(clsdate& date)
	{
		return IncraseDateByXDecades(date, 10);
	}
	void IncraseDateByOneCentury()
	{
		IncraseDateByOneCentury(*this);
	}


	static clsdate IncraseDateByOneMillennium(clsdate& date)
	{
		return IncraseDateByXDecades(date, 100);
	}
	void IncraseDateByOneMillennium()
	{
		IncraseDateByOneMillennium(*this);
	}


	static bool IsItEndOfWeek(clsdate date)
	{
		return  DayOfWeekOrder(date.year, date.month, date.day) == 6;
	}
	bool IsItEndOfWeek()
	{
		return IsItEndOfWeek(*this);
	}


	static bool IsItWeekend(clsdate date)
	{
		short dayOrder = DayOfWeekOrder(date.year, date.month, date.day);
		return  (dayOrder == 5 || dayOrder == 6);
	}
	bool IsItWeekend()
	{
		return IsItWeekend(*this);
	}


	static bool IsItBusinessDay(clsdate date)
	{
		return !IsItWeekend(date);
	}
	bool IsItBusinessDay()
	{
		return IsItBusinessDay(*this);
	}


	static short DaysUntilTheEndOfweekend(clsdate date)
	{
		return 6 - DayOfWeekOrder(date.year, date.month, date.day);

	}
	short DaysUntilTheEndOfweekend()
	{
		return DaysUntilTheEndOfweekend(*this);
	}


	static bool IfItIsLastDayIndMonth(clsdate date)
	{
		return (date.day == TotalDaysInMonth(date.year, date.month));
	}
	bool IfItIsLastDayIndMonth()
	{
		return IfItIsLastDayIndMonth(*this);
	}


	static bool IfItIsLastMonthInYear(clsdate date)
	{
		return (date.month == 12);
	}
	bool IfItIsLastMonthInYear()
	{
		return IfItIsLastMonthInYear(*this);
	}


	static short ActucalVacationDays(clsdate VacationStart_Date, clsdate VacationEnds_Date)
	{

		short ActucalVacationDays = 0;

		while (IfDate1beforDate2(VacationStart_Date, VacationEnds_Date))
		{
			if (IsItBusinessDay(VacationStart_Date))
			{
				ActucalVacationDays++;
			}
			VacationStart_Date = IncraseDateByOneDay(VacationStart_Date);
		}

		return ActucalVacationDays;
	}
	short ActucalVacationDays(clsdate VacationEnds_Date)
	{
		return ActucalVacationDays(*this, VacationEnds_Date);
	}


	static void outputDate(clsdate date)
	{
		cout << date.day << "/" << date.month << "/" << date.year << endl;
	}
	void outputDate()
	{
		outputDate(*this);
	}

	static void TakeDateWithOrderedNumber(clsdate date)
	{
		string DaysOfWeek_arr[7] = { "Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday" };

		short DayOrder = DayOfWeekOrder(date.year, date.month, date.day);

		cout << ":" << DaysOfWeek_arr[DayOrder] << " , "; outputDate(date);
	}
	void TakeDateWithOrderedNumber()
	{
		TakeDateWithOrderedNumber(*this);
	}


	enum enCompareResults { befor = -1, after = 1, equal = 0 };
	static enCompareResults CompareDates(clsdate date1, clsdate date2)
	{
		if (IfDate1beforDate2(date1, date2))
			return enCompareResults::befor; //-1

		else if (IfDate1AfterDate2(date1, date2))
			return enCompareResults::after;//1

		else
			return enCompareResults::equal; //0
	}
	enCompareResults CompareDates(clsdate date2)
	{
		return CompareDates(*this, date2);
	}


	//periods length (from start to end)
	static int  PeriodLength(clsdate periodStartDate, clsdate periodEndDate, bool includeEndDay = false)
	{
		return DifferencesBetweenTwoDatesInDays(periodStartDate, periodEndDate, includeEndDay);
	}


	//is date in period
	static bool IsDateInPeriod(clsdate periodStartDate, clsdate periodEndDate, clsdate date)
	{
		return (

			!(CompareDates(date, periodStartDate) == enCompareResults::befor

				||

				CompareDates(date, periodEndDate) == enCompareResults::after)
			);
	}


	//date validation
	static bool ValidateDate(clsdate date)
	{
		//my solution
		return (date.year != 0) ? ((date.month >= 1 && date.month <= 12) ? ((date.day > 0 && date.day <= TotalDaysInMonth(date.year, date.month)) ? true : false) : false) : false;

		//M.abuhadhoud soution
		//if (date.day < 1 || date.day > 31)
		//	return false;
		//if (date.month < 1 || date.month > 12)
		//	return false;

		//if (date.month == 2)
		//{
		//	if (isLeapYear(date))
		//	{
		//		if (date.day > 29)
		//			return false;
		//	}
		//	else
		//	{
		//		if (date.day > 28)
		//			return false;
		//	}
		//}

		//short DaysInMonth = TotalDaysInMonth(date.year, date.month);
		//if (date.day > DaysInMonth)
		//{
		//	return false;
		//}

		//return true;
	}


	static clsdate StringToDateStructure(string strdate)
	{
		clsdate date;

		vector <string> Vdate = clsString::Split(strdate, "/");

		date.day = stoi(Vdate[0]);
		date.month = stoi(Vdate[1]);
		date.year = stoi(Vdate[2]);

		return date;
	}


	static string  FormatDate(clsdate date, string DateFormat = "dd/mm/yyyy")
	{
		string FormatdateString = "";

		FormatdateString = clsString::ReplaceWord(DateFormat, "dd", to_string(date.day));
		FormatdateString = clsString::ReplaceWord(FormatdateString, "mm", to_string(date.month));
		FormatdateString = clsString::ReplaceWord(FormatdateString, "yyyy", to_string(date.year));

		return FormatdateString;
	}
	string  FormatDate(string DateFormat = "dd/mm/yyyy")
	{
		return FormatDate(*this, DateFormat);
	}


	static void Swap(clsdate& Date1, clsdate& Date2)
	{
		clsdate Date;

		Date = Date1;
		Date1 = Date2;
		Date2 = Date;
	};
	void Swap(clsdate& Date2)
	{
		Swap(*this, Date2);
	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* Now = localtime(&t);

		short Day, Month, year, hour, minutes, seconds;

		year  = Now->tm_year + 1900;
		Month = Now->tm_mon + 1;
		Day = Now->tm_mday;
		hour = Now->tm_hour;
		minutes = Now->tm_min;
		seconds = Now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(year)
			+ " - " + to_string(hour) + ":" + to_string(minutes) + ":" + to_string(seconds));
	}
};

