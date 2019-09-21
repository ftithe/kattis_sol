#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cstdlib>

using namespace std;

int main () {

	int n;
	long long V;

	cin >> n >> V;

	int i;
	long long v;

	vector<long long> vol;

	string line;

	cin.ignore();
	while (true) {

		getline (cin, line);
		if (line.empty())
			break;
		stringstream str_st(line);
		v = 1;
		while(getline(str_st, line, ' ')) {
			v = v * atol(line.c_str());
		}
		
		vol.push_back(v);
	}

	sort(vol.begin(), vol.end());

	long d;

	d = vol[vol.size() - 1] - V;

	cout << d << endl;

	return 0;

}
