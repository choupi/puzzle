class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> fruit;
        fruit.insert({tree[0], 1});
        int i=0, j=1;
        int max_len = 1;
        for (;j<tree.size();j++) {
            fruit[tree[j]]++;
            while (fruit.size()>2) {
                fruit[tree[i]]--;
                if (fruit[tree[i]]==0) fruit.erase(tree[i]);
                i++;
            }
            if (j-i+1>max_len) max_len = j-i+1;
        }
        return max_len;
    }
};
