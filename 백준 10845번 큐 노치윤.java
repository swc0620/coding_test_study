import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Queue {
	private Linkedlist queue=new Linkedlist();
	public void push(int num) {
		queue.add_last(num);
	}
	public int pop() {
		return queue.remove_first();
	}
	public int size() {
		return queue.size();
	}
	public int empty() {
		if(queue.size()==0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
	public int front() {
		return queue.front();
	}
	public int back() {
		return queue.back();
	}
}

public class Main{
    public static void main(String[] args) throws IOException {
		Queue queue=new Queue();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str=br.readLine();
		int cnt=Integer.parseInt(str);
		int i=0;
		while(i<cnt) {
			String cmd=br.readLine();
			if(cmd.length()>=6) {
				String temp=cmd.substring(5);
				queue.push(Integer.parseInt(temp));
			}
			else if(cmd.compareTo("pop")==0) {
				System.out.println(queue.pop());
			}
			else if(cmd.compareTo("size")==0) {
				System.out.println(queue.size());
			}
			else if(cmd.compareTo("empty")==0) {
				System.out.println(queue.empty());
			}
			else if(cmd.compareTo("front")==0) {
				System.out.println(queue.front());
			}
			else if(cmd.compareTo("back")==0) {
				System.out.println(queue.back());
			}
			else {
				System.out.println("잘못된 입력");
			}
			
			i++;
		}
		br.close();
		// TODO Auto-generated method stub

	}
}


class Linkedlist{
	private Node head;
	private int size=0;
	
	public Linkedlist() {
		this.head=new Node(0);
	}
	
	public void add_last(int a) {
		Node node=new Node(a);
		Node temp=head;
		while(temp.next!=null) {
			temp=temp.next;
		}
		temp.next=node;
		size++;
	}
	
	public int remove_first() {
		if(head.next==null) {
			return -1;
		}
		else {
			Node temp=head.next;
			head.next=temp.next;
			size--;
			return temp.get_num();
		}
	}
	
	public int size() {
		return this.size;
	}
	
	public int front() {
		if(head.next==null) {
			return -1;
		}
		else {
			return head.next.get_num();
		}
	}
	
	public int back() {
		if(head.next==null) {
			return -1;
		}
		else {
			Node temp=head;
			while(temp.next!=null) {
				temp=temp.next;
			}
			return temp.get_num();
		}
	}
}

class Node{
	public Node next;
	private int num;
	
	public Node(int num){
		this.next=null;
		this.num=num;
	}	
	
	public int get_num() {
		return this.num;
	}
}
