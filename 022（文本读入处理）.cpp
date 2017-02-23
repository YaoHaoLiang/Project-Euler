#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;
int main()
{
	ifstream inFile("names.txt");
	string s;
	 
	inFile >> s;

	vector<string> names;
	string name;
	bool inName = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (isupper(s[i]))
		{
			name += s[i];	
			inName = true;
		} 
		else
		{
			if (inName)
			{
				names.push_back(name);	
				name.clear();
				inName = false;
			}	
		}
	}

	sort(names.begin(), names.end());

	long long sum = 0;
	for (int i = 0; i < names.size(); i++)
	{
		string str = names[i];
		int val = 0;
		for (int j = 0; j < str.size(); j++)
		{
			val += str[j] - 'A' + 1;
		}
		sum = sum + (i+1)*val;
	}

	cout << sum << endl;
	return 0;
}