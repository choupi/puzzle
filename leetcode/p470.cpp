// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int r0 = 4;
        int r1 = 7;
        while (r0 == 4) {
            r0 = rand7();
        }
        while (r1 > 5) {
            r1 = rand7();
        }
        return r0>4 ? r1+5 : r1;
    }
};
