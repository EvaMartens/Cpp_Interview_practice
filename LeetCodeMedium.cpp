//
// Created by epm04 on 05/02/2024.
//

#include <iostream>
#include <vector>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        //-------------------------------

        //1) element allowed at most twice
        //2) order needs to be maintained
        //3) return k elements
        //4) array either contains k elements at front or is size k
        //5) no extra space
        //6) array size at least 1

        //---------------------

        //upon each new element reset a count
        //int nOE = 1;
        int nOW = 1;

        //initiate k to count
        int k = 1;

        //edge case 1 - arr size 1
        if(nums.size()==1){
            return k;
        }

        //edge case 2 - arr size 2
        if(nums.size() == 2){
            return k + 1;
        }

        //array size at least 3
        // 1 1 1
        //     ^

        for(int i = 1; i < nums.size(); i++){ //nOW = 1
            if(nums[i] == nums[i - 1]){
                nOW++;
                std::cout << "Nums i is -> " << nums[i] << " and nOW is " << nOW << std::endl;
                if(nOW > 2){
                    while(nums[i] == nums[i-1]){
                        std::cout << nums[i] << " got erased" << std::endl;
                        nums.erase(nums.begin()+i-1);
                        for(int i : nums)
                            std::cout << i << " ";
                        if(i == nums.size()){
                            break;
                        }
                    }
                    nOW = 1;
                }
                k++;
                std::cout<< "1) k is " << k << std::endl;
            } else {
                nOW = 1;
                k++;
                std::cout<< "2) k is " << k << std::endl;
            }
        }

        std::cout << k << std::endl;
        k = nums.size();
        return k;

        //if next element is the same as previous, nOE++
        //if nOW > 2, delete local element
        //grab next element and copy value into current position

        //return k elements





    }
};