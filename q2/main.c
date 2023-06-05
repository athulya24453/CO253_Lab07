#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'activityNotification' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float findMedian(int arr[], int size) {

    qsort(arr, size, sizeof(int), compare);

    if (size % 2 == 1) {
        return arr[size / 2];
    } else {
        int mid1 = arr[size / 2 - 1];
        int mid2 = arr[size / 2];
        return (float)(mid1 + mid2) / 2.0;
    }
}

int activityNotification(int expenditure_count, int* expenditure, int d) {
    int count = 0;

    for (int i=d; i<expenditure_count; i++){
        int* temp_arr = (int*)malloc(i*sizeof(int));
        for (int j=0; j<i; j++){
           *(temp_arr+j) = expenditure[j];
        }

        int median = (int)findMedian(temp_arr, i);

        if (expenditure[i]>2*median){
            count++;
        }
        free(temp_arr);
    }
      return count;

}

int main() {
    int exp[] = {10,20,30,40,50};
    int c = 5;

    int ans = activityNotification(exp, c, 3);
    printf("%d", ans);
}


