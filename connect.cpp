#include<iostream>
#include<vector>
#include<sstream>
#include<cstdlib>

using namespace std;

int count_connection(vector<int>, int, int);

int main () {

        int x, y, n;

        cin >> x >> y >> n;

        cin.ignore();

        string line;
        vector<int> board_r;
        vector<vector<int> > board;

        while (true) {
                getline(cin, line);
                if (line.empty())
                        break;
                stringstream str_st(line);
                while(getline(str_st, line, ' ')){
                        if (line == "B") {
                                board_r.push_back(1);
                        }
                        else if (line == "R") {
                                board_r.push_back(2);
                        }
                        else {
                                board_r.push_back(atoi(line.c_str()));
                        }
                }
                board.push_back(board_r);
                board_r.clear();
        }


        vector<int> horizontal, vertical, diagonal_p, diagonal_m;

        for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++)
                        horizontal.push_back(board[i][j]);
                horizontal.push_back(-1);
        }

        for (int j = 0; j < y; j++) {
                for (int i = 0; i < x; i++)
                        vertical.push_back(board[i][j]);
                vertical.push_back(-1);
        }

	for (int j = 0; j < y; j++) {
                for (int k = 0; k < j + 1 && k < x; k++)
                        diagonal_p.push_back(board[k][j - k]);
                diagonal_p.push_back(-1);
        }
        for (int i = 1; i < x; i++) {
                for (int k = 0; k < y - i &&  i + k < x; k++)
                        diagonal_p.push_back(board[i + k][y - 1 - k]);
                diagonal_p.push_back(-1);
        }

        for (int j = y - 1; j > -1; j--) {
                for (int k = 0; k < y - j && k < x; k++)
                        diagonal_m.push_back(board[k][j + k]);
                diagonal_m.push_back(-1);
        }
        for (int i = 1; i < x; i++) {
                for (int k = 0; k < y - i && i + k < x; k++)
                        diagonal_m.push_back(board[i + k][k]);
                diagonal_m.push_back(-1);
        }

        vector<int> b_count, r_count;

        b_count.push_back(count_connection(horizontal, 1, n));
        b_count.push_back(count_connection(vertical, 1, n));
        b_count.push_back(count_connection(diagonal_p, 1, n));
        b_count.push_back(count_connection(diagonal_m, 1, n));

        r_count.push_back(count_connection(horizontal, 2, n));
        r_count.push_back(count_connection(vertical, 2, n));
        r_count.push_back(count_connection(diagonal_p, 2, n));
        r_count.push_back(count_connection(diagonal_m, 2, n));

        int k;
        for (k = 0; k < b_count.size(); k++) {
                if (b_count[k] == n) {
                        cout << "BLUE WINS" << endl;
                        break;
                }
                else if (r_count[k] == n) {
                        cout << "RED WINS" << endl;
                        break;
                }
        }

        if (k == b_count.size())
                cout << "NONE" << endl;

        return 0;

}

int count_connection (vector<int> line, int s, int n) {

        int count = -1;
        for (int i = 0; i < line.size(); i++) {
                if (line[i] == s) {
                        int j = i + 1;
                        count = 1;
                        if (count == n)
                                break;
                        while (j < line.size()) {
                                if (line[j] != s)
                                        break;
                                count++;
                                if (count == n)
                                        break;
                                j++;
                        }
                        if (count == n)
                                break;
                        i = j + 1;
                }
        }
        return count;

}
