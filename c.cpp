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
		"aa.com", "ab.com",
	};
	string name = "Ab.com";
	/*
	sort(begin(myvector), end(myvector), [](string const &a, string const &b)
	{
	    return lexicographical_compare(begin(a), end(a), begin(b), end(b), [](string::value_type a, string::value_type b)
	    {
	        return tolower(a) < tolower(b);
	    });
	});
	*/
	for(auto const &s : myvector)
	{
		cout << s << endl;
	}
	transform(name.begin(), name.end(), name.begin(), (int(*)(int))std::tolower);
	auto it = find(myvector.begin(), myvector.end(), name/*, [](string const &a, string const &b){return strcasecmp(a.c_str(), b.c_str()); }*/);
	if (myvector.end()==it)
		cout << "not found" << endl;
	else
		cout << "found" << endl;
}
