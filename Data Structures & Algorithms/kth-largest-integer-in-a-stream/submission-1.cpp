class KthLargest {
    priority_queue<int ,vector<int>,greater<int>>h;
    int k_max;    
public:
    KthLargest(int k, vector<int>& nums) {
        k_max=k;

        for(int n:nums)add(n);
    }
    
    int add(int val) {
        h.push(val);

        if(h.size()>k_max){
            h.pop();
        }
        
        return h.top();
    }
};
