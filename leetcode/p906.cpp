class Solution {
public:
    long long L;
    long long R;
    bool check(long long t) {
        string tt = to_string(t);
        int l = tt.size();
        int ll = l/2;
        for (int i=0;i<ll;i++) {
            if (tt[i]!=tt[l-i-1]) return false;
        }
        return true;
    }
    int gen(int pre, int mid=-1) {
        string s = to_string(pre);
        string r = string(s.rbegin(), s.rend());
        string t;
        if (mid>=0) {
            t = s+to_string(mid)+r;
        } else {
            t = s+r;
        }
        return stoll(t);
    }
    long long run(int len) {
        long long total = 0;
        if (len==1) {
            for (int i=1;i<4;i++) {
                int ii = i*i;
                if (ii>=L && ii<=R) total++;
            }
            return total;
        }
        int ml=len/2;
        bool mid = len%2==1;
        long long st=1;
        for (int i=0;i<ml-1;i++) st *= 10;
        for (int i=st;i<st*10;i++) {
            if (mid) {
                for (int j=0;j<10;j++) {
                    long long t = gen(i, j);
                    long long tt = t*t;
                    //cout << i << " t:" <<t<<" tt:"<<tt<<endl;
                    if (tt>R) return total;
                    if (tt>=L && tt<=R && check(tt)) total++;
                }
            } else {
                long long t = gen(i);
                long long tt = t*t;
                //cout << i << " t:" <<t<<" tt:"<<tt<<endl;
                if (tt>R) return total;
                if (tt>=L && tt<=R && check(tt)) total++;
            }
        }
        return total;
    }
    int superpalindromesInRange(string left, string right) {
        L = stoll(left);
        R = stoll(right);
        int ll = left.size()/2;
        if (ll==0) ll=1;
        int rr = right.size()/2+1;
        long long total = 0;
        for (int i=ll;i<=rr;i++) {
            total += run(i);
            //cout << i << " total:" <<total << endl;
        }
        return total;
    }
};
