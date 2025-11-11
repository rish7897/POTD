#include<iostream>
using namespace std;

// using common sequence method
// dp tabulation space optimisation
int minSuperSeq(string & s1, string & s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector < int > prev(n2);
    for (int i1 = 0; i1 < n1; i1++) {
        vector < int > curr(n2);
        for (int i2 = 0; i2 < n2; i2++) {
            if (i1 == 0 && i2 == 0) {
                curr[i2] = (s1[i1] == s2[i2]);
            } else {
                int common = 0;
                if (i1 >= 1) {
                    common = max(common, prev[i2]);
                }
                if (i2 >= 1) {
                    common = max(common, curr[i2 - 1]);
                }
                if (s1[i1] == s2[i2]) {
                    if (i1 >= 1 && i2 >= 1) {
                        common = max(common, 1 + prev[i2 - 1]);
                    } else {
                        common = max(common, 1);
                    }
                }
                curr[i2] = common;
            }
        }
        prev = curr;
    }
    return n1 + n2 - prev[n2 - 1];
}