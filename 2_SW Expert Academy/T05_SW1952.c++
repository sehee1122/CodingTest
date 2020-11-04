#include <stdio.h>
#include <string.h>
//#include <algorithm>
using namespace std;

int day, month1, month3, year;
int price[13];
int ans;
int dp[13];

int min(int a, int b) {
    return (a < b ? a : b);
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int testcase = 1; testcase <= T; ++testcase) {
        scanf("%d %d %d %d", &day, &month1, &month3, &year);
        memset(price, 0, sizeof(price));
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= 12; ++i) {
            scanf("%d", &price[i]);
        }
        // 1월 최소 금액
        dp[1] = min(price[1] * day, min(month1, month3));
        // 2월 최소 금액
        dp[2] = min(dp[1] + price[2] * day, min(dp[1] + month1, month3));

        // 일, 1달, 3달 비교
        for (int mon = 3; mon <= 12; mon++) {
            dp[mon] = min(dp[mon-1] + price[mon] * day, min(dp[mon-1] + month1, dp[mon-3] + month3));
        }
        // 1년 비교
        ans = min(dp[12], year);

        printf("#%d %d\n", testcase, ans);
    }
}

/*
//니르
//제출일 : 2017-10-20 22:06
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define INF 987654321
using namespace std;
 
int day, month1, month3, year;
int arr[13];
int ans;
int dp[13];
int main() {
 
    int T;
    scanf("%d",&T);
    for (int test = 1; test <= T; test++) {
        scanf("%d %d %d %d", &day, &month1, &month3, &year);
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 12; i++) {
            int a;
            scanf("%d",&arr[i]);
        }
        dp[1] = min(arr[1] * day, min(month1, month3));
        dp[2] = min(dp[1] + arr[2] * day, min(dp[1] + month1, month3));
        for (int i = 3; i <= 12; i++) {
            dp[i] = min(dp[i - 1] + arr[i] * day, min(dp[i - 1] + month1, dp[i - 3] + month3));
        }
        ans = min(dp[12], year);
        printf("#%d %d\n",test, ans);
    }
     
    return 0;
}

/*
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#define ALL_MON 12

// https://koreanfoodie.me/501
// 가장 적은 비용으로
// 이용권 종류에 따라 분류

int price[4];
int month[13];
//int firstPrice[13];
int secondPrice[13];

int MIN(int a, int b) {
    return (a < b) ? a : b;
}

int BFS(int firstPrice[13]) {
    int ret = -1;
    int threeMon[14];

    // MIN: 하루 요금 * 일수 or 한달 요금
    // 월간 최소값 저장
    for (int i = 1; i <= ALL_MON; ++i) {
        firstPrice[i] = MIN(price[0] * month[i], price[1]);
    }
    // 세달치 비교
    for (int j = 3; j <= ALL_MON; ++j) {
        //threeMon[j] = price[3];
        
        if (price[3] < firstPrice[j] + firstPrice[j-1] + firstPrice[j-2]) {
            firstPrice[j] = price[3]/3;
            firstPrice[j-1] = price[3]/3;
            firstPrice[j-2] = price[3]/3;
        }
    }
    if (price[3] < firstPrice[11] + firstPrice[12]) {
        firstPrice[11] = price[3]/2;
        firstPrice[12] = price[3]/2;
    }
    if (price[3] < firstPrice[12]) {
        firstPrice[12] = price[3];
    }
    
    // 1년 이용 비교

    //return ret;
}

int main() {
    int testcase = 0;
    scanf("%d", &testcase);

    for (int i = 1; i <= testcase; ++i) {
        // 이용권: 1일, 1달, 3달, 1년 이용권
        for (int pass = 0; pass < 4; ++pass) {
            scanf("%d", &price[pass]);
        }
        for (int mon = 1; mon <= ALL_MON; ++mon) {
            scanf("%d", &month[mon]);
        }
        int ret = BFS(price);
        printf("#%d %d", testcase, ret);
    }
}
*/