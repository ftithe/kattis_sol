#include<iostream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include<cmath>

using namespace std;

int redundency_n (vector<vector<int> >, int, int);
void root_length (vector<vector<int> >, int, int, vector<long double>&);
long double get_time(int, int, int);


bool compare_y (vector<int> i, vector<int> j) {

	return (i[1] < j[1]);	

}

bool compare_length (vector<long double> i, vector<long double> j) {

	return (i[i.size() - 1] > j[j.size() - 1]);

}

int main () {

	int n, v_y, a_max;

	cin >> n >> v_y >> a_max;

	vector<vector<int> > targets_positions;
	vector<int> target_position;

	int x, y, target;

	string line;

	target = 1;
	cin.ignore();
	while (getline(cin, line)) {
		if (line.empty())
			break;
		stringstream str_st(line);
		while (getline(str_st, line, ' ')) {
			x = atoi(line.c_str());
			target_position.push_back(x);
			break;
		}
		getline(str_st, line);
		y = atoi(line.c_str());
		target_position.push_back(y);
		target_position.push_back(target);
		targets_positions.push_back(target_position);
		target_position.clear();
		target++;
	}


	sort(targets_positions.begin(), targets_positions.end(), compare_y);

	for (int i = 0; i < targets_positions.size(); i++) {
		for (int j = 0; j < targets_positions[i].size(); j++)
			cout << targets_positions[i][j] << ' ';
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < targets_positions.size(); i++) {
		for (int j = i + 1; j < targets_positions.size(); j++) {
			if (targets_positions[i][1] == targets_positions[j][1]) {
				if (targets_positions[i][0] == targets_positions[j][0]) {
					for (int k = 2; k < targets_positions[j].size(); k++)
						targets_positions[i].push_back(targets_positions[j][k]);
					targets_positions.erase(targets_positions.begin() + j);
					j--;
				}
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < targets_positions.size(); i++)
		sort(targets_positions[i].begin() + 2, targets_positions[i].end());

	for (int i = 0; i < targets_positions.size(); i++) {
		for (int j = 0; j < targets_positions[i].size(); j++)
			cout << targets_positions[i][j] << ' ';
		cout << endl;
	}

	cout << endl;

	int redundancy_i;
	vector<int> redundancy;

	for (int i = 0; i < targets_positions.size(); i++) {
		redundancy_i = 1;
		for (int j = i + 1; j < targets_positions.size(); j++) {
			if (targets_positions[i][1] == targets_positions[j][1]) {
				redundancy_i++;
			}
			else {
				break;
			}
		}
		redundancy.push_back(redundancy_i);
	}

	int redundancy_count;

	redundancy_count = 1;
	for (int i = 0; i < redundancy.size(); i++)
		redundancy_count *= redundancy[i];

	cout << redundancy_count << endl;

	vector<vector<long double> > list_root;
	vector<vector<int> > root;
	vector<long double> length;
	
	target = 0;
	do {	

		for (int i = 0; i < targets_positions.size(); i++) {
			for (int j = 0; j < targets_positions[i].size(); j++)
				target_position.push_back(targets_positions[i][j]);
			root.push_back(target_position);
			target_position.clear();
			int j;
			j = i;
			i = redundency_n(targets_positions, targets_positions[i][1], i) - 1;
			if (i != j) {
				targets_positions.erase(targets_positions.begin() + j);
				i--;
			}
		}

		cout << endl;

		for (int i = 0; i < root.size(); i++) {
			for (int j = 0; j < root[i].size(); j++) {
				cout << root[i][j] << ' ';
			}
			cout << endl;
		}

		cout << endl;
	
		root_length(root, v_y, a_max, length);		
		list_root.push_back(length);
		root.clear();
		length.clear();
		target++;

	} while (target < redundancy_count);

	if (list_root.size() != 0)
		sort(list_root.begin(), list_root.end(), compare_length);

	cout << endl;

	for (int i = 0; i < list_root.size(); i++) {
		for (int j = 0; j < list_root[i].size(); j++)
			cout << list_root[i][j] << ' ';
		cout << endl;
	}

	cout << endl;

	if (list_root.size() != 0) {
		if (list_root[0].size() == 1) {
			cout << "Cannot visit any targets" << endl;
		}
		else {
			for (int i = 0; i < list_root[0].size() - 1; i++)
				cout << list_root[0][i] << ' ';

			cout << endl;
		}
	}

	return 0;

}

int redundency_n (vector<vector<int> > targets_positions, int y, int i) {
	
	int j;

	for ( j = i + 1; j < targets_positions.size(); j++) {
		if (y == targets_positions[j][1]) {
			j = redundency_n (targets_positions, y, j);
		}
		break;
	}

	return j;

}

void root_length (vector<vector<int> > root, int v_y, int a_max, vector<long double>& length) {

	int x_init, y_init;
	long double x_final;
	long double delta_x;	

	long double t, a;
	long double r_length;
	long double v_init;

	x_init = 0;
	y_init = 0;

	r_length = 0;
	v_init = 0;

	for (int i = 0; i < root.size(); i++) {
			t = get_time(root[i][1], y_init, v_y);
		
			delta_x = root[i][0] - x_init;

			if (delta_x > 0) {
				if (v_init < 0)
					v_init = 0;
				x_final = x_init + v_init * t + 0.5 * a_max * pow(t, 2);
			}
			else if (delta_x < 0) {
				if (v_init > 0)
					v_init = 0;
				x_final = x_init + v_init * t - 0.5 * a_max * pow(t, 2);
			}

			else {
				v_init = 0;
				x_final = x_init;
			}

			cout << i << ' ' << v_init << ' ' << x_final << endl;

			if ((delta_x > 0 and x_final >= root[i][0]) or (delta_x < 0 and x_final <= root[i][0]) or (delta_x == 0 and x_final == root[i][0])) {
				for (int j = 2; j < root[i].size(); j++)
					length.push_back(root[i][j]);
				r_length += sqrt(pow((x_final - x_init), 2) + pow((root[i][1] - y_init), 2));

				if (delta_x > 0) {
					a = (delta_x - v_init * t) / (0.5 * pow(t, 2));
				}
				else if (delta_x < 0) {
					a = (delta_x - v_init * t) / (0.5 * pow(t, 2));
				}
				else {
					a = 0;
				}

				v_init = a * t  + v_init;

				cout << a << ' ' << v_init  << endl;

				x_init = root[i][0];
				y_init = root[i][1];
			}
	}

	if (r_length == 0) {
		length.push_back(-1);
	}
	else {
		length.push_back(r_length);
	}

}

long double get_time(int y_final, int y_init, int v_y) {

	int delta_y;
	long double t;

	delta_y = y_final - y_init;
	t = delta_y / static_cast<long double>(v_y);

	return t;

}
