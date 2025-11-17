#include <stdio.h>
#include <stdlib.h>

// Function to find two indices that add up to target
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL; // No solution found
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);
    if (result) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    }
    return 0;
}

// What I learned: This is a brute force approach, O(n^2). Better ways use hash map for O(n).
// Compared to others: Many use hash table in C with structs or arrays.
