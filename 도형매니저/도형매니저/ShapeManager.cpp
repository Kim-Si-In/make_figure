#include <iostream>
#include <fstream>
#include "ShapeManager.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "line.h"
using namespace std;

ShapeManager::ShapeManager(int n)
{
	nShape = 0;
	capacity = n;
	shapes = new Shape*[capacity];
}

ShapeManager::~ShapeManager()
{
	for (int i = 0; i < nShape; ++i) {
		delete shapes[i];
	}
	delete[] shapes;
}

void ShapeManager::insert(Shape* a)
{
	if (nShape == capacity) {
		delete shapes[0];
		--nShape;
		for (int i = 0; i < nShape; ++i) {
			shapes[i] = shapes[i + 1];
		}
	}
	shapes[nShape] = a;
	nShape++;
}

void ShapeManager::draw() const
{
	cout << "----------------------------------------------------" << endl;
	cout << "�����ϴ� ��� ������ �׸��ϴ�" << endl;
	cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ�����." << endl;
	cout << "��� " << nShape << "���� ������ �ֽ��ϴ�" << endl;
	cout << "----------------------------------------------------" << endl;

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]";
		shapes[i]->draw();
	}

	cout << endl;

	cout << "----------------------------------------------------" << endl;
	cout << "�׸��⸦ ��Ĩ�ϴ�" << endl;
	cout << "----------------------------------------------------" << endl << endl;
}

void ShapeManager::remove(int menu2, int removal)
{
	if (menu2==1) {
		if (removal < 0 || nShape <= removal) {
			cout << removal << "° ������ �����ϴ�." << endl;
			return;
		}

		delete shapes[removal];
		for (int i = removal; i < nShape - 1; ++i) {
			shapes[i] = shapes[i + 1];
		}
		--nShape;
	}
	else {
		int removeCount = 0;

		switch (removal) {
		case 1:
			for (int i = 0; i < nShape; ++i) {
				if (dynamic_cast<Triangle*>(shapes[i]) != nullptr) {
					delete shapes[i];
					++removeCount;
				}
				else {
					shapes[i- removeCount] = shapes[i];
				}
			}
			nShape -= removeCount;
			break;
		case 2:
			for (int i = 0; i < nShape; ++i) {
				if (dynamic_cast<Rectangle*>(shapes[i]) != nullptr) {
					delete shapes[i];
					++removeCount;
				}
				else {
					shapes[i - removeCount] = shapes[i];
				}
			}
			nShape -= removeCount;
			break;
		case 3:
			for (int i = 0; i < nShape; ++i) {
				if (dynamic_cast<Circle*>(shapes[i]) != nullptr) {
					delete shapes[i];
					++removeCount;
				}
				else {
					shapes[i - removeCount] = shapes[i];
				}
			}
			nShape -= removeCount;
			break;
		case 4:
			for (int i = 0; i < nShape; ++i) {
				if (dynamic_cast<Line*>(shapes[i]) != nullptr) {
					delete shapes[i];
					++removeCount;
				}
				else {
					shapes[i - removeCount] = shapes[i];
				}
			}
			nShape -= removeCount;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	}
}

void ShapeManager::save() const
{
	ofstream out("��������.txt");

	for (int i = 0; i < nShape; ++i) {
		shapes[i]->save( out );
	}

	cout << "����Ǿ����ϴ�!" << endl;
}

void ShapeManager::load(string fileName)
{
	ifstream in(fileName);

	if (in) {
		int shapeCheck;
		double shapeArg[6];
		for (int i = 0; i < nShape; ++i) {
			delete shapes[i];
		}

		nShape = 0;

		while (in >> shapeCheck) {
			cout << "shapeCheck: " << shapeCheck << endl;

			switch (shapeCheck) {
			case 1:
				for (int i = 0; i < 6; ++i) {
					in >> shapeArg[i];
					cout << "shapeArg[" << i << "]: " << shapeArg[i] << endl;
				}
				shapes[nShape] = new Triangle(Point(shapeArg[0], shapeArg[1]), Point(shapeArg[2], shapeArg[3]), Point(shapeArg[4], shapeArg[5]));
				break;

			case 2:
				for (int i = 0; i < 4; ++i) {
					in >> shapeArg[i];
					cout << "shapeArg[" << i << "]: " << shapeArg[i] << endl;
				}
				shapes[nShape] = new Rectangle(Point(shapeArg[0], shapeArg[1]), Point(shapeArg[2], shapeArg[3]));
				break;

			case 3:
				for (int i = 0; i < 3; ++i) {
					in >> shapeArg[i];
					cout << "shapeArg[" << i << "]: " << shapeArg[i] << endl;
				}
				shapes[nShape] = new Circle(Point(shapeArg[0], shapeArg[1]), (int)shapeArg[2]);
				break;

			case 4:
				for (int i = 0; i < 4; ++i) {
					in >> shapeArg[i];
					cout << "shapeArg[" << i << "]: " << shapeArg[i] << endl;
				}
				shapes[nShape] = new Line(Point(shapeArg[0], shapeArg[1]), Point(shapeArg[2], shapeArg[3]));
				break;

			default:
				cout << "������ �߻�����ϴ� �ֽ��ϴ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!  ::" << shapeCheck << endl;
				break;
			}

			++nShape;
		}

		cout << "�ҷ��Խ��ϴ�!" << endl;
	}
	else {
		cout << "������ �������� �ʽ��ϴ�!!!" << endl;
	}

}
