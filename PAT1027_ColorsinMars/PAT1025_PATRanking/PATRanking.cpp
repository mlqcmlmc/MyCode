#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Testee
{
	string reg_num;
	int score;
	int final_rank = 0;
	int location_number;
	int local_rank = 0;
};
bool cmp(Testee t1, Testee t2)
{
	if (t1.score == t2.score)
	{
		return t1.reg_num < t2.reg_num;
	}
	else
	{
		return t1.score > t2.score;
	}
}
//void SortTestee(vector<Testee> &testees)
//{
//	sort(testees.begin(), testees.end(), cmp);
//	for (int i = 0; i < testees.size()-1; i++)
//	{
//		if (testees[i].local_rank == 0)
//		{
//			testees[i].local_rank = i + 1;
//		}
//		if (testees[i + 1].score == testees[i].score)
//		{
//			testees[i + 1].local_rank = testees[i].local_rank;
//		}
//		else
//		{
//			testees[i + 1].local_rank = i + 2;
//		}
//	}
//}
void SortTestee(vector<Testee> &testees)
{
	sort(testees.begin(), testees.end(), cmp);
	for (int i = 0; i<testees.size(); i++)
	{
		if (i != 0 && testees[i].score == testees[i - 1].score)
			testees[i].local_rank = testees[i - 1].local_rank;
		else
			testees[i].local_rank = i + 1;
	}
}
void SortRankLists(vector<Testee> &Lists)
{
	sort(Lists.begin(), Lists.end(), cmp);
	for (int i = 0; i<Lists.size(); i++)
	{
		if (i != 0 && Lists[i].score == Lists[i - 1].score)
			Lists[i].final_rank = Lists[i - 1].final_rank;
		else
			Lists[i].final_rank = i + 1;
	}
}
//void SortRankLists(vector<Testee> &Lists)
//{
//	sort(Lists.begin(), Lists.end(), cmp);
//	for (int i = 0; i < Lists.size() - 1; i++)
//	{
//		if (Lists[i].final_rank == 0)
//		{
//			Lists[i].final_rank = i + 1;
//		}
//		if (Lists[i + 1].score == Lists[i].score)
//		{
//			Lists[i + 1].final_rank = Lists[i].final_rank;
//		}
//		else
//		{
//			Lists[i + 1].final_rank = i + 2;
//		}
//	}
//}
int main()
{
	//vector<vector<Testee>> ranklists;
	vector<Testee> testees, ranklists;
	Testee temp_testee;
	int N, K;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> temp_testee.reg_num >> temp_testee.score;
			temp_testee.location_number = i + 1;
			testees.push_back(temp_testee);
		}
		SortTestee(testees);
		ranklists.insert(ranklists.begin(),testees.begin(),testees.end());
		testees.clear();
	}
	SortRankLists(ranklists);
	cout << ranklists.size() << endl;
	for (int i = 0; i < ranklists.size(); ++i)
	{
		cout << ranklists[i].reg_num << ' ' << ranklists[i].final_rank << ' ';
		cout << ranklists[i].location_number << ' ' << ranklists[i].local_rank << endl;
	}
	return 0;
}