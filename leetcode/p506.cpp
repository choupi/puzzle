class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> tmp;
        vector<string> res(score.size());
        for (int i=0;i<score.size();i++) {
            tmp.push_back({score[i], i});
        }
        sort(tmp.begin(), tmp.end(), greater<pair<int,int>>());
        //cout << tmp[0].first << endl;
        for (int i=0;i<tmp.size();i++) {
            if (i==0) res[tmp[i].second] = "Gold Medal";
            else if (i==1) res[tmp[i].second] = "Silver Medal";
            else if (i==2) res[tmp[i].second] = "Bronze Medal";
            else res[tmp[i].second] = to_string(i+1);
        }
        return res;
    }
};
