/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ladrillo.hpp
 * Author: amygwyllion
 *
 * Created on 19 de febrero de 2017, 23:16
 */

#ifndef LADRILLO_HPP
#define LADRILLO_HPP
#include <SFML/Graphics.hpp>
#include "Rectangulo.hpp"
using namespace std;
using namespace sf;

class Ladrillo : public Rectangulo{
    float ancho_ladrillo, alto_ladrillo;
    bool destruido;
    Texture textura;
public:
    Ladrillo(float,float);
    Ladrillo(const Ladrillo& orig);
    virtual ~Ladrillo();
    
    RectangleShape get_shape();
    bool get_destruido() const;
    void set_destruido(bool);
    float get_ancho_ladrillo();
    float get_alto_ladrillo();
private:

};

#endif /* LADRILLO_HPP */

