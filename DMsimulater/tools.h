//tools.h
#include <string>
#include<iostream>
#include <cstdlib>
#include<time.h>
using namespace std;
#ifndef TOOLS
#define TOOLS
int rollxdyhz(int x = 1, int y = 20, int z = 1);//�������x��1~y�����������ѡȡ�ߵ�z��
int rollxdy_add(int x = 1, int y = 20, int add = 0);//�������x��1~y�����������add��ֵ
int confirm();//���ȷ�����
void pause();//����ȷ�ϼ�����
bool changeYes();//
int pay(int ability, int* point, int reduce);//
void switchit(int *a, int *b);//����˫��λ��
bool stopYes();//���� ��������true
bool delYes();//�Ƿ�ɾ��
#endif
