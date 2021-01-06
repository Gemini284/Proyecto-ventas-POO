#ifndef CARRITO_H
#define CARRITO_H
#include <string>
#include "ProductoCarrito.h"
#include "ProductoAlmacen.h"


class Carrito{
  private:
    std::string cliente; //Representa el nombre del cliente que está haciendo la compra
    ProductoCarrito productos[10]; //Es donde se guardan los productos que se han metido al carrito. Su tamaño siempre es 10 aunque puede haber menos productos.
    int size; //esta variable entera te servirá para saber cuántos productos se han cargado en el almacén(Ojo productos no artículos).
  public:
    //Constructores
    Carrito();
    Carrito(std::string _cliente);
    //Setters y Getters
    std::string getCliente()const;
    void setCliente(std::string);
    int getSize()const;
    void setSize(int);
    //Métodos
    double total(); //regresa cuál es el monto total a pagar por los artículos del carrito.
    void print();
    void agregarProducto(std::string,int,ProductoAlmacen);
    void modificarProducto(std::string,int);
    ProductoCarrito regresarProducto(int);
};

//CONSTRUCTORES----------------------------------------------------------
Carrito::Carrito(){
    cliente = "";
    size = 0;
    for (int i=0;i<size;i++){
        productos[i] = ProductoCarrito();
    }
}

Carrito::Carrito(std::string _cliente){
  cliente = _cliente;
}

//SETTERS Y GETTERS--------------------------------------------------------
std::string Carrito::getCliente()const{
    return cliente;
}

void Carrito::setCliente(std::string _cliente){
    cliente = _cliente;
}

int Carrito::getSize()const{
    return size;
}

void Carrito::setSize(int _size){
    size = _size;
}

//MÉTODOS------------------------------------------------------------------
double Carrito::total(){ //funcion que regresa el total de la compra
    double total = 0;
    for(int i=0;i<size;i++){
        total += productos[i].subtotal();
    }
    return total;
}

void Carrito::print(){ //funcion que imprime los productos en el carrito
    for (int i=0; i<size;i++){
        if (productos[i].getCantidad() != 0){
            productos[i].print();
        }
    }
}

void Carrito::agregarProducto(std::string _id, int _cantidad,ProductoAlmacen _product){ //funcion que agrega productos al carrito y quita del almacen
    int cantVieja;
    if(size<=10){
        productos[size].setId(_id);
        productos[size].setNombre(_product.getNombre());
        productos[size].setPrecio(_product.getPrecio());
        productos[size].setCantidad(_cantidad);
    }
    size++;
}

void Carrito::modificarProducto(std::string _id, int _cantidad){ //funcion que modifica productos del carrito
    int cantVieja;
    for (int i=0;i<size;i++){
        if(_id == productos[i].getId()){
            productos[i].setCantidad(_cantidad);
        }
    }
}

ProductoCarrito Carrito::regresarProducto(int _i){ //funcion que regresa producto segun indice
    for (int i=0;i<size;i++){
        if (_i == i){
            return productos[i];
        }
    }
}

#endif