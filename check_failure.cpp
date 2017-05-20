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

vector<bool> check_failure(const vector<int> &v)
{
	vector<int> v2{ v[0],v[4],v[8],v[12],v[1],v[5],v[9],v[13],v[2], v[6], v[10], v[14] ,v[3], v[7], v[11], v[15] };	//矩阵转置
	bool a, b, c, d, a2, b2, c2, d2;
	vector<bool> ret(2);	//其中的两个元素分别表示各行是否还能滑动和各列是否还能滑动
	a = (v.begin() + 4 == adjacent_find(v.begin(), v.begin() + 4));	//检查第一行还能否滑动，不能滑动为真
	b = (v.begin() + 8 == adjacent_find(v.begin() + 4, v.begin() + 8));	//检查第二行还能否滑动，不能滑动为真
	c = (v.begin() + 12 == adjacent_find(v.begin() + 8, v.begin() + 12));	//检查第三行还能否滑动，不能滑动为真
	d = (v.end() == adjacent_find(v.begin(), v.end()));	//检查第四行还能否滑动，不能滑动为真
	a2 = (v2.begin() + 4 == adjacent_find(v2.begin(), v2.begin() + 4));	//检查第一列还能否滑动，不能滑动为真
	b2 = (v2.begin() + 8 == adjacent_find(v2.begin() + 4, v2.begin() + 8));	//检查第列行还能否滑动，不能滑动为真
	c2 = (v2.begin() + 12 == adjacent_find(v2.begin() + 8, v2.begin() + 12));	//检查第列行还能否滑动，不能滑动为真
	d2 = (v2.end() == adjacent_find(v2.begin(), v2.end()));	//检查第列行还能否滑动，不能滑动为真
	ret[0] = a&&b&&c&&d;
	ret[1] = a2&&b2&&c2&&d2;
	return ret;
}