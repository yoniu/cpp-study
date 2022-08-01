#include <iostream>

class Player {
private:
	int speed = 20;
public:
	int x, y;
	void Move(int xTo, int yTo) {
		x += xTo * speed;
		y += yTo * speed;
	}
	int GetCurrentX() {
		return x;
	}
	int GetCurrentY() {
		return y;
	}
};

int main3() {
	Player a;
	a.x = 0;
	a.y = 0;
	a.Move(5, 10);
	std::cout << a.GetCurrentX() << std::endl;
	std::cout << a.GetCurrentY() << std::endl;
	std::cin.get();
	return 0;
}