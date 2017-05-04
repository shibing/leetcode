class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }
        int imin = 0, imax = nums1.size();
        int size1 = nums1.size();
        int size2 = nums2.size();
        int half_size = (size1 + size2 + 1) / 2;
        double mid = 0.0;
        while (imin <= imax) {
            int i = (imax + imin) / 2;
            int j = half_size - i;
            
            if (i < size1 && nums2[j - 1] > nums1[i]) {
                imin = i + 1;
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                imax = i - 1;
            } else {
                
                int max_of_left;
                int min_of_right;
                
                if (i == 0) {
                    max_of_left = nums2[j - 1];
                } else if(j == 0) {
                    max_of_left = nums1[i - 1];
                } else {
                    max_of_left = max(nums1[i - 1], nums2[j - 1]);
                }
                
                if (i == size1) {
                    min_of_right = nums2[j];
                } else if (j == size2) {
                    min_of_right = nums1[i];
                } else {
                    min_of_right = min(nums1[i], nums2[j]);
                }
                
                if ((nums1.size() + nums2.size()) % 2 == 0) {
                    mid =  (max_of_left + min_of_right)/2.0;
                } else {
                    mid = max_of_left;
                }
                break;
            }
        }
        return mid;
        
    }
};
