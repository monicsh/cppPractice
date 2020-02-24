#import <stdio.h>
#import <string>
#import <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

int LPS_Memo(string s, int start, int end) {
    if (start > end)
        return 0;

    if (start == end)
        return 1;

    if (s[start] == s[end])
        return 2 + LPS_Memo(s, start+1, end-1);
    else
        return max(LPS_Memo(s, start, end-1), LPS_Memo(s, start+1, end));
}

int LPS_Tab(string s) {
    int n = s.size();
    vector<vector<int>> DP(n, vector<int>(n, 0));

    for(int i=0; i<n;i++)
        DP[i][i] = 1;

    if ( s[i] == s[j] )
               DP[i][j] = 2 + DP[i-1][j-1];
           else
               DP[i][j] = max(DP[i][j-1], DP[i+1][j]);
    return DP[0][n-1];
}
    
int longestPalindromeSubsequence(string s) {
    //return LPS_Memo(s, 0, s.size()-1);

    return LPS_Tab(s);
}


TEST_CASE("longestPalindrome test cases 001", "[longestPalindrome]"){
    REQUIRE( longestPalindromeSubsequence("badab") == 5);
    REQUIRE( longestPalindromeSubsequence("badac") == 3);
    REQUIRE( longestPalindromeSubsequence("xabccbax") == 8);
    REQUIRE( longestPalindromeSubsequence("xabbaywuvwaw") == 5);

}

TEST_CASE("longestPalindrome very long string test cases 004", "[]"){
	REQUIRE(longestPalindromeSubsequence("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew") == 20);
}

TEST_CASE("longestPalindrome test cases 002", "[longestPalindrome]"){
    REQUIRE( longestPalindromeSubsequence("bad") == 1);
}

TEST_CASE("longestPalindrome test cases 003", "[longestPalindrome]"){
    REQUIRE( longestPalindromeSubsequence("") == 0);
}
