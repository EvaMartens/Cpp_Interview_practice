//
// Created by epm04 on 07/02/2024.
//

/**
 * Problem:
 *
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
    and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

    Merge nums1 and nums2 into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, but instead be stored
    inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first
    m elements denote the elements that should be merged, and the last n elements are set to 0 and
    should be ignored. nums2 has a length of n.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        //max vector indexes
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        //itterate over the lists backwards, filling in nums 1 with largest value first
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--; k--;
            } else {
                nums1[k] = nums2[j];
                j--; k--;
            }
        }

        //if n = 0 (nums 1 is empty) or there are numbers left over in nums2, then fill them into nums1
        while(j>=0){
            nums1[k] = nums2[j];
            j--; k--;
        }

    }
};