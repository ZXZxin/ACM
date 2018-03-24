#include <cstdio>
#include <iostream>
using namespace std;
int v[4]={3,4,5,6};

int gcd(int a,int b){ //a是更大的
    return b == 0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int ngcd(int v[],int n){
    if(n == 1) return v[0];
    return gcd(v[n-1],ngcd(v,n-1));
}
int nlcm(int v[],int n){
    if(n == 1) return v[0];
    return lcm(v[n-1],nlcm(v,n-1));
}
int main(){
    printf("%d\n",ngcd(v,4));
    printf("%d",nlcm(v,4));
    return 0;
}
