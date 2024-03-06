#define _CRT_SECURE_NO_WARNINGS 
#ifndef __112550013_STRUCT_H__
#define __112550013_STRUCT_H__
#include <stdlib.h>
#include <string.h>

typedef struct _reg_node {
	char ID[15];
	char name[20];
	char pwd[30];
	_reg_node* nxt;

	void init(char _ID[], char _name[], char _pwd[]) {
		strcpy(ID, _ID);
		strcpy(name, _name);
		strcpy(pwd, _pwd);
		nxt = NULL;
	}
}reg_node;

struct reg_list {
	reg_node* root;
	int sz;

	void init() {
		root = (reg_node*)malloc(sizeof(reg_node));
		root->nxt = NULL;
		sz = 0;
	}
	void add(reg_node* node) {
		reg_node* tmp = root;
		while (tmp->nxt) {
			tmp = tmp->nxt;
		}
		tmp->nxt = node;
		sz++;
	}
	int find(char ID[]) {
		reg_node* tmp = root;
		while (tmp) {
			if (strcmp(tmp->ID, ID) == 0) return 1;
			tmp = tmp->nxt;
		}
		return 0;
	}
	int chkPwd(char ID[], char pwd[]) {
		reg_node* tmp = root;
		while (tmp) {
			if (strcmp(tmp->ID, ID) == 0 && strcmp(tmp->pwd, pwd) == 0) return 1;
			tmp = tmp->nxt;
		}
		return 0;
	}
};

typedef struct _res_node {
	char ID[15];
	char branch[20];
	char date[20];
	int hour;
	int cos;
	_res_node* nxt;

	void init(char _ID[], char _branch[], char _date[], int _hour, int _cos) {
		strcpy(ID, _ID);
		strcpy(branch, _branch);
		strcpy(date, _date);
		hour = _hour;
		cos = _cos;
		nxt = NULL;
	}
}res_node;

struct res_list {
	res_node* root;
	int sz;

	void init() {
		root = (res_node*)malloc(sizeof(res_node));
		root->nxt = NULL;
		sz = 0;
	}
	void add(res_node* node) {
		res_node* tmp = root;
		while (tmp->nxt) {
			tmp = tmp->nxt;
		}
		tmp->nxt = node;
		sz++;
	}
	void del(int cnt) {
		cnt--;
		res_node* tmp = root;
		while (tmp && cnt--) {
			tmp = tmp->nxt;
		}
		tmp->nxt = tmp->nxt->nxt;
		sz--;
	}
	res_node* get(char ID[], int cnt) {
		res_node* tmp = root;
		while (tmp && cnt --) {
			tmp = tmp->nxt;
		}
		return tmp;
	}
};

int chkIDValid(char[]);

#endif
