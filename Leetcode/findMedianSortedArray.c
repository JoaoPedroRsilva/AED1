#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mergedArray[nums1Size + nums2Size];
    int i = 0; int j = 0; int k = 0;

    while((i < nums1Size) && (j < nums2Size))
    {
        if(nums1[i] < nums2[j])
        {
            mergedArray[k] = nums1[i];
            i++;
            k++;
        } else 
        {
            mergedArray[k] = nums2[j];
            j++;
            k++;
        }
    }
    if(i == nums1Size) // Para caso sobre elementos em nums2
    {
        while(j < nums2Size)
        {
            mergedArray[k] = nums2[j];
            j++;
            k++;
        }
    }
    if(j == nums2Size) // Para caso sobre elementos em nums1
    {
        while(i < nums1Size)
        {
            mergedArray[k] = nums1[i];
            k++;
            i++;
        }
    }

    float media = 0;
    if(k % 2 == 0)
    {
        media = (float)(mergedArray[k/2] + mergedArray[(k/2) - 1]) / 2;

        return media;
    } else 
    {
        media = mergedArray[(k/2)];

        return media;
    }
}

int main() {
    int nums1[] = {1, 3, 5};
    int nums2[] = {2, 4, 6};

    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    double mediana = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    printf("A mediana dos arrays ordenados é: %.2f\n", mediana);

    return 0;
}
