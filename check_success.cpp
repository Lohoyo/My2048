#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <array>
#include <time.h>
#include <map>
#include <set>
#include <memory>
#include <functional>
#include <random>

using namespace std;

#include "My2048.h"

//有三个重载版本

bool check_success(int &a, int &b)
{
	if (a == b)
	{
		a *= 2;
		score += a;
		b = 0;
		return a == 2048 ? true : false;
	}
	return false;
}

bool check_success(int &a, int &b, int &c)
{
	if (a == b)
	{
		a *= 2;
		score += a;
		b = c;
		c = 0;
		return a == 2048 ? true : false;
	}
	else
	{
		if (b == c)
		{
			b *= 2;
			score += b;
			c = 0;
			return b == 2048 ? true : false;
		}
	}
	return false;
}

bool check_success(int &a, int &b, int &c, int &d)
{
	if (a == b)
	{
		a *= 2;
		score += a;
		b = c;
		c = d;
		d = 0;
		if (b == c)
		{
			b *= 2;
			score += b;
			c = 0;
			return b == 2048 ? true : false;
		}
		return a == 2048 ? true : false;
	}
	else
	{
		if (b == c)
		{
			b *= 2;
			score += b;
			c = d;
			d = 0;
			return b == 2048 ? true : false;
		}
		else
		{
			if (c == d)
			{
				c *= 2;
				score += c;
				d = 0;
				return c == 2048 ? true : false;
			}
		}
	}
	return false;
}