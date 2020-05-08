#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Memset(int *ptr, int val, size_t size);
int main() {
    int n;
    scanf("%d", &n);

      if(n >= 1 && n <= 1000){
          int amt = 2*n - 1;
          int *nums = calloc(amt, sizeof(int)), c = 0;

          Memset(nums, n, amt);
          for(int i = 0; i < amt; i++){
              if(i <= amt/2)
                  Memset(nums+i, n-i, amt-i*2);
              else {
                  Memset(nums + amt/2 - c, i-n+2, i*2-amt);
                  c++;
              }
              for(int j = 0; j < amt; j++){
                  printf("%d ", nums[j]);
              }
              printf("\n");
          }
          free(nums);
    }
    return 0;
}
void Memset(int *ptr, int val, size_t size){
    for(int i = 0; i < size; i++){
        *(ptr+i) = val;
    }
}