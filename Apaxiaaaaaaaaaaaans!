#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main () {
    
    int i, j;
    int frequency;
    string name;
    
    cin >> name;
    
    for (i = 0; i < name.size(); i++) {
        frequency = count(name.begin() + i, name.end(), name[i]);
        if (frequency > 1) {
            j = 1;
            while (j < frequency ) {
                if (name[i] == name[i + 1]) {
                    name.erase(i + 1, 1);
                }
                else {
                    break;
                }
                j++;
            }
        }
    }
    
    cout << name << endl;
    
    return 0;
    
}
