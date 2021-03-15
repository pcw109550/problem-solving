// 478. Generate Random Point in a Circle
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

class Solution {
    double radius;
    double x_center;
    double y_center;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> rf;
    public:
        Solution(double radius, double x_center, double y_center)
            : radius { radius }, x_center { x_center }, y_center { y_center } {
                gen = std::mt19937 (rd()); 
                rf = std::uniform_real_distribution<> (-radius, radius);
            }
    
        std::vector<double> randPoint() {
            double x, y;
            do {
                x = rf(gen), y = rf(gen);
            } while ( x * x + y * y > radius * radius);
            return std::vector<double> { x + x_center, y + y_center };
        }
};

int main(void) {
}