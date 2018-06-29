/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nave.hpp
 * Author: amygwyllion
 *
 * Created on 19 de febrero de 2017, 23:07
 */

#ifndef NAVE_HPP
#define NAVE_HPP
#include <SFML/Graphics.hpp>
#include "Rectangulo.hpp"
using namespace std;
using namespace sf;

class Nave : public Rectangulo{
    float ancho_nave, alto_nave;
    float velocidad_nave;
    Vector2f velocidad;
    Texture textura;
public:
    Nave(float,float);
    Nave(const Nave& orig);
    virtual ~Nave();
    
    RectangleShape get_shape();
    float get_velocidad_nave();
    void set_velocidad_nave(float);
    void actualizar_movimiento(float,float);
private:

};

#endif /* NAVE_HPP */

