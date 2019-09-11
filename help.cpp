#include<iostream>
#include<vector>
#include<cstdlib>
#include<sstream>

using namespace std;

int main () {

	int N;
	int sum;

	cin >> N;

	cin.ignore();

	string line;

	while(getline(cin, line)) {
		if (line.empty())
			break;
		if (line[0] == 'P') {
			cout << "skipped" << endl;
		}
		else {

			stringstream str_st(line);
			
			sum = 0;
			while (getline(str_st, line, '+')) {
				sum = sum + atoi(line.c_str());
			}
			cout << sum << endl;
		}
	}

	return 0;

}
