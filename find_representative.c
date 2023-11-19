#include <stdio.h>
#include <stdlib.h>
#define MAXN 1005
int main() {
    int n, arr[MAXN], sums[MAXN] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i)
            sums[i] = sums[i - 1] + arr[i];
        else
            sums[i] = arr[i];
    }

    int l = 0, r = n - 1, l_sum, r_sum;
    while (l <= r) {
        if (l == r) {
            printf("%d\n", l);
            break;
        }
        int mid = ((r + l + 1) >> 1) - 1;
        l_sum = (sums[mid] - sums[l] + arr[l]) / (mid + 1 - l);
        r_sum = (sums[r] - sums[mid]) / (r - mid);
        if (l_sum >= r_sum)
            r = mid;
        else
            l = mid + 1;
    }

    return 0;
}
