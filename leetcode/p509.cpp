class Solution {
public:
    vector<int> table;
    int fib(int n) {
        table.push_back(0);
        table.push_back(1);
        for (int i=2;i<=n;i++) {
            table.push_back(table[i-2] + table[i-1]);
        }
        return table[n];
    }
};
