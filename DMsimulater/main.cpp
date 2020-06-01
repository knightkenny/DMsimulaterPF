#include"character_card_PF.h"
#include"tools.h"
#include"map.h"
#include <fstream>
using namespace std;
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
struct card {
	character_card_pf temp;
	string filename;
	struct card* next;
};
void searchCard(struct card* head) {
	string name;
	cout << "输入查询卡角色名" << endl;
	name = checkIn(name);
	struct card* pSearch = head->next;
	if (pSearch = NULL) {
		cout << "列表为空";
		return;
	}
	while (true) {
		if (name == pSearch->temp.getName()) {
			cout << pSearch->temp.getName() << " " << pSearch->temp.getLevel() <<  "  " << pSearch->temp.getRace()<<"  "<< pSearch->temp.getAli()<<endl;
			system("pause");
			return;
		}
		else if (pSearch->next != NULL) {
			cout << "无此角色数据";
			system("pause");
			return;
		}
		else { pSearch = pSearch->next; }
	}
}
void showAll(struct card* head) {
	cout << "姓名\t种族\t阵营\t等级" << endl;
	struct card* show=head->next;
	while (show!= NULL) {
		cout << show->temp.getName() << "\t" << show->temp.getRace() << "\t"
			<< show->temp.getAli() << "\t"<<show->temp.getLevel()<<endl;
		if(show->next!=NULL)show = show->next;
		else {
			system("pause");
			return;
		}
	}
	pause();
	return;
}
void pfTools(card* head) {
	cout << "请选择你要使用的工具\n1.回合顺序\n2.地图模拟";
	int choice=0;
	int subchoice = -2;
	bool stop = false;
	bool substop = false;
	choice = checkIn(choice);
	switch (choice) {
	case 1:
		
		break;
	case 2:
		board BD;
		while (!stop) {
			subchoice = -2;
			system("cls");
			BD.printBorad();
			cout << "1.设置障碍\n2.设置地形\n3.设置棋子\n4.移动棋子\n5.载入地图\n-1退出功能\n请输入你要选择的功能\n";
			subchoice = checkIn(subchoice);
			switch (subchoice) {
			case 1:
				while (!substop) {
					int x = -1, y = -1;
					cout << "输入x坐标";
					while (x < 0 || x>9)x = checkIn(x);
					cout << "输入y坐标";
					while (y < 0 || y>9)y = checkIn(y);
					BD.setChess(x, y, 2);
					substop = stopYes();
				}
				break;
			case 2:
				while (!substop) {
					int x = -1, y = -1;
					cout << "输入x坐标";
					while (x < 0 || x>9)x = checkIn(x);
					cout << "输入y坐标";
					while (y < 0 || y>9)y = checkIn(y);
					BD.setChess(x, y, 1);
					substop = stopYes();
				}
				break;
			case 3:
				while (!substop) {
					int x = -1, y = -1;
					string name;
					cout << "输入棋子名";
					name = checkIn(name);
					cout << "输入x坐标";
					while (x < 0 || x>9)x = checkIn(x);
					cout << "输入y坐标";
					while (y < 0 || y>9)y = checkIn(y);
					if (BD.searchChesses(name)) {

					}
					BD.setChess(x, y, 3);
					substop = stopYes();
				}
				break;
			case -1:
				stop = stopYes();
				break;
			}
		}
	}
	return;
}
void welcome() {
	system("cls");
	cout << "欢迎使用角色卡管理系统，请选择你要的功能" << endl
		<< "1.新建/导入角色" << endl
		<< "2.查找角色" << endl
		<< "3.展示所有角色" << endl
		<< "4.删除角色" << endl
		<< "5.跑团工具" << endl
		<< "0.退出系统" << endl;
}
int main() {
	string filename;
	bool KillPorgram = false;
	card* head, * pEnd, * pCur;
	head = NULL;
	pCur = NULL;
	pEnd = NULL;
	struct card* pSearch, * pPre;
	string name;
	int choice = -1;
	bool done;
	ifstream pin;
	ofstream pout;
	pin.open("filename.pf");
	if (pin.is_open()) {
		int i = 0;
		while (pin.peek()!=EOF) {
			pin >> filename;
			if (head == NULL&& pin.peek() != EOF) {
				head = new card;
				pCur = new card;
				pCur->temp.read_character(filename);
				pCur->filename = filename;
				head->next = pCur;
				pEnd = pCur;
			}//创建头结点
			else if(pin.peek() != EOF) {
				pCur = new card;
				pCur->temp.read_character(filename);
				pCur->filename = filename;
				pEnd->next = pCur;
				pEnd = pCur;
			}
			pEnd->next = NULL;
			i++;
		}
	}
	pin.close();
	do {
		done = false;
		welcome();
		choice = -1;
		while (choice<0||choice>5)choice = checkIn(choice);
		switch (choice) {
		case 1:
			system("cls");
			if (head == NULL) {
				head = new card;
				pCur = new card;
				pCur->filename=pCur->temp.main_borad();
				head->next = pCur;
				pEnd = pCur;
			}//创建头结点
			else {
				pCur = new card;
				pCur->filename = pCur->temp.main_borad();
				pEnd->next = pCur;
				pEnd = pCur;
			}
			pEnd->next = NULL;
			system("pause");
			break;
		case 2:
			searchCard(head);
			break;
		case 3:
			showAll(head);
			break;
		case 4:

			cout << "输入删除卡角色名" << endl;
			name = checkIn(name);
			pSearch = head->next;
			pPre = head;
			while (!done) {
				if (name == pSearch->temp.getName()) {
					cout << pSearch->temp.getName() << " " << pSearch->temp.getLevel() << "  " << pSearch->temp.getRace() << "  " << pSearch->temp.getAli() << endl;
					system("pause");
					if (delYes()) {
						done = true;
						pPre->next = pSearch->next;
					}
				}
				else if (pSearch->next != NULL) {
					cout << "无此角色数据";
					system("pause");
				}
				else { 
					pPre = pSearch;
					pSearch = pSearch->next; }
			}
			break;
		case 5:
			pfTools(head);
			break;
		case 0:
			KillPorgram = stopYes();
			pout.open("filename.pf");
			while (head->next != NULL) {
				if(filename!="unknown")pout << head->next->filename <<" ";
				head = head->next;
			}
			break;
		}
	} while (!KillPorgram);
	return 0;
}