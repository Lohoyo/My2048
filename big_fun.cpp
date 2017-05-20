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

bool big_fun(int &a, int &b, int &c, int &d)
{
	//每行（列）有三个空位置的情况
	if (d == 0)
	{
		if (c == 0)
		{
			if (b == 0)
			{
				//什么也不做
			}
			else
			{
				if (a == 0)
				{
					swap(a, b);
				}
				else
				{
					if (check_success(a, b))
					{
						return true;
					}
				}
			}
		}
		else
		{
			if (b == 0 && a == 0)
			{
				swap(a, c);
			}
			else
			{
				if (b != 0 && a == 0)
				{
					//这种写法与用swap，哪个好？
					a = b;
					b = c;
					c = 0;
					if (check_success(a, b))
					{
						return true;
					}
				}
				else
				{
					if (b == 0 && a != 0)
					{
						swap(b, c);
						if (check_success(a, b))
						{
							return true;
						}
					}
					else
					{
						if (b != 0 && a != 0)
						{
							if (check_success(a, b, c))
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if (count_zero(a, b, c, d) == 3)
		{
			swap(a, d);
		}
		else
		{
			//每行（列）有两个空位置的情况
			if (count_zero(a, b, c, d) == 2)
			{
				if (a != 0)
				{
					swap(b, d);
					if (check_success(a, b))
					{
						return true;
					}
				}
				else
				{
					if (b != 0)
					{
						swap(a, b);
						swap(b, d);
						if (check_success(a, b))
						{
							return true;
						}
					}
					else
					{
						if (c != 0)
						{
							swap(a, c);
							swap(b, d);
							if (check_success(a, b))
							{
								return true;
							}
						}
					}
				}
			}
			else
			{
				//每行（列）有一个空位置的情况
				if (count_zero(a, b, c, d) == 1)
				{
					if (a == 0)
					{
						swap(a, b);
						swap(b, c);
						swap(c, d);
						if (check_success(a, b, c))
						{
							return true;
						}
					}
					else
					{
						if (b == 0)
						{
							swap(b, c);
							swap(c, d);
							if (check_success(a, b, c))
							{
								return true;
							}
						}
						else
						{
							if (c == 0)
							{
								swap(c, d);
								if (check_success(a, b, c))
								{
									return true;
								}
							}
						}
					}
				}
				else
				{
					////每行（列）有没有空位置的情况
					if (check_success(a, b, c, d))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}