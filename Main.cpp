#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#include "ProductoAlmacen.h"
#include "Almacen.h"
#include "ProductoCarrito.h"
#include "Carrito.h"

//FUNCIONES---------------------------------------------------------------------------------------------------------------------------
void mostrarAlmacen(Almacen _store){ //funcion que muestra el almacen
    cout << "******* PRODUCTOS *******" << endl;
    _store.print();
    cout << "--------------------------------------" << endl << endl;
}

void mostrarCarrito(Carrito _cart){ //funcion que muestra el carrito
    cout << endl << "******* Carrito de Compras de " << _cart.getCliente() << " *******" << endl;
    _cart.print();
    cout << "--------------------------------------" << endl << endl;
}

//MAIN--------------------------------------------------------------------------------------------------------------------------------
int main(){
    //VARIABLES------------------------------------------------------------------------------
    Almacen store;
    Carrito cart;
    string id,nombre,precio1,existencia1;
    int existencia;
    double precio;

    //LECTURA DE ARCHIVOS---------------------------------------------------------------------
    ifstream productos("productos.txt");
    string line;                  
    while(getline(productos, line)){
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline (ss,precio1,',');
        precio = stof(precio1);
        getline (ss,precio1,',');
        existencia = stoi(precio1);
        store.agregarProducto(ProductoAlmacen(id, nombre, precio, existencia));
    }
    productos.close();
    
    //MENÚ PRINCIPAL---------------------------------------------------------------------------
    char opcion;
    char opcion2;

    do{
        cout << endl;
        cout<<" 1) Ver Productos"<<endl;
        cout<<" 2) Comprar."<<endl; 
        cout<<" 3) Ver Carrito. "<<endl; //Ver y agregar productos al carrito
        cout<<" 4) Editar."<<endl; //Info del cliente y compra
        cout<<" 5) Pagar."<<endl;
        cout<<" 6) Salir"<<endl;
        cout<<"¿Que desea hacer? ";
        cin>>opcion;
        cout << endl;

        string idComprar, idEditar, idBorrar;
        int cantComprar, cantEditar;

        switch (opcion){
/* 1) VER PRODUCTOS ---------------------------------------------------------------------------------------------------
Muestra todos los productos que maneja el almacén en pantalla.
Una línea por producto y cada elemento del producto separado por comas y sin espacio antes y después de la coma.
Ej: A1,Pluma,12.5,100 */
            case '1': 
            {
                mostrarAlmacen(store);
            }
            break;

/* 2) COMPRAR ---------------------------------------------------------------------------------------------------------
Te lleva a un submenú donde elegirás un producto para agregarlo al carrito.
Este menú te pedirá que escribas id, cantidad y si está correcto o no lo que acabas de escribir.
Si dices que sí regresa al menú principal agregando el producto al carrito de compras y si dices que no te vuelve a pedir estos últimos 3 datos.
Validar que si tenga la cantidad de productos seleccionados en el almacén.*/
            case '2':
            {
                string correcto = "no";
                //SUBMENÚ------------------------------------------------------------------------------------------
                do{
                    cout << "Escriba el ID del producto a comprar: ";
                    cin >> idComprar;
                    cout << endl;
                    cout << "Escriba la cantidad del producto a comprar: ";
                    cin >> cantComprar;
                    cout << endl;
                    if (cantComprar <= store.regresarProducto(idComprar).getExistencia()){
                        cout << "Escogio comprar " << cantComprar << " productos con ID: " << idComprar << endl;
                        cout << "¿Es correcto? Escriba si o no: ";
                        cin >> correcto;
                        cout << endl;
                    }else{
                        cout << "No hay suficientes productos." << endl;
                    }
                }while(correcto != "si");
                cart.agregarProducto(idComprar,cantComprar,store.regresarProducto(idComprar));
            }
            break;
/* 3) VER CARRITO -------------------------------------------------------------------------------------------------------
Te despliega “Carrito de compras de [nombre]” y luego muestra los productos que has agregado al carrito de compra.
Un producto por línea, separados por coma sin espacio antes y después de la coma
y al final en una línea nueva imprime el total $ de los artículos puestos en el carrito.*/
            case '3':
            {
                mostrarCarrito(cart);
                cout << "Total: $" << cart.total() << endl;
            }
            break;
/* 4) EDITAR -------------------------------------------------------------------------------------------------------------
Te lleva a un submenú que te va a permitir cambiar el número de artículos a pedir de un producto o eliminar un producto del carrito de compra.
El submenú te pedirá el id del producto a modificar, la cantidad que quieres comprar de ese producto y si está correcto o no lo que acabas de escribir.
Si dices que sí regresa al menú principal y si dices que no te vuelve a pedir estos últimos 3 datos.
Validar que si tenga la cantidad de productos seleccionados en el almacén.*/
            case '4':
            {
                string correcto2 = "no";
                //SUBMENÚ------------------------------------------------------------------------------------------
                do{
                    cout << "1) Cambiar cantidad a pedir." << endl;
                    cout << "2) Eliminar producto del carrito." << endl;
                    cout << "3) Regresar a menú principal." << endl;
                    cout << "¿Que desea hacer? ";
                    cin >> opcion2;
                    cout << endl;

                    switch(opcion2){
                // 1) CAMBIAR CANTIDAD----------------------------------------------------------------------------------
                        case '1':
                        {
                            do{
                                cout << "Escriba el ID del producto a editar: ";
                                cin >> idEditar;
                                cout << endl;
                                cout << "Escriba la nueva cantidad del producto: ";
                                cin >> cantEditar;
                                cout << endl;
                                if (cantEditar <= store.regresarProducto(idEditar).getExistencia()){
                                    cout << "Escogio comprar " << cantEditar << " productos con ID: " << idEditar << endl;
                                    cout << "¿Es correcto? Escriba si o no: ";
                                    cin >> correcto2;
                                    cout << endl;
                                }else{
                                    cout << "No hay suficientes productos." << endl;
                                }
                            }while(correcto2 != "si");
                            cart.modificarProducto(idEditar,cantEditar);
                        }
                        break;

                // 2) ELIMINAR PRODUCTO--------------------------------------------------------------------------------
                        case '2':
                        {
                            cout << "Escriba el ID del producto a eliminar: ";
                            cin >> idBorrar;
                            cout << endl;
                            cart.modificarProducto(idBorrar,0);
                        }
                        break;

                // 3) REGRESAR------------------------------------------------------------------------------------------
                        case '3':
                        {
                            cout << "Regreso al menú principal." << endl;
                        }
                        break;

                //INVALIDO------------------------------------------------------------------------------------------
                        default:
                            cout << "Ingrese una opción válida." << endl;
                            break;
                    }
                }while(opcion2 != '3');
            }
            break;

/* 5) PAGAR ---------------------------------------------------------------------------------------------------------------
Simplemente te dice de cuanto fue tu cuenta, te da las gracias por tu compra y “vacía” el carrito y descuenta los productos del almacén*/
            case '5':
            {
                cout << "Tu cuenta fue de $" << cart.total() << endl;
                for(int i=0;i < cart.getSize();i++){
                  store.retirarProductos(cart.regresarProducto(i),cart.regresarProducto(i).getId());
                }
                cart = Carrito();
                
            }
            
            break;

/* 6) SALIR -----------------------------------------------------------------------------------------------------------------
Termina el programa. Sólo en esta función no regresa al menú principal, las demás al final regresan al menú.*/
            case '6':
            {
                cout << "Has salido del programa." << endl;
            }
            break;

//INVALIDA ---------------------------------------------------------------------------------------------------------------
            default:
                cout << "Escoge una opción válida." << endl;
            break;
        }
    }while(opcion!='6');
    return 0;
}