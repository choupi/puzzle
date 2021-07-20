// https://leetcode.com/problems/open-the-lock/

#define N 10000
class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> q;
    int T;
    int openLock(vector<string>& deadends, string target) {
        T = stoi(target);
        if (T==0) return 0;
        visited.resize(N, false);
        for (string s: deadends) {
            int n = stoi(s);
            if (n==0) return -1;
            visited[n] = true;
        }
        int k = 0;
        visited[0] = true;
        q.push_back(vector<int>());
        q[k].push_back(0);
        while (q[k].size()>0) {
            q.push_back(vector<int>());
            for (int n: q[k]) {
                for (int i=1;i<5;i++) {
                    int t;
                    string s = to_string(n+N);
                    if (s[i] == '9') {
                        s[i] = '0';
                    } else {
                        s[i]++;
                    }
                    t = stoi(s) % N;
                    if (t==T) return k+1;
                    if (!visited[t]) {
                        //cout << t << endl;
                        visited[t] = true;
                        q[k+1].push_back(t);
                    }
                    s = to_string(n+N);
                    if (s[i] == '0') {
                        s[i] = '9';
                    } else {
                        s[i]--;
                    }
                    t = stoi(s) % N;
                    if (t==T) return k+1;
                    if (!visited[t]) {
                        //cout << t << endl;
                        visited[t] = true;
                        q[k+1].push_back(t);
                    }
                }
            }
            k++;
        }
        return -1;
    }
};
