#include <stdio.h>
#include <stdlib.h>


int* runningSum(int* nums, int numsSize, int* returnSize) 
{
    *returnSize = numsSize;
    for ( int i = 1; i < numsSize; i++ )
    {
        nums[ i ] += nums[ i - 1 ]; 
    }
    return nums;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* resultado = runningSum(nums, numsSize, &returnSize);

    printf("Resultado:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
