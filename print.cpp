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
#include <iomanip>

using namespace std;

#include "My2048.h"

void print(const vector<int> &v)
{
	unsigned count = 0, count2 = 0;
	cout << " -----------------------------" << endl << " | " << setw(7) << " | " << setw(7) << " | " << setw(7) << " | " << setw(7) << " | " << endl;
	for (const auto a : v)
	{
		if (a != 0)
		{
			cout << " | " << setw(4) << a;
		}
		else
		{
			cout << " | " << "    ";
		}
		if (++count == 4)
		{
			cout << " | " << endl << " | " << setw(7) << " | " << setw(7) << " | " << setw(7) << " | " << setw(7) << " | " << endl;
			cout << " -----------------------------" << endl;
			if (++count2 != 4)
			{
				cout << " | " << setw(7) << " | " << setw(7) << " | " << setw(7) << " | " << setw(7) << " | " << endl;
			}
			count = 0;
		}
	}
	cout << "当前分数：" << score << '\t' << "历史最高分数：" << score_best << endl;
}