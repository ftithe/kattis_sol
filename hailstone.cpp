#include<iostream>
#include<vector>

using namespace std;

void h(unsigned long int, vector<unsigned long int>&);

int main () {

	unsigned long int n;
	unsigned long int sum_seq;

	cin >> n;

	vector<unsigned long int> n_seq;
	
	n_seq.push_back(n);

	if (n != 1)
		h(n, n_seq);

	sum_seq = 0;
	
	for (int i = 0; i < n_seq.size(); i++) {
		sum_seq += n_seq[i];
		//cout << n_seq[i]<<endl;
	}

	cout << sum_seq << endl;

	return 0;
}

void h(unsigned long int n, vector<unsigned long int>& n_seq) {

	if (n % 2 == 0) {
		if (n == 2) {
			n_seq.push_back(n / 2);
		}
		else {
			n_seq.push_back(n / 2);
			h(n / 2, n_seq);
		}
	}
	else {
		if (n == 1) {
			n_seq.push_back(n);
		}
		else {
			n_seq.push_back((3 * n) + 1);
			h((3 * n) + 1, n_seq);
		}
	}
}


