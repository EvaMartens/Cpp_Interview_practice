//
// Created by epm04 on 05/02/2024.
//

/** Problem Description:

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that 
each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the 
result be placed in the first part of the array nums. More formally, if there are k elements after 
removing the duplicates, then the first k elements of nums should hold the final result. It does not 
matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place 
with O(1) extra memory.

**/

#include <iostream>
#include <vector>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        //-------------------------------
        //Constraints:
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
        //   ^

        for(int i = 1; i < nums.size(); i++){ //from second position to end
            if(nums[i] == nums[i - 1]){
                nOW++;
                std::cout << "Nums i is -> " << nums[i] << " and nOW is " << nOW << std::endl;
                if(nOW > 2){
                    while(nums[i] == nums[i-1]){
                        std::cout << nums[i] << " got erased" << std::endl;
                        nums.erase(nums.begin()+i-1);
                        if(i == nums.size()){ //makes sure we don't get index out of bounds error when deleting second to last element
                            break;
                        }
                    }
                    nOW = 1;
                }
                std::cout<< "1) k is " << k << std::endl;
            } else {
                nOW = 1;
                std::cout<< "2) k is " << k << std::endl;
            }
        }
        
        k = nums.size();
        return k;

    }
};
