#include <iostream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

class CyclicSort {
 public:
  CyclicSort(){}
  static vector<int> allMissingNumbers(vector<int>& nums) {
    	int n = nums.size();
	vector<int> result;
	int i =0;
	
	while(i<n){
        if (nums[i] == i+1)
        {
          	i++;
            continue;
        }

        if (nums[i] > n || nums[i] < 1)
        {
            i++;
            continue;
        }

        if (nums[i] != i+1)
        {
            if (nums[nums[i] -1] == nums[i])
            {
                nums[i] = n + 1;
                i++;
            } else {
                int a = nums[i];

                nums[i] = nums[nums[i] - 1];
                nums[a - 1] = a;
            }
        }
	
      }

	for(auto j=0; j<n; j++)
	{
		if (nums[j] != j+1)
		{	
			result.push_back(j+1);
		}
		
	} 

	return result;
  }
};


TEST_CASE("sort sequence test cases 001", "[allMissingNumbers]"){
	vector<int> input = {2, 3, 1, 8, 2, 3, 5, 1};
	vector<int> expected = {4, 6, 7};

	CyclicSort* c = new CyclicSort();
    REQUIRE(c->allMissingNumbers(input) == expected);
}

TEST_CASE("sort sequence test cases 002", "[allMissingNumbers]"){
    vector<int> input = {2, 4, 1, 2};
    vector<int> expected = {3};

    CyclicSort* c = new CyclicSort();
    REQUIRE(c->allMissingNumbers(input) == expected);
}

TEST_CASE("sort sequence test cases 003", "[allMissingNumbers]"){
    vector<int> input = {2, 3, 2, 1};
    vector<int> expected = {4};

    CyclicSort* c = new CyclicSort();
    REQUIRE(c->allMissingNumbers(input) == expected);
}






