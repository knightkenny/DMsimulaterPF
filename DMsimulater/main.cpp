//main.cpp
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
		cin.clear();		//��һ�����Ҫ����cin���±��Ϊ��ȷ���Դﵽ���������Ŀ��
		while (cin.get() != '\n')		//�������֮ǰcin������������
			continue;
		cout << "������������������";
		return checkIn(type);
	}
}
struct card {
	character_card_pf temp;//����
	string filename;//�����Զ���ȡ�ļ�
	struct card* next;//��һ���ļ�ָ��
};
void searchCard(struct card* head) {
	if (head == NULL) {
		cout << "û������";
		pause();
		return;
	}
	string name;
	cout << "�����ѯ����ɫ��" << endl;
	name = checkIn(name);
	struct card* pSearch = head->next;
	if (pSearch == NULL) {
		cout << "�б�Ϊ��";
		pause();
		return;
	}
	while (true) {
		if (name == pSearch->temp.getName()) {
			cout << pSearch->temp.getName() << " " << pSearch->temp.getLevel() <<  "  " << pSearch->temp.getRace()<<"  "<< pSearch->temp.getAli()<<endl;
			system("pause");
			return;
		}
		else if (pSearch->next != NULL) {
			cout << "�޴˽�ɫ����";
			system("pause");
			return;
		}
		else { pSearch = pSearch->next; }
	}
}
void showAll(struct card* head) {
	if (head == NULL) {
		cout << "û������";
		pause();
		return;
	}
	cout << "����\t����\t��Ӫ\t�ȼ�" << endl;
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

	cout << "��ѡ����Ҫʹ�õĹ���\n1.�غ�˳��\n2.��ͼģ��";
	int choice=0;
	int subchoice = -2;
	bool stop = false;
	bool substop = false;
	choice = checkIn(choice);
	switch (choice) {
	case 1:
		cout << "��δ�깤";
		break;
	case 2:
		board BD;
		while (!stop) {
			substop = false;
			subchoice = -2;
			system("cls");
			BD.printBorad();
			cout << "1.�����ϰ�\n2.���õ���\n3.��������\n4.�ƶ�����\n5.�����ͼ\n-1�˳�����\n��������Ҫѡ��Ĺ���\n";
			subchoice = checkIn(subchoice);
			switch (subchoice) {
			case 1:
				while (!substop) {
					int x = -1, y = -1;
					cout << "����x����";
					while (x < 0 || x>9)x = checkIn(x);
					cout << "����y����";
					while (y < 0 || y>9)y = checkIn(y);
					if (BD.block(x,y)) {
						cout << "�Ѵ����������壬����ʧ��";
					}
					else {
						BD.setChess(x, y, 2);
					}
					substop = stopYes();
				}
				break;
			case 2:
				while (!substop) {
					int x = -1, y = -1;
					cout << "����x����";
					while (x < 0 || x>9)x = checkIn(x);
					cout << "����y����";
					while (y < 0 || y>9)y = checkIn(y);
					if (BD.block(x,y)) {
						cout << "�Ѵ����������壬����ʧ��";
					}
					else {
						BD.setChess(x, y, 1);
					}
					substop = stopYes();
				}
				break;
			case 3:
				while (!substop) {
					int x = -1, y = -1;
					string name;
					cout << "����������";
					name = checkIn(name);
					cout << "����x����";
					while (x < 0 || x>9)x = checkIn(x);
					cout << "����y����";
					while (y < 0 || y>9)y = checkIn(y);
					if (BD.block(x,y)) {
						cout << "�Ѵ����������壬����ʧ��";
					}
					else{
						if (!BD.searchChesses(name)) {
							int ID = BD.enptyID();
							if (ID != -1) {
								BD.setChesses(x, y, name, ID);
								BD.setChess(x, y, 3);
							}
							else {
								cout << "��������������ɾ���ٽ������";
							}
						}
					}
					substop = stopYes();
				}
				break;
			case 4:
				while (!substop) {
					int x = -1, y = -1;
					int ID = 0;
					cout << "�������ƶ����ӵ�ID";
					ID = checkIn(ID);
					cout << "����x����";
					while (x < 0 || x>9)x = checkIn(x);
					cout << "����y����";
					while (y < 0 || y>9)y = checkIn(y);
					if (BD.block(x, y)) {
						cout << "�Ѵ����������壬����ʧ��";
					}
					else {
						BD.moveChess(x, y, ID);
					}
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
	cout << "��ӭʹ�ý�ɫ������ϵͳ����ѡ����Ҫ�Ĺ���" << endl
		<< "1.�½�/�����ɫ" << endl
		<< "2.���ҽ�ɫ" << endl
		<< "3.չʾ���н�ɫ" << endl
		<< "4.ɾ����ɫ" << endl
		<< "5.���Ź���" << endl
		<< "6.�����ɫ���" << endl
		<< "0.�˳�ϵͳ" << endl;
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
			}//����ͷ���
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
		while (choice<0||choice>6)choice = checkIn(choice);
		switch (choice) {
		case 1:
			system("cls");
			if (head == NULL) {
				head = new card;
				pCur = new card;
				pCur->filename=pCur->temp.main_borad();
				head->next = pCur;
				pEnd = pCur;
			}//����ͷ���
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
			cout << "����ɾ������ɫ��" << endl;
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
				else if (pSearch->next == NULL) {
					cout << "�޴˽�ɫ����";
					done = true;
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
		case 6:
			showAll(head);
			cout << "������뿨��ɫ��" << endl;
			name = checkIn(name);
			pSearch = head->next;
			pPre = head;
			while (!done) {
				if (name == pSearch->temp.getName()) {
					done = true;
					pSearch->temp.main_borad();
				}
				else if (pSearch->next == NULL) {
					cout << "�޴˽�ɫ����";
					done = true;
					system("pause");
				}
				else {
					pPre = pSearch;
					pSearch = pSearch->next;
				}
			}
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