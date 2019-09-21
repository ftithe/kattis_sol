#include<iostream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct city {

        int city_i;
        string city_name;
        long long t_to_visit;
        long long last_time_visited;

        city () : last_time_visited (-1) {
        }

        void get_data (int c_i, string name, long long t) {
                city_i = c_i;
                city_name = name;
                t_to_visit = t;
        }

        void set_last_time_visited (long long t) {
                last_time_visited = t;
        }
};

struct road {

        int from_city;
        int to_city;
        long long driving_time;

        void get_data (int c_f, int c_t, long long d) {
                from_city = c_f;
                to_city = c_t;
                driving_time = d;
        }

};

bool compare_road_c_to (road i, road j) {
        return (i.to_city < j.to_city);
}

bool compare_road_d_t (road i, road j) {
        return (i.driving_time < j.driving_time);
}

int main () {

        int N, R, S;
        long long H, M;
        
        cin >> N >> R >> H >> M >> S;

        city city_x;
        vector<city> cities;

        int i;
        string name;
        long long t;

        string line;

        int k;

        k = 0;
        cin.ignore();
        while (k < N) {
                getline(cin, line);
                stringstream str_st(line);
                getline(str_st, line, ' ');
                i = atoi(line.c_str());
                getline(str_st, line, ' ');
                name = line;
                getline(str_st, line);
                t = atol(line.c_str());
                city_x.get_data(i, name, t);
                cities.push_back(city_x);
                k++;
        }

        road road_x;
        vector<road> roads;

        int c_f, c_t;
        long long d;


        k = 0;
        while (k < R) {

                getline(cin, line);
                stringstream str_st(line);
                getline(str_st, line, ' ');
                c_f = atoi(line.c_str());
                getline(str_st, line, ' ');
                c_t = atoi(line.c_str());
                getline(str_st, line);
                d = atol(line.c_str());
                road_x.get_data(c_f, c_t, d);
                roads.push_back(road_x);
                road_x.get_data(c_t, c_f, d);
                roads.push_back(road_x);
                k++;
        }

        if (roads.size() > 0) {
            stable_sort(roads.begin(), roads.end(), compare_road_c_to);
            stable_sort(roads.begin(), roads.end(), compare_road_d_t);
        }
        
        long long t_lv;
        long long T;

        vector<string> dest;

        for (k = 0; k < N; k++) {
                if (S == cities[k].city_i) {
                        dest.push_back(cities[k].city_name);
                        T = cities[k].t_to_visit;
                        cities[k].set_last_time_visited(T);
                        break;
                }
        }

        for (k = 0; k < roads.size(); k++) {
                if (roads[k].from_city == S) {
                        for (int l = 0; l < N; l++) {
                                if (roads[k].to_city == cities[l].city_i) {
                                        t_lv = cities[l].last_time_visited;
					if (T + roads[k].driving_time + cities[l].t_to_visit > M) {
						break;
					}
                                        if (t_lv != -1 and T + roads[k].driving_time - t_lv < H) {
                                                break;
                                        }
                                        S = cities[l].city_i;
                                        dest.push_back(cities[l].city_name);
                                        T = T + roads[k].driving_time + cities[l].t_to_visit;
                                        cities[l].set_last_time_visited(T);
                                        k = -1;
                                        break;
                                }
                        }
                }
        }

        for (k = 0; k < dest.size(); k++)
                cout << dest[k] << ' ';

        cout << endl << T << endl;

        return 0;

}
