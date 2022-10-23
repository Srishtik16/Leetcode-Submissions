class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n + 1, 0);
        for(auto x: bookings) {
            int f = x[0];
            int l = x[1];
            int s = x[2];
            seats[f - 1] += s;
            seats[l] -= s;
        }
        for(int i = 1; i <= n; i++) {
            seats[i] += seats[i - 1];
        }
        seats.resize(n);
        return seats;
    }
};