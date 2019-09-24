#include<iostream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

bool comp (vector<int> first, vector<int> second) {
	return (first[0] < second[0]);
}

int main () {


	int N;

	cin >> N;

	int i;
	vector<int> coord;
	vector<vector<int> > coords;
	string line;

	i = 0;
	cin.ignore();
	while (i < N) {
		getline(cin, line);
		if (line.empty())
			break;
		stringstream str_st(line);
		while (getline(str_st, line, ' ')) {
			coord.push_back(atoi(line.c_str()));
		}
		coords.push_back(coord);
		coord.clear();
		i++;
	}

	sort(coords.begin(), coords.end(), comp); 

	int len, l_len, r_len;
	
	len = 0;
	while (coords.size()) {
		l_len = 0;
		r_len = 0;
		i = coords.size() - 1;
		for (int j = i - 1; j > -1; j--) {
			if (coords[j][2] > coords[i][1] and coords[j][1] <= coords[i][1] and l_len == 0) {
				len = len + (coords[i][0] - coords[j][0]);
				l_len++;
			}
		
			if (coords[j][2] >= coords[i][2] and coords[j][1] < coords[i][2] and r_len == 0) {
				len = len + (coords[i][0] - coords[j][0]);
				r_len++;
			}

			if (l_len != 0 and r_len != 0)
				break;
		}
		if (l_len == 0) {
			len = len + coords[i][0];
		}

		if (r_len == 0) {
			len = len + coords[i][0];
		}
		coords.erase(coords.end() - 1);
	}

	cout << len << endl;

	return 0;

}
