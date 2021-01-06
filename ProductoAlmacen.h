#ifndef PRODUCTOALMACEN_H
#define PRODUCTOALMACEN_H
#include <iostream>
#include <string>
//Esta clase representa los artículos que maneja la tienda.
class ProductoAlmacen{
  private:
    std::string id; //Es tipo texto y representa el código del producto
    std::string nombre; //Es la descripción del producto
    double precio; //representa el precio unitario del producto.
    int existencia; //Representa cuántas unidades se tiene en almacén
  public:
    //Constructores
    ProductoAlmacen();
    ProductoAlmacen(std::string id, std::string nombre, double precio, int existencia); 
    //Setters y Getters
    std::string getId()const;
    std::string getNombre()const;
    double getPrecio()const;
    int getExistencia()const;
    void setId(std::string);
    void setNombre(std::string);
    void setPrecio(double);
    void setExistencia(int);
    //Métodos
    void print();
};

//CONSTRUCTORES-----------------------------------------------------------------
ProductoAlmacen::ProductoAlmacen(){
    id = "";
    nombre = "";
    precio = 0.0;
    existencia = 0;
}

ProductoAlmacen::ProductoAlmacen(std::string _id, std::string _nombre, double _precio, int _existencia){
    id = _id;
    nombre = _nombre;
    precio = _precio;
    existencia = _existencia;
}

//SETTERS Y GETTERS----------------------------------------------------------------
std::string ProductoAlmacen::getId()const{
    return id;
}

std::string ProductoAlmacen::getNombre()const{
    return nombre;
}

double ProductoAlmacen::getPrecio()const{
    return precio;
}

int ProductoAlmacen::getExistencia()const{
    return existencia;
}

void ProductoAlmacen::setId(std::string _id){
    id = _id;
}

void ProductoAlmacen::setNombre(std::string _nombre){
    nombre = _nombre;
}

void ProductoAlmacen::setPrecio(double _precio){
    precio = _precio;
}

void ProductoAlmacen::setExistencia(int _existencia){
    existencia = _existencia;
}


//MÉTODOS---------------------------------------------------------------------------
void ProductoAlmacen::print(){ //funcion que imprime el producto
    std::cout << id << "," << nombre << "," << precio << "," << existencia << std::endl;
}

#endif