//
// Created by epm04 on 08/02/2024.
//

/**
Problem:
 Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
 The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

 Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

 Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
 The remaining elements of nums are not important as well as the size of nums.
 Return k.
 */

#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::map<int, int> m; //int key is vector element, second int value is number of occurances

        //account for edge cases
        if(nums.size() == 0){
            return 0;
        } else if (nums.size()==1){
            if(val == nums[0]){
                return 0;
            } else {
                return 1;
            }
        }

        //make map with nums input: key = int, value = how often int occurs
        for(int i = 0; i < nums.size(); i++){
            int ins = nums[i];
            if(m.find(ins) == m.end()){
                m.insert({ins, 1});
            }else{
                int occur = m.at(ins);
                occur++;
                std::map<int,int>::iterator it = m.find(ins);
                it->second=occur;
            }
        }

        //print map -optional
        for(std::map<int,int>::iterator it = m.begin(); it != m.end(); it++){
            std::cout << it->first << " " << it->second << std::endl;
        }

        //if the val is in map, erase is and clear vector, else return size of vector and unchanged nums
        if(m.find(val) != m.end()){
            m.erase(val);
            nums.clear();
        } else {
            return nums.size();
        }

        //fill vector with int values based of how often they occur
        for(std::map<int,int>::iterator it = m.begin(); it != m.end(); it++){

            std::cout << it->first << " " << it->second << std::endl;
            int element = it->first;
            int times = it->second;

            for(int i = 0; i < times; i++){
                nums.push_back(element);
            }
        }

        int k = nums.size();

        return k;


    }
};