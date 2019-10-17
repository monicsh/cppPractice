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
 Problem Statement- Given a list of intervals, merge all the overlapping intervals to produce
 a list that has only mutually exclusive intervals.
 */
class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

static bool myCompare(Interval& a, Interval& b)
{
    if (a.start < b.start)
        return true;

    return false;
}

class InsertInterval {
public:
    static vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> mergedIntervals;

        // Find the position : in the start? in the end? or somewhere in middle before an item
        int idx = findPositionForNewInterval();

        // Check whether it is overlapped with its neighbors


        // Update mergedIntervals

//        mergedIntervals.push_back(intervals[0]);
//        int write = 0;
//        for(auto i=1; i < intervals.size(); i++)
//        {
//            Interval currIter = intervals[i];
//            if (mergedIntervals[write].end >= currIter.start)
//            {
//                // Overlapped
//                mergedIntervals[write].end = max(mergedIntervals[write].end, currIter.end);
//
//            } else {
//                // Disjoint
//                mergedIntervals.push_back(currIter);
//                write++;
//            }
//        }

        return mergedIntervals;
    }
};

bool operator==(const vector<Interval>& a, const vector<Interval>& b){

    for(auto i=0; i<a.size(); i++)
     {
         Interval I1 = a[i];
         Interval I2 = b[i];
         if (I1.start != I2.start || I1.end != I2.end)
             return false;
     }

    return true;
}

TEST_CASE("MergeIntervals test cases 000", "[merge]"){
    vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
    vector<Interval> actual = InsertInterval::insert(input, {4, 6});

    vector<Interval> expected = {{1, 3}, {4, 7}, {8, 12}};

    REQUIRE(actual.size() == expected.size());
    REQUIRE(actual == expected);
}

TEST_CASE("MergeIntervals test cases 000", "[merge]"){
    vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
    vector<Interval> actual = InsertInterval::insert(input, {4, 10});

    vector<Interval> expected = {{1, 3}, {4, 12}};

    REQUIRE(actual.size() == expected.size());
    REQUIRE(actual == expected);
}

TEST_CASE("MergeIntervals test cases 000", "[merge]"){
    vector<Interval> input = {{2, 3}, {5, 7}};
    vector<Interval> actual = InsertInterval::insert(input, {1, 4});

    vector<Interval> expected = {{1, 4}, {5, 7}};

    REQUIRE(actual.size() == expected.size());
    REQUIRE(actual == expected);
}

