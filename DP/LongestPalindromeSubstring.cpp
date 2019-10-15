#import <stdio.h>
#import <string>
#import <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

    
string longestPalindrome(string s) {
        int n = s.size(); 
        
        if (n<=0)
            return "";
        
        int maxLen = 1;
        int start = 0;
        int end = 0;
        
        bool DP[n][n];
        // making DP, true to diagnal elements and false to others
        for(auto i=0; i<n; i++)
            for(auto j=0; j<n; j++)
                if(i == j)
                    DP[i][j] = true;
                else
                    DP[i][j] = false;
        
        
        // for length 2 substring
        for(auto i=0; i <n-1; i++)
            if (s[i] == s[i+1]){
                DP[i][i+1] = true;
                maxLen = 2;
                start = i;
                end = i+1;
            }
                
        // for length 3 onwards

        for(auto len=3; len<=n; len++){
            for(auto i=0; i<=n-len; i++){
                int l = i;
                int r = l + len -1;
                
                if (s[l] == s[r] && DP[l+1][r-1])
                {
                    DP[l][r] = true;
                    if (len > maxLen){
                        maxLen = len;
                        start = l;
                        end = r;
                    }
                    
                }
            }
        }
        
        return s.substr(start, end-start+1);
}


TEST_CASE("longestPalindrome test cases 001", "[longestPalindrome]"){
    REQUIRE( longestPalindrome("badab") == "badab");
    REQUIRE( longestPalindrome("badac") == "ada");
    REQUIRE( longestPalindrome("xabccbax") == "xabccbax");
    REQUIRE( longestPalindrome("xabbaywuvwaw") == "abba");

}

TEST_CASE("longestPalindrome test cases 002", "[longestPalindrome]"){
    REQUIRE( longestPalindrome("bad") == "b");
}

TEST_CASE("longestPalindrome test cases 003", "[longestPalindrome]"){
    REQUIRE( longestPalindrome("") == "");
}