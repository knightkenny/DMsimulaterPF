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
	void printBorad();//������ͼ
	string get_name();//��ȡ����
	void readInMap(string mapname);//�����ͼ
	void setChess(int x, int y,int type=3);//���õ�ͼ xyΪ������
	void delChess(int x, int y);//ɾ������ xyΪ������
	void moveChess(int newx, int newy, int chessId);//�ƶ�����
	void setChesses(int x=0,int y=0,string name = "unknown",int chessesId=0);//������������
	void showChesses();//չʾ��������
	bool searchChesses(string name);
	bool searchChesses(int ID);
	int enptyID();
	bool block(int x,int y);
private:
	int boards[10][10];
	chess chesses[10];
};

#endif