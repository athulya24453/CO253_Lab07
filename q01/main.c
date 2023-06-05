#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int find_index(int arr[], int n, int ele) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele)
            return i;
    }
    return -1;
}

int lilysHomework(int* arr, int arr_count) {
    int s_Array[arr_count];
    bool visited[arr_count];
    int count = 0;

    for (int i = 0; i < arr_count; i++) {
        s_Array[i] = arr[i];
        visited[i] = false;
    }

    for (int i = 0; i < arr_count - 1; i++) {
        for (int j = 0; j < arr_count - i - 1; j++) {
            if (s_Array[j] > s_Array[j + 1]) {
                int temp = s_Array[j];
                s_Array[j] = s_Array[j + 1];
                s_Array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < arr_count; i++) {
        if (visited[i] || arr[i] == s_Array[i])
            continue;

        int c = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = find_index(s_Array, arr_count, arr[j]);
            c++;
        }

        if (c > 0)
            count += c - 1;
    }

    return count;
}

int main() {
    int arr[] = {1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int swaps = lilysHomework(arr, n);
    printf("%d", swaps);

    return 0;
}
