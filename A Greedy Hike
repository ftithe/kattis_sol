#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int main () {
    
    
    int r, c, x_in, y_in, x, y;
    vector<int> row;
    vector<vector<int> > map;
    
    cin >> r >> c;
    cin >> x_in >> y_in;
    
    x = 0;
    while (x < r) {
        for (int i = 0; i < c; i++) {
            cin >> y;
            row.push_back(y);
        }
        map.push_back(row);
        row.clear();
        x = x + 1;
    }
    
    int elevation, x_plus, x_zero, x_minus;
    
    elevation = 0;
    x = x_in;
    y = y_in;
    
    while ( y != c - 1) {
        
        x_in = x;
        y_in = y;
        
        x_zero = abs(map[x][y + 1] - map[x][y]);
        
        if (x == 0) {
            if (x != r - 1) {
                x_plus = abs(map[x + 1][y + 1] - map[x][y]);
                if (x_plus < x_zero) {
                    x = x + 1;
                }
            }
        }
        else if (x == r - 1) {
            x_minus = abs(map[x - 1][y + 1] - map[x][y]);
            if (x_minus < x_zero) {
                x = x - 1;
            }
        }
        else {
            x_plus = abs(map[x + 1][y + 1] - map[x][y]);
            x_minus = abs(map[x - 1][y + 1] - map[x][y]);
            if (x_plus < x_minus) {
                if (x_plus < x_zero) {
                    x = x + 1;
                }
            }
            else if (x_plus == x_minus) {
                if (x_plus < x_zero) {
                    x = x + 1;
                }
            }
            else {
                if (x_plus < x_zero) {
                    x = x - 1;
                }
                else if(x_plus > x_zero) {
                    if (x_zero > x_minus) {
                        x = x - 1;
                    }
                }
            }
        }
        
        y = y + 1;
        elevation += abs(map[x][y] - map[x_in][y_in]);
    }
    
    cout << x << " " << y << " " << elevation << endl;
    
    return 0;
   
}
