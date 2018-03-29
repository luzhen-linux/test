#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <algorithm>
#include <strings.h>
 
using namespace std;

int main()
{
	list<string> myvector
	{
		"aa.com", "Ab.com",
	};
	string name = "ac.com";
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
		cout << s << endl;
	}
	auto it = find_if(myvector.begin(), myvector.end(), [name](string &a){cout << "compare " << a << " and " << name << endl;
			return !::strcasecmp(a.c_str(), name.c_str()); });
	if (myvector.end()==it)
		cout << "not found" << endl;
	else
		cout << "found" << endl;
	vector<string> str {"a", "b"};
	for (string &s: str) {
		cout << s << endl;
		str.push_back("c");
	}
	cout << "next:" << endl;
	for (string &s: str) {
		cout << s << endl;
	}
}
