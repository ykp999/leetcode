#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

void reverse_words(string &s)
{
	if (s.size() <= 1)
		return ;

	string whitespaces(" \t\f\v\n\r");

	auto lt_left = s.begin();
	auto lt_right = s.begin();

	while (true)
	{
		lt_left = find_if_not(lt_right, s.end(), ::isspace);
		lt_right = find_if(lt_left, s.end(), ::isspace);

		reverse(lt_left, lt_right);

		if (lt_right == s.end())
			break;
	}

	reverse(s.begin(), s.end());
}

void trim_head(string& s)
{
	auto lt_first_not_space = find_if_not(s.begin(), s.end(), ::isspace);
		
	if (lt_first_not_space != s.end())
	{
		s.erase(copy(lt_first_not_space, s.end(), s.begin()), s.end());
	}
	else
	{
		s.clear();
	}
}

void trim_middle(string& s)
{
	if (s.size() <= 1)
		return ;
	
	auto lt_left = s.begin();
	auto lt_right = lt_left + 1;

	for (; lt_right != s.end(); lt_right++)
	{
		if (!(::isspace(*lt_left) && ::isspace(*lt_right)))
		{
			lt_left++;
			*lt_left = *lt_right;
		}
	}

	s.erase(lt_left+1, s.end());
}

void trim_tail(string& s)
{
	string whitespaces(" \t\f\v\n\r");
	
	auto found = s.find_last_not_of(whitespaces);
		
	if (found != std::string::npos)
		s.erase(found+1);
	else
		s.clear();
}


int main(int n, char* args[])
{
	// cout << "hello, world" << endl;

	string s1 = "    a   b  ";
	cout << s1 << endl;
	trim_head(s1);
	cout << s1 << endl;
	trim_tail(s1);
	cout << s1 << endl;
	trim_middle(s1);
	cout << s1 << endl;
	reverse_words(s1);
	cout << s1 << endl;

	return 0;
}


