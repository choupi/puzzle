class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, vector<int>> mapping;
        sort(products.begin(), products.end());
        for (int p=0;p<products.size();p++) {
            for (int i=1;i<=products[p].size();i++) {
                string t = products[p].substr(0, i);
                if (mapping[t].size()<3) {
                    mapping[t].push_back(p);
                }
            }
        }
        vector<vector<string>> res;
        for (int i=1;i<=searchWord.size();i++) {
            vector<string> r;
            string t = searchWord.substr(0, i);
            for (int p: mapping[t]) {
                r.push_back(products[p]);
            }
            res.push_back(r);
        }
        return res;
    }
};
