#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string clear_str(string a) {
	int s = a.size();
	for (int i = 0; i < s; i++)
	{
		if ((!isdigit(a[i])) && !(isalpha(a[i])))
			a[i] = ' ';
	}
	return a;
}

void sort(map<string, int>& M, ofstream &f, double sum)
{
	multimap<int, string> m;
	for (auto& it : M) {
		m.insert({ it.second, it.first });
	}	
	for (multimap<int, string>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it) {
		f << it->second << "; " << it->first << "; " << (double)(sum * it->first) << endl;
	}
}

int main(int argc, char**argv) {
	istringstream ss;
	string arr;
	string l;
	double sum = 0;
	map <string, int> mp;
	ifstream f;
	ofstream g;
	f.open(argv[1]);
	if (f.is_open()) {
		getline(f, arr);
		while (f) {
			arr = clear_str(arr);
			ss.clear();
			ss.str(arr);
			while (ss) {
				getline(ss, l, ' ');
				if (l == "")
					continue;
				else {
					mp[l]++;
					sum++;
				}				
			}
          getline(f, arr);
		}
	}
   	f.close();
	sum /= 100;
	g.open(argv[2]);
	sort(mp, g, sum);
	g.close();
	return 0;
}