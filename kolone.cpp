#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void swap_chrs(string &, string, int, int);

int main () {

	int N_1, N_2;

	cin >> N_1 >> N_2;

	int T;
	string left_movers, right_movers;
	
	cin.ignore();
	getline(cin, left_movers);
	getline(cin, right_movers);

	cin >> T;

	string left_right;

	int i;

	for (i = N_1 - 1; i > -1; i--) {
		left_right.append(1, left_movers[i]);
	}

	left_right.append(right_movers);

	int j, k;

	if (N_1 > 1 and  N_2 > 1) {
		k = N_1 - 1;

		for (i = 0; i < T; i++) {
			j = 0;
			do {	
				swap_chrs(left_right, left_movers, k - i + j, k - i + 1 + j);
				j += 2;
			} while (j <= 2 * i);
			if (left_right[left_right.size() - left_movers.size()] == left_movers[left_movers.size() - 1])
				break;
		}
	}
	else if (N_1 == 1) {
		for (i = 0; i < T; i++) {
			swap_chrs(left_right, left_movers, i, i + 1);
			if (left_right[left_right.size() - 1] == left_movers[0])
				break;
		}
	}
	else {
		k = N_1;
		for (i = 0; i < T; i++) {
			swap_chrs(left_right, left_movers, k - 1 - i, k - i);
			if (left_right[0] == right_movers[0])
				break;
		}
	}

	cout << left_right << endl;

	return 0;
}

void swap_chrs(string& left_right, string left, int i, int j) {

	if (i >= 0 && i < left_right.size() - 1) { 
		char chr_l;
		char chr_r;

		chr_l = left_right[i];
		chr_r = left_right[j];

		string::iterator found_l, found_r;

		found_l = find(left.begin(), left.end(), chr_l);
		found_r = find(left.begin(), left.end(), chr_r);

		if ((found_l == left.end() and found_r != left.end()) or (found_l != left.end() and found_r == left.end())) {
			left_right[i] = chr_r;
			left_right[j] = chr_l;
		}
	}

}
