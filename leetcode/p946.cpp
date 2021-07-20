class Solution {
public:
    list<int>::iterator find(list<int>::iterator it, list<int>::iterator it_end, int n) {
        while (*it != n && it != it_end) it++;
        return it;
    }
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0) return true;
        list<int> l;
        for (int i=0;i<pushed.size();i++) {
            l.push_back(pushed[i]);
        }
        list<int>::iterator it = find(l.begin(), l.end(), popped[0]);
        for (int i=1;i<popped.size();i++) {
            // cout << *it << endl;
            if (it != l.begin() && popped[i] == *(prev(it))) {
                it--;
                l.erase(next(it));
            } else if(next(it) != l.end() && popped[i] == *(next(it))) {
                it++;
                l.erase(prev(it));
            } else {
                list<int>::iterator new_it = find(it, l.end(), popped[i]);
                if (new_it == l.end()) return false;
                l.erase(it);
                it = new_it;
            }
        }
        return true;
    }
};
