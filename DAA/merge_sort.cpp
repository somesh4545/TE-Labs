#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int lArrSize = mid-start+1;
    int rArrSize = end-mid;

    int lArr[lArrSize];
    int rArr[rArrSize];
    for(int i=0; i<lArrSize; i++)
        lArr[i] = arr[start+i];
    for(int j=0; j<rArrSize; j++)
        rArr[j] = arr[mid+1+j];
    
    int i=0, j=0, index = start;
    while(i<lArrSize && j<rArrSize){
        if(lArr[i] > rArr[i]){
            arr[index++] = lArr[i++];
        }else{
            arr[index++] = rArr[j++];
        }
    }

    while(i<lArrSize) arr[index++] = lArr[i++];
    while(j<rArrSize) arr[index++] = rArr[j++];

    // cout << lArrSize << " " << rArrSize << endl;
}

void mergesort(int arr[], int start, int end){
    if(start>=end) return;

    int mid = (end+start)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    int arr[5] = {10, 2, 1, 4, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, 0, size-1);

    for(int i=0; i<size; i++) cout << arr[i] << " ";

    return 0;
}