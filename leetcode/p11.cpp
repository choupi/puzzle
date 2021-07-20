class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol = 0;
        int i = 0, j = height.size() - 1;
        while (j > i) {
            int vol = (j - i) * (height[i]<height[j] ? height[i] : height[j]);
            if (vol > max_vol) max_vol = vol;
            if (height[i] > height[j]) j--;
            else i++;
        }
        return max_vol;
    }
};
