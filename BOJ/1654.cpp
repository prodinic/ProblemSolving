#include <stdio.h>
#define MAX_VAL 2147483647
#define MAX_LEN 10001
#define ui unsigned int

// ui BinarySearch(int* N, int* K, int v[]) {
//     // 설명 : 이분 탐색을 수행합니다.

//     int k, i;   
//     ui answer = 0, left = 0, right = MAX_VAL, mid;
    
//     while(left <= right) {
//         mid = (left + right) / 2;
//         k = 0;
        
//         // 길이가 mid인 랜선의 합을 구합니다.
//         for (i = 0; i < *K; i++) {
//             k += v[i] / mid;
//         }   

//         // 모자를 경우, 길이를 줄입니다.
//         if (k < *N) {
//             right = mid - 1;
//         }
//         // 이미 충분한 경우, 길이를 늘립니다.
//         else {
//             answer = mid;
//             left = mid + 1;
//         }
//     }

//     return answer;
// }

int main() {

    int i, N, K;
    int v[MAX_LEN];

    scanf("%d %d", &K, &N);
    for (i = 0; i < K; i++) scanf("%d", v + i);
    
    int k;   
    ui answer = 0, left = 0, right = MAX_VAL, mid;
    
    while(left <= right) {
        mid = (left + right) / 2;
        k = 0;
        
        // 길이가 mid인 랜선의 합을 구합니다.
        for (i = 0; i < K; i++) {
            k += v[i] / mid;
        }   

        // 모자를 경우, 길이를 줄입니다.
        if (k < N) {
            right = mid - 1;
        }
        // 이미 충분한 경우, 길이를 늘립니다.
        else {
            answer = mid;
            left = mid + 1;
        }
    }

    printf("%u\n", answer);  // 정답을 출력합니다.
    return 0;
}