#include <iostream>
#include "shapes.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "cube.h"
#include "simplex.h"
#include "container.h"
using namespace std;


int main()
{
	Container Cont;
	Point <char> point;
	Line <char> line(8, '-');
	Circle <char> circle(3, '0');
	Square <int> square(6, 0);
	Rectangle <int> rectangle(3, 10, 0);
	Cube <char> cube(5, '0');
	Simplex <char> simplex(4, '0');

	Cont.Add(point);
	Cont.Add(line);
	Cont.Add(square);
	Cont.Add(rectangle);
	Cont.Add(circle);
	Cont.Add(cube);
	Cont.Add(simplex);

	cout << "point:" << endl;
	Cont.Off(point);
	cout << endl << endl;

	cout << "line:" << endl;
	Cont.Off(line);
	cout << endl;

	cout << "circle:" << endl;
	Cont.Off(circle);
	cout << endl;

	cout << "square:" << endl;
	Cont.Off(square);
	cout << endl;

	cout << "rectangle:" << endl;
	Cont.Off(rectangle);
	cout << endl;

	cout << "simplex projection:";
	Cont.Off(simplex);
	cout << endl;

	cout << "cube projection:" << endl;
	Cont.Off(cube);
	cout << endl;

	if (square.Perimeter() > cube.Perimeter())
		Cont.Delete(cube);
	if (square.Perimeter() < cube.Perimeter())
		Cont.Delete(square);

	cout << endl;
	cout << "-------- CONTAINER --------";
	cout << endl;
	cout << Cont;
	return 0;
}
