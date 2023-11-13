#include<iostream>
#include<vector>
#include <cmath>
#include <random>

using namespace std;

vector<float> find_hyp(vector<float> base, vector<float> perp)
{
    vector<float> hyp;
    for (int i = 0; i < 100; i++) {
        hyp.push_back(sqrt((base[i] * base[i]) + (perp[i] * perp[i])));
    }
    return hyp;
}

int main()
{
    vector <float> base;
    vector <float> perp;
    vector<float> hyp;

    random_device rd;
    mt19937 gen(rd());

    
    uniform_real_distribution<double> distribution(1.0, 100.0);

    for (int i = 0; i < 100; i++) {
        base.push_back(distribution(gen));
        perp.push_back(distribution(gen));
    }

    hyp = find_hyp(base, perp);

    for (int i = 0; i < 100; i++) {
        cout << "Triangle " << i + 1 << endl << " with Base: " << base[i] << " and Perpendicular: " << perp[i] << " has Hyportinuse: " << hyp[i] << endl;
    }

    return 0;
}