class Solution {
public:
    unordered_map<string, unordered_set<string>> ws;
    unordered_map<string, int> wi;
    unordered_map<string, int> wv;
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (int j=0;j<wordlist.size();j++) {
            string w = wordlist[j];
            string wl = w;
            for (int i=0;i<wl.size();i++) {
                wl[i] = tolower(wl[i]);
            }
            ws[wl].insert(w);
            if (wi.find(wl)==wi.end()) wi[wl] = j;
            for (int i=0;i<wl.size();i++) {
                if (wl[i]=='a' || wl[i]=='e' || wl[i]=='i' || wl[i]=='o' || wl[i]=='u') {
                    wl[i] = '-';
                }
            }
            if (wv.find(wl)==wv.end()) wv[wl] = j;
        }
        vector<string> res;
        for (string w: queries) {
            string wl = w;
            for (int i=0;i<wl.size();i++) {
                wl[i] = tolower(wl[i]);
            }
            if (ws.find(wl)!=ws.end()) {
                if (ws[wl].find(w)!=ws[wl].end()) {
                    res.push_back(w);
                } else {
                    res.push_back(wordlist[wi[wl]]);
                }
                continue;
            }
            for (int i=0;i<wl.size();i++) {
                if (wl[i]=='a' || wl[i]=='e' || wl[i]=='i' || wl[i]=='o' || wl[i]=='u') {
                    wl[i] = '-';
                }
            }
            if (wv.find(wl)!=wv.end()) {
                res.push_back(wordlist[wv[wl]]);
                continue;
            }
            res.push_back("");
        }
        return res;
    }
};
