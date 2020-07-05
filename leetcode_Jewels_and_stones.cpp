// leetcode 771 Jewels and Stones
// Find the number of characters indicated in the J string from the S string 
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
int cmp(const void* p1, const void* p2){
    return *(char *)p1 - *(char *)p2;
}
int numJewelsInStones(char * J, char * S){ 
    int lenJ = strlen(J);
    int lenS = strlen(S);
    qsort(J, lenJ, sizeof(char), cmp);
    qsort(S, lenS, sizeof(char), cmp);
    int countJewel = 0, indexJewel=0;
    for (int i = 0; i < lenS; i++){
        while(S[i]>J[indexJewel]){
            indexJewel++;
            if(indexJewel>=lenJ){
                return countJewel;
            }
        }
        if(S[i]==J[indexJewel]){
            countJewel++;
        }
    }
    return countJewel;
}
int numJewelsInStones_fast_method(char * J, char * S){  // O(J)+O(S)
    int table[123] = {0}; // 97+25 = 122
    int count = 0;
    for (int i = 0; i<strlen(S); i++){
        table[(int)S[i]]++;
    }
    for (int i = 0; i< strlen(J); i++){
        count += table[(int)J[i]];
    }
    return count;
}
int main(){
    // char dataJ[] = "aA", dataS[] = "aAAbbbb";
    char J[] = "aA", S[] = "aAAbbbb";
    // char J[] = "z", S[] = "ZZ";
    // char *J = (char *)malloc(strlen(dataJ) * sizeof(char));
    // strcpy(J, dataJ);
    // char *S = (char *)malloc(strlen(dataS) * sizeof(char));
    // strcpy(S, dataS);
    // int ans = numJewelsInStones(J, S);
    int ans = numJewelsInStones_fast_method(J, S);
    printf("There are %d jewels in stones", ans);
    return 0;
}