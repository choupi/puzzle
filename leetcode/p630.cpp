class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1]==b[1]) return a[0]<b[0];
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), cmp);
        //for (int i=0;i<courses.size();i++) cout << courses[i][0] << " " << courses[i][1] << endl;
        int cur=0;
        int cnt=0;
        for (int i=0;i<courses.size();i++) {
            //cout << cur << " " << cnt << "@" << courses[i][0] << endl;
            if (cur+courses[i][0]<=courses[i][1]) {
                cnt++;
                cur += courses[i][0];
                pq.push(courses[i][0]);
            } else if (!pq.empty()) {
                int t = pq.top();
                //cout << cur-t+courses[i][0] <<" " << courses[i][1] << endl;
                if (t>courses[i][0] && cur-t+courses[i][0]<=courses[i][1]) {
                    cur = cur-t+courses[i][0];
                    pq.pop();
                    pq.push(courses[i][0]);
                } 
            }
        }
        return cnt;
    }
};
