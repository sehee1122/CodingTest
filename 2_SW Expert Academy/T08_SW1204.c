#include <stdio.h>
#include <string.h>

int score_count[101];
int score[1000];

int main() {
    int compare_score = 0;
    int T = 0;
    int max = 0;
    scanf("%d", &T);
    
    for (int testcase = 1; testcase <= T; ++testcase) {
        memset(score, 0, sizeof(score));
    	memset(score_count, 0, sizeof(score_count));
        scanf("%d", &testcase);
        
        for (int i = 0; i < 1000; ++i) {
            scanf("%d", &score[i]);
            ++score_count[score[i]];
        }
        for (int j = 0; j < 1000; ++j) {
        	if (score_count[score[j]] > max) {
            	max = score_count[score[j]];
                compare_score = score[j];
            }
            // score_count[i]: i = 0-100점까지 분포 배열
            // score_count[score[i]]: max = 점수 i를 가진 학생의 빈도수
            // score[i]: i번째 학생의 개인별 점수
            // compare_score: 최고 점수
			else if ((score_count[score[j]] == max) && (score[j] > compare_score)) {
                compare_score = score[j];
        	}
        }
        printf("#%d %d\n", testcase, compare_score);
        max = 0;
    }
    return 0;
}

/*
// ver.2
 morimori
제출일 : 2018-01-26 21:57
#include <stdio.h>
#include <memory.h>
int s_count[101];
int score[1000];
 
int main()
{
    int i,j;
    int testnum;
    int maxcount=0;
    int idx=0;
 
    memset(score,0,sizeof(score));
     
    for(j=0;j<10;j++)
    {
        scanf("%d",&testnum);
        for(i=0;i<1000;i++)
        {
            scanf("%d",&score[i]);
            s_count[score[i]]++;
             
            if(maxcount < s_count[score[i]])
            {
                maxcount = s_count[score[i]];
                idx = score[i];
            }
            else if(maxcount == s_count[score[i]])
            {
                if(idx < score[i])
                    idx = score[i];
            }
        }
        printf("#%d %d\n",testnum,idx);
        idx =0;
        maxcount = 0;
        memset(s_count,0,sizeof(s_count));
    }
    return 0;
}

// ver.1
#include<stdio.h>
int main(){
    int k,i,max,ind,num,cnt[1000];
    while (k != 10){
        scanf("%d", &k);
        for (i = 0; i < 1000; i++) cnt[i] = 0;
        max = 0;
        for (i = 0; i < 1000; i++){
            scanf("%d", &num);
            if (max <= ++cnt[num - 1]){
                max = cnt[num - 1];
                ind = num ;
            }
        }   
        printf("#%d %d\n",k ,ind);
    }
}
*/