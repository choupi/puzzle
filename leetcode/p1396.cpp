class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> user;
    unordered_map<string, unordered_map<string, pair<double, int>>> times;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        user[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [sta, tt] = user[id];
        auto [s, c] = times[sta][stationName];
        times[sta][stationName] = {s+(t-tt), c+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [s, c] = times[startStation][endStation];
        return s/c;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
