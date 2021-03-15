// 1396. Design Underground System
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

class UndergroundSystem {
        std::unordered_map<int, std::pair<std::string, int> > M;
        std::unordered_map<std::string, std::unordered_map<std::string, int > > dir;
        std::unordered_map<std::string, std::unordered_map<std::string, int > > cnt;
    public:
        UndergroundSystem() {
        }

        void checkIn(int id, std::string stationName, int t) {
            // O(1)
            M[id] = {stationName, t};
        }

        void checkOut(int id, std::string stationName, int t) {
            // O(1)
            auto checkin = M[id];
            M.erase(id);
            dir[checkin.first][stationName] += t - checkin.second;
            cnt[checkin.first][stationName]++;
        }

        double getAverageTime(std::string startStation, std::string endStation) {
            // O(1)
            return dir[startStation][endStation] / static_cast<double>(cnt[startStation][endStation]);
        }
};

int main(void) {
}