//题目链接：https://vjudge.net/contest/169966#problem/D
//题目大意：给你一段打乱的字符串，中间[代表home键，[代表End键，求正确的文本
//解题思路：用链表或者STL中的 list容器 求解


//（1）
#include <stdio.h>
#include <iostream>
#include <list>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 100000+10;

char str[maxn];
int nxt[maxn];

int main(){
    while(cin>>str+1){
        //freopen("in.txt","r",stdin);
        int len = strlen(str+1);
        int cur,last;
        cur = last = 0;
        nxt[0] = 0;
        for(int i = 1; i <= len; i++){
            if(str[i] == '['){
                cur = 0;
            }
            else if(str[i] == ']'){
                cur = last;
            }
            else {
                nxt[i] = nxt[cur];//有点像链表插入的感觉，插入i
                nxt[cur] = i;
                if(cur == last)last = i;
                cur = i;
            }
        }
        for(int i = nxt[0]; i != 0; i = nxt[i]){
            printf("%c",str[i]);
        }
        cout<<endl;
    }
    return 0;
}


//（2）
#include <stdio.h>
#include <iostream>
#include <list>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 100000+10;

int main(){
    string s;
    while(cin>>s){
        int len = s.length();
        list<char>a;
        list<char>::iterator it = a.begin();
        for(int i = 0;i < len; i++){
            if(s[i] == '[')
                it = a.begin();
            else if(s[i] == ']')
                it = a.end();
            else {
                it = a.insert(it,s[i]);
                it++;
            }
        }
        for(it = a.begin(); it != a.end(); it++){
            cout<<*it;
        }
        cout<<endl;
    }
    return 0;
}
