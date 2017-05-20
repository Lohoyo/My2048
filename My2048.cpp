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

int main()
{
	//读取历史最高分数
	ifstream in("data");
	if (in)
	{
		in >> score_best;
	}
	//游戏的初始状态
	cout << "*******************************************************胡粤版2048*******************************************************";
	cout << "******************************************************开发：刘胡粤*******************************************************";
	cout << "**************************************************测试：刘胡粤 翁桦健**************************************************" << endl;
	cout << "游戏说明：" << endl;
	cout << "每次可以选择上下左右（分别对应W、S、A和D）其中一个方向去滑动，每滑动一次，所有的数字都会往滑动的方向靠拢，同时，系统在空白的地方出现一个数字2或数字4，相同数字在靠拢、相撞时会相加。不断的叠加最终拼凑出2048这个数字就算成功。" << endl << endl;
	vector<int> v(16);	//用于保存游戏的状态
	uniform_int_distribution<unsigned> u(0, 15);
	default_random_engine e(time(0));
	unsigned beg1 = u(e), beg2 = u(e);
	while (beg1 == beg2)
	{
		beg1 = u(e);
	}
	v[beg1] = v[beg2] = 2;
	print(v);

	string s;	//用于保存输入指令
	char ch;	//用于保存处理后的输入指令
	bool a, b, c, d, result = false, row_failure = false, column_failure = false;
	while (cin >> s)
	{
		if (s.size() == 1)
		{
			ch = s[0];
			switch (ch)
			{
			case 'W':
			case 'w':
				//判断数字是否在列的方向已经滑动不了了
				if (column_failure)
				{
					continue;
				}

				a = big_fun(v[0], v[4], v[8], v[12]);	//第一列的滑动结果
				b = big_fun(v[1], v[5], v[9], v[13]);	//第二列的滑动结果
				c = big_fun(v[2], v[6], v[10], v[14]);	//第三列的滑动结果
				d = big_fun(v[3], v[7], v[11], v[15]);	//第四列的滑动结果
				row_failure = false;
				break;
			case 'S':
			case 's':
				if (column_failure)
				{
					continue;
				}
				a = big_fun(v[12], v[8], v[4], v[0]);
				b = big_fun(v[13], v[9], v[5], v[1]);
				c = big_fun(v[14], v[10], v[6], v[2]);
				d = big_fun(v[15], v[11], v[7], v[3]);
				row_failure = false;
				break;
			case 'A':
			case 'a':
				//判断数字是否在行的方向已经滑动不了了
				if (row_failure)
				{
					continue;
				}

				a = big_fun(v[0], v[1], v[2], v[3]);	//第一行的滑动结果
				b = big_fun(v[4], v[5], v[6], v[7]);	//第二行的滑动结果
				c = big_fun(v[8], v[9], v[10], v[11]);	//第三行的滑动结果
				d = big_fun(v[12], v[13], v[14], v[15]);//第四行的滑动结果
				column_failure = false;
				break;
			case 'D':
			case 'd':
				if (row_failure)
				{
					continue;
				}
				a = big_fun(v[3], v[2], v[1], v[0]);
				b = big_fun(v[8], v[7], v[5], v[4]);
				c = big_fun(v[11], v[10], v[9], v[8]);
				d = big_fun(v[15], v[14], v[13], v[12]);
				column_failure = false;
				break;
			default:
				continue;	//无视无效输入
			}
		}
		else
		{
			continue;	//无视无效输入
		}
		//在空白的地方生成一个数字2或数字4
		unsigned new_num;
		uniform_int_distribution<unsigned> u2(0, 9);
		while (true)
		{
			new_num = u(e);
			if (v[new_num] == 0)
			{
				if (u2(e) == 0)
				{
					v[new_num] = 4;
				}
				else
				{
					v[new_num] = 2;
				}
				break;
			}
		}
		//如果没有空白的地方了，检查游戏是否失败
		if (!count(v.begin(), v.end(), 0))
		{
			row_failure = check_failure(v)[0];
			column_failure = check_failure(v)[1];
			if (row_failure&&column_failure)
			{
				break;
			}
		}
		//检查游戏是否成功
		if (a || b || c || d)
		{
			result = true;
			break;
		}

		print(v);
	}
	//检查是否打破历史纪录
	string sscore = to_string(score);
	if (sscore > score_best)
	{
		ofstream out("data");
		out << sscore;
	}

	//输出最终游戏结果
	print(v);
	if (result)
	{
		cout << "大宝宝好叻吖！" << endl;
	}
	else
	{
		cout << "大宝宝好boom吖！" << endl;
	}
}