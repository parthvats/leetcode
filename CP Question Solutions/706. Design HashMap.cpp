class MyHashMap {
private: 
    vector<int> nums;
public:
    MyHashMap() {
        nums = vector<int> (1000001,-1);
    }
    
    void put(int key, int value) {
        nums[key] = value;
    }
    
    int get(int key) {
        return nums[key]==-1?-1:nums[key];
    }
    
    void remove(int key) {
        nums[key] = -1;
    }
};
