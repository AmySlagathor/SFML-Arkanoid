/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nave.cpp
 * Author: amygwyllion
 * 
 * Created on 19 de febrero de 2017, 23:07
 */

#include "Nave.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Nave::Nave(float x, float y) {
    ancho_nave = 90;
    alto_nave = 20;
    velocidad_nave = 6;
    if (!textura.loadFromFile("resources/sprites.png"))
    {
        cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    shape.setPosition(x, y);
    shape.setSize(Vector2f(ancho_nave, alto_nave));
    shape.setTexture(&textura);
    shape.setTextureRect(sf::IntRect(4*16 , 9*8 , 16 , 8));
    shape.setOrigin(ancho_nave/2, alto_nave/2);//origen del collider box
}

Nave::Nave(const Nave& orig) {
}

Nave::~Nave() {
}

RectangleShape Nave::get_shape(){return shape;}
float Nave::get_velocidad_nave(){return velocidad_nave;}
void Nave::set_velocidad_nave(float mvelocidad){velocidad_nave = mvelocidad;}
void Nave::actualizar_movimiento(float ancho_ventana, float alto_ventana){
    shape.move(velocidad);

    //tambien controlamos que la nave no se salga de la pantalla
    if(Keyboard::isKeyPressed(Keyboard::Key::Left) && izquierda() > 0) velocidad.x = -velocidad_nave;
    else if(Keyboard::isKeyPressed(Keyboard::Key::Right) && derecha() < ancho_ventana) velocidad.x = velocidad_nave;
    else velocidad.x = 0;
}
