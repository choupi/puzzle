/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int tmp;
    bool tmp_flag;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    tmp_flag = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (tmp_flag) {
            return tmp;
        }
        tmp = Iterator::next();
        tmp_flag = true;
        return tmp;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (tmp_flag) {
            tmp_flag = false;
            return tmp;
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
	    return tmp_flag || Iterator::hasNext();
	}
};
