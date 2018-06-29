/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bola.cpp
 * Author: amygwyllion
 * 
 * Created on 19 de febrero de 2017, 22:13
 */

#include "Bola.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Bola::Bola(float x, float y) {  
    velocidad_bola = 8.0;
    radio = 10.0;
    velocidad = Vector2f(-velocidad_bola, -velocidad_bola);
        if (!textura.loadFromFile("resources/sprites.png"))
    {
        cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
    shape.setPosition(x, y);
    shape.setRadius(radio);
    //shape.setFillColor(Color::Red);
    shape.setTexture(&textura);
    shape.setTextureRect(sf::IntRect(7*16 , 17*8 , 7 , 7));
    shape.setOrigin(radio, radio);
    alpha = 255;
}

Bola::Bola(const Bola& orig) {
}

Bola::~Bola() {
}

float Bola::get_x(){ return shape.getPosition().x;} //decuelve el centro de la bola en el eje x
float Bola::get_y(){ return shape.getPosition().y;}// devuelve el centro de la bola en el eje y
CircleShape Bola::get_shape(){ return shape;}
void Bola::shape_set_position(float x, float y){ shape.setPosition(x,y);}
float Bola::get_velocidad_x(){ return velocidad.x;}
float Bola::get_velocidad_y(){ return velocidad.y;}
float Bola::get_velocidad_bola(){ return velocidad_bola;}
void Bola::set_velocidad_x(float mvelocidad){ velocidad.x = mvelocidad;}
void Bola::set_velocidad_y(float mvelocidad){ velocidad.y = mvelocidad;}
void Bola::set_velocidad_bola(float mvelocidad){ velocidad_bola = mvelocidad;}
void Bola::set_velocidad(Vector2f mvelocidad){ velocidad = mvelocidad;}
float Bola::izquierda(){ return get_x() - shape.getRadius();} // ya que la funcion x() devuelve el centro del circulo si le restamos el radio en el eje x obtenemos el borde derecho
float Bola::derecha(){ return get_x() + shape.getRadius();} // el centro mas el radio en el eje x obtenemos el borde derecho
float Bola::arriba(){ return get_y() - shape.getRadius();}// el centro menos el radio en el eje y obtenemos el borde de arriba
float Bola::abajo(){ return get_y() + shape.getRadius();}// el centro mas el radio en el eje y obtenemos el borde de abajo

void Bola::actualizar_movimiento(float ancho_ventana, float alto_ventana){//actualizar el movimiento de la bola
    shape.move(velocidad);

    //para saber si la bola se sale de la pantalla basta con calcular su posicion y si se encuentra fuera le cambiamos la velocidad para que vaya en la otra direccion
    //las coordenadas de la pantalla van de (0,0) en la esquina superior izquierda hasta (ancho_ventana, alto_ventana) en la esquina inferior derecha
    if(izquierda() < 0 ) velocidad.x = velocidad_bola;// si se sale por la izquierda le ponemos velocidad positiva para que cambie de dirección
    else if(derecha() > ancho_ventana ) velocidad.x = -velocidad_bola; // si se sale por la derecha le ponemos velocidad negativa

    if(arriba() < 0) velocidad.y = velocidad_bola;// si se sale por arriba le ponemos velocidad positiva
    else if(abajo() > alto_ventana ) velocidad.y = -velocidad_bola;// si se sale por abajo le ponemos velocidad negativa
}

//funcion generica para comprobar si dos figuras colisionan
//se comprueba de manera que si la parte derecha de un objeto A esta en una posicion mayor que la parte izquierda de otro objeto B y a su vez la parte superior del objeto A está en una posicion superior que la parte inferior del objeto B significa que estan interseccionados
template <class T1, class T2>
bool Bola::isIntersecting(T1& mA, T2& mB)
{
    return mA.derecha() >= mB.izquierda() && mA.izquierda() <= mB.derecha() && //si la parte de la derecha del objeto mA está dentro de la parte izqierda del objeto mB o viceversa
           mA.abajo() >= mB.arriba() && mA.arriba() <= mB.abajo(); //si la parte inferior del objeto mA está dentro de la parte superior del objeto mB o viceversa
}

void Bola::colision_ladrillo_bola(Ladrillo& mladrillo, Bola& mbola){
    
    if(!isIntersecting(mladrillo, mbola)) return;
    
    mladrillo.set_destruido(true);
    
    //calculamos las colisiones en todas las direcciones, de la misma manera que para la nave y la bola
    //empezamos primero calculando la magnitud de las colisiones, restando los bordes de los dos objetos
    float colision_izquierda = mbola.derecha() - mladrillo.izquierda();
    float colision_derecha = mladrillo.derecha() - mbola.izquierda();
    float colision_arriba = mbola.arriba() - mladrillo.abajo();
    float colision_abajo = mladrillo.arriba() - mbola.abajo();
    
    //si la magnitud de la colision izquierda es menor que la magnitud de la colision derecha significa que la bola esta golpeando al ladrillo por la izquierda
    bool bola_por_izquierda = abs(colision_izquierda) < abs(colision_derecha);
    bool bola_por_arriba = abs(colision_arriba) < abs(colision_abajo);
   
    //la minima colision en el eje x; es colision_izquierda si se cumple bola_por_izquierda : de otro modo sera colision_derecha
    float min_colision_x = (bola_por_izquierda ? colision_izquierda : colision_derecha);
    float min_colision_y = (bola_por_arriba ? colision_arriba : colision_abajo);
    float mvelocidad;
    
    //si la magnitud minima en el eje x es menor que la colision minima en el eje y significa que la bola ha colisionado horizontalmente, por lo contrario habra sido verticalmente
    if(abs(min_colision_x) < abs(min_colision_y)){//si la colision es horizontal
        //cambiamos la direccion de la bola
        //si se cumple que bola_por_izquierda entonces -velocidad_bola(hacia la izquierda) : en cualquier otro caso velocidad_bola(hacia la derecha)
        mvelocidad = bola_por_izquierda ? -mbola.get_velocidad_bola() : mbola.get_velocidad_bola();
        mbola.set_velocidad_x(mvelocidad);
    }
    else{//si la colision es vertical
        //si se cumple que bola_por_arriba entondes velocidad_bola(hacia arriba) : en cualquier otro caso -velocidad_bola(hacia abajo)
        mvelocidad  = bola_por_arriba ? mbola.get_velocidad_bola() : -mbola.get_velocidad_bola();
        mbola.set_velocidad_y(mvelocidad);
    }
    
    
}

void Bola::colision_nave_bola(Nave& mnave, Bola& mbola){
    
    //si no estan interseccionando no hacemos nada
    if(!isIntersecting(mnave,mbola)) return;
    
    //por el contrario necesitamos cambiar la dirección y de la bola
    mbola.set_velocidad_y(-mbola.get_velocidad_bola());
    
    //redireccionamos la bola segun donde haya golpeado a la nave en el eje x
    //comprobamos el centro de la bola y el centro de la nave, si el centro de la bola es menor que el centro de la nave entonces la bola ira hacia la izquierda
    if(mbola.get_x() < mnave.get_x()) mbola.set_velocidad_x(-mbola.get_velocidad_bola());
    //por el contrario, si el centro de la bola esta en una posicion mayor en el eje x la bola ira hacia la derecha
    else mbola.set_velocidad_x(mbola.get_velocidad_bola());
}

void Bola::parpadeo(){   
    if(alpha<150){
        alpha = 255;
    }
    shape.setFillColor(Color(0,255,0,alpha));
    alpha--;
}