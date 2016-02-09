#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.reserve(1000); //可以稍微提点速度
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = 0 - nums[i];
            for (int j = i + 1, k = nums.size() - 1;  j < k;) {
                if (j == i) {
                    ++j; continue;
                }
                if (k == i) {
                    --k; continue;
                }
                int rLeft = nums[j] + nums[k];
                if ( rLeft == left) {
                    if (nums[i] <= nums[j]) {
                        ret.push_back({nums[i], nums[j], nums[k]});
                    } else if (nums[i] >= nums[k]) {
                        ret.push_back({nums[j], nums[k], nums[i]});
                    } else {
                         ret.push_back({nums[j], nums[i], nums[k]});
                    }
                    ++j;
                    --k;
                } else if (rLeft < left) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        std::sort(ret.begin(), ret.end());
        ret.erase(std::unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};


int main()
{
	Solution s;
	vector<int> data{-7,2,1,10,9,-10,-5,4,13,-9,-4,6,11,-12,-6,-9,-6,-9,-11,-4,10,10,-3,-1,-4,-7,-12,-15,11,5,14,11,-7,-8,6,9,-2,9,-10,-12,-15,2,10,4,5,11,10,6,-13,6,-13,12,-7,-9,-12,4,-9,13,-4,10,4,-12,6,4,-5,-10,-2,0,14,4,4,6,13,-9,-5,-5,-13,12,-14,11,3,10,8,11,-13,4,-8,-7,2,4,10,13,7,2,2,9,-1,8,-5,-10,-3,6,3,-5,12,6,-3,6,3,-2,2,14,-7,-13,10,-13,-2,-12,-4,8,-1,13,6,-9,0,-14,-15,6,9};
	s.threeSum(data);
	return 0;
}