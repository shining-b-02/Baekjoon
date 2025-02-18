#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
vector<int> v;
deque<pair<int, int>> dq;
int N, L;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int num;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!dq.empty())
		{
			if (dq.front().second < i - L + 1) 
				dq.pop_front();
		}

		while (!dq.empty() && dq.back().first > v[i - 1]) 
			dq.pop_back();
		dq.push_back(make_pair(v[i - 1], i)); 
		cout << dq.front().first << " "; 
	}
}
