#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int main () {

        vector<string> dict_entries;

        string line;

        while (getline(cin, line)) {
                if (line.empty())
                        break;
                stringstream str_st(line);
                getline(str_st, line, ' ');
                dict_entries.push_back(line);
                getline(str_st, line);
                dict_entries.push_back(line);
        }

        vector<string> frg_word;

        while (getline(cin, line)) {
                if (line.empty())
                        break;
                frg_word.push_back(line);
        }

        vector<string>::iterator found;

        for (int i = 0; i < frg_word.size(); i++) {
                found = find(dict_entries.begin(), dict_entries.end(), frg_word[i]);
                if (found != dict_entries.end()) {
                        cout << *(found - 1) << endl;
                        dict_entries.erase(found - 1, found + 1);
                }
                else {
                        cout  << "eh" << endl;
                }
        }

        return 0;
}
