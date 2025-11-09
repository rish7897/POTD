// iterative
int minimumOneBitOperations(int n) {
    int ans = 0;
    int curr = 1;
    while(curr <= n){
        if((curr & n) != 0){
            ans = 2 * curr - 1 - ans;
        }
        curr *= 2;
    }
    return ans;
}