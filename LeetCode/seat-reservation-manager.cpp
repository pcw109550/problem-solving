// 1845. Seat Reservation Manager
#include <set>

class SeatManager {
    std::set<int> S;
    public:
        SeatManager(int n) {
            for (int i = 1; i <= n; i++)
                S.insert(i); 
        }

        int reserve() {
            // O(log(N))
            int result = *S.begin();
            S.erase(result);
            return result;
        }

        void unreserve(int seatNumber) {
            // O(log(N))
            S.insert(seatNumber);
        }
};

int main(void) {
    SeatManager* obj;
}