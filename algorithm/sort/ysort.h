#include <vector>
using namespace std;

void swap(int &a, int&b){
    int temp = a;
    a = b;
    b = temp;
}


/*******************************************************/
// 1、冒泡排序
void Bubble(vector<int> &array){
    int len = array.size();
    for(int i = 0; i < len - 1; i++){    //大循环 控制遍历次数
        for(int j = 0; j < len - 1 - i; j++){   //小循环 控制遍历元素
            if(array[i] > array[i+1]){   //if >= it will not stable
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}

//-鸡尾酒排序
void CocktailSort(vector<int> &array){
    int left = 0;
    int right = array.size() - 1;  // 已减一
    while(left < right){
        for(int i = left; i < right; i++){
            if(array[i] > array[i+1])
                swap(array[i], array[i+1]);
        }
        right--;
        for(int i = right; i > left; i--){
            if(array[i] < array[i-1])
                swap(array[i], array[i-1]);
        }
        left++;
    }
}


/*******************************************************/
// 选择排序
void SelectionSort(vector<int> &array){
    int len = array.size();
    for(int i = 0; i < len; i++){
        int min_index = i;
        for(int j = i+1; j < len; j++){
            if(array[j] < array[min_index])
                min_index = j;
            if(min_index != i)
                swap(array[i], array[min_index]);
    }
}



/*******************************************************/
// 插入排序
void InsertionSort(vector<int> &array){
    int len = array.size();
    for(int i = 1; i < len; i++){
        int temp = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > temp){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

//二分插入排序
void BinaryInsertionSort(vector<int> &array){
    int len = array.size();
    for(int i = 1; i < len; i++){
        int temp = array[i];
        int right = i - 1;
        int left = 0;
        while(left <= right){  // 中止条件
            int mid = (left + right) / 2;
            if(array[mid] > temp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for(int j = i - 1; j >= left; j--)
            array[j+1] = array[j];
        array[left] = temp;
    }
}


// Shell 希尔排序
void ShellSort(vector<int> &array){
    int len = array.size();
    int d = 0;
    while(d <= len)
        d = d * 3 + 1;
    while(d >= 1){
        for(int i = d; i < len; i++){
            int j = i - d;
            int temp = array[i];
            while(j >= 0 && array[j] > temp){
                array[j+d] = array[j];
                j = j - d;
            }
            array[j+d] = temp;
        }
        d = (d - 1) / 3;
    }
}


/*******************************************************/
// 归并排序

// 合并两个已排序数组
void Merge(vector<int> &array, int left, int mid, int right){ //
    int len = right - left + 1;
    int *temp = new int[len];
    int index = 0;                          // 辅助空间的索引
    int i = left;                           // 前一数组的索引
    int j = mid + 1;                        // 后一数组的索引
    while(i <= mid && j <= right)           // 谁小先取谁
        temp[index++] = array[i] > array[j] ? array[i++] : array[j++];
    while(i <= mid)                         // 补充未取元素
        temp[index++] = array[i++];
    while(j <= right)
        temp[index++] = ayyay[j++];
    for(int k = 0; k < len; k++)
        array[left+k] = temp[k];
    delete[] temp;
}

void MergeSortRecursion(vector<int> &array, int left, int right){
    if(left == right)                       // 递归中止条件
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(array, left, mid);
    MergeSortRecuesion(array, mid + 1, right);
    Merge(array, left, mid, right);
}

void MergeSortIteration(vector<int> &array){
    int len = array.size();
    int left, mid, right;
    for(int i = 1; i < len; i *= 2){          // i 为每次步长
        left = 0;                             // 每次
        while(left + i < len){
            mid = left + i - 1;               // right = mid +i
            right = mid + i < len ? mid + i : len - 1;
            Merge(array, left, mid, right);
            left = right + 1; 
        }
    }
}

void (vector<int> &array){

    int len = array.size();
}



/*******************************************************/
// 堆排序
void Heapify(vector<int> &array, int i, int size){ // 从array[i]向下进行堆调整
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    int max = i;
    if(left_child < size && array[left_child] > array[max])
        max = left_child;
    if(right_child < size && array[right_child] > array[max])
        max = right_child;
    if(max != i){
        swap(array[max], array[i]);
        Heapify(array, max, size);              // 递归调用，继续从当前节点向下进行堆调整
    }
}
// 建堆 O(n)
void BuildHeap(vector<int> &array){
    int heap_size = array.size();
    for(int i = heap_size / 2 - 1; i >= 0; i--) // 从非叶节点开始向下调整
        Heapify(array, i, heap_size);
    return heap_size;
}
// 排序
void HeapSort(vector<int> &array){
    int heap_size = BuildHeap(array);            // 建立最大堆
    while(heap_size > 1){
        swap(array[0], array[--heap_size]);      // 将最大值移到最后
        Heapify(array,0,heap_size);              // 重新调整堆
    }
}


/*******************************************************/
// 快速排序
// 划分函数 返回中间元素的索引
int Partition(vector<int> &array, int left, int right){
    int pivot = array[right];
    int tail = left - 1;                // 小于基准元素的最后一个的索引
    for(int i = left; i < right; i++){
        if(array[i] <= pivot)           // 小于等于基准元素的放最后
            swap(array[++tail], ayyay[i]);
    }
    swap(array[++tail], pivot);         // 将基准元素放到最后一个元素后面
    return tail;
}

// 初始值为 0, size() - 1
void QuickSort(vector<int> &array, int left, int right){
    if(left >= right)
        return;
    int index = Partition(array, left, right);
    QuickSort(array, left, index - 1);
    QuickSort(array, index + 1, right);
}

/*******************************************************/
// 计数排序
const int k = 100;              // 要求数组里数字均小于k [0, 99]
int C[k];
void CountingSort(vector<int> &array){
    int len = array.size();
    for(int i = 0; i < k; i++)      // 初始化，将数组C中的元素置0
        C[i] = 0;
    for(int i = 0; i < len; i++)    // 使C[i]保存着等于i的元素个数
        C[array[i]]++;
    for(int i = 0; i < k-1; i++)    // 使C[i]保存着小于等于i的元素个数，排序后元素i就放在第C[i]个输出位置上
        C[i+1] += C[i];
    int *B = new int[len];
    for(int i = len - 1; i > 0; i++)  // 从后往前排 不破坏稳定性
        B[--C[array[i]]] = array[i];
    for(int i = 0; i < len; i++)
        array[i] = B[i];
    delete[] B;
}

/*******************************************************/
// 排序
void (vector<int> &array){
    int len = array.size();
}

/*******************************************************/
// 排序
void (vector<int> &array){
        int len = array.size();
}