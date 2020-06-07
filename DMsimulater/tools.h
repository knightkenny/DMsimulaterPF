//tools.h
#include <string>
#include<iostream>
#include <cstdlib>
#include<time.h>
using namespace std;
#ifndef TOOLS
#define TOOLS
int rollxdyhz(int x = 1, int y = 20, int z = 1);//随机生成x个1~y的随机数从中选取高的z个
int rollxdy_add(int x = 1, int y = 20, int add = 0);//随机生成x个1~y的随机数加上add的值
int confirm();//输出确认语句
void pause();//按下确认加清屏
bool changeYes();//
int pay(int ability, int* point, int reduce);//
void switchit(int *a, int *b);//交换双方位置
bool stopYes();//结束 结束返回true
bool delYes();//是否删除
#endif
