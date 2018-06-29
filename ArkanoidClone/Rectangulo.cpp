/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rectangulo.cpp
 * Author: amygwyllion
 * 
 * Created on 19 de febrero de 2017, 23:01
 */

#include "Rectangulo.hpp"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Rectangulo::Rectangulo() {
}

Rectangulo::Rectangulo(const Rectangulo& orig) {
}

Rectangulo::~Rectangulo() {
}

float Rectangulo::get_x(){ return shape.getPosition().x;}
float Rectangulo::get_y(){ return shape.getPosition().y;}
float Rectangulo::izquierda(){ return get_x() - shape.getSize().x / 2;}
float Rectangulo::derecha(){ return get_x() + shape.getSize().x / 2;}
float Rectangulo::arriba(){ return get_y() - shape.getSize().y / 2;}
float Rectangulo::abajo(){ return get_y() + shape.getSize().y / 2;}
