//though we will be using monotonic stack, the way we use them here is little different.
//First we create a vector with sorted positions
//then we use the concept of monotonic stack and we start from the end
//we push the element in the stack and check if the stack has 2 or more elements
//if yes we compare last 2 elements to see if they make a fleet. if yes we take out the top element
//this we will be keeping atleast one car of a fleet in the stack.
//e.g let say we have 3 cars that will eventually make a fleet
// we check first 2. and pop() first car.
//the we check the next 2 and pop second car
//so whatever length of stack we are left with in the end is the answer
//remember to keep time as float.

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int,int>> comb(n);
        stack<float> s;
        for(int i=0; i<n;i++){
            comb[i] = {position[i],speed[i]};
        }
        sort(comb.begin(), comb.end());
        for(int i=n-1; i>=0; i--){
            float t = float(target-comb[i].first)/comb[i].second;
            // s.push(t);
            if(s.size()>=1 && t<=s.top()) continue;
            else s.push(t);
        }
        return s.size();
    }
};