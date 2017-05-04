#define min(a, b) ((a) >= (b) ? (b) : (a))

#define max(a, b) ((a) >= (b) ? (a) : (b))

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int maxArea = 0;
        int i = 0;
        int j = size - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            maxArea = max(maxArea, h * (j - i));
            while (height[i] <= h && i < j) ++i;
            while (height[j] <= h && j > i) --j;
        }
        return maxArea;
    }
};
