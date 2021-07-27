import java.util.*;
class MinStack {
    int min;
    LinkedList<Integer> num; 
    /** initialize your data structure here. */
    public MinStack() {
        num= new LinkedList<Integer>();
    }
    
    public void push(int val) {
        num.add(val);
    }
    
    public void pop() {
        num.removeLast();
    }
    
    public int top() {
        return num.get(num.size()-1);
    }
    
    public int getMin() {
        int min=num.get(0);
        for(Integer i:num){
            if(min>i) min=i;
        }
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */