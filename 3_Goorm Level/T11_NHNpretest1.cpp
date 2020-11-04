// 수건돌리기 게임 //
#include <stdio.h>

int PNum, fastPNum;
int joinPNum[26];

int main() {
	
	scanf("%d", &PNum);
	scanf("%d", &fastPNum);
	
	for (int i = 0; i < fastPNum; ++i) {
		//scanf("%d", )
	}
}

// 주문표 변환하기 //
#include <stdio.h>

// order_sheet: 주문표 장수
int numberOfOrder;
// order_staff: 직원이 작성한 주문표
char orderArr[10];
// order_conv: 변환한 주문표
char orderConv[10];
int R, G, B;

int main() {
	scanf("%d", &numberOfOrder);
	
	for (int testcase = 0; testcase < numberOfOrder; ++testcase) {
		scanf("%s", &orderArr[testcase]);
		
		if (orderArr)
		
		printf("%s", orderConv[testcase]);
	}
}
#include <stdio.h>

// order_sheet: 주문표 장수
int numberOfOrder;
// order_staff: 직원이 작성한 주문표
char orderArr[10];
// order_conv: 변환한 주문표
char orderConv[10];
int R, G, B;

int main() {
	scanf("%d", &numberOfOrder);
	
	for (int testcase = 0; testcase < numberOfOrder; ++testcase) {
		scanf("%s", &orderArr[testcase]);
		
		if (orderArr)
		
		printf("%s", orderConv[testcase]);
	}
}


// 시멘트 양 계산하기 //

#include <stdio.h>
#include <string.h>

// T: 공사 기간 일수, W: 작업 영역의 너비
int time, width;
int arr[1000];

int main() {
  //int max = 0;
	int cement = 0;
	int max_left, max_right = 0;
	// left와 right 중 비교해서 작은 값 도출
	int comp_lr = 0;
	
	memset(arr, 0, sizeof(arr));
	
	scanf("%d", &time);
	scanf("%d", &width);
  
	for (int i = 0; i < time; ++i) {
		for (int j = 0; j < width; j++) {
			scanf("%d", &arr[j]);
			/*
			if (max < arr[j]) {
				max = arr[j];
			}
			*/
		}
	}
	for (int k = 0; k < width; k++) {
		// k가 10이면.. left는 0부터 10까지
		for (int left = 1; left <= k; ++left) {
			// width가 20이고 k가 10이면.. right는 0부터 10까지
			for (int right = 1; right <= width-k; ++right) {
				if((arr[k] >= arr[k-left]) || arr[k] >= arr[k+right]) continue;
				if((arr[k] < arr[k-left]) && (arr[k] < arr[k+right])) {
        	if (max_left < arr[k-left]) {
						max_left = arr[k-left];
					}
					if (max_right < arr[k+right]) {
						max_right = arr[k+right];
					}
					if (max_left > max_right) {
						comp_lr = max_right;
					} else {
						comp_lr = max_left;
					}
					
					//for (int exc = max_left+1; exc < max_right; ++exc) {
						// 다음의 사항은 제외한다 - 좌측 시멘트 중복
					if (arr[k-left] >= max_right) {
						for (int num = arr[k-left]+1; num < max_right; ++num) {
							cement += comp_lr - arr[num];
							arr[num] = comp_lr;
						}
					}
					// 다음의 사항은 제외한다 - 우측 시멘트 중복
					else if (arr[k+right] >= max_left) {
						for (int num = max_left+1; num < arr[k+right]; ++num) {
							cement += comp_lr - arr[num];
							arr[num] = comp_lr;
						}
					} else {
						for (int num = max_left+1; num < max_right; ++num) {
							cement += comp_lr - arr[num];
							arr[num] = comp_lr;
						}
					}
					//}
				}
			}
  	}
	}
	printf("%d", cement);
}


//////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

// T: 공사 기간 일수, W: 작업 영역의 너비
int time, width;
int arr[1000];

int main() {
  //int max = 0;
	int cement = 0;
	int max_left, max_right = 0;
	// left와 right 중 비교해서 작은 값 도출
	int comp_lr = 0;
	
	memset(arr, 0, sizeof(arr));
	
	scanf("%d", &time);
	scanf("%d", &width);
  
	for (int i = 0; i < time; ++i) {
		for (int j = 0; j < width; j++) {
			scanf("%d", &arr[j]);
			/*
			if (max < arr[j]) {
				max = arr[j];
			}
			*/
		}
	}
	for (int k = 0; k < width; k++) {
		// k가 10이면.. left는 0부터 10까지
		for (int left = 1; left <= k; ++left) {
			// width가 20이고 k가 10이면.. right는 0부터 10까지
			for (int right = 1; right <= width-k; ++right) {
				if((arr[k] < arr[k-left]) && (arr[k] < arr[k+right])) {
        	if (max_left < arr[k-left]) {
						max_left = arr[k-left];
					}
					if (max_right < arr[k+right]) {
						max_right = arr[k+right];
					}
					if (max_left > max_right) {
						comp_lr = max_right;
					} else {
						comp_lr = max_left;
					}
					for (int num = max_left+1; num < max_right; ++num) {
						cement += comp_lr - arr[num];
					}
				}
			}
  	}
	}
	printf("%d", cement);
}

/*
#include <iostream>
#include <sstream>

using namespace std;

void solution(int day, int width, int **blocks) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.

}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}
*/