/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ladrillo.cpp
 * Author: amygwyllion
 * 
 * Created on 19 de febrero de 2017, 23:16
 */

#include "Ladrillo.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Ladrillo::Ladrillo(float x, float y) {
    destruido = false;
    ancho_ladrillo = 60;
    alto_ladrillo = 20;
    if (!textura.loadFromFile("resources/sprites.png"))
    {
        cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    shape.setPosition(x,y);
    shape.setSize(Vector2f(ancho_ladrillo, alto_ladrillo));
    shape.setFillColor(Color::Yellow);
    //shape.setTexture(&textura);
    //shape.setTextureRect(sf::IntRect(2*16, 0*8 , 16, 8));
    shape.setOrigin(ancho_ladrillo/2, alto_ladrillo/2);
}

Ladrillo::Ladrillo(const Ladrillo& orig) {
}

Ladrillo::~Ladrillo() {
}

RectangleShape Ladrillo::get_shape(){return shape;}
bool Ladrillo::get_destruido() const {return destruido;}
void Ladrillo::set_destruido(bool flag){destruido = flag;}
float Ladrillo::get_ancho_ladrillo(){return ancho_ladrillo;}
float Ladrillo::get_alto_ladrillo(){return alto_ladrillo;}

