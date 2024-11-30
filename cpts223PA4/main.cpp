#include <iostream>
#include <vector>
#include <chrono>
#include <random>

class SortingComparison {
public:
    // insrtion sort
    void insertionSort(std::vector<int>& arr) {
        for (int i=1;i<(int)arr.size(); i++) {
            int hold=std::move(arr[i]);
            int m=0;
            for (m=i;m>0&&hold<arr[m-1];m--) {
                arr[m]=std::move(arr[m-1]);
            }
            arr[m]=std::move(hold);
        }
    }

    // quick sort -> With the given function definition, we can skip the driver function
    // and go directly into main private helper functions
    void quickSort(std::vector<int>& arr, int left, int right) {
        // after the unsorted size drops below the cutoff, switch sorting
        // methods to preserve efficiency
        if (left+10<=right){
            const int & pivot= median3(arr,left,right);
            int i=left,m=right-1;
            for(;;) {
                while(arr[++i]<pivot) {}
                while (pivot<arr[--m]) {}
                if (i<m) std::swap(arr[i],arr[m]);
                else break;
            }
            std::swap(arr[i],arr[right-1]);

            quickSort(arr,left,i-1);
            quickSort(arr,i+1,right);
        }
        else insertionSort(arr);
    }

    // merge sort
    void mergeSort(std::vector<int>& arr, int left, int right) {
        std::vector<int> tempArr(arr.size());
        mergeSort(arr,tempArr,left,right);
    }

    // generate random integers
    std::vector<int> generateRandomArray(int size) {
        std::vector<int> arr(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 100000);
        for (int& x : arr) {
            x = dist(gen);
        }
        return arr;
    }

    // test sorted
    bool isSorted(const std::vector<int>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // comparison run time for three sorting algorithms
    void compareSortingAlgorithms() {
        std::vector<int> sizes = {1000, 10000, 100000}; // data scales
        for (int size : sizes) {
            std::vector<int> arr = generateRandomArray(size);
            
            std::cout << "Data size: " << size << "\n";

            // test insertion sort
            std::vector<int> arr_copy = arr;
            auto start = std::chrono::high_resolution_clock::now();
            insertionSort(arr_copy);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "Insertion Sort: " << elapsed.count() << " seconds\n";
            std::cout << "Sorted: " << (isSorted(arr_copy) ? "Yes" : "No") << "\n";

            // test quick sort
            arr_copy = arr;
            start = std::chrono::high_resolution_clock::now();
            quickSort(arr_copy, 0, arr_copy.size() - 1);
            end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            std::cout << "Quick Sort: " << elapsed.count() << " seconds\n";
            std::cout << "Sorted: " << (isSorted(arr_copy) ? "Yes" : "No") << "\n";

            // test merge sort
            arr_copy = arr;
            start = std::chrono::high_resolution_clock::now();
            mergeSort(arr_copy, 0, arr_copy.size() - 1);
            end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            std::cout << "Merge Sort: " << elapsed.count() << " seconds\n";
            std::cout << "Sorted: " << (isSorted(arr_copy) ? "Yes" : "No") << "\n\n";
        }
    }

private:
    // Some internal helper functions
    void mergeSort(std::vector<int>& arr,std::vector<int>& tempArr, int left, int right){
        if (left<right) {
            int center =(left+right)/2;
            mergeSort(arr,tempArr,left,center);
            mergeSort(arr,tempArr,center+1,right);
            merge(arr,tempArr,left,center+1,right);
        }
    }

    void merge(std::vector<int>& arr,std::vector<int>& tempArr, int leftPos, int rightPos, int finish2) {
        int finish1=rightPos-1;
        int tempPos=leftPos;
        int noElemenets=finish2-leftPos+1;

        while(leftPos<=finish1&&rightPos<=finish2) {
            if(arr[leftPos]<=arr[rightPos]) tempArr[tempPos++]=std::move(arr[leftPos++]);
            else tempArr[tempPos++]=std::move(arr[rightPos++]);
        }

        // following 2 while loops complete the tempArr if any are left in the left or right arrays
        while (leftPos<=finish1) tempArr[tempPos++]=std::move(arr[leftPos++]);
        while (rightPos<=finish2) tempArr[tempPos++]=std::move(arr[rightPos++]);

        for (int i=0;i<noElemenets;i++,finish2--) arr[finish2]=std::move(tempArr[finish2]);
    }

    const int & median3(std::vector<int>& arr,int left,int right) {
        int center = (left+right)/2;
        if (arr[center<arr[left]]) std::swap(arr[left],arr[center]);
        if(arr[right]<arr[left]) std::swap(arr[left],arr[right]);
        if(arr[right]<arr[center]) std::swap(arr[right],arr[center]);

        std::swap(arr[center],arr[right-1]);
        return arr[right-1];
    }
};

int main() {
    SortingComparison sorter;
    sorter.compareSortingAlgorithms();
    return 0;
}
