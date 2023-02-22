#pragma once
#include "SFML/Graphics.hpp"

struct Explosion {
	sf::Texture textureArr[9];
	sf::Sprite sprite[9];
	float delay;
	int frame;
	sf::Clock timer;
};

float getWidth(sf::Sprite sprite) { 
	return sprite.getLocalBounds().width; 
}
float getHeight(sf::Sprite sprite){
	return sprite.getLocalBounds().height; 
}

void expInit(Explosion* exp) {
	for (int i = 0; i < 9; i++) {
		exp->textureArr[i].loadFromFile(
			"regularExplosion0" + std::to_string(i) + ".png");
	}
	exp->sprite[0].setTexture(exp->textureArr[0]);
	exp->sprite[0].setOrigin(getWidth(exp->sprite[0]) / 2, 
		getHeight(exp->sprite[0]) / 2);
	exp->sprite[0].setPosition(400.f, 300.f);
	exp->frame = 0;
	exp->delay = 100.f;
	//exp->timer.restart();
}

void expUpdate(Explosion* exp) {
	float time = exp->timer.getElapsedTime().asMilliseconds();
	if (time > exp->delay) {
		exp->timer.restart();
		exp->frame++;
		if (exp->frame < 9) {
			exp->sprite[exp->frame].setTexture(exp->textureArr[exp->frame]);
			exp->sprite[exp->frame].setOrigin(
				getWidth(exp->sprite[exp->frame]) / 2, 
				getHeight(exp->sprite[exp->frame]) / 2);
			exp->sprite[exp->frame].setPosition(400.f, 300.f);
		}
		else exp->frame = 0;
	}
}

void expDraw(sf::RenderWindow& window, Explosion* exp) {
	window.draw(exp->sprite[exp->frame]);
}
