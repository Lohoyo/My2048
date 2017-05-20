#pragma once
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

extern unsigned score;	//当前分数
extern string score_best;	//历史最高分数

int count_zero(const int &, const int &, const int &, const int &);	//计算一行或一列有多少空位置
//判断游戏是否成功
bool check_success(int &, int &);
bool check_success(int &, int &, int &);
bool check_success(int &, int &, int &, int &);

bool big_fun(int &, int &, int &, int &);	//大函数

void print(const vector<int> &);	//输出游戏的当前状态

vector<bool> check_failure(const vector<int> &);	//判断游戏是否失败