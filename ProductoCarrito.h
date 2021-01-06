#ifndef PRODUCTOCARRITO_H
#define PRODUCTOCARRITO_H
#include <string>
//Esta clase te servirá para representar los artículos que están puestos en un carrito de compra.
class ProductoCarrito{
  private:
    std::string id; //Es tipo texto y representa el código del producto
    std::string nombre; //Es la descripción del producto
    double precio; //representa el precio unitario del producto.
    int cantidad; //representa cuántos artículos de ese producto se han agregado al carrito.
  public:
    //Constructores
    ProductoCarrito();
    ProductoCarrito(std::string _id, std::string _nombre, double _precio, int _cantidad);
    //Setters y Getters
    std::string getId()const;
    std::string getNombre()const;
    double getPrecio()const;
    int getCantidad()const;
    void setId(std::string);
    void setNombre(std::string);
    void setPrecio(double);
    void setCantidad(int);
    //Métodos
    double subtotal(); //regresa cuál es el monto por la compra este producto.
    void print();
};

//CONSTRUCTORES----------------------------------------------------------------------------
ProductoCarrito::ProductoCarrito(){
    id = "";
    nombre = "";
    precio = 0.0;
    cantidad = 0;
}

ProductoCarrito::ProductoCarrito(std::string _id, std::string _nombre, double _precio, int _cantidad){
    id = _id;
    nombre = _nombre;
    precio = _precio;
    cantidad = _cantidad;
}

//SETTERS Y GETTERS------------------------------------------------------------------------
std::string ProductoCarrito::getId()const{
    return id;
}

std::string ProductoCarrito::getNombre()const{
    return nombre;
}

double ProductoCarrito::getPrecio()const{
    return precio;
}

int ProductoCarrito::getCantidad()const{
    return cantidad;
}

void ProductoCarrito::setId(std::string _id){
    id = _id;
}

void ProductoCarrito::setNombre(std::string _nombre){
    nombre = _nombre;
}

void ProductoCarrito::setPrecio(double _precio){
    precio = _precio;
}

void ProductoCarrito::setCantidad(int _cantidad){
    cantidad = _cantidad;
}


//MÉTODOS-------------------------------------------------------------------------------------
double ProductoCarrito::subtotal(){
    double subtotal;
    subtotal = precio * cantidad;
    return subtotal;
}

void ProductoCarrito::print(){ //funcion que imprime el producto
    std::cout << id << "," << nombre << "," << precio << "," << cantidad << std::endl;
}

#endif