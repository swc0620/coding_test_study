#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int main() {
	priority_queue<int> pq;
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			if (pq.size() == 0) {
				printf("0\n");
			}
			else {
				int temp = -1 * pq.top();
				printf("%d\n", temp);
				pq.pop();
			}
		}
		else {
			pq.push(-1 * num);
		}

	}
}