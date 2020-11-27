#include<bits/stdc++.h>
using namespace std;
vector<int> fenwick(1000,0);
void update(int i, int val, int limit){
   for(int j=i+1;j<=limit;j+=(j&(-j))){
       fenwick[j] += val;
   }
}
int squery(int i){
    int res = 0;
    for(int j=i+1;j>=1;j-=(j&(-j))){
        res += fenwick[j];
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        update(i,arr[i],arr.size());
    }
    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        if(ch == 'U'){
            int idx,num;
            cin>>idx>>num;
            int diff = num - arr[idx];
            update(idx,diff,arr.size());
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<squery(r)-squery(l-1)<<endl;
        }
    }
}
