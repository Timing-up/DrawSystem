#pragma once
#include <iostream>

#include <graphics.h>
#include"Graph.h"
// 基类：四边形
using namespace std;
class Quadrilateral:Graph
{
    protected:
        int side1, side2, side3, side4;

    public:
    Quadrilateral() {
			side1 = 0;
			side2 = 0;
			side3 = 0;
			side4 = 0;
		}
        Quadrilateral(int s1, int s2, int s3, int s4)
            : side1(s1), side2(s2), side3(s3), side4(s4) {
        }

        virtual ~Quadrilateral() {
		}
        virtual Image* Draw() {
			cout << "This is a quadrilateral." << endl;
		}
        virtual int getArea() {
            return 0;
        }

        virtual void showInfo() {
           cout << "This is a quadrilateral." << endl;
        }
        virtual void DrawQUadrilateral(
            const POINT* points,
            int num
        );
};

