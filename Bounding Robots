#include<iostream>
#include<vector>
#include<cstdlib>
#include<sstream>

using namespace std;

struct description {
    
    char x;
    int y;
    
};

struct robot {
    
    int width;
    int length;
    int n_segment;
    vector<description> xy;
    
    void get_data (int w, int l, int n) {
        width = w;
        length = l;
        n_segment = n;
    }
    
    void get_description (char x, int y) {
        description description_i;
        description_i.x = x;
        description_i.y = y;
        
        xy.push_back(description_i);
    }
    
    void clear_description () {
        xy.clear();
    }
    
};

int actual_x (int, int, int);
int actual_y (int, int, int);

int main () {
    
    int width, length, segment, y;
    char x;
    robot simulation_i;
    vector<robot> simulation;
    string line;
    int i;
    
    do {
        
        cin >> width >> length;
        
        if (width == 0)
            break;
        
        cin >> segment;
        
        simulation_i.get_data(width, length, segment);
        cin.ignore();
        
        i = 0;
        while (i < segment) {
            
            getline(cin, line);
            stringstream str_st(line);
            while(getline(str_st, line, ' ')) {
                x = line[0];
                break;
            }
            getline(str_st, line);
            y = atoi(line.c_str());
            simulation_i.get_description(x, y);
            i++;
            
        }
        simulation.push_back(simulation_i);
        simulation_i.clear_description();
        
    } while (true);
    
    int x_p, y_p;
    int x_a, y_a;
    
    for (i = 0; i < simulation.size(); i++) {
        
        x_p = 0; x_a = 0;
        y_p = 0; y_a = 0;
        
        for (int j = 0; j < simulation[i].xy.size(); j++) {
            if (simulation[i].xy[j].x == 'u') {
                y_p += simulation[i].xy[j].y;
                y_a = actual_y(y_a, simulation[i].xy[j].y, simulation[i].length - 1);
            }
            else if (simulation[i].xy[j].x == 'd') {
                y_p -= simulation[i].xy[j].y;
                y_a = actual_y(y_a, -simulation[i].xy[j].y, simulation[i].length - 1);
            }
            else if (simulation[i].xy[j].x == 'r') {
                x_p += simulation[i].xy[j].y;
                x_a = actual_x(x_a, simulation[i].xy[j].y, simulation[i].width - 1);
            }
            else {
                x_p -= simulation[i].xy[j].y;
                x_a = actual_x(x_a, -simulation[i].xy[j].y, simulation[i].width - 1);
            }
        }
        
        cout << "Robot thinks " << x_p << " " << y_p << endl;
        cout << "Actually at " << x_a << " " << y_a << endl;
        
    }
    
    return 0;
    
}

int actual_y (int y_a, int y, int length) {
    
    if (y >= length) {
        y_a = length;
    }
    else if (y <= -length) {
        y_a = 0;
    }
    else {
        y_a = y_a + y;
        if (y_a > length) {
            y_a = length;
        }
        else if (y_a < 0) {
            y_a = 0;
        }
    }
    
    return y_a;
    
}

int actual_x (int x_a, int x, int width) {
    
    if (x >= width) {
        x_a = width;
    }
    else if (x <= -width) {
        x_a = 0;
    }
    else {
        x_a = x_a + x;
        if (x_a > width) {
            x_a = width;
        }
        else if (x_a < 0) {
            x_a = 0;
        }
    }
    
    return x_a;
    
}
