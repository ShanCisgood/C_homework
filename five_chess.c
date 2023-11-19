#include <stdio.h>
#include <stdlib.h>
int board[19][19] = {0};  // black: 1, white: 2
int in_range(int a, int b) { return (a >= 0 && a <= 18) && (b >= 0 && b <= 18); }
void check_line(int nx, int ny) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 19; i++)
        cnt1 += (board[i][ny] > 0);
    for (int i = 0; i < 19; i++)
        cnt2 += (board[nx][i] > 0);
    printf("%d:%d %d:%d\n", nx, cnt2, ny, cnt1);
}
int terminal_condition() {
    // x axis
    for (int i = 0; i < 19; i++) {
        int cnt = 0, tic = 0, mx = -1;  // count longest continuous subsequence
        for (int j = 0; j < 18; j++) {
            if (board[i][j] && board[i][j] == board[i][j + 1]) {
                cnt++;
                if (mx < cnt) {
                    mx = cnt;
                    tic = board[i][j];
                }
            }
            else
                cnt = 0;
        }
        if (mx + 1 >= 5)
            return tic;
    }
    // y axis
    for (int i = 0; i < 19; i++) {
        int cnt = 0, tic = 0, mx = -1;  // count longest continuous subsequence
        for (int j = 0; j < 18; j++) {
            if (board[j][i] && board[j][i] == board[j + 1][i]) {
                cnt++;
                if (mx < cnt) {
                    mx = cnt;
                    tic = board[j][i];
                }
            }
            else
                cnt = 0;
        }
        // printf(">>>>>>> i: %d mix: %d\n", i, mx);
        if (mx + 1 >= 5)
            return tic;
    }

    // slash: y = -x + 32, y = -x + 4
    //  Domain: [0, 18], Range: [0, 18]
    for (int i = 4; i <= 32; i++) {
        int cnt = 0, tic = 0, mx = -1;
        for (int j = 0; j < 19; j++) {
            int x = j, y = i - j;
            if (in_range(x, y) && in_range(x - 1, i - x + 1) && board[x][y] &&
                board[x][y] == board[x - 1][i - (x - 1)]) {
                cnt++;
                if (mx < cnt) {
                    mx = cnt;
                    tic = board[x][y];
                }
            }
            else
                cnt = 0;
        }

        if (mx + 1 >= 5)
            return tic;
    }

    // slash: y = x + 18, y = x - 18
    //  Domain: [0, 18], Range: [0, 18]
    for (int i = -18; i <= 18; i++) {
        int cnt = 0, tic = 0, mx = -1;
        for (int j = 0; j < 19; j++) {
            int x = j, y = j + i;
            if (in_range(x, y) && in_range(x - 1, i + x - 1) && board[x][y] &&
                board[x][y] == board[x - 1][i + (x - 1)]) {
                cnt++;
                if (mx < cnt) {
                    mx = cnt;
                    tic = board[x][y];
                }
            }
            else
                cnt = 0;
        }
        // printf(">>>>>>> i: %d mix: %d\n", i, mx);
        if (mx + 1 >= 5)
            return tic;
    }
    return 0;
}
int main() {
    int x, y, tic = 1, ans;
    while (scanf("%d,%d", &x, &y) != EOF) {
        if (in_range(x, y) && !board[x][y]) {
            board[x][y] = tic * 1 + !tic * 2;
            check_line(x, y);
            ans = terminal_condition();
            // printf(">>>>>> ans: %d\n", ans);
            if (ans)
                break;
        }
        tic ^= 1;  // tic = 1: black turn, tic = 0: white turn
    }
    if (ans == 1)
        printf("black\n");
    else if (ans == 2)
        printf("white\n");

    return 0;
}
