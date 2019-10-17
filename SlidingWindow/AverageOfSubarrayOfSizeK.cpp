#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <queue>
#include <unordered_map>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

class AverageOfSubarrayOfSizeK {
    public:
        static vector<double> findAveragesBruteForce(int K, const vector<int>& arr) {
            vector<double> result(arr.size() - K + 1);
            for (int i = 0; i <= arr.size() - K; i++)
            {
              // find sum of next 'K' elements
              double sum = 0;
              for (int j = i; j < i + K; j++) {
                sum += arr[j];
              }
              result[i] = sum / K;  // calculate average
            }

            return result;
        }

        static vector<double> findAverages(int K, const vector<int>& arr) {
            vector<double> result(arr.size() - K + 1);
            double windowSum = 0;
            int windowStart = 0;

            for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
              windowSum += arr[windowEnd];  // add the next element
              // slide the window, we don't need to slide if we've not hit the required window size of 'k'
              if (windowEnd >= K - 1) {
                result[windowStart] = windowSum / K;  // calculate the average
                windowSum -= arr[windowStart];        // subtract the element going out
                windowStart++;                        // slide the window ahead
              }
            }

            return result;
        }
};


TEST_CASE("AverageOfSubarrayOfSizeK test cases 001", "[findAverages]"){
    vector<double> actual =
        AverageOfSubarrayOfSizeK::findAverages(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});

    for(auto no : actual){
        cout<<no<<" ";
    }
    cout<<endl;
    vector<double> expected = {2.2, 2.8, 2.4, 3.6, 2.8};
    CHECK(actual == expected);
}

TEST_CASE("AverageOfSubarrayOfSizeK test cases 002", "[findAverages]"){
    vector<int> nums = {1, 3, 2, 6, -1, 4, 1, 8, 2};

    const auto pt1 = std::chrono::steady_clock::now();

    vector<double> actual1 = AverageOfSubarrayOfSizeK::findAverages(5, nums);

    const auto pt2 = std::chrono::steady_clock::now();
    const std::chrono::duration<double> dur_1 = pt2 - pt1;
    std::cout << "Time for Bruteforce " << dur_1.count() << " seconds" << std::endl;

    vector<double> actual2 = AverageOfSubarrayOfSizeK::findAveragesBruteForce(5, nums);

    const auto pt3 = std::chrono::steady_clock::now();
    const std::chrono::duration<double> dur_2 = pt3 - pt2;
    std::cout << "Time for SlidingWindow " << dur_2.count() << " seconds" << std::endl;

    vector<double> expected = {2.2, 2.8, 2.4, 3.6, 2.8};
    CHECK(((actual1 == expected) && (actual2 == expected)));
}

