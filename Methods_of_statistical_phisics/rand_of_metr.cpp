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
    std::mt19937 generator (seed);
    std::normal_distribution<double> distribution (0.0, 1.5);

    const double DELTA = 0.2;

    std::ofstream out;
    std::ofstream x_txt;
    out.open("govno.txt");
    x_txt.open("x_txt.txt");

    double x = distribution(generator);
    double x1;
    double step;
    double w;
    double r;
    int data = 0;
    double interval = -20.0;
    vector<double> v;
    int step_count = 0;
    int i = 0;
     for (i=0; i<1000000; ++i) 
    {
        step = distribution(generator);
        std::cout << "step_generation" << step << endl;
        if (step >= -DELTA && step <= DELTA)
        {
            step_count++;
            std::cout << "step_inner" << step << endl;
            x1 = x + step;            
            
            
            w = P(x1)/P(x);
            //cout << "W = " << w << endl;
            if (w >= 1) 
            {
                x = x1;
                data++;
                v.push_back(x1);
            
            } else
            {
                r = distribution(generator);
                //cout << "r = " << r << endl;
                if(r <= w)
                {
                    data++;
                    x = x1;
                    //cout << "x = " << x << endl;
                    v.push_back(x1);
                    //out << v << endl;
                }
            }
        }

        while(interval <= 20.0)
        {
            x_txt << interval << endl;
            interval += 0.004;
        }
        if(data == 10000) {
            break ;
        }

    }
    std::cout << "iterations = " << i << endl;
    //std::cout << "interval = " << interval << endl;
    for (double oput : v)
    {

        out << oput << endl;
    }
    cout << "step_count = " << step_count << endl;
    //cout << "DATA = " << data << endl;


}