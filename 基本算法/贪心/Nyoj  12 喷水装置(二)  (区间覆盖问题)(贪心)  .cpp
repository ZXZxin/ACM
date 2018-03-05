// ���串������
//��Ŀ���� : http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=12
//��Ŀ���� : ������
//����˼· : ������Ҫ����ͷ���ǵ�Բ�β���ת��Ϊһ�������϶�Ӧ��һ������Ȼ��ʹ�����串�ǵ�˼����
        /*���串������ : ���串������ :
        ��������n������[ai,bi]��ѡ�����ٵ����串��һ��ָ���߶�[s,t]��
        ̰�Ĳ��ԣ��Ѹ����䰴��a��С�������򣬴�ǰ��������Ȼ��ÿ��ѡ��ӵ�ǰ���S��ʼ������䣬
        �������������Ҷ˵�Ϊ�µ���㣬����ѡ��ֱ���Ҳ������串�ǵ�ǰ���S����S�Ѿ������߶�ĩ�ˡ�
        ��Ҫע����ǣ����ĳһ����߽����s,t�ı߽磬Ӧ�����Ǳ��s��t����Ϊ�����Ĳ��ֺ������壬ͬʱ����Ӱ������ݵķ�����*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int maxn = 10000 + 10;

struct Range{
    int l,r;
    bool operator < (const Range & rhs)const {
        return l < rhs.l;
    }
}rag[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int T,n,w,h,x,r;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&w,&h);
        for(int i = 0; i < n; i++){
            scanf("%d%d",&x,&r);
            if(r*r < (h/2)*(h/2)){i--,n--;continue;}
            rag[i].l = x - sqrt(r*r - (h/2)*(h/2));
            rag[i].r = x + sqrt(r*r - (h/2)*(h/2));
        }
        sort(rag,rag+n);
        double End = 0;
        int k = -1,cnt = 0;
        while(End < w && rag[k+1].l <= End){
            double maxx = -1;
            for(int i = k + 1; rag[i].l <= End && i < n; i++){ //�ҳ��Ҷ˵�����
                if(rag[i].r > maxx){
                    maxx = rag[i].r;
                    k = i;
                }
            }
            End = maxx; //����End
            cnt++;
        }
        printf("%d\n",End < w ? 0 : cnt);
    }
    return 0;
}
