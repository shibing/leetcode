#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numsF, nums;
        if (nums1.size() < nums2.size()) {
            numsF = nums2;
            nums = nums1;
        } else {
            numsF = nums1;
            nums = nums2;
        }
        int startPos = 0;
        for (int z = 0; z < nums.size(); ++z) {
            int num = nums[z];
            int i = startPos, j = numsF.size() - 1;
            int mid;
            while (i <= j) {
                mid = (j - i) / 2 + i;
                if (numsF[mid] < num) {
                    i = mid + 1;
                } else if (numsF[mid] == num) {
                    break;
                } else {
                    j  = mid - 1;
                }
            }
            if (i <= j) {
                numsF.insert(numsF.begin() + mid + 1, num);
                startPos = mid + 1;
            } else {
                numsF.insert(numsF.begin() + i, num);
                startPos = i;
            }
        }
        if (numsF.size() % 2 == 0) {
            return (numsF[numsF.size() / 2] + numsF[numsF.size() / 2 - 1]) / 2.0;
        }
        return numsF[numsF.size() / 2];
    }
};

int main()
{
	Solution s;
	vector<int> v1 = {1, 2};
	vector<int> v2 = {3, 4};
	s.findMedianSortedArrays(v1, v2);
	return 0;
}
