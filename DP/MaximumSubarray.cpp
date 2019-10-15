#import <stdio.h>
#import <string>
#import <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int finalSum = nums[0];
        
        for(auto i=1; i<nums.size(); i++)
        {
            currSum = max (nums[i], currSum+nums[i]);
            
            if(currSum > finalSum)
                finalSum = currSum;
        }
        
        return finalSum;
    }



TEST_CASE("Maximum subarray test cases 001", "[maxSubArray]"){
    REQUIRE( longestPalindrome("badab") == "badab");
}

TEST_CASE("Maximum subarray test cases 002", "[maxSubArray]"){
    REQUIRE( longestPalindrome("badab") == "badab");
}

TEST_CASE("Maximum subarray test cases 003", "[maxSubArray]"){
    REQUIRE( longestPalindrome("badab") == "badab");
}