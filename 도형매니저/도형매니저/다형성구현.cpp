#include <iostream>
#include <string>
#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "ShapeManager.h"

int main()
{
	std::cout << sizeof(Triangle) << std::endl;
	std::cout << sizeof(Point) << std::endl;

	ShapeManager sm(100);
	
	sm.insert(new Circle(Point(3.43, 12.23), 7.32));
	sm.insert(new Circle(Point(11.32, 146.5), 9.45));
	sm.insert(new Triangle());
	sm.insert(new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)));

	for (int i = 0; i < 64; ++i) {
		sm.insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));
	}

	sm.draw();
	//-------------------------------Menu-----------------------------
	int menu = 0;
	int menu2 = 0;
	Point p1;
	Point p2;
	Point p3;
	int radius;

	int removal;

	std::string fileName;

	while (true) {
		std::cout << "���ϴ� �����߰�(1), ��ü ������ �׸���(2), ���� �����ϱ�(3), ���� ����&�ҷ�����(4), ���α׷� ������(5):";
		std::cin >> menu;

		switch (menu) {
		case 1:
			std::cout << "�ﰢ��(1), �簢��(2), ��(3), ����(4):";
			std::cin >> menu2;
			
			switch (menu2) {
			case 1:
				std::cout << "�ﰢ���� �� �������� �Է��Ͻÿ�" << std::endl << "(x1,y1):";
				std::cin >> p1.x >> p1.y;
				std::cout << "(x2,y2):";
				std::cin >> p2.x >> p2.y;
				std::cout << "(x3,y3):";
				std::cin >> p3.x >> p3.y;
				sm.insert(new Triangle(p1, p2, p3));
				break;
			case 2:
				std::cout << "�簢���� �²������� �Է��Ͻÿ�" << std::endl << "(x1,y1):";
				std::cin >> p1.x >> p1.y;
				std::cout << "(x2,y2):";
				std::cin >> p2.x >> p2.y;
				sm.insert(new Rectangle(p1, p2));
				break;
			case 3:
				std::cout << "���� �߽ɰ� �������� �Է��Ͻÿ�" << std::endl << "(x1,y1):";
				std::cin >> p1.x >> p1.y;
				std::cout << "������:";
				std::cin >> radius;
				sm.insert(new Circle(p1, radius));
				break;
			case 4:
				std::cout << "������ �������� ������ �Է��Ͻÿ�" << std::endl << "(x1,y1):";
				std::cin >> p1.x >> p1.y;
				std::cout << "(x2,y2):";
				std::cin >> p2.x >> p2.y;
				sm.insert(new Line(p1, p2));
				break;
			}
			break;

		case 2:
			sm.draw();
			break;

		case 3:
			std::cout << "��ȣ�� ����(1), Ŭ������ ����(2):";
			std::cin >> menu2;
			if (menu2 == 1) {
				std::cout << "������ ��ȣ�� �Է��Ͻÿ�:";
				std::cin >> removal;
			}
			else {
				std::cout << "� ������ �����ұ��? �ﰢ��(1), �簢��(2), ��(3), ����(4):";
				std::cin >> removal;
			}
			sm.remove(menu2, removal);
			break;
		case 4:
			std::cout << "���� �����ϱ�(1), ���� �ҷ�����(2):";
			std::cin >> menu2;
			switch (menu2) {
			case 1:
				sm.save();
				break;

			case 2:
				std::cout << "���� �̸��� �Է����ּ���(��: ��������.txt ): ";
				std::cin >> fileName;
				sm.load(fileName);
				break;

			default:
				std::cout << "�߸��� �Է��Դϴ�." << std::endl;
				break;
			}
			break;

		case 5:
			break;

		default:
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			continue;
		}

		if (menu == 5) {
			std::cout << "�׸��⸦ �����մϴ�." << std::endl;
			break;
		}
	}
}