class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, int>> arrived_position;
        //arrived_position.assign(speed.size(), make_pair(0, -1));
        for (int i=0;i<speed.size();i++) {
            double t = double(target-position[i])/speed[i];
            arrived_position.push_back(make_pair(t, position[i]));
        }
        sort(arrived_position.begin(), arrived_position.end());
        reverse(arrived_position.begin(), arrived_position.end());
        //for (int i=0;i<arrived_position.size();i++) {
        //    printf("%f %d\n", arrived_position[i].first, arrived_position[i].second);
        //}
        int current_pos = -1;
        int total = 0;
        for (int i=0;i<arrived_position.size();i++) {
            if (arrived_position[i].second>current_pos) {
                total++;
                current_pos = arrived_position[i].second;
            }
        }
        return total;
    }
};
