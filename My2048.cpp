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
	//��ȡ��ʷ��߷���
	ifstream in("data");
	if (in)
	{
		in >> score_best;
	}
	//��Ϸ�ĳ�ʼ״̬
	cout << "*******************************************************������2048*******************************************************";
	cout << "******************************************************������������*******************************************************";
	cout << "**************************************************���ԣ������� ���뽡**************************************************" << endl;
	cout << "��Ϸ˵����" << endl;
	cout << "ÿ�ο���ѡ���������ң��ֱ��ӦW��S��A��D������һ������ȥ������ÿ����һ�Σ����е����ֶ����������ķ���£��ͬʱ��ϵͳ�ڿհ׵ĵط�����һ������2������4����ͬ�����ڿ�£����ײʱ����ӡ����ϵĵ�������ƴ�ճ�2048������־���ɹ���" << endl << endl;
	vector<int> v(16);	//���ڱ�����Ϸ��״̬
	uniform_int_distribution<unsigned> u(0, 15);
	default_random_engine e(time(0));
	unsigned beg1 = u(e), beg2 = u(e);
	while (beg1 == beg2)
	{
		beg1 = u(e);
	}
	v[beg1] = v[beg2] = 2;
	print(v);

	string s;	//���ڱ�������ָ��
	char ch;	//���ڱ��洦��������ָ��
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
				//�ж������Ƿ����еķ����Ѿ�����������
				if (column_failure)
				{
					continue;
				}

				a = big_fun(v[0], v[4], v[8], v[12]);	//��һ�еĻ������
				b = big_fun(v[1], v[5], v[9], v[13]);	//�ڶ��еĻ������
				c = big_fun(v[2], v[6], v[10], v[14]);	//�����еĻ������
				d = big_fun(v[3], v[7], v[11], v[15]);	//�����еĻ������
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
				//�ж������Ƿ����еķ����Ѿ�����������
				if (row_failure)
				{
					continue;
				}

				a = big_fun(v[0], v[1], v[2], v[3]);	//��һ�еĻ������
				b = big_fun(v[4], v[5], v[6], v[7]);	//�ڶ��еĻ������
				c = big_fun(v[8], v[9], v[10], v[11]);	//�����еĻ������
				d = big_fun(v[12], v[13], v[14], v[15]);//�����еĻ������
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
				continue;	//������Ч����
			}
		}
		else
		{
			continue;	//������Ч����
		}
		//�ڿհ׵ĵط�����һ������2������4
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
		//���û�пհ׵ĵط��ˣ������Ϸ�Ƿ�ʧ��
		if (!count(v.begin(), v.end(), 0))
		{
			row_failure = check_failure(v)[0];
			column_failure = check_failure(v)[1];
			if (row_failure&&column_failure)
			{
				break;
			}
		}
		//�����Ϸ�Ƿ�ɹ�
		if (a || b || c || d)
		{
			result = true;
			break;
		}

		print(v);
	}
	//����Ƿ������ʷ��¼
	string sscore = to_string(score);
	if (sscore > score_best)
	{
		ofstream out("data");
		out << sscore;
	}

	//���������Ϸ���
	print(v);
	if (result)
	{
		cout << "�󱦱���߷߹��" << endl;
	}
	else
	{
		cout << "�󱦱���boom߹��" << endl;
	}
}