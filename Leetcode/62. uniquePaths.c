unsigned long long int uniquePaths(int m, int n) {
    unsigned long long int pathsNumber = 1;
    unsigned long long int total = ( m - 1 ) + ( n - 1 );
    int denominator = 0;
    int denomCut = 0;
    if( m > n ){ 
        denomCut = n - 1;
    } else{
        denomCut = m - 1;
    }
    unsigned long long int numerator = 1;
    for( int i = 0; i < denomCut; i++ ){
        pathsNumber = pathsNumber * ( total - i ) / ( i + 1 );
    }
    return pathsNumber;
}

