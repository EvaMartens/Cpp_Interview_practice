//
// Created by epm04 on 07/02/2024.
//

/**
 * PROBLEM DESCRIPTION - LEET CODE EASY
 *
 You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        //find the greatest difference in array
        // -> smallest number
        // -> largest number

        //buy 1 - (days -1)
        //sell - (buy + 1)

        //-----------------------------

        //max dif = 8
        //pos buy = 2
        //pos sell = 3
        int max_dif = 0;
        int pos_buy = prices[0];
        int pos_sell = -1;

        //[2,11,1,9,8,10,3,20]
        //               ^                 -buy
        //                  ^               -sell

/**
        if(prices.size() == 1){
            return 0;
        }

        for(int i = 1; i < prices.size(); i++){
            for(int j = i; j < prices.size(); j++){
                if(max_dif < (prices[j] - prices[i-1])){
                    max_dif = prices[j] - prices[i-1];
                    pos_buy = prices[i];
                    pos_sell = prices[j];
                }
            }
        }

        return max_dif;

        **/

        //----OTHER PEOPLES SOLUTIONS-----///

        /**
        int min_price = prices[0];
        int maxprof = 0;

        for(int i=1;i<prices.size();i++){
            maxprof = max(maxprof,prices[i]-min_price);
            min_price = min(prices[i],min_price);
        }

        return maxprof;
        **/

        int maxProfit = 0;
        int cheapest = std::numeric_limits<int>::max();
        for (auto price: prices) {
            cheapest = std::min(cheapest, price);
            maxProfit = std::max(maxProfit, price - cheapest);
        }
        return maxProfit;

    }
};