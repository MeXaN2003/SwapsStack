#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct NewStruct {
	char second_name[13];
	int first_mark;
	int second_mark;
	int third_mark;
	int fourth_mark;
	NewStruct* next;
} NewList;

void ListDelete(NewList*);
void swap(int a, int b, NewList*);
template<typename TypeStack>
void swapADDR_Pro(int a, int b, TypeStack* head);
void swapADDR(int a, int b, NewList* head);
int main() {
	srand(time(NULL));
	NewList* p, * head;
	head = new NewList;
	head->next = NULL;
	for (int i = 0; i < 10; i++) {
		p = new NewList;
		switch (i) {
		case 0:
			strcpy(p->second_name, "Ivanov");
			break;
		case 1:
			strcpy(p->second_name, "Petrov");
			break;
		case 2:
			strcpy(p->second_name, "Sidorov");
			break;
		case 3:
			strcpy(p->second_name, "Lermontov");
			break;
		case 4:
			strcpy(p->second_name, "Pushkin");
			break;
		case 5:
			strcpy(p->second_name, "Sokolov");
			break;
		case 6:
			strcpy(p->second_name, "Velkov");
			break;
		case 7:
			strcpy(p->second_name, "Starchenkov");
			break;
		case 8:
			strcpy(p->second_name, "Ptushkin");
			break;
		case 9:
			strcpy(p->second_name, "Russkij");
			break;
		}
		p->first_mark = (int)rand() * (6 - 2) / RAND_MAX + 2;
		p->second_mark = (int)rand() * (6 - 2) / RAND_MAX + 2;
		p->third_mark = (int)rand() * (6 - 2) / RAND_MAX + 2;
		p->fourth_mark = (int)rand() * (6 - 2) / RAND_MAX + 2;
		p->next = head->next;
		head->next = p;
	}
	for (NewList* p = head->next; p; p = p->next) {
		printf("|%s|%d|%d|%d|%d|\n", p->second_name, p->first_mark, p->second_mark, p->third_mark, p->fourth_mark);
	}
	printf("\n");
	swapADDR(1, 13, head);
	for (NewList* p = head->next; p; p = p->next) {
		printf("|%s|%d|%d|%d|%d|\n", p->second_name, p->first_mark, p->second_mark, p->third_mark, p->fourth_mark);
	}
	ListDelete(head);
	return 0;
}

void swapADDR(int a, int b, NewList* head) {
	if (NULL == head) return;
	if (0 == a || 0 == b) return;
	if (a > b) {
		int c = b;
		b = a;
		a = c;
	}
	if (a == b) return;
	if (b - a == 1) {
		NewList* xx, * x, * y, * newHead;
		xx = head;
		for (int i = 1; i <= a; i++) {
			if (NULL == xx) return;
			xx = xx->next;
		}
		x = xx->next;
		if (NULL == x) return;
		y = x->next;
		//1
		newHead = head;
		for (int i = 0; i < b; i++)
		{
			newHead = newHead->next;
		}
		newHead->next = xx;
		//2
		newHead = head;
		for (int i = 0; i < a; i++)
		{
			newHead = newHead->next;
		}
		newHead->next = y;
		//3
		newHead = head;
		for (int i = 1; i < a; i++)
		{
			newHead = newHead->next;
		}
		newHead->next = x;
		return;
	}
	NewList* xx, * yy, * y, * newHead;
	xx = head;
	yy = head;
	for (int i = 1; i <= a; i++) {
		if (NULL == xx) return;
		xx = xx->next;
	}
	for (int i = 1; i <= b; i++) {
		if (NULL == yy) return;
		yy = yy->next;
	}
	y = yy->next;
	//1
	newHead = head;
	for (int i = 0; i < b; i++)
	{
		newHead = newHead->next;
	}
	newHead->next = xx->next;
	//2
	newHead = head;
	for (int i = 1; i < b; i++)
	{
		newHead = newHead->next;
	}
	newHead->next = xx;
	//3
	newHead = head;
	for (int i = 0; i < a; i++)
	{
		newHead = newHead->next;
	}
	newHead->next = y;
	//4
	newHead = head;
	for (int i = 1; i < a; i++)
	{
		newHead = newHead->next;
	}
	newHead->next = yy;

}

template<typename TypeStack>
void swapADDR_Pro(int a, int b, TypeStack* head) {
	if (NULL == head) return;
	if (0 == a || 0 == b) return;
	if (a > b) {
		int c = b;
		b = a;
		a = c;
	}
	if (a == b) return;
	if (b - a == 1) {
		TypeStack* xx, * x, * y, * newHead;
		xx = head;
		for (int i = 1; i <= a; i++) {
			if (NULL == xx) return;
			xx = xx->next;
		}
		x = xx->next;
		if (NULL == x) return;
		y = x->next;
		//1
		newHead = head;
		for (int i = 0; i < b; i++)
		{
			newHead = newHead->next;
		}
		newHead->next = xx;
		//2
		newHead = head;
		for (int i = 0; i < a; i++)
		{
			newHead = newHead->next;
		}
		newHead->next = y;
		//3
		newHead = head;
		for (int i = 1; i < a; i++)
		{
			newHead = newHead->next;
		}
		newHead->next = x;
		return;
	}
	TypeStack* xx, * yy, * y, * newHead;
	xx = head;
	yy = head;
	for (int i = 1; i <= a; i++) {
		if (NULL == xx) return;
		xx = xx->next;
	}
	for (int i = 1; i <= b; i++) {
		if (NULL == yy) return;
		yy = yy->next;
	}
	y = yy->next;
	//1
	newHead = head;
	for (int i = 0; i < b; i++)
	{
		newHead = newHead->next;
	}
	newHead->next = xx->next;
	//2
	newHead = head;
	for (int i = 1; i < b; i++)
	{
		newHead = newHead->next;
	}
	newHead->next = xx;
	//3
	newHead = head;
	for (int i = 0; i < a; i++)
	{
		newHead = newHead->next;
	}
	newHead->next = y;
	//4
	newHead = head;
	for (int i = 1; i < a; i++)
	{
		newHead = newHead->next;
	}
	newHead->next = yy;
}

void swap(int a, int b, NewList* head) {
	NewList* aa = head,* bb = head;
	for (int i = 0; i < a; i++) {
		aa = aa->next;
		if (NULL == aa->next) return;
	}
	for (int i = 0; i < b; i++) {
		bb = bb->next;
		if (NULL == bb->next) return;
	}
	NewList xx, yy;
	xx = *aa;
	yy = *bb;
	xx.next = bb->next;
	yy.next = aa->next;
	*bb = xx;
	*aa = yy;
}
void ListDelete(NewList* head) {
	NewList* pp, * p;
	for (p = head; p; p = pp) {
		pp = p->next;
		delete(p);
	}
}
