#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string AddNum(string str,string strrev)
{
	string strsum;
	int sum = 0, carry = 0;
	for (int i = str.size() - 1; i >= 0; --i)
	{
		sum = (str[i] - '0') + (strrev[i] - '0') + carry;
		strsum.insert(strsum.begin(), '0' + sum % 10);
		carry = sum / 10;
	}
	if (carry != 0)
	{
		strsum.insert(strsum.begin(), '0' + carry);
	}
	return strsum;
}
int main()
{
	string strN, strNrev;
	int K, count = 0;
	cin >> strN >> K;
	for (int i = 0; i < K; ++i)
	{
		strNrev = strN;
		reverse(strNrev.begin(), strNrev.end());
		if (strN == strNrev)
		{
			break;
		}
		strN = AddNum(strN, strNrev);
		count++;
	}
	cout << strN << endl;
	cout << count << endl;
	return 0;
}