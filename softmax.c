#include <math.h>
#include <stdio.h>
double arr[5] = {0}, s, mn;
int is_same() {
    int flag = 1;
    for (int i = 1; i < 5; i++) {
        if (arr[i] != arr[i - 1]) {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main() {
    while (scanf("%lf,%lf,%lf,%lf,%lf", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]) != EOF) {
        mn = arr[0];
        if (is_same()) {
            printf("0.200,0.200,0.200,0.200,0.200\n");
        }
        else {
            for (int i = 0; i < 5; i++) {
                s = 0;
                for (int j = 0; j < 5; j++) {
                    s += exp(arr[j] - arr[i]);
                }
                printf("%.3lf", 1 / s);
                printf("%c", ",\n"[i == 4]);
            }
        }
    }
    return 0;
}
