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

extern unsigned score;	//��ǰ����
extern string score_best;	//��ʷ��߷���

int count_zero(const int &, const int &, const int &, const int &);	//����һ�л�һ���ж��ٿ�λ��
//�ж���Ϸ�Ƿ�ɹ�
bool check_success(int &, int &);
bool check_success(int &, int &, int &);
bool check_success(int &, int &, int &, int &);

bool big_fun(int &, int &, int &, int &);	//����

void print(const vector<int> &);	//�����Ϸ�ĵ�ǰ״̬

vector<bool> check_failure(const vector<int> &);	//�ж���Ϸ�Ƿ�ʧ��