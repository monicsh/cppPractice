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

class MergeIntervals {
public:
    static vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> mergedIntervals;

        // Sort Intervals list on start field
        sort(intervals.begin(), intervals.end(), myCompare);

        mergedIntervals.push_back(intervals[0]);
        int write = 0;
        for(auto i=1; i < intervals.size(); i++)
        {
            Interval currIter = intervals[i];
            if (mergedIntervals[write].end >= currIter.start)
            {
                // Overlapped
                mergedIntervals[write].end = max(mergedIntervals[write].end, currIter.end);

            } else {
                // Disjoint
                mergedIntervals.push_back(currIter);
                write++;
            }
        }

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
    vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
    vector<Interval> actual = MergeIntervals::merge(input);

    vector<Interval> expected = {{1, 5}, {7, 9}};

    REQUIRE(actual == expected);
}

TEST_CASE("MergeIntervals test cases 001", "[merge]"){
    vector<Interval> input = {{1, 3}, {3, 5}, {7, 9}};
    vector<Interval> actual = MergeIntervals::merge(input);

    vector<Interval> expected = {{1, 5}, {7, 9}};

    REQUIRE(actual == expected);
}

TEST_CASE("MergeIntervals test cases 002", "[merge]"){
    vector<Interval> input = {{6, 7}, {2, 4}, {5, 9}};
    vector<Interval> actual = MergeIntervals::merge(input);
    vector<Interval> expected = {{2, 4}, {5, 9}};

    REQUIRE(actual == expected);
}

TEST_CASE("MergeIntervals test cases 003", "[merge]"){
    vector<Interval> input = {{1, 4}, {2, 6}, {3, 5}};
    vector<Interval> actual = MergeIntervals::merge(input);
    vector<Interval> expected = {{1, 6}};

    REQUIRE(actual == expected);
}

TEST_CASE("MergeIntervals test cases 004 -- Test Size", "[merge]"){
    vector<Interval> input = {{1, 4}, {2, 6}, {3, 5}};
    vector<Interval> actual = MergeIntervals::merge(input);
    vector<Interval> expected = {{1, 3}};

    REQUIRE(actual.size() == expected.size());
}

TEST_CASE("MergeIntervals test cases 005", "[merge]"){
    vector<Interval> input = {{1, 4}, {2, 6}, {3, 5}};
    vector<Interval> actual = MergeIntervals::merge(input);
    vector<Interval> expected = {{1, 5}};

    REQUIRE(actual.size() == expected.size());
    REQUIRE(!(actual == expected));
}


