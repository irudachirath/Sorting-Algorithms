#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    if (end <= start) return;
    int pivotIndex = partition(array, start, end);
    quickSort(array, start, pivotIndex-1);
    quickSort(array, pivotIndex+1, end);
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
    auto start = high_resolution_clock::now();
    quickSort(arr,0,length-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}
