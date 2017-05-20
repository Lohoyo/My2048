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

int count_zero(const int &a, const int &b, const int &c, const int &d)
{
	int count = 0;
	if (a == 0)
	{
		++count;
	}
	if (b == 0)
	{
		++count;
	}
	if (c == 0)
	{
		++count;
	}
	if (d == 0)
	{
		++count;
	}
	return count;
}