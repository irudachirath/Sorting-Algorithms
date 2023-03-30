#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stack>

using namespace std;

int partition(int array[], int start, int end){
    int pivot = array[end];
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(array[j] < pivot){
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    i++;
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    return i;
}


void quickSort(int array[], int start, int end){
    stack<pair<int, int>> s;
    s.push(make_pair(start, end));
    while (!s.empty()) {
        int start = s.top().first;
        int end = s.top().second;
        s.pop();
        if (end <= start) continue;
        int pivotIndex = partition(array, start, end);
        s.push(make_pair(start, pivotIndex - 1));
        s.push(make_pair(pivotIndex + 1, end));
    }
}


int main(){
    srand(time(NULL));
    int length;
    cout << "Enter the array size - ";
    cin >> length;
    int arr[length];
    for (int a=0; a<length; a++){
        arr[a] = rand()%100;
    }
    quickSort(arr,0,length-1);
    for (int b = 0; b < length; b++){
        cout << arr[b] << " ";
    }
    return 0;
}
