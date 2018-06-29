/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bola.hpp
 * Author: amygwyllion
 *
 * Created on 19 de febrero de 2017, 22:13
 */

#ifndef BOLA_HPP
#define BOLA_HPP
#include <SFML/Graphics.hpp>
#include "Ladrillo.hpp"
#include "Nave.hpp"

using namespace std;
using namespace sf;


class Bola {
    float x, y;
    float velocidad_bola;
    float radio;
    CircleShape shape;
    Vector2f velocidad;
    Texture textura;
    int alpha;
    
public:
    Bola(float,float);
    Bola(const Bola& orig);
    virtual ~Bola();
    float get_x();
    float get_y();
    CircleShape get_shape();
    void shape_set_position(float, float);
    float get_velocidad_x();
    float get_velocidad_y();
    float get_velocidad_bola();
    void set_velocidad(Vector2f);
    void set_velocidad_x(float);
    void set_velocidad_y(float);
    void set_velocidad_bola(float);
    float arriba();
    float abajo();
    float izquierda();
    float derecha();
    void actualizar_movimiento(float,float);
    template<class T1,class T2> bool isIntersecting(T1&, T2&);
    void colision_ladrillo_bola(Ladrillo&, Bola&);
    void colision_nave_bola(Nave&, Bola&);
    void parpadeo();
    
private:

};

#endif /* BOLA_HPP */

