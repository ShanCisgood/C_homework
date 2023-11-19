#include <stdio.h>
#include <stdlib.h>
int m, n, k = 0;
int used[15], arr[15], ans[15], tmp, matrix[200][16];
void sortMatrix() {
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j + i < k - 1; j++) {
            if (matrix[j][15] > matrix[j + 1][15]) {
                for (int ki = 0, t; ki < 16; ki++) {
                    t = matrix[j][ki];
                    matrix[j][ki] = matrix[j + 1][ki];
                    matrix[j + 1][ki] = t;
                }
            }
        }
    }
}
int check() {
    int cnt_odd = 0;
    for (int i = 0; i < n; i++)
        cnt_odd += (ans[i] & 1);
    return n - cnt_odd >= cnt_odd;
}
void dfs(int layer, int start) {
    if (layer == n) {
        if (!check())
            return;
        int cnt_even = 0;
        // printf("%d. ", k + 1);
        // for (int i = 0; i < n; i++)
        //     printf("%d%c", ans[i], ",\n"[i == n - 1]);
        for (int i = 0; i < n; i++) {
            matrix[k][i] = ans[i];
            cnt_even += (!(ans[i] & 1));
        }
        matrix[k++][15] = cnt_even;
        return;
    }
    for (int i = start; i < m; i++) {
        if (!used[i]) {
            if (!(!layer && (arr[i] & 1)))
                ans[layer] = arr[i];
            used[i] = 1;
            dfs(layer + 1, i + 1);
            used[i] = 0;
        }
    }
}
int main() {
    int cnt_odd = 0, cnt = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
        cnt_odd += (arr[i] & 1);
    }
    for (int i = 0; cnt < cnt_odd && i < m; i++) {
        if (arr[i] & 1) {
            tmp = arr[i];
            for (int j = i; j < m; j++)
                arr[j] = arr[j + 1];
            arr[m - 1] = tmp;
            cnt++;
            i--;
        }
    }
    // for (int i = 0; i < m; i++)
    //     printf("%d%c", arr[i], " \n"[i == m - 1]);
    dfs(0, 0);
    sortMatrix();
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%c", matrix[i][j], ",\n"[j == n - 1]);
        }
        // printf(">>>>%d\n", matrix[i][15]);
    }
    return 0;
}
