#include <iostream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

class CyclicSort {
 public:
  CyclicSort(){}
  static void csort(vector<int>& nums) {
    	int n = nums.size();
	int i =0;
	
	while(i<n){
        if (nums[i] == i + 1){
          i++;
        } else {
          int a = nums[i];
          nums[i] = nums[nums[i] - 1];
          nums[a-1] = a;
        }	
      } 
  }
};


TEST_CASE("sort sequence test cases 001", "[sort]"){
	vector<int> input = {3, 1, 5, 4, 2};
	vector<int> expected = {1, 2, 3, 4, 5};

	CyclicSort* c = new CyclicSort();
	c->csort(input);

    	REQUIRE(input == expected);
}

TEST_CASE("sort sequence test cases 002", "[sort]"){
	vector<int> input = {1, 3, 5, 4, 2};
	vector<int> expected = {1, 2, 3, 4, 5};

	CyclicSort* c = new CyclicSort();
	c->csort(input);

    	REQUIRE(input == expected);
}

TEST_CASE("sort sequence test cases 003", "[sort]"){
	vector<int> input = {3, 1, 2, 4, 5};
	vector<int> expected = {1, 2, 3, 4, 5};

	CyclicSort* c = new CyclicSort();
	c->csort(input);

    	REQUIRE(input == expected);
}

TEST_CASE("sort sequence test cases 004", "[sort]"){
	vector<int> input = {4, 3, 2, 1};
	vector<int> expected = {1, 2, 3, 4};

	CyclicSort* c = new CyclicSort();
	c->csort(input);

    	REQUIRE(input == expected);
}

TEST_CASE("sort sequence test cases 005", "[sort]"){
	vector<int> input = {1, 2, 3, 4};
	vector<int> expected = {1, 2, 3, 4};

	CyclicSort* c = new CyclicSort();
	c->csort(input);

    	REQUIRE(input == expected);
}