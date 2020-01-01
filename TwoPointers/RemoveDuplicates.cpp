#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

/*
 Given an array of sorted numbers and a target sum,
 find a pair in the array whose sum is equal to the given target.
 */
class PairWithTargetSum {
public:
    static pair<int, int> search(const vector<int>& arr, int targetSum) {
        // Assert that array is not empty, single item

        // Assign two pointers
        int left = 0;
        int right = arr.size()-1;

        while(left < right){
            int currSum = arr[left] + arr[right];
            if ( currSum == targetSum)
                return make_pair(arr[left], arr[right]);

            if (currSum > targetSum)
                right--;

            if (currSum < targetSum)
                left++;
        }

        return make_pair(-1, -1);
    }
};

TEST_CASE("PairWithTargetSum TC000: Pair not found ", "[search]"){
    vector<int> input = {1, 2, 4, 6};
    int target = 9;

    pair<int, int> actual = PairWithTargetSum::search(input, target);
    pair<int, int> expected = {-1, -1};

    REQUIRE((actual.first == expected.first && actual.second == expected.second ));
}

TEST_CASE("PairWithTargetSum TC001: ", "[search]"){
    vector<int> input = {1, 2, 3, 4, 6};
    int target = 6;

    pair<int, int> actual = PairWithTargetSum::search(input, target);
    pair<int, int> expected = {2, 4};

    REQUIRE((actual.first == expected.first && actual.second == expected.second ));
}

TEST_CASE("PairWithTargetSum TC002: MIX Integer (Negative & Positive) ", "[search]"){
    vector<int> input = {-2, -1, 2, 3, 4, 6, 7};
    int target = 6;

    pair<int, int> actual = PairWithTargetSum::search(input, target);
    pair<int, int> expected = {-1, 7};

    REQUIRE((actual.first == expected.first && actual.second == expected.second ));
}

TEST_CASE("PairWithTargetSum TC003: Negative target ", "[search]"){
    vector<int> input = {-5, -3, -2, -1, 0};
    int target = -4;

    pair<int, int> actual = PairWithTargetSum::search(input, target);
    pair<int, int> expected = {-3, -1};

    REQUIRE((actual.first == expected.first && actual.second == expected.second ));
}
