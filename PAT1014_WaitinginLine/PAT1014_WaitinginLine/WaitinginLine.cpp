#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include"stdio.h"
using namespace std;

int N, M, K, Q;


struct Window
{
	int mark = 0;
	int window_first = 0;
	int window_last = 0;
	queue<int> window_time;
};

bool cmp(Window a, Window b)
{
	if (a.window_first == b.window_first)
	{
		return a.mark < b.mark;
	}
	else
	{
		return a.window_first < b.window_first;
	}
}
int main()
{

	cin >> N >> M >> K >> Q;
	vector<int> left_time, serve_time;
	vector<Window> windows;
	windows.resize(N);
	for (int i = 0; i < N; ++i)
	{
		windows[i].mark = i;
	}
	//vector<int> window_first, window_last;
	//window_first.resize(N);
	//window_last.resize(N);
	int temp_time;
	for (int i = 0; i < K; ++i)
	{
		cin >> temp_time;
		if (windows[i%N].window_time.size() < M-1 )
		{
			windows[i%N].window_time.push(temp_time);
			windows[i%N].window_last += temp_time;			//计算每个窗口的最后一个人的离开时间

			left_time.push_back(windows[i%N].window_last);	//保存每个顾客的离开时间
		}
		else if (windows[i%N].window_time.size() == M - 1)
		{
			windows[i%N].window_time.push(temp_time);
			windows[i%N].window_last += temp_time;			//计算每个窗口的最后一个人的离开时间

			auto data = windows[i%N].window_time.front();
			windows[i%N].window_first += data;				//计算每个窗口的第一个人的离开时间

			left_time.push_back(windows[i%N].window_last);	//保存每个顾客的离开时间
		}
		else
		{
			sort(windows.begin(), windows.end(), cmp);		//排序，每个窗口第一个人将要离开的最小时间

			windows[0].window_time.push(temp_time);
			windows[0].window_last += temp_time;			//计算每个窗口的最后一个人的离开时间

			windows[0].window_time.pop();
			auto data = windows[0].window_time.front();
			windows[0].window_first += data;				//计算每个窗口的第一个人的离开时间
								

			left_time.push_back(windows[0].window_last);	//保存每个顾客的离开时间
		}
		serve_time.push_back(left_time[i] - temp_time);
	}
	int out_customer;
	int shi;
	int fen;
	for (int i = 0; i < Q; ++i)
	{
		cin >> out_customer;
		// 本题容易出错的地方：是在17:00及以后开始服务的客户输出"Sorry"，而不是17 : 00之前结束服务的输出"Sorry"；
		//如客户cId是16:59开始服务，服务时间为2，则输出的应该是17:01，而不是"Sorry"。
		if (serve_time[out_customer - 1] < 540)
		{
			shi = 8 + left_time[out_customer-1] / 60;
			fen = left_time[out_customer-1] % 60;
			printf("%02d:%02d", shi, fen);
			printf("\n");
		}
		else
		{
			cout << "Sorry" << endl;
		}
	}

	return 0;
}