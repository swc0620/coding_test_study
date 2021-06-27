#include <iostream>
#include <queue>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {
	priority_queue<int> pq;
	int num;
	scanf("%d", &num);
	int cnt = 0;
	while (cnt < num) {
		int input;
		scanf("%d", &input);

		if (input == 0) {

			if (pq.size() == 0) {
				printf("0\n");
			}
			else {
				int temp = pq.top();
				printf("%d\n", temp);
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
		cnt++;
	}
}