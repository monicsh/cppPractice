#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"

using namespace std;

/*
 Problem Statement- Given a list of intervals, merge all the overlapping intervals to produce
 a list that has only mutually exclusive intervals.
 */
//bool operator==(const Interval& l1, const Interval& l2){
//
//    bool result;
//    result = (l1==l2);
//    return result;
//}

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
            if (mergedIntervals[write].end > currIter.start)
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


int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}


//TEST_CASE("MergeIntervals test cases 001", "[merge]"){
//    vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
//    vector<Interval> actual = MergeIntervals::merge(input);
//    vector<Interval> expected = {{1, 5}, {7, 9}};
//
//    REQUIRE(actual == expected);
//}

//TEST_CASE("MergeIntervals test cases 001", "[merge]"){
//    vector<Interval> input = {{6, 7}, {2, 4}, {5, 9}};
//    vector<Interval> actual = MergeIntervals::merge(input);
//    vector<Interval> expected = {{2, 4}, {5, 9}};
//
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("MergeIntervals test cases 001", "[merge]"){
//    vector<Interval> input = {{1, 4}, {2, 6}, {3, 5}};
//    vector<Interval> actual = MergeIntervals::merge(input);
//    vector<Interval> expected = {{1, 6}};
//
//    REQUIRE(actual == expected);
//}



