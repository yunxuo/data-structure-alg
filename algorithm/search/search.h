#include <vector>


/***************************************************/
// 1、顺序查找
int SequenceSearch(vector<int> array, int value){
    int len = array.size();
    for(int i = 0; i < len; i++){
        if(array[i] == value)
            return i;
    }
    return -1;
}



/***************************************************/
// 1、二分查找
int BinarySearch(vector<int> &array, int value){
    int len = array.size();
    sort(array.begin(), array.end());
    int left = 0, right = len - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(array[mid] == value)
            return mid;
        if(array[mid] > value)
            right = mid - 1;
        if(array[mid] < value)
            left = mid + 1;
    }
    return -1;
}

int BinarySearch(vector<int> &array, int value, int low, int high){
    if(low > high) 
        return -1;
    int mid = (low + high) / 2;
    if(array[mid] == value)
        return mid;
    if(array[mid] < value)
        return BinarySearch(array, value, mid + 1, high);
    if(array[mid] > value)
        return BinarySearch(array, value, low, mid - 1);
}



/***************************************************/
// 3、插值查找
int InsertionSearch(vector<int> &array, int value, int low, int high){
    if(low > high) 
        return -1;
    // 只更改mid 的调整位置，使他更接近vale
    int mid = low + (value-array[low])/(array[high]-array[low])*)(high-low);
    if(array[mid] == value)
        return mid;
    if(array[mid] < value)
        return BinarySearch(array, value, mid + 1, high);
    if(array[mid] > value)
        return BinarySearch(array, value, low, mid - 1);
}



/***************************************************/
// 4、Fibonacci查找
const int max_size = 20; // Fibonacci max length

int SequenceSearch(vector<int> array, int value){
    int len = array.size();
    int low = 0;
    int high = len - 1;
    vector<int> F(max_size); // 构造一个斐波那契数组F 
    int k = 0;
    while(len > F[k] - 1)    // 计算n位于斐波那契数列的位置
        k++;
    vector<int> temp(F[k] - 1); // 将数组a扩展到F[k]-1的长度
    for(int i = 0; i < F[k] - 1; i++){
        if(i < len)
            temp[i] = array[i];
        temp[i] = array[len-1];
    }
    while(low <= high){
        int mid = low + F[k-1]-1;
        if(value > temp[mid]){
            low = mid + 1;
            k = k - 2;  // 参考上图 根据mid-high之间的元素数
        }
        else if(value < temp[mid]){
            high = mid - 1;
            k = k - 1;
        }
        else{
            if(mid < n)
                return mid;
            else
                return -1;
        }
    }
    return -1;
}

void Fibonacci(vector<int> F){
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i < F.size(); i++){
        F[i] = F[i-1] + F[i-2];
    }
}



/***************************************************/
// 5、二叉查找树 查找
int SequenceSearch(vector<int> array, int value){
    int len = array.size();
    for(int i = 0; i < len; i++){
        
    }
}




/***************************************************/
// 1、顺序查找
int SequenceSearch(vector<int> array, int value){
    int len = array.size();
    for(int i = 0; i < len; i++){
        
    }
}




/***************************************************/
// 1、顺序查找
int SequenceSearch(vector<int> array, int value){
    int len = array.size();
    for(int i = 0; i < len; i++){
        
    }
}




/***************************************************/
// 1、顺序查找
int SequenceSearch(vector<int> array, int value){
    int len = array.size();
    for(int i = 0; i < len; i++){
        
    }
}




/***************************************************/
// 1、顺序查找
int SequenceSearch(vector<int> array, int value){
    int len = array.size();
    for(int i = 0; i < len; i++){
        
    }
}


