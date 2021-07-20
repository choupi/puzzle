class Solution {
public:
    vector<string> gen(string str) {
        //cout << str << endl;
        vector<string> r;
        if (str[str.size()-1]=='0') {
            if (str.size()==1 || str[0]!='0') r.push_back(str);
            return r;
        } else if (str[0]=='0') {
            r.push_back("0."+str.substr(1));
            return r;
        }
        for (int i=1;i<str.size();i++) {
            //cout << str.substr(0, i) << " " << str.substr(i) << endl;
            r.push_back(str.substr(0, i)+"."+str.substr(i));
        }
        r.push_back(str);
        return r;
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        s = s.substr(1, s.size()-2);
        //cout << s << endl;
        for (int l=1;l<s.size();l++) {
            vector<string> X = gen(s.substr(0, l));
            vector<string> Y = gen(s.substr(l));
            for (auto i:X) {
                for (auto j:Y) {
                    res.push_back("("+i+", "+j+")");
                }
            }
        }
        return res;
    }
};
