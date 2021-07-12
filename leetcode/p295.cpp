// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> pq0;
    priority_queue<int, vector<int>, greater<int>> pq1;
    int cnt;
    MedianFinder() {
        cnt = 0;
        return;
    }
    
    void addNum(int num) {
        cnt++;
        if (!pq0.empty() && num>pq0.top()) {
            pq1.push(num);
        } else {
            pq0.push(num);
        }
        if (pq1.size()>pq0.size()) {
            int t = pq1.top();
            pq1.pop();
            pq0.push(t);
        } else if (pq0.size()>pq1.size()+1) {
            int t = pq0.top();
            pq0.pop();
            pq1.push(t);
        }
        //cout << num << " " << pq0.size() << " " << pq1.size() << endl; 
    }
    
    double findMedian() {
        if (cnt%2==1) {
            return pq0.top();
        } else {
            return (pq0.top() + pq1.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
