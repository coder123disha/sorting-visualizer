#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h> // for Sleep()

using namespace std;

void printArray(const vector<int>& arr) {
    for (int val : arr) {
        for (int i = 0; i < val; i++) cout << "#";
        cout << " (" << val << ")";
        cout << endl;
    }
    cout << "-----------------" << endl;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            printArray(arr);
            Sleep(500); // sleep for 500ms
        }
    }
}

//insertion sort

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;

            printArray(arr);  // show progress
            cout << "Press Enter to continue...\n";
            cin.get();
        }
        arr[j + 1] = key;

        // Print after inserting key
        printArray(arr);
        cout << "Press Enter to continue...\n";
        cin.get();
    }
}
//merge sort

void merge(vector<int>&arr,int low,int mid,int high){

  int n1=mid-low+1;
  int n2=high-mid;

  vector<int>left(n1),right(n2);
  for(int i=0;i<n1;i++){
    left[i]=arr[low+i];
  }

  for(int j=0;j<n2;j++){
    right[j]=arr[mid+1+j];
  }

  int i=0;
  int j=0;
  int k=low;

  while(i<n1 && j<n2){
    if(left[i]<right[j]){
      arr[k]=left[i];
      i++;
    }else{
      arr[k]=right[j];
      j++;
    }
    k++;
    printArray(arr);
    cout<<"enter to contine...\n"<<endl;
    cin.get();
  }

  while(i<n1){
    arr[k]=left[i];
    i++;
    k++;
    printArray(arr);
    cout<<"enter to contine...\n"<<endl;
    cin.get();

  }
 while(j<n2){
    arr[k]=right[j];
    j++;
    k++;
    printArray(arr);
    cout<<"enter to contine...\n"<<endl;
    cin.get();

  }

  

}

void merge_Sort(vector<int>& arr,int low,int high){
  
    if(low<high){
    int mid=(low+high)/2;

    merge_Sort(arr,low,mid);
    merge_Sort(arr,mid+1,high);
   

    merge(arr,low,mid,high);
    
  }
}




int main() {
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    
    cout << "Original Array:\n";
    printArray(arr);
     
     int a;
    cout<<"Choose which Sorting algorithm u want"<<endl;
    cout<<"choose 1 for Bubble sort"<<endl;
    cout<<"choose 2 for insertion sort"<<endl;
    cout<<"choose 3 for merge sort"<<endl;
    cin>>a;
    switch(a){
               
      case 1: cout<<"Bubble sort"<<endl;
              bubbleSort(arr);
              break;
      case 2: cout<<"Insertiom Sort"<<endl;
              insertionSort(arr);
              break;
      case 3: cout<<"Merge Sort"<<endl;
              merge_Sort(arr,0,arr.size()-1);
              break;
    }

    cout << "Sorted Array:\n";
    printArray(arr);

    return 0;
}
