#include <iostream>
#include <ext/hash_map>  
#include <cstring> 

using namespace __gnu_cxx;

using namespace std;

struct eqstr
{
	bool operator() (const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) == 0;
	}
};


int main()
{
	hash_map<const char*, int, hash<const char*>, eqstr> s;

	cout << s.size() << endl;

	s["why"] = 3;
	s["always"] = 4;
	s["me"] = 8;
	s["star"] = 9;
	s["steve"] = 18;

	cout << s.size() << endl;
	
	cout << "why -> " << s["why"] << endl;
	cout << "me -> " << s["me"] << endl;
	cout << "star -> " << s["star"] << endl;

	hash_map<const char*, int, hash<const char*>, eqstr>::iterator it = s.begin();
	for (; it != s.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	return 0;
}
