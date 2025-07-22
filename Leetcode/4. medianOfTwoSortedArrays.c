double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mergedSize = nums1Size + nums2Size;
    int *newArray = ( int* ) malloc( sizeof( int ) * mergedSize );
    if( !newArray ){
        exit( 1 );
    }

    int i = 0;
    for( ; i < nums1Size; i++ ){
        newArray[i] = nums1[i];
    }
    for ( ; i < mergedSize; i++ ){
        newArray[i] = nums2[i - nums1Size];
    }

    int lower = 0;
    int temp = 0;
    for( int j = 0; j < mergedSize - 1; j++ ){
        lower = j;
        for( int k = j + 1; k < mergedSize; k++ ){
            if( newArray[lower] > newArray[k] ){
                lower = k;
            }
        }
        if( lower != j ){
            temp = newArray[lower];
            newArray[lower] = newArray[j];
            newArray[j] = temp;
        }
    }

    float median = 0;
    if( mergedSize % 2 == 0 ){
        median = ( float )( newArray[mergedSize / 2] + newArray[( mergedSize / 2 ) - 1] ) / 2.f;
    } else {
        median = newArray[mergedSize / 2];
    }
    return median;
}