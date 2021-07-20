class MyCalendar {
public:
    // {start, end}
    map<int, int> table;
    MyCalendar() {
        return;
    }
    
    bool book(int start, int end) {
        cout << start << " " << end << endl;
        auto it = table.upper_bound(start);
        if (it!=table.end() && (*(it)).second < end) {
            return false;
        }
        table[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
