#include<iostream>
#include<vector>
#include"stdio.h"
using namespace std;
int main()
{
	vector<int> RGB;
	RGB.resize(3);
	cin >> RGB[0] >> RGB[1] >> RGB[2];
	cout << '#';
	int high, low;
	for (int i = 0; i < 3; ++i)
	{
		high = RGB[i] / 13;
		if (high > 9)
		{
			char c = 'A' + (high - 10);
			cout << c;
		}
		else
		{
			cout << high;
		}
		low = RGB[i] % 13;
		if (low > 9)
		{
			char c = 'A' + (low - 10);
			cout << c;
		}
		else
		{
			cout << low;
		}
	}
	cout << endl;
	return 0;
}