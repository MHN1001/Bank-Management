#pragma once
#include "clsdate.h";

class clsPeriod
{
public:

	clsdate startDate;
	clsdate endDate;

	//contractor
	clsPeriod(clsdate StartDaate, clsdate EndDate)
	{
		this->startDate = StartDaate;
		this->endDate = EndDate;
	}


	static bool IfOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		if (
			clsdate::CompareDates(Period2.endDate, Period1.startDate) == clsdate::enCompareResults::befor
			||
			clsdate::CompareDates(Period2.startDate, Period1.endDate) == clsdate::enCompareResults::after
			)
			return false;
		else
			return true;
	}
	bool IfOverlapPeriods(clsPeriod Period2)
	{
		return IfOverlapPeriods(*this, Period2);
	}

     static int PeriodLength(clsPeriod period, bool includeEndDay = false)
	{
		return clsdate::DifferencesBetweenTwoDatesInDays(period.startDate, period.endDate, includeEndDay);
	}
	 int PeriodLength(bool includeEndDay = false)
	 {
		 return PeriodLength(*this);
	 }


	 static bool IsDateInPeriod(clsPeriod period, clsdate date)
	 {
		 return (

			 !(clsdate::CompareDates(date, period.startDate) == clsdate::enCompareResults::befor

				 ||

				 clsdate::CompareDates(date, period.endDate) == clsdate::enCompareResults::after)
			 );
	 }
	 bool IsDateInPeriod(clsdate date)
	 {
		 return IsDateInPeriod(*this, date);
	 }

	void Print()
	{
		cout << "Period Start: ";
		startDate.print();


		cout << "Period End: ";
		endDate.print();
	}

};

