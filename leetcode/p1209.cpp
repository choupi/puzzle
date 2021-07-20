class Solution {
public:
    list<pair<char, int>> pl;
    string removeDuplicates(string s, int k) {
        char c=s[0];
        int cnt=1;
        for (int i=1;i<s.size();i++) {
            if (s[i]!=c) {
                pl.push_back({c, cnt});
                c = s[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        pl.push_back({c, cnt});
        auto it = pl.begin();
        while (it != pl.end()) {
            //cout << (*it).first << (*it).second<<endl;
            if ((*it).second%k!=0) {
                //cout <<"@1" <<endl;
                (*it).second %= k;
                it++;
            } else if ((*it).second%k==0) {
                auto lit = pl.end(); lit--;
                if (it == pl.begin() || it == lit) {
                    //cout << "@2" <<endl;
                    auto cit = it;
                    it++;
                    pl.erase(cit);
                } else {
                    //cout << "@3" <<endl;
                    auto pit = it;
                    pit--;
                    auto nit = it;
                    nit++;
                    pl.erase(it);
                    if ((*pit).first == (*nit).first) {
                        //cout <<"@4" << endl;
                        (*pit).second += (*nit).second;
                        pl.erase(nit);
                        it = pit;
                    } else {
                        //cout << "@5" << endl;
                        it = nit;
                    }
                }
            } else {
                it++;
            }
        }
        //cout <<"@@@" <<endl;
        string res;
        for (it=pl.begin();it!=pl.end();it++) {
            res.append((*it).second, (*it).first);
        }
        return res;
    }
};
