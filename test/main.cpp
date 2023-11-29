#include <iostream>
//this one is to enable you to write and compile code if you need to



int min_pos(int arr[], uint32_t size){
    int actual_size = sizeof(arr)/sizeof(arr[0]);
    if(size==1)return actual_size-size;
    int cur_index = actual_size-size;
    std::cout << actual_size << sizeof(arr) << std::endl;
    int cur_val = arr[cur_index];
    int min_index = min_pos(arr, size-1);
    int prev_val = arr[min_index];
    if(cur_val < prev_val) {
        return cur_index;
    }
    return min_index;
}

int main() {
    int temp [5] = {1,4,0,3,5};
    std::cout << sizeof(temp)/sizeof(int) << std::endl;
    std::cout << min_pos(temp, 5) << std::endl;
    return 0;
}


