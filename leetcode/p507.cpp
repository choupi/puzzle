class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int rt = sqrt(num);
        //cout << rt << endl;
        int s = 1;
        for (int i=2;i<=rt;i++) {
            if (num%i == 0) {
                s += i;
                int t = num/i;
                if (t!=i) s += num/i;
            }
        }
        //cout << s << endl;
        if (s == num) return true;
        else return false;
    }
};
