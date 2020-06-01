#include "map.h"
template <class T> T checkIn(T type) {
	T inTemp;
	cin >> inTemp;
	if (cin.good()) {
		return inTemp;
	}
	else {
		cin.clear();		//这一句很总要，将cin重新标记为正确，以达到重新输入的目的
		while (cin.get() != '\n')		//这里清空之前cin缓冲区的数据
			continue;
		cout << "输入有误，请重新输入";
		return checkIn(type);
	}
}
board::board()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			boards[i][j] = 0;
}
void board::printBorad()
{
	{
		cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
		for (int i = 0; i < 10; i++){
			cout << i;
			for (int j = 0; j < 10; j++) { 

				if (boards[i][j] == 0)cout << "□";
				else if (boards[i][j] == 1)cout << "XX";
				else if (boards[i][j] == 2)cout << "■";
				else if (boards[i][j] == 3) {
					for (int k = 0; k < 10; k++) {
						if (chesses[k].x == i&&chesses[k].y==j){
							cout << chesses[k].getname();
						}
					}
				}
			}
			cout << endl;
		}
		showChesses();
	}
}

string board::get_name()
{
	string name = "s";
	return name;
}

void board::readInMap(string mapname)
{
}

void board::setChess(int x, int y,int type)
{
	boards[x][y] = type;
}

void board::delChess(int x, int y)
{
	boards[x][y] = 0;
}

void board::moveChess(int newx, int newy,int chessId)
{
	delChess(chesses[chessId].getx(), chesses[chessId].gety());
	chesses[chessId].move(newx, newy);
	setChess(newx, newy);
}

void board::setChesses(int x, int y, string name, int chessesId)
{
	chesses[chessesId].x = x;
	chesses[chessesId].y = y;
	chesses[chessesId].name = name;
}

void board::showChesses()
{
	cout << "■  墙壁\tXX  困难地形\t□  空地" << endl;
	cout << "——————棋子数据——————" << endl
		<< "ID\t(x,y)\t名字" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << "\t(" << chesses[i].x << "," << chesses[i].y << ")\t" << chesses[i].name << endl;
	}
}

bool board::searchChesses(string name)
{
	for (int i = 0; i < 10; i++) {
		if (name == chesses[i].name) return true;
	}
	return false;
}

int board::enptyID()
{
	for (int i = 0; i < 10; i++) {
		if (chesses[i].getname == "unknown")return i;
	}
	return -1;
}

chess::chess()
{
	x = 0;
	y = 0;
	name = "unknown";
}

int chess::getx()
{
	return x;
}

int chess::gety()
{
	return y;
}

int chess::move(int nextx, int nexty)
{
	x = nextx;
	y = nexty;
	return 0;
}

string chess::getname()
{
	return name.substr(0,2);
}
