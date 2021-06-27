#include <iostream>
#include <deque>
#include<map>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Location {
public:
	int x;
	int y;
	Location(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void one(){
		this->y++;
	}
	void two() {
		this->x--;
	}
	void three() {
		this->y--;
	}
	void four() {
		this->x++;
	}
	bool operator ==(Location& a) {
		if (a.x == this->x) {
			if (a.y == this->y) {
				return true;
			}
		}
		return false;
	}
};

class Snake {
public:
	deque<Location> snake;
	int direction;
	Snake() {
		Location init(1, 1);
		snake.push_back(init);
		direction = 1;
	}
	void move(){
		if (direction == 1) {
			Location head = snake.front();
			head.one();
			snake.push_front(head);
			snake.pop_back();
		}
		else if (direction == 2) {
			Location head = snake.front();
			head.two();
			snake.push_front(head);
			snake.pop_back();
		}
		else if (direction == 3) {
			Location head = snake.front();
			head.three();
			snake.push_front(head);
			snake.pop_back();
		}
		else if (direction == 4) {
			Location head = snake.front();
			head.four();
			snake.push_front(head);
			snake.pop_back();
		}
	}
	void eat_apple() {
		if (direction == 1) {
			Location head = snake.front();
			head.one();
			snake.push_front(head);
			
		}
		else if (direction == 2) {
			Location head = snake.front();
			head.two();
			snake.push_front(head);
			
		}
		else if (direction == 3) {
			Location head = snake.front();
			head.three();
			snake.push_front(head);
			
		}
		else if (direction == 4) {
			Location head = snake.front();
			head.four();
			snake.push_front(head);
			
		}
	}
	void rotate_D() {
		if (direction == 1) {
			this->direction = 4;
		}
		else if (direction == 2) {
			this->direction = 1;
		}
		else if (direction == 3) {
			this->direction = 2;
		}
		else if (direction == 4) {
			this->direction = 3;
		}
	}
	void rotate_L() {
		if (direction == 1) {
			this->direction = 2;
		}
		else if (direction == 2) {
			this->direction = 3;
		}
		else if (direction == 3) {
			this->direction = 4;
		}
		else if (direction == 4) {
			this->direction = 1;
		}
	}
};
int main() {
	Snake a;
	int size;
	scanf("%d", &size);
	int num_apple;
	scanf("%d", &num_apple);
	deque<Location> apple;
	int cnt = 0;
	while (cnt < num_apple) {
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		Location temp(x, y);
		apple.push_back(temp);
		cnt++;
	}
	int direc;
	scanf("%d", &direc);
	int cnt_ = 0;
	map<int, char> rotate;
	while (cnt_ < direc) {
		int time_;
		char D_L;
		scanf("%d %c", &time_, &D_L);
		rotate[time_] = D_L;
		cnt_++;
	}
	int time = 0;
	while (true) {
		Location temp = a.snake.back();
		if (rotate.find(time) == rotate.end()) {
			a.move();
		}
		else {
			if (rotate[time] == 'D') {
				a.rotate_D();
			}
			else if(rotate[time]=='L'){
				a.rotate_L();
			}
			a.move();
		}
		time++;
		if (a.snake.front().x<1 || a.snake.front().x>size || a.snake.front().y<1 || a.snake.front().y>size) {
			printf("%d\n", time);
			return 0;
		}
		if (temp == a.snake.front()) {
			printf("%d\n", time);
			return 0;
		}
		for (deque<Location>::iterator iter_ = (a.snake.begin()+1); iter_ != a.snake.end(); iter_++) {
			if (*(iter_) == a.snake.front()) {
				printf("%d\n", time);
				return 0;
			}
		}

		for (deque<Location>::iterator iter = apple.begin(); iter != apple.end(); iter++) {
			if (*(iter) == a.snake.front()) {
				a.snake.push_back(temp);
				apple.erase(iter);
				break;
			}
		}
	}
	
}