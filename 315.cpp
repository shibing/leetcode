
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

class Solution {
public:
   vector<int> countSmaller(const vector<int>& nums) { if (nums.empty()) { return vector<int>(); }
        vector<int> res(nums.size(), 0);
        vector<int> sorted;
        for (int i = nums.size() - 1; i >= 0; --i) {
            auto iter = std::lower_bound(sorted.begin(), sorted.end(), nums[i]);
            res[i] = iter - sorted.begin();
            sorted.insert(iter, nums[i]);
        }
        return res;
    }
};

int main() 
{
    Solution solution;
    vector<int> nums {5, 2, 6, 1};
    auto res = solution.countSmaller(nums);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
}