#include <stdio.h>

int arr[1000];

int main() {
    int width = 0;
    
    // i: testcase
    for (int i = 0; i < 10; i++) {
        int cnt = 0;
        scanf("%d", &width);
        
        for (int j = 0; j < width; j++) {
            scanf("%d", &arr[j]);
        }
        for (int k = 2; k < width - 2; k++) {
            int max = 0;
            if((arr[k] > arr[k-1]) && (arr[k] > arr[k-2]) && (arr[k] > arr[k+1]) && (arr[k] > arr[k+2])) {
                if (max < arr[k-1])
                    max = arr[k-1];
                if (max < arr[k-2])
                    max = arr[k-2];
                if (max < arr[k+1])
                    max = arr[k+1];
                if (max < arr[k+2])
                    max = arr[k+2];
                cnt += arr[k] - max;
            }
        }
        printf("#%d %d\n", i+1, cnt);
        
        for (int n = 0; n < 1000; n++) {
            arr[n] = 0;
        }
    }
}