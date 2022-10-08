#include <bits/stdc++.h>
using namespace std;

void add(vector<int> &fen, int i, int value){
    // cout<<"add(fen,"<<i<<","<<value<<")"<<endl;
    while(i<fen.size()){
        fen[i] += value;
        i += i & (-i);
    }
}
int sum(vector<int> &fen, int i){
    int sum=0;
    while(i>0){
        sum += fen[i];
        i -= i & (-i);
    }
    return sum;
}
int rangeSum(vector<int> &fen, int l, int r){
    return sum(fen,r) + sum(fen,l-1);
}
void print(vector<int> &fen){
    cout<<"[";
    for(int i=0;i<fen.size();i++){
        cout<<fen[i]<<" ";
    }
    cout<<"]"<<endl;
}
int main(){
    vector<int> fen(11,0);
    vector<int> arr(10,1);
    for(int i=1; i<10; i++){
        arr[i] += arr[i-1];
    }
    print(arr);
    print(fen);
    for(int i=0; i<10; i++){
        add(fen,i+1,arr[i]);
    }
    print(fen);
    cout<<sum(fen,4)<<endl;
    cout<<rangeSum(fen,1,3)<<endl;
    return 0;
}