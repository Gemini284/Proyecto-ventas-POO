#ifndef ALMACEN_H
#define ALMACEN_H
#include <string>
#include "ProductoAlmacen.h"
#include "ProductoCarrito.h"
//Esta clase representa el almacén con los productos con los que se cuenta. O sea, es un arreglo de objetos ProductoAlmacen.
class Almacen{
  private:
    ProductoAlmacen productos[20]; //Es donde se guardan los productos. Su tamaño siempre es 20 aunque no necesariamente este almacén está lleno
    int size; //Esta variable entera te servirá para saber cuántos productos se han cargado en el almacén
  public:
    //Constructores
    Almacen();
    Almacen(int _size);
    //Getters y Setters
    int getSize()const;
    void setSize(int);
    //Métodos
    void agregarProducto(ProductoAlmacen);
    void print();
    ProductoAlmacen regresarProducto(std::string);
    void retirarProductos(ProductoCarrito,std::string);
};

//CONSTRUCTORES----------------------------------------------
Almacen::Almacen(){
    size = 0;
    for (int i=0;i<20;i++){
        productos[i] = ProductoAlmacen();
    }
}

//GETTERS Y SETTERS-------------------------------------------
int Almacen::getSize()const{
    return size;
}

void Almacen::setSize(int _size){
    size = _size;
}

//MÉTODOS-----------------------------------------------------
void Almacen::agregarProducto(ProductoAlmacen x){ //funcion que agrega productos al almacen
  if(size<20){
    productos[size] = x;
    size++;
  }
}

void Almacen::print(){ //funcion que imprime los productos del almacen
    for(int i=0; i<size; i++){
        productos[i].print();
    }
}

ProductoAlmacen Almacen::regresarProducto(std::string _id){ //funcion que regresa un producto del almacen segun su ID
    for (int i=0;i<size;i++){
        if (_id == productos[i].getId()){
            return productos[i];
        }
    }
}

void Almacen::retirarProductos(ProductoCarrito _product, std::string _id){ //funcion que cambia la existencia del producto segun su id
    int cantPC = _product.getCantidad();
    for (int i=0;i<size;i++){
        if (_id == productos[i].getId()){
            int cantActual = productos[i].getExistencia();
            productos[i].setExistencia(cantActual-cantPC);
        }
    }
}

#endif