#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

void SimpleMerge(int A[], int low, int mid, int high,int size) {
  int i = low, j = mid + 1, k = low;
  int B[size];
  while ((i <= mid) && (j <= high)) {
    if (A[i] < A[j])
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
  }

  while (j <= high)
    B[k++] = A[j++];
  while (i <= mid)
    B[k++] = A[i++];

  for (i = low; i <= high; i++)
    A[i] = B[i];
}

void MergeSort(int A[], int low, int high,int size) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    MergeSort(A, low, mid,size);
    MergeSort(A, mid + 1, high,size);
    SimpleMerge(A, low, mid, high,size);
  }
}

// Complete the maximumToys function below.
int maximumToys(int prices_count, int* prices, int k) {
    int i,j,temp;
    MergeSort(prices,0,prices_count-1,prices_count);
    i=0;
    while(i<prices_count)
    {
        if(k>0)
        {
            k-=prices[i];
            i++;
        }
        else
        break;
    }

    return i-1;

}
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nk = split_string(readline());

    char* n_endptr;
    char* n_str = nk[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char** prices_temp = split_string(readline());

    int* prices = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* prices_item_endptr;
        char* prices_item_str = *(prices_temp + i);
        int prices_item = strtol(prices_item_str, &prices_item_endptr, 10);

        if (prices_item_endptr == prices_item_str || *prices_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(prices + i) = prices_item;
    }

    int prices_count = n;

    int result = maximumToys(prices_count, prices, k);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
