#include <stdio.h>
#include <stdlib.h>
//// не сделано
void qsort_impl(int *arr, unsigned low, unsigned high) {
  if (low >= high) return;
  unsigned pi = partition(arr, low, high);
  if (pi > low) qsort_impl(arr, low, pi - 1);
  qsort_impl(arr, pi + 1, high);
}

void qsort(int *arr, unsigned len) {
  qsort_impl(arr, 0u, len - 1);
}

unsigned partition(int *arr, unsigned low, unsigned high) {
  
}