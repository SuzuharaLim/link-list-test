//Link List 學習紀錄
#include<stdio.h>

//定義一個struct
typedef struct node {
	int num;
	struct node* next;
}Node;

//基本的單向連結
//建立讓a的下一個鏈結為b，並驗證是否為b的記憶體位置
void basic_onefront() {
	Node a, b;
	a.next = &b;

	printf("a next:%p\n", a.next);
	printf("b:%p\n", &b);
}

//以array輸入
void array_intput() {
	char letter[4] = { 'a','b','c' };
	node act[3];
	Node* now = &act[0];
	for (int i = 0; i < 3; i++) {
		now->num = letter[i];
		if (i == 2) {//確認是否為最後一個數
			now->next = 0;//是就補零
		}
		else {
			now->next = &act[i + 1];
		}
		printf("[%d] , sum:%c , next_ptr:%p\n", i, now->num, now->next);
		now = now->next;
	}
}

//用迴圈查詢值所在的位置
void loop_serch() {
	char letter[4] = { 'a','b','c' };
	node act[3];
	char target = 'b';

	Node* now = &act[0];
	for (int i = 0; i < 3; i++) {
		now->num = letter[i];
		if (i == 2) {
			now->next = 0;
		}
		else if (now->num == target) { //如果當前鏈結值為目標值則輸出並結束迴圈
			printf("[%d] , sum:%c , next_ptr:%p\n", i, now->num, now->next);
			break;
		}
		else {
			now->next = &act[i + 1];
		}
	}
}

//用迴圈查詢值所在的位置並出入一個鏈結//尚未完成
void loop_insert_value() {
	char letter[4] = { 'a','b','c' };
	node act[3];
	char target = 'b';
	node x;

	Node* now = &act[0];
	for (int i = 0; i < 3; i++) {
		now->num = letter[i];
		if (i == 2) {
			now->next = 0;
		}
		else if (now->num == target) { //如果當前鏈結值為目標值則輸出並結束迴圈
			Node* loc = now->next;
			x.num = 'x';
			x.next = loc;

			now->next = &x;
		}
		else {
			now->next = &act[i + 1];
		}
		printf("[%d] , sum:%c , next_ptr:%p\n", i, now->num, now->next);
	}
}


int main() {

	loop_insert_value();
	return 0;
}