int monthday(int year, int month, int day)
{
	int detective(int year);
	int daymonth = 0;
	switch (month)
	{
	case 1:
		if (day > 31)
			daymonth = -2;
		else
			daymonth = 0;
		break;
	case 2:
		if (detective(year))
		{
			if (day > 29)
				daymonth = -2;
			else
				daymonth = 31;
		}
		else
			if (day > 28)
				daymonth = -2;
			else
				daymonth = 31;
		break;
	case 3:
		if (day > 31)
			daymonth = -2;
		else
			daymonth = 31 + 28;
		break;
	case 4:
		if (day > 30)
			daymonth = -2;
		else
			daymonth = 31 + 28 + 31;
		break;
	case 5:
		if (day > 31)
			daymonth = -2;
		else
			daymonth = 31 + 28 + 31 + 30;
		break;
	case 6:
		if (day > 30)
			daymonth = -2;
		else
			daymonth = 31 + 28 + 31 + 30 + 31;
		break;
	case 7:
		if (day > 31)
			daymonth = -2;
		else
			daymonth = 31 + 28 + 31 + 30 + 31 + 30;
		break;
	case 8:
		if (day > 31)
			daymonth = -2;
		else
			daymonth = 31 + 28 + 31 + 30 + 31 + 30 + 31;
		break;
	case 9:
		if (day > 30)
			daymonth = -2;
		else
			daymonth = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
		break;
	case 10:
		if (day > 31)
			daymonth = -2;
		else
			daymonth = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		break;
	case 11:
		if (day > 30)
			daymonth = -2;
		else
			daymonth = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		break;
	case 12:
		if (day > 31)
			daymonth = -2;
		else
			daymonth = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		break;
	default:
		daymonth = -1;
		break;
	}
	return daymonth;
}