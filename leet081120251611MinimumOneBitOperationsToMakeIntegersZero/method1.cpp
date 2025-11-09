// recursive
int minimumOneBitOperations(int n) {
    if(n == 0){
        return 0;
    }
    int curr = 1;
    int k = 0;
    
    while(2 * curr <= n){
        curr *= 2;
        k++;
    }
    return (1 << (k + 1)) - 1 - minimumOneBitOperations(n ^ curr);
}