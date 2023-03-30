#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

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
    while (start < end) {
        int pivotIndex = partition(array, start, end);
        if (pivotIndex - start < end - pivotIndex) {
            quickSort(array, start, pivotIndex - 1);
            start = pivotIndex + 1;
        } else {
            quickSort(array, pivotIndex + 1, end);
            end = pivotIndex - 1;
        }
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
