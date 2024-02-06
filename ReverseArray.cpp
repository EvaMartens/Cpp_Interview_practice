//
// Created by epm04 on 06/02/2024.
//

/**
 * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

    Example :

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]

 **/

#include <iostream>
#include <vector>

class Reverse {
public:
    void rotate(std::vector<int>& nums, int k) {
        // k is step size
        // arraysize + 1

        /**
        int cont;

        for(int j = 0; j < k; j++){

            //take tail and container it
            cont = nums[nums.size()-1];

            // 1 2 3 4 5 6 7
            //   ^

            for(int i = (nums.size()-1); i >= 1; i--){
                std::cout << " i = " << i << "; j = " << j << ";" << std::endl;
            //start in back and shift everything
            nums[i] = nums[i-1];
            }

            for(int l : nums)
            std::cout << l << " ";

            nums[0] = cont;
        }
        **/

        // 1 2 3 4 5 6
        // k = 8

        k = k%nums.size(); // (reduce k to number between 0 and nums.size())
        //after this k = 2

        std::reverse(nums.begin(), nums.begin()+(nums.size()-k)); //-> std::reverse is part of C++17 & C++20
        // 4 3 2 1 - 5 6
        //         ^

        std::reverse(nums.begin()+(nums.size()-k), nums.end());
        //4 3 2 1 - 6 5
        //        ^

        std::reverse(nums.begin(), nums.end());
        //5 6 1 2 3 4

    }
};