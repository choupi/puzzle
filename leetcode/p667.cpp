class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        int a=1;
        int b=k+1;
        for (int i=0;i<k+1;i++) {
            if (i%2 == 0) {
                //cout << i << "a" << a << endl;
                res[i] = a;
                a++;
            } else {
                //cout << i << "b" << b << endl;
                res[i] = b;
                b--;
            }
        }
        for (int i=k+1;i<n;i++) {
            res[i] = i+1;
        }
        return res;
    }
};
