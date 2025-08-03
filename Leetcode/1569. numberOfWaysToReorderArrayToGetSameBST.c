#define MOD 1000000007
long long combinationsTable[1001][1001];

long long possibleComb( int total, int subSize ){
    return combinationsTable[total][subSize];
}

void pascalTriangle( int max ){
 for (int i = 0; i <= max; i++) {
        combinationsTable[i][0] = 1; 
        for (int j = 1; j <= i; j++) {
            combinationsTable[i][j] = (combinationsTable[i-1][j-1] + combinationsTable[i-1][j]) % MOD;
        }
    }
}
int numOfWaysCounter( int* nums, int numsSize ){
    if( numsSize == 1 || numsSize == 0 ) return 1;

    int subArrayLess[numsSize];
    int subArrayMore[numsSize];

    int smallerSize = 0;
    int biggerSize = 0; 

    for( int i = 1; i < numsSize; i++ ){
        if( nums[i] < nums[0] && nums[i] != 0 ){
            subArrayLess[smallerSize++] = nums[i];
        } else if( nums[i] > nums[0] && nums[i] != 0 ){
            subArrayMore[biggerSize++] = nums[i];
        }
    }
 
    int total = smallerSize + biggerSize;

    long long combinations = possibleComb( total, smallerSize);
    long long leftWays = numOfWaysCounter(subArrayLess, smallerSize);
    long long rightWays = numOfWaysCounter(subArrayMore, biggerSize);
    long long temp = ( combinations * leftWays ) % MOD;
    
    return ( temp * rightWays ) % MOD;
}

long long numOfWays( int* nums, int numsSize ) {
    long long result = 0;

    pascalTriangle( numsSize );
    result = numOfWaysCounter( nums, numsSize );
    

    return ( result - 1 + MOD ) % MOD;
}