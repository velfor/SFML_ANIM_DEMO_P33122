#include "SFML/Graphics.hpp"
#include "exp.h"

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60);

	Explosion* exp = new Explosion();
	expInit(exp);

	while (window.isOpen())
	{
		//1 обработка событий
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//обновление игровых объектов (функции update)
		expUpdate(exp);
		//отрисовка объектов и обновление окна
		window.clear();
		/*window.draw(shape);*/
		//if (exp != nullptr && exp->frame < 9) {
			expDraw(window, exp);
		//}
		//else {
		//	delete exp;
		//	exp = nullptr;
		//}
		window.display();
	}

	return 0;
}