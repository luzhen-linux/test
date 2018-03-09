#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <algorithm>
 
using namespace std;

int main()
{
	list<string> myvector
	{
		"aa.com", "Ab.com",
	};
	string name = "ab.com";
	/*
	sort(begin(myvector), end(myvector), [](string const &a, string const &b)
	{
	    return lexicographical_compare(begin(a), end(a), begin(b), end(b), [](string::value_type a, string::value_type b)
	    {
	        return tolower(a) < tolower(b);
	    });
	});
	*/
	for(string &s : myvector)
	{
		transform(s.begin(), s.end(), s.begin(), [](char c){ return tolower(c); });
		cout << s << endl;
	}
	auto it = find(myvector.begin(), myvector.end(), name/*, [](string const &a, string const &b){return strcasecmp(a.c_str(), b.c_str()); }*/);
	if (myvector.end()==it)
		cout << "not found" << endl;
	else
		cout << "found" << endl;
}
