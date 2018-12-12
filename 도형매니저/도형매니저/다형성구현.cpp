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
		std::cout << "원하는 도형추가(1), 전체 도형을 그리기(2), 도형 제거하기(3), 파일 저장&불러오기(4), 프로그램 끝내기(5):";
		std::cin >> menu;

		switch (menu) {
		case 1:
			std::cout << "삼각형(1), 사각형(2), 원(3), 직선(4):";
			std::cin >> menu2;
			
			switch (menu2) {
			case 1:
				std::cout << "삼각형의 세 꼭짓점을 입력하시오" << std::endl << "(x1,y1):";
				std::cin >> p1.x >> p1.y;
				std::cout << "(x2,y2):";
				std::cin >> p2.x >> p2.y;
				std::cout << "(x3,y3):";
				std::cin >> p3.x >> p3.y;
				sm.insert(new Triangle(p1, p2, p3));
				break;
			case 2:
				std::cout << "사각형의 맞꼭짓점을 입력하시오" << std::endl << "(x1,y1):";
				std::cin >> p1.x >> p1.y;
				std::cout << "(x2,y2):";
				std::cin >> p2.x >> p2.y;
				sm.insert(new Rectangle(p1, p2));
				break;
			case 3:
				std::cout << "원의 중심과 반지름을 입력하시오" << std::endl << "(x1,y1):";
				std::cin >> p1.x >> p1.y;
				std::cout << "반지름:";
				std::cin >> radius;
				sm.insert(new Circle(p1, radius));
				break;
			case 4:
				std::cout << "직선의 시작점과 끝점을 입력하시오" << std::endl << "(x1,y1):";
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
			std::cout << "번호로 제거(1), 클래스로 제거(2):";
			std::cin >> menu2;
			if (menu2 == 1) {
				std::cout << "제거할 번호를 입력하시오:";
				std::cin >> removal;
			}
			else {
				std::cout << "어떤 도형을 제거할까요? 삼각형(1), 사각형(2), 원(3), 직선(4):";
				std::cin >> removal;
			}
			sm.remove(menu2, removal);
			break;
		case 4:
			std::cout << "파일 저장하기(1), 파일 불러오기(2):";
			std::cin >> menu2;
			switch (menu2) {
			case 1:
				sm.save();
				break;

			case 2:
				std::cout << "파일 이름을 입력해주세요(예: 도형저장.txt ): ";
				std::cin >> fileName;
				sm.load(fileName);
				break;

			default:
				std::cout << "잘못된 입력입니다." << std::endl;
				break;
			}
			break;

		case 5:
			break;

		default:
			std::cout << "잘못된 입력입니다." << std::endl;
			continue;
		}

		if (menu == 5) {
			std::cout << "그리기를 종료합니다." << std::endl;
			break;
		}
	}
}