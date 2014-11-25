#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

void three_sum(vector<int>& num, vector<vector<int> >& rets) {
	for (auto i = num.begin(); i != num.end(); ) {
		for (auto j = i+1; j != num.end(); ) {
			
			int value = 0 - *i - *j;

			if (value >= *j && binary_search(j+1, num.end(), value))
			{
				rets.push_back(vector<int> {*i, *j, value} );
			}

			j = find_if(j+1, num.end(), [&j](int v)->bool { return v != *j; });
		}

		i = find_if(i+1, num.end(), [&i](int v)->bool { return v != *i; });
	}
}



vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > rets;
	if (num.size() < 3) {
		return rets;
	}

	sort(num.begin(), num.end());

	three_sum(num, rets);

	return rets;
}

int main(int n, char* args[])
{
	vector<int> nums = {-1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1};

	vector<vector<int> > rets = threeSum(nums);

	for (auto i = rets.begin(); i != rets.end(); i++)
	{
		for(auto j = i->begin(); j != i->end(); j++)
		{
			cout << *j << "\t";
		}
		cout << endl;
	}
	
	return 0;
}

