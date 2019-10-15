#include <iostream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

class CyclicSort {
 public:
  CyclicSort(){}
  static int missingNumber(vector<int>& nums) {
    	int n = nums.size();
	int i =0;
	
	while(i<n){
        if (nums[i] == i)
	{
          	i++;
        } 
	else if(nums[i] == n)
	{
       		i++;
        }
	else 
	{
          int a = nums[i];
          nums[i] = nums[nums[i]];
          nums[a] = a;
        }	
      }

	for(auto j=0; j<n; j++)
	{
		if (nums[j] != j)
		{	
			return j;
		}
		
	} 

	return -1;
  }
};


TEST_CASE("sort sequence test cases 001", "[sort]"){
	vector<int> input = {4, 0, 3, 1};
	int expected = 2;

	CyclicSort* c = new CyclicSort();

    	REQUIRE(c->missingNumber(input) == expected);
}

TEST_CASE("sort sequence test cases 002", "[sort]"){
	vector<int> input = {0, 1, 2, 3};
	int expected = -1;

	CyclicSort* c = new CyclicSort();

    	REQUIRE(c->missingNumber(input) == expected);
}

TEST_CASE("sort sequence test cases 003", "[sort]"){
	vector<int> input = {8, 3, 5, 2, 4, 6, 0, 1};
	int expected = 7;

	CyclicSort* c = new CyclicSort();

    	REQUIRE(c->missingNumber(input) == expected);
}

TEST_CASE("sort sequence test cases 004", "[sort]"){
	vector<int> input = {1};
	int expected = 0;

	CyclicSort* c = new CyclicSort();

    	REQUIRE(c->missingNumber(input) == expected);
}


