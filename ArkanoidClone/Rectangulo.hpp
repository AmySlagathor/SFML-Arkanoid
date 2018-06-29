/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rectangulo.hpp
 * Author: amygwyllion
 *
 * Created on 19 de febrero de 2017, 23:01
 */

#ifndef RECTANGULO_HPP
#define RECTANGULO_HPP
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Rectangulo {
protected:
    RectangleShape shape;
public:
    Rectangulo();
    Rectangulo(const Rectangulo& orig);
    virtual ~Rectangulo();
    float get_x();
    float get_y();
    float izquierda();
    float derecha();
    float arriba();
    float abajo();
private:

};

#endif /* RECTANGULO_HPP */

