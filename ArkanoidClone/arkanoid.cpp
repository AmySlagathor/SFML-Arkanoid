/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arkanoid.cpp
 * Author: amygwyllion
 *
 * Created on 18 de febrero de 2017, 20:05
 */
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Bola.hpp"
#include "Nave.hpp"
#include "Ladrillo.hpp"


using namespace std;
using namespace sf;

int const ancho_ventana = 800, alto_ventana = 600;
float ladrillos_en_x = 11, ladrillos_en_y = 4;

int main() {
    
    RenderWindow ventana(sf::VideoMode(ancho_ventana, alto_ventana), "Arkanoid");
    ventana.setFramerateLimit(60);
    Bola bola(ancho_ventana/2, alto_ventana/2);
    Nave nave(ancho_ventana/2, alto_ventana - 50);
    
    /*TEXTO*/
    /*controles*/
    Font fuente;
    fuente.loadFromFile("resources/helvetica.ttf");
    Text texto;
    texto.setFont(fuente);
    texto.setString("CONTROLES: <- izquierda  -> derecha  Espacio: acelerar");
    texto.scale(0.8,0.8);
    texto.setPosition(180,nave.abajo()+10);
    texto.setColor(Color(255,255,255,150));
    /*contador*/
    Text contador;
    int vidas = 3;
    contador.setFont(fuente);
    contador.setString("Vidas : "+to_string(vidas));
    contador.setPosition(25,nave.abajo()+3);
    /**/
    
    /*FONDO*/
    Texture tex_fondo;
    tex_fondo.loadFromFile("resources/fondo.png");
    tex_fondo.setRepeated(true);
    Sprite fondo(tex_fondo);
    fondo.setScale(0.5,0.5);
    /**/
    
    /*LINEA_MUERTE*/
    RectangleShape linea_muerte(Vector2f(ancho_ventana,2));
    int alpha = 0;
    linea_muerte.setFillColor(Color(255,0,0,alpha));
    linea_muerte.setPosition(0,nave.abajo()+3);
    
    
    //vector para dibujar los ladrillos
    vector<Ladrillo> ladrillos;
    //reservamos memoria ya que sabemos cuanto va a ocupar el vector
    ladrillos.reserve(ladrillos_en_x*ladrillos_en_y);
    
    Ladrillo tmp(0,0);
    float ancho_ladrillo = tmp.get_ancho_ladrillo();
    float alto_ladrillo = tmp.get_alto_ladrillo();

    //rellenamos el vector de ladrillos
    for(int x = 0; x < ladrillos_en_x; x++){
        for(int y = 0; y < ladrillos_en_y; y++){
            ladrillos.emplace_back((x+1) * (ancho_ladrillo+3) + 22,(y+1) * (alto_ladrillo+3));
        }
    }
    
    while(ventana.isOpen()){    
        //ventana.clear(Color::Black);
        
        /**MANEJADOR DE EVENTOS**/
        Event evento;
        while (ventana.pollEvent(evento))
        {
            
            switch(evento.type){
                
                //Si se recibe el evento de cerrar la ventana la cierro
                case Event::Closed:
                    ventana.close();
                break;
                    
                //Se pulsó una tecla, imprimo su codigo
                case Event::KeyPressed:
                    
                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(evento.key.code) {
                        //Tecla ESC para salir
                        case Keyboard::Escape:
                            ventana.close();
                        break;
                        
                        case Keyboard::Space:
                            if(nave.get_velocidad_nave() < 10)
                             nave.set_velocidad_nave(nave.get_velocidad_nave()+5.0);
                            cout <<"Pressed Space: " << evento.key.code << " Velocidad nave: "<< nave.get_velocidad_nave()<< endl;
                        break;
                        
                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            cout <<"Pressed: " << evento.key.code <<endl;
                        break;      
                    }
                break;
                    
                case Event::KeyReleased:
                    switch(evento.key.code){
                        case Keyboard::Space:
                            if(nave.get_velocidad_nave() > 7)
                            nave.set_velocidad_nave(nave.get_velocidad_nave()-5.0);
                            cout <<"Released Space: "<< evento.key.code << " Velocidad nave: "<< nave.get_velocidad_nave() << endl;
                        break;
                        
                        default:
                            cout <<"Released: "<< evento.key.code << endl;
                        break;  
                    }
                break;
            }
        }
        /*CONTADOR*/
        if(bola.abajo() > nave.abajo()){
            if(vidas<=0){
                ladrillos.clear();
                ladrillos.reserve(ladrillos_en_x*ladrillos_en_y);
                for(int x = 0; x < ladrillos_en_x; x++){
                    for(int y = 0; y < ladrillos_en_y; y++){
                        ladrillos.emplace_back((x+1) * (ancho_ladrillo+3) + 22,(y+1) * (alto_ladrillo+3));
                    }
                }
                vidas = 3;
            }else{
                vidas--;
            }
            bola.shape_set_position(ancho_ventana/2, alto_ventana/2);
            bola.set_velocidad(Vector2f(bola.get_velocidad_bola()/2, bola.get_velocidad_bola()/2));
        }
        contador.setString("Vidas : "+to_string(vidas));
        bola.parpadeo();
        //actualizar el movimiento de la bola en cada frame
        bola.actualizar_movimiento(ancho_ventana, alto_ventana);
        nave.actualizar_movimiento(ancho_ventana, alto_ventana);
        
        /*LINEA DE MUERTE*/
        if(alpha<0){
            alpha=100;
        }
        linea_muerte.setFillColor(Color(255,0,0,alpha));
        alpha--;
        
        /*COLISIONES*/
        bola.colision_nave_bola(nave, bola);
        
        //un foreach en c++11, por cada objeto ladrillo en el vector ladrillos ejecuta colision_ladrillo_bola
        for(auto& ladrillo : ladrillos) bola.colision_ladrillo_bola(ladrillo, bola);
        /**/
        
        //ladrillos.eliminar(iterador1, iterador2); elimina todos los elementos del vector entre los dos iteradores
        //remove_if es un algoritmo stl que contiene un vector y un predicado y mueve todos los elementos que no cumplen con el predicado al principio del vector
        //remove_if sera el iterador de la funcion ladrillos.eliminar()
        
        /**TODO: PROBLEMA ya que los mueve al inicio del vector las texturas se van a tomar por culo**/
        ladrillos.erase(remove_if(begin(ladrillos), end(ladrillos),
                [](const Ladrillo& mladrillo){return mladrillo.get_destruido();}), end(ladrillos));
               
        //dibujamos el fondo:
        ventana.draw(fondo);
        //los controles
        ventana.draw(texto);
        //otra version equivalente a for(auto& ladrillo : ladrillos) ventana.draw(ladrillo.shape)
        for(int i = 0; i < ladrillos.size(); ++i){
            ventana.draw(ladrillos[i].get_shape());
        }   
        ventana.draw(bola.get_shape());
        ventana.draw(nave.get_shape());
        ventana.draw(linea_muerte);
        ventana.draw(contador);
        ventana.display();
    }
    return 0;
}
