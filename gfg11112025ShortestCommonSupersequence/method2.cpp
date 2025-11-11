#include<iostream>
using namespace std;

// using common sequence method
// dp tabulation
int minSuperSeq(string & s1, string & s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector < vector < int >> dp(n1, vector < int > (n2));
    for (int i1 = 0; i1 < n1; i1++) {
        for (int i2 = 0; i2 < n2; i2++) {
            if (i1 == 0 && i2 == 0) {
                dp[0][0] = (s1[0] == s2[0]);
            } else {
                int common = 0;
                if (i1 >= 1) {
                    common = max(common, dp[i1 - 1][i2]);
                }
                if (i2 >= 1) {
                    common = max(common, dp[i1][i2 - 1]);
                }
                if (s1[i1] == s2[i2]) {
                    common = max(common, 1);
                    if (i1 >= 1 && i2 >= 1) {
                        common = max(common, 1 + dp[i1 - 1][i2 - 1]);
                    } else {
                        common = max(common, 1);
                    }
                }
                dp[i1][i2] = common;
            }
        }
    }
    int common = dp[n1 - 1][n2 - 1];
    return n1 + n2 - common;
}