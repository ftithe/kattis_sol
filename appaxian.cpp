#include<iostream>
#include<vector>

using namespace std;

struct status {
    string name;
    int frequency;
    
    void set_frequncies () {
        frequency = 0;
    }
};

int main () {
    
    string community_name;
    int n_names;
    
    cin >> community_name >> n_names;
    
    vector<status> list(4);
    
    list[0].name = "princess";
    list[1].name = "baron";
    list[2].name = "priest";
    list[3].name = "commoner";
    
    int i;
    string name_i;
    vector<string> names;
    
    i = 0;
    while (i < n_names) {
        cin >> name_i;
        names.push_back(name_i);
        i++;
    }
    
    int len;
    int found;
    len = community_name.size();
    
    for (i = 0; i < names.size(); i++) {
        if (names[i].size() > len) {
            found = names[i].find(community_name);
            if (found == 0) {
                list[0].frequency++;
            }
            else if (found + len == names[i].size()) {
                list[1].frequency++;
            }
            else if (found == -1) {
                list[3].frequency++;
            }
            else {
                list[2].frequency++;
            }
        }
        else {
            list[3].frequency++;
        }
    }
    
    for (i = 0; i < list.size(); i++) {
        cout << list[i].frequency << " " << list[i].name << endl;
    }
    
    return 0;
}

