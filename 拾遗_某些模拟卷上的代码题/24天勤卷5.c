/*

2024天勤八套卷卷5 算法设计
思想：利用哈希的思想，设置一个两个数组统计这个字符串当中每个第一次出现和最后一次出现的位置，然后相减找出

*/
#include <stdio.h>
#include <string.h>

int GetTheFarest(char a[],int n){
	int firstAppear[128];
	int lastAppear[128];
	memset(firstAppear, -1, sizeof(firstAppear));
	memset(lastAppear, -1, sizeof(lastAppear));
	
	for(int i=0;i<n;i++){
		if(firstAppear[a[i]]<0){
			firstAppear[a[i]]=i;
		}
		lastAppear[a[i]]=i;
	}
	for(int i=0;i<128;i++){
		firstAppear[i]=lastAppear[i]-firstAppear[i];
	}
	int max=0;
	for(int i=0;i<128;i++){
		if(firstAppear[i]>max){
			max=firstAppear[i];
		}
	}
	return max;
}

void test(){
	char tes[]="KLabcLdecL";
	printf("%d",GetTheFarest(tes,strlen(tes)));
}

int main(){
	test();
}
/*
	时间复杂度O(n)
	空间复杂度O(1)
*/

