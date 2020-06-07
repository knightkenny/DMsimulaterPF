//map.h
#include"tools.h"
#include"character_card_PF.h"
#ifndef MAPS
#define MAPS
class chess {
	friend class board;
public:
	chess();
	int getx();
	int gety();
	int move(int nextx, int nexty);
	string getname();
private:
	int x;
	int y;
	string name;
};
class board {
	friend class chess;
public:
	board();
	void printBorad();//画出地图
	string get_name();//获取名字
	void readInMap(string mapname);//读入地图
	void setChess(int x, int y,int type=3);//设置地图 xy为其坐标
	void delChess(int x, int y);//删除棋子 xy为其坐标
	void moveChess(int newx, int newy, int chessId);//移动棋子
	void setChesses(int x=0,int y=0,string name = "unknown",int chessesId=0);//设置棋子数据
	void showChesses();//展示棋子数据
	bool searchChesses(string name);
	bool searchChesses(int ID);
	int enptyID();
	bool block(int x,int y);
private:
	int boards[10][10];
	chess chesses[10];
};

#endif