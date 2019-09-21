#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct list_name {

	int n_names;
	vector<string> names;

	list_name () : n_names (0) {
	}

	void get_n_names (int n) {
		n_names = n;
	}

	void get_names (string name) {
		names.push_back(name);
	}

};

bool comp (string i, string j) {
	i = i.substr(0, 2);
	j = j.substr(0, 2);

	return (i < j);

}

int main () {

	int i, j;
	string line;
	list_name name_x;
	vector<list_name> names;

	while (true) {
		getline(cin, line);
		j = atoi(line.c_str());
		if (j == 0)
			break;
		i = 0;
		name_x.get_n_names(j);
		while (i < j) {
			getline(cin, line);
			name_x.get_names(line);
			i++;
		}
		names.push_back(name_x);
		name_x.names.clear();
	}

	for (i = 0; i < names.size(); i++)
		stable_sort(names[i].names.begin(), names[i].names.end(), comp);

	for (i = 0; i < names.size(); i++) {
		for (j = 0; j < names[i].names.size(); j++)
			cout << names[i].names[j] << endl;
		if (i != names.size() - 1)
			cout << endl;
	}	

	return 0;

}
