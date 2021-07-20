class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int l=0;l<stamp.size();l++) {
                for (int i=0;i<=l;i++) {
                    string t;
                    t.append(i, '*');
                    t.append(stamp, i, stamp.size()-l);
                    t.append(l-i, '*');
                    int pos = 0;
                    //cout << t << endl;
                    while (true) {
                        pos = target.find(t);
                        if (pos != string::npos) {
                            res.push_back(pos);
                            target.replace(pos, stamp.size(), stamp.size(), '*');
                            flag = true;
                            //cout << "replace " << target << endl;
                        } else break;
                    }
                }
                if (l==0 && res.size()==0) break;
            }
        }
        //cout << target << endl;
        if (target.find_first_not_of("*") != string::npos) {
            res.resize(0);
            return res;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
