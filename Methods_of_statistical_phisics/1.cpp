#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <vector>
#include <fstream>


using namespace std;

double P(double x){
    return 2.0 * exp(-(x * x)) ;
}

int main(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    normal_distribution<double> distribution (0.0, 1.0);

    const double DELTA = 0.2;

    ofstream out;
    out.open("govno.txt");

    vector<double> v;
    int data = 0;
    double w;

    double xi;
    double x = distribution(generator); 
    for (int i = 0; i < 100000; i++) {
        
        double step = distribution(generator);
        if(step >= -DELTA && step <= DELTA){
            cout << "Шаг на " << i << " итерации = " << step << endl;
            xi = x + step;

            w = P(xi)/P(x);
            cout << "x = " << x << "\t x = " << x << "\t w = " << w << endl;
            //cout << "W = " << w << endl;
            if (w >= 1) 
            {
                x = xi;
                data++;
                v.push_back(x);           
            } else {
                double r = distribution(generator);
                cout << "Сгенерировали r = " << r << endl;
                if(r <= w)
                {
                    data++;
                    x = xi;
                    v.push_back(x);
                }
            }

            if(data == 10000){
                break;
            }
        }
    }

    for (double oput : v)
    {
        out << oput << endl;
    }

}