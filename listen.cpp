#include<iostream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include<cmath>

using namespace std;

bool comp(vector<long double> first, vector<long double> second) {
	return (first[first.size() - 1] < second[second.size() - 1]);
}

int main () {

	string line;
	vector<vector<long double> > coords;
	vector<long double> coord;

	while (true) {
		getline(cin, line);
		if (line.empty())
			break;
		stringstream str_st(line);
		while (getline(str_st, line, ' ')) {
			coord.push_back(atoi(line.c_str()));
		}
		coords.push_back(coord);
		coord.clear();
	}

	long double r, s;
	
	for (int i = 0; i < coords.size(); i++) {
		r = sqrt(pow(coords[i][0] - coords[0][0], 2) + pow(coords[i][1] - coords[0][1], 2));
		coords[i].push_back(r);
		s = coords[i][3] - coords[i][2];
		coords[i].push_back(s);
	}

	sort(coords.begin(), coords.end(), comp);

	s = coords[3][4];

	if (s < 0) {
		cout << 0 << endl;
	}
	else { 
		cout << static_cast<int>(s) << endl;
	}

	return 0;

}
