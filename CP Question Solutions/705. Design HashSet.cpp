class MyHashSet {
private: 
    vector<int> nums;
    int n = -1;

    int idx(int key){
        return (key/32);
    }

    int pos(int key){
        int k = (key%32);
        return 1<<k;
    }
public:

    MyHashSet() {
        nums = vector<int> (3125);
    }
    
    void add(int key) {
        if(key==1000000) n = 1;
        else{
            nums[idx(key)] |= pos(key);
        }
    }
    
    void remove(int key) {
        if(key==1000000) n = -1;
        else{
            nums[idx(key)] &= (~pos(key));
        }
    }
    
    bool contains(int key) {
        if(key==1000000) return n==1?true:false;
        return nums[idx(key)]&pos(key);
    }
};
