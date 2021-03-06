#include <iostream>

#include "Point.h"
#include "Queue.h"
#include "LinkedList.h"

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

char board[10][10];
bool visited[10][10];

void findAccessiblePointsBFS(Point &start, int &n, int &m, LinkedList<Point> &points);
void getAllPathsFromPointDFS(Point start, Point end, int &n, int &m);

LinkedList<Point> currentPath;
LinkedList<LinkedList<Point>> pathsPoint;
LinkedList<LinkedList<LinkedList<Point>>> allPaths;

int main() {

	int n, m;
	std::cin >> n >> m;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			std::cin >> board[i][j];
			visited[i][j] = false;
		}
	}

	int row, col;
	std::cin >> row >> col;
	Point start(row, col);

	std::cout << "--------------------------------------------------------" << std::endl;

	LinkedList<Point> accessiblePoints;
	findAccessiblePointsBFS(start, n, m, accessiblePoints);
	int sizeAccessP = accessiblePoints.getSize();

	for (int i = 0; i < sizeAccessP; i++) {
		Point current = accessiblePoints.getFront();
		accessiblePoints.pop_front();
		accessiblePoints.push_back(current);
		current.print();
	}
	std::cout << std::endl;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	start.print();
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	for (int i = 0; i < sizeAccessP; i++) {
		Point current = accessiblePoints.getFront();
		accessiblePoints.pop_front();
		accessiblePoints.push_back(current);
		
		getAllPathsFromPointDFS(start, current, n, m);

		allPaths.push_back(pathsPoint);
		pathsPoint.clear();
		currentPath.clear();
	}

	int sizeAllPaths = allPaths.getSize();

	for (int i = 0; i < sizeAllPaths; i++) {
		Point point = accessiblePoints.getFront();
		accessiblePoints.pop_front();
		accessiblePoints.push_back(point);
		point.print();
		std::cout << std::endl;

		pathsPoint.clear();
		pathsPoint = allPaths.getFront();

		pathsPoint.mergeSort();

		int sizePathsP = pathsPoint.getSize();

		for (int j = 0; j < sizePathsP; j++) {
			currentPath.clear();

			currentPath = pathsPoint.getFront();
			int sizeCurrPath = currentPath.getSize();

			for (int k = 0; k < sizeCurrPath; k++) {
				Point current = currentPath.getFront();
				currentPath.pop_front();
				currentPath.push_back(current);
				current.print();
			}
			std::cout << std::endl;

			pathsPoint.pop_front();
			pathsPoint.push_back(currentPath);
		}
		std::cout << "--------------------------------------------------------" << std::endl;

		allPaths.pop_front();
		allPaths.push_back(pathsPoint);
	}

	return 0;
}

void findAccessiblePointsBFS(Point &start, int &n, int &m, LinkedList<Point> &points) {
	Queue<Point> queue;
	int x = start.getRow();
	int y = start.getCol();

	visited[x][y] = true;
	queue.enqueue(start);

	while (!queue.isEmpty()) {
		Point current = queue.head();
		queue.dequeue();

		for (int i = 0; i < 4; i++) {
			x = current.getRow() + dr[i];
			y = current.getCol() + dc[i];

			if (visited[x][y] == false && board[x][y] != '#' && x >= 0 && x < n && y >= 0 && y < m) {
				visited[x][y] = true;
				Point temp(x, y);
				queue.enqueue(temp);
				points.push_back(temp);
			}
		}
	}
}

void getAllPathsFromPointDFS(Point start, Point end, int &n, int &m) {
	if (start.getRow() == end.getRow() && start.getCol() == end.getCol()) {
		currentPath.push_back(end);
		pathsPoint.push_back(currentPath);
		currentPath.pop_back();

		return;
	}

	visited[start.getRow()][start.getCol()] = true;
	currentPath.push_back(start);

	for (int i = 0; i < 4; i++) {
		int x = start.getRow() + dr[i];
		int y = start.getCol() + dc[i];
		if (visited[x][y] == false && board[x][y] != '#' && x >= 0 && x < n && y >= 0 && y < m) {
			Point temp(x, y);
			getAllPathsFromPointDFS(temp, end, n, m);
		}
	}

	visited[start.getRow()][start.getCol()] = false;
	currentPath.pop_back();
}