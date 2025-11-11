#include<iostream>
using namespace std;

// using common sequence method
// dp memoisation
int commonSequence(string & s1, string & s2, int i1, int i2, vector < vector < int >> & dp) {
    int n1 = s1.size();
    int n2 = s2.size();
    if (i1 == n1 || i2 == n2) {
        return 0;
    }
    if (dp[i1][i2] != -1) {
        return dp[i1][i2];
    }
    int common1 = commonSequence(s1, s2, i1 + 1, i2, dp);
    int common2 = commonSequence(s1, s2, i1, i2 + 1, dp);
    int ans = max(common1, common2);
    int common3 = 0;
    if (s1[i1] == s2[i2]) {
        common3 = 1 + commonSequence(s1, s2, i1 + 1, i2 + 1, dp);
    }
    ans = max(ans, common3);
    dp[i1][i2] = ans;
    return ans;
}
int minSuperSeq(string & s1, string & s2) {
    // code here
    int n1 = s1.size();
    int n2 = s2.size();
    vector < vector < int >> dp(n1, vector < int > (n2, -1));
    int common = commonSequence(s1, s2, 0, 0, dp);
    return n1 + n2 - common;
}