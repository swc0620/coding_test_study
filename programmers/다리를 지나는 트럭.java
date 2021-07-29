import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int time = 1;
        int sum_weight=0;
        Queue<Integer> que = new LinkedList<>();
        Queue<Node> onBridge = new LinkedList<>();
        boolean arrive=false;
        if(truck_weights.length==0) return time;
        for(int truck:truck_weights){
            que.add(truck);
        }
        sum_weight=que.peek();
        onBridge.add(new Node(que.poll(),1));
        while(!onBridge.isEmpty()){
             if(arrive){
                sum_weight-=onBridge.peek().weight;
                onBridge.poll();
                arrive=false;
            }
            if(!que.isEmpty() && sum_weight+que.peek()<=weight){
                sum_weight+=que.peek();
                onBridge.add(new Node(que.poll(),0));
            }
            for(Node element : onBridge){
                element.onBridgeTime++;
                if(element.onBridgeTime==bridge_length){
                    arrive=true;
                }
            }
            time++;
        }
        return time;
    }
}
class Node{
    int weight;
    int onBridgeTime;
    Node(int a,int b){
        this.weight=a;
        this.onBridgeTime=b;
    }
}
