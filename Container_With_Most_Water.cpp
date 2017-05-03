#define min(a, b) ((a) >= (b) ? (b) : (a))
#define max(a, b) ((a) >= (b) ? (a) : (b))

class Solution {
public:
    int maxArea(vector<int>& height) {
       return maxAreaHelp(height, 0, height.size() - 1);
    }
private:

    
    int maxAreaHelp(vector<int>& height, int low, int high)
    {
        if (high - low <= 1) {
            return min(height[low], height[high]);
        }
        
        int middle = (high - low ) / 2 + low;
        
        int left = maxAreaHelp(height, low, middle);
        
        int right = maxAreaHelp(height, middle, high);

        int midAreaMax = 0;
        int maxIndex = 0;
        for (int i = low; i < middle; ++i) {
            if (maxIndex > 0 && height[i] <= height[maxIndex]) {
                continue;
            }
            for (int j = middle + 1; j <= high; ++j) {
                int area = min(height[i], height[j]) * (j  - i);
                if (area > midAreaMax) { 
                    midAreaMax = area;
                    maxIndex = i;
                }
            }
        }
        return max(max(left, right), midAreaMax);
    }
};

