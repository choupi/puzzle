typedef pair<int, int> pt;
class Solution {
public:
    priority_queue<pt> lq;
    priority_queue<pt, vector<pt>, greater<pt>> hq;
    template <typename T>
    pt mtop(T &q, int ik) {
        while (!q.empty() && q.top().second < ik) {
            //cout << q.size() << "" << q.top().second << " " << ki << endl;
            q.pop();
        }
        return q.top();
    }
    
    void update(int n, int i, int ik) {
        pt np = {n, i};
        pt tp = mtop(lq, ik);
        if (np < tp) {
            //cout <<i << "L" << n << endl;
            //cout << tp.first << tp.second << endl;
            hq.push(tp);
            lq.pop();
            lq.push(np);
        } else {
            //cout <<i << "H" << n << endl;
            hq.push(np);
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int k2 = k/2;
        int i = 0;
        vector<double> res;
        if (k == 1) {
            for (i=0;i<nums.size();i++) res.push_back(nums[i]);
            return res;
        }
        for (i=0;i<k2;i++) {
            lq.push({nums[i], i});
        }
        for (i=k2;i<k-1;i++) {
            update(nums[i], i, -1);
        }
        for (i=k-1;i<nums.size();i++) {
            int ik = i-k+1;
            update(nums[i], i, ik);
            if (k&1) {
                double t = mtop(hq, ik).first;
                //cout << hq.top().second <<  "m " << t << endl;
                res.push_back(t);
            } else {
                double l = mtop(lq, ik).first;
                double h = mtop(hq, ik).first;
                double t = (l+h)/2.0;
                //cout << l << h << "m " << t<< endl;
                res.push_back(t);
            }
            pt rp = {nums[ik], ik};
            pt tp = mtop(lq, ik);
            if (rp <= tp) {
                //cout << rp.second << "<=" << tp.second << endl;
                if (tp.second == ik) lq.pop();
                pt p = mtop(hq, ik);
                hq.pop();
                lq.push(p);
            }
        }
        return res;
    }
};
