#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int** triplets = (int**)malloc(sizeof(int*) * (numsSize*(numsSize-1)*(numsSize-2)/6)); // maximum number of triplets
    int tripletCount = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                triplets[tripletCount] = (int*)malloc(sizeof(int) * 3);
                triplets[tripletCount][0] = nums[i];
                triplets[tripletCount][1] = nums[left];
                triplets[tripletCount][2] = nums[right];
                tripletCount++;
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    *returnSize = tripletCount;
    *returnColumnSizes = (int*)malloc(sizeof(int) * tripletCount);
    for (int i = 0; i < tripletCount; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return triplets;
}

int main() {
    int nums[] = {-1, 0, 1, 3, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;
    int** triplets = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", triplets[i][0], triplets[i][1], triplets[i][2]);
        free(triplets[i]);
    }
    free(triplets);
    free(returnColumnSizes);
    return 0;
}
