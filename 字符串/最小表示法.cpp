#include <iostream>
#include <cstring>
using namespace std;
char s[1000005];
int max(int x,int y) {return x<y?y:x;}
int min(int x,int y) {return x<y?x:y;} 
int main() 
{
	scanf("%s",s);
	int i = 0,j = 1,k = 0;
	int len = strlen(s);
	while (k<len && i<len && j<len) {
		if (s[(i+k)%len] == s[(j+k)%len]) k++; 
		else {
			if (s[(i+k)%len] > s[(j+k)%len]) i = max(j+1,i+k+1);
			else j = max(i+1,j+k+1);
			k = 0;
		}
	}
	for (int t=0;t<len;t++) printf("%c",s[(min(i,j)+t)%len]); //取min:j后跳当且仅当开始的字符串更小，即此时i+k与j之间的字符串大于i串
	printf("\n");
	return 0;
}
