#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <queue>
#include <unordered_map>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

/*
 Given an array, find the average of all contiguous subarrays of size ‘K’ in it.
 */
class MaximumSumSubarray {
    public:
        static int maxSumSubarraySizeK(int K, const vector<int>& arr) {
            int maxSum = 0;
            int start = 0;
            int currSum = 0;

            for(auto end=0; end<arr.size(); end++)
            {
                currSum += arr[end];
                if(end >= K-1)
                {
                    maxSum = max(maxSum, currSum);
                    currSum -= arr[start];
                    start++;
                }
            }

            return maxSum;
        }
};


TEST_CASE("MaximumSumSubarray test cases 001", "[maxSum]"){
    int actual = MaximumSumSubarray::maxSumSubarraySizeK(3, vector<int>{2, 1, 5, 1, 3, 2});
    int expected = 9;

    REQUIRE(actual == expected);
}



