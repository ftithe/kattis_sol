#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

int main () {

	int n_lines;
	
	cin >> n_lines;

	cin.ignore();
	
	string line;
	vector<string> str;

	while (getline(cin, line)) {
		if (line.empty())
			break;
		str.push_back(line);
	}

	int size;

	int i, j, k;

	vector<string> text;

	for (i = 0; i < str.size(); i++) {

		size = sqrt(str[i].size());

		j = 0;
		while (j < str[i].size()) {

			text.push_back(str[i].substr(j, size));
			j += size;

		}

		k = size - 1;
		while (k > -1) {

			for (j = 0; j < text.size(); j++)
				cout << text[j][k];

			k--;
		}

		text.clear();

		cout << endl;

	}

	return 0;
}
