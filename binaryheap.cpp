#include<bits/stdc++.h>
using namespace std;
struct bheap{
    int *heap;
    int size;
    int length;
};
bheap* BinaryHeap(int n){
    bheap* x=new bheap;
    x->size=n;
    x->heap=new int[n];
    x->length=0;
    return x;
}
int isempty(bheap* x){
    if(x->length==0) return 1;
    return 0;
}
void insert(bheap* x,int y){
    x->heap[x->length]=y;
    int i=x->length,temp;
    while(i!=0){
        int k=(i-1)/2;
        if(x->heap[i]>x->heap[k]){
            temp=x->heap[i];
            x->heap[i]=x->heap[k];
            x->heap[k]=temp;
            i=k;
        }
        else{
            break;
        }
    }
    x->length++;
}
int findmax(bheap* x){
    if(isempty(x)==1) return 1;
    return x->heap[0];
}
int extractmax(bheap* x){
    if(isempty(x)==1) return -1;
    int temp=x->heap[0],z;
    int i=0;
    x->heap[0]=x->heap[x->length-1];
    while(2*i+1<x->length){
        if(2*i+1<x->length && 2*i+2<x->length){
            int k=(x->heap[2*i+1]>x->heap[2*i+2])?2*i+1:2*i+2;
            if(x->heap[i]<x->heap[k]){
                z=x->heap[i];
                x->heap[i]=x->heap[k];
                x->heap[k]=z;
                i=k;
            }
            else{
                break;
            }
        }
        else if(2*i+1<x->length){
            int k=2*i+1;
             if(x->heap[i]<x->heap[k]){
                z=x->heap[i];
                x->heap[i]=x->heap[k];
                x->heap[k]=z;
                i=k;
            }
            else{
                break;
            }
        }
    }
    x->length--;
    return temp;
}
int size(bheap* x){
    return x->length;
}
int main(){
    bheap* x=BinaryHeap(7);
    insert(x,23);
    insert(x,12);
    insert(x,19);
    insert(x,35);
    insert(x,33);
    insert(x,42);
    insert(x,25);
    cout<<extractmax(x)<<"\n";
    cout<<extractmax(x)<<"\n";
    for(int i=0;i<x->length;i++){
        cout<<x->heap[i]<<" ";
    }
}