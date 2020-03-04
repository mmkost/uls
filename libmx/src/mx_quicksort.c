#include "../inc/libmx.h"

static void swap(char **arr1, char **arr2) {
    char *temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

static int *partition(char **arr, int left, int right, int *swap_count) {
    int low = left;
    int high = right;
    int middle = mx_strlen(arr[(low + (high - low) / 2)]);

    while (low < high) {
        while (mx_strlen(arr[low]) < middle) low++;
        while (mx_strlen(arr[high]) > middle) high--;
        if (low < high) {
            if (mx_strlen(arr[low]) != mx_strlen(arr[high])) {
                swap(&arr[low], &arr[high]);
                (*swap_count)++;
            }
            low++;
            high--;
        }
    }
    return (int[]) {low, high};
}

int mx_quicksort(char **arr, int left, int right) {
    int swap_count = 0;
    int low = left;
    int high = right;
    int *s;

    if (!arr && !*arr)
        return -1;

    s = partition(arr, low, high, &swap_count);
    low = s[LOW];
    high = s[HIGH];

    if (left < high)
        swap_count += mx_quicksort(arr, left, high);
    if (low == left) low++;
    if (low < right)
        swap_count += mx_quicksort(arr, low, right);

    return swap_count;
}

// int mx_quicksort(char **arr, int left, int right) {
//     if (arr && *arr)
//         return -1;

//     int swap = 0;
//     int low = left;
//     int high = right;
//     int middle = mx_strlen(arr[low + (high - low) / 2]);

//     while (low < high) {
//         while (mx_strlen(arr[low]) < middle) low++;
//         while (mx_strlen(arr[high]) > middle) high--;
//         if (low < high) {
//             if (mx_strlen(arr[low]) != mx_strlen(arr[high])) {
//                 swap++;
//                 char *tmp = arr[low];
//                 arr[low] = arr[high];
//                 arr[high] = tmp;
//             }
//             low++;
//             high--;
//         }
//     }

//     if (left < high)
//         swap += mx_quicksort(arr, left, high);

//     if (low == left) low++;

//     if (low < right)
//         swap += mx_quicksort(arr, low, right);
//     return swap;
// }
