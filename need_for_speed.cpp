#include<iostream>
#include<vector>
#include<ctime>
#include<cmath>
#include<cstdlib>

using namespace std;

struct segment {
    long double distance_in_miles;
    long double speedometer_reading;
    
    segment () : distance_in_miles (0), speedometer_reading (0) {
    }
    void get_data (long double distance, long double speed) {
        distance_in_miles = distance;
        speedometer_reading = speed;
    }
};

vector<long double> operator * (long double cons, vector<long double> poly) {
    
    vector<long double> polynomial;
    
    for (int i = 0; i < poly.size(); i++)
        polynomial.push_back(cons * poly[i]);
    
    return polynomial;
    
}

vector<long double> operator + (vector<long double> poly_r, vector<long double> poly_l) {
    
    vector<long double> poly;
    
    for (int i = 0; i < poly_r.size(); i++)
        poly.push_back(poly_r[i] + poly_l[i]);
    
    return poly;
}

vector<long double> operator - (vector<long double> poly_r, vector<long double> poly_l) {
    
    vector<long double> poly;
    
    poly = poly_r;
    
    for (int i = 0; i < poly_l.size(); i++)
        poly[i] = poly_r[i] - poly_l[i];
    
    return poly;
    
}

vector<long double> polynomial_coefficents (int, vector<segment>);
long double solve_newton (vector<long double>, long double, long double);
long double f (long double, vector<long double>);
long double f_prime (long double, vector<long double>);
bool check_answer (long double, vector<segment>);

int main () {
    
    int number_of_sections, total_time;
    
    cin >> number_of_sections >> total_time;
    
    int i;
    
    vector<segment> journey;
    segment journey_i;
    long double distance, speed;
    
    i = 0;
    while (i < number_of_sections) {
        cin >> distance >> speed;
        journey_i.get_data(distance, speed);
        journey.push_back(journey_i);
        i++;
    }
    
    vector<long double> polynomial_l(number_of_sections + 1);
    
    polynomial_l = total_time * polynomial_coefficents (-1, journey);
    
    vector<long double> polynomial_r(number_of_sections);
    
    for (i = 0; i < journey.size(); i++)
        polynomial_r = polynomial_r + journey[i].distance_in_miles * polynomial_coefficents(i, journey);
    
    vector<long double> polynomial(number_of_sections + 1);
    
    polynomial = polynomial_l - polynomial_r;
    
    long double const_shift;
    
    long double initial_guess;
    
    initial_guess = journey[0].speedometer_reading;
    for (i = 0; i < journey.size(); i++)
        if (initial_guess > journey[i].speedometer_reading)
            initial_guess = journey[i].speedometer_reading;
    
    long double max_distance;
    
    max_distance = journey[0].distance_in_miles;
    for (i = 0; i < journey.size(); i++)
        if (max_distance < journey[i].distance_in_miles)
            max_distance = journey[i].distance_in_miles;
    
    do {
        
        const_shift = solve_newton(polynomial, -initial_guess, max_distance);
        
    } while (!check_answer(const_shift, journey));
    
    cout << const_shift << endl;
    
    return 0;
}

vector<long double> polynomial_coefficents (int index, vector<segment> journey) {
    
    vector<segment> section;
    vector<long double> polynomial(journey.size());
    
    if (index == -1) {
        polynomial.push_back(0);
    }
    else {
        if (journey.size() == 1) {
            polynomial[0] = 1;
            return polynomial;
        }
        
        journey.erase(journey.begin() + index);
    }
    
    section = journey;
    
    polynomial[0] = section[0].speedometer_reading;
    polynomial[1] = 1;
    
    for (int i = 1; i < section.size(); i++) {
        polynomial[i + 1] = polynomial[i];
        for (int j = i; j > 0; j--)
            polynomial[j] = polynomial[j] * section[i].speedometer_reading + polynomial[j - 1];
        polynomial[0] *= section[i].speedometer_reading;
    }
    
    return polynomial;
    
}

long double solve_newton (vector<long double> poly, long double guess, long double distance) {
    
    if (poly.size() == 1)
        return 0.;
    
    if (poly.size() == 2)
        return -poly[0] / poly[1];
    
    srand(time(0));
    
    long double c, c_r, c_l;
    long double tolerance = 0.000001;
    
    c_l = rand() % 1000 + guess + 1;
    
    do {
        while (abs(f_prime(c_l, poly)) <= tolerance) {
            if (abs(f(c_l, poly)) <= tolerance)
                return c_l;
            c_l = rand() % 1000 + guess + 1;
        }
        c = f(c_l, poly) / f_prime(c_l, poly);
        c_r = c_l - c;
        c_l = c_r;
    } while (abs(c) > tolerance);
    
    return c_l;
    
}

bool check_answer (long double c, vector<segment> section) {
    
    for (int i = 0; i < section.size(); i++)
        if (c + section[i].speedometer_reading <= 0)
            return false;
    return true;
    
}

long double f (long double c, vector<long double> poly) {
    
    long double result;
    
    result = 0.;
    for (int i = 0; i < poly.size(); i++)
        result += pow(c, i) * poly[i];
    
    return result;
    
}

long double f_prime (long double c, vector<long double> poly) {
    
    long double result;
    
    result = 0.;
    for (int i = 1; i < poly.size(); i++)
        result += pow(c, i - 1) * poly[i] * i;
    
    return result;
    
}
