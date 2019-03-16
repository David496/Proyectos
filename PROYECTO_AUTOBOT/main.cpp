#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

//id y contraseña del administrador
#define USER "admin"
#define PASS "admin"
using namespace std;

//ESTRUCTURAS

//CLIENTE
struct fecha
{
    int dia;
    int mes;
    int anio;
};

typedef fecha TpFecha;

struct licencia
{
    string numero_licencia;
    TpFecha fecha_caducidad;
};

typedef licencia TpLicencia;

struct tarjeta
{
    string nro_tarjeta;
    string tipo_tarjeta;
    TpFecha fecha_caducidad_Tcredito;
};

typedef tarjeta TpTarjeta;

struct cliente
{
    string id;
    string nombre;
    string apellidos;
    string dni;
    string correo;
    string telefono;
    TpLicencia licencia_conducir;
    TpTarjeta tarjeta_credito;
    int edad;
    string estado;
};

typedef cliente Tpcliente;

//AUTOMOVIL
struct automovil
{
    string id_auto;
    string matricula_auto;
    string marca;
    string modelo;
    string color;
    string tipo;
    float precio;
    string estado;
};

typedef automovil TpAutomovil;

//RESERVA
struct reserva
{
    string id_cliente;
    string id_vehiculo;
    TpFecha fecha_inicial;
    TpFecha fecha_final;
    string estado;
    float precio_total;
};

typedef reserva TpReserva;

//FUNCIONES
void menu_principal();
void menu_administrador();
void menu_cliente();

void registro_cliente();
void consulta_lista_clientes();
void consulta_datos_por_cliente();
void eliminar_cliente();

void agregar_vehiculo();
void consulta_lista_vehiculos();
void consulta_lista_vehiculos_cliente();
void consulta_datos_por_vehiculo();
void eliminar_vehiculo();

int numero_dias(int dia, int mes, int anio);
void lectura_vehiculo(string id);
void lectura_cliente(string id);

void reservar_vehiculo();
void consulta_lista_reservas();

int main()
{
    string user,password;
    char opc;
    do
    {
        menu_principal();
        cout<<"\nINGRESE LA OPCION --->";
        cin>>opc;
        switch(opc)
        {
        case '1':
            //login
            do
            {
                system("cls");
                cout<<"\t------------------------------------------"<<endl;
                cout<<"\t----------------AUTOBOT.SA----------------"<<endl;
                cout<<"\t------------------------------------------"<<endl;
                cout<<"\t----SISTEMA DE ALQUILER DE AUTOMOVILES----"<<endl;
                cout<<"\t------------------------------------------"<<endl;
                cout<<"\t-----------LOGIN ADMINISTRADOR------------"<<endl;
                cout<<"\t------------------------------------------"<<endl;
                fflush(stdin);
                cout<<"\tINGRESE ID: ";
                getline(cin,user);
                cout<<"\tINGRESE CONTRASEÑA: ";
                getline(cin,password);
                if(user==USER && password==PASS)
                {
                    menu_administrador();
                }
                else
                {
                    cout<<"ID O CONTRASEÑA INCORRECTO"<<endl;
                }
                system("PAUSE");
            }
            while(user!=USER && password!=PASS);
            break;

        case '2':
            menu_cliente();
            break;

        default:
            if(opc!='0')
            {
                cout<<"INGRESE LA OPCION CORRECTA..."<<endl;
            }
            break;
        }
        system("PAUSE");
    }
    while(opc!='0');

    cin.get();
}

void menu_principal()
{
    system("cls");
    cout<<"\t------------------------------------------"<<endl;
    cout<<"\t----------------AUTOBOT.SA----------------"<<endl;
    cout<<"\t------------------------------------------"<<endl;
    cout<<"\t----SISTEMA DE ALQUILER DE AUTOMOVILES----"<<endl;
    cout<<"\t------------------------------------------"<<endl;
    cout<<"\t--------------MENU PRINCIPAL--------------"<<endl;
    cout<<"\t------------------------------------------"<<endl;

    cout<<"\t1. ADMINISTRADOR"<<endl;
    cout<<"\t2. CLIENTE"<<endl;
    cout<<"\t0. SALIR"<<endl;
}

void menu_administrador()
{
    char opc_admin;
    do
    {
        system("cls");
        cout<<"\t------------------------------------------"<<endl;
        cout<<"\t----------------AUTOBOT.SA----------------"<<endl;
        cout<<"\t------------------------------------------"<<endl;
        cout<<"\t----SISTEMA DE ALQUILER DE AUTOMOVILES----"<<endl;
        cout<<"\t------------------------------------------"<<endl;
        cout<<"\t-----------MENU ADMINISTRADOR-------------"<<endl;
        cout<<"\t------------------------------------------"<<endl;

        cout<<"\t1. REGISTRO DE CLIENTE"<<endl;
        cout<<"\t2. CONSULTAR LISTA DE CLIENTES"<<endl;
        cout<<"\t3. CONSULTAR DATOS POR CLIENTE"<<endl;
        cout<<"\t4. ELIMINAR CLIENTE"<<endl;
        cout<<"\t5. AGREGAR VEHICULO"<<endl;
        cout<<"\t6. CONSULTAR LISTA DE VEHICULOS"<<endl;
        cout<<"\t7. CONSULTAR DATOS POR VEHICULO"<<endl;
        cout<<"\t8. ELIMINAR VEHICULO"<<endl;
        cout<<"\t9. RESERVAR VEHICULO"<<endl;
        cout<<"\ta. CONSULTAR LISTA DE RESERVAS"<<endl;
        cout<<"\tb. REGISTRAR DEVOLUCION DE VEHICULO"<<endl;
        cout<<"\t0. SALIR"<<endl<<endl;
        cout<<"INGRESE LA OPCION --->";
        cin>>opc_admin;

        switch(opc_admin)
        {
        case '1':
            registro_cliente();
            break;
        case '2':
            consulta_lista_clientes();
            break;
        case '3':
            consulta_datos_por_cliente();
            break;
        case '4':
            eliminar_cliente();
            break;
        case '5':
            agregar_vehiculo();
            break;
        case '6':
            consulta_lista_vehiculos();
            break;
        case '7':
            consulta_datos_por_vehiculo();
            break;
        case '8':
            eliminar_vehiculo();
            break;
        case '9':
            reservar_vehiculo();
            break;
        case 'a':
            consulta_lista_reservas();
            break;
        case 'b':
            break;
        default:
            if(opc_admin!='0')
            {
                cout<<"INGRESE LA OPCION CORRECTA..."<<endl;
            }
            break;
        }
        system("PAUSE");
    }
    while(opc_admin!='0');
}

void menu_cliente()
{
    char opc_cliente;
    do
    {
        system("cls");
        cout<<"\t------------------------------------------"<<endl;
        cout<<"\t----------------AUTOBOT.SA----------------"<<endl;
        cout<<"\t------------------------------------------"<<endl;
        cout<<"\t----SISTEMA DE ALQUILER DE AUTOMOVILES----"<<endl;
        cout<<"\t------------------------------------------"<<endl;
        cout<<"\t---------------MENU CLIENTE---------------"<<endl;
        cout<<"\t------------------------------------------"<<endl;

        cout<<"\t1. CONSULTAR OFERTA DE VEHICULOS"<<endl;
        cout<<"\t2. CONSULTAR DATOS POR CLIENTE"<<endl;
        cout<<"\t0. SALIR"<<endl<<endl;

        cout<<"INGRESE LA OPCION --->";
        cin>>opc_cliente;

        switch(opc_cliente)
        {
        case '1':
            consulta_lista_vehiculos_cliente();
            break;
        case '2':
            consulta_datos_por_cliente();
            break;
        default:
            if(opc_cliente!='0')
            {
                cout<<"INGRESE LA OPCION CORRECTA..."<<endl;
            }
            break;
        }
        system("PAUSE");
    }
    while(opc_cliente!='0');
}

void registro_cliente()
{
    system("cls");
    Tpcliente client;
    fflush(stdin);
    cout<<"---------------REGISTRO DE CLIENTE---------------"<<endl<<endl;
    cout<<"INGRESE UN ID DE CLIENTE: ";
    getline(cin,client.id);
    cout<<"INGRESE NOMBRES: ";
    getline(cin,client.nombre);
    cout<<"INGRESE APELLIDOS: ";
    getline(cin,client.apellidos);
    cout<<"INGRESE DNI: ";
    getline(cin,client.dni);
    cout<<"INGRESE CORREO: ";
    getline(cin,client.correo);
    cout<<"INGRESE TELEFONO: ";
    getline(cin,client.telefono);
    fflush(stdin);
    cout<<"INGRESE EDAD: ";
    cin>>client.edad;
    fflush(stdin);
    cout<<"\n-----DATOS DE LA LICENCIA DE CONDUCIR-----"<<endl;
    cout<<"INGRESE NUMERO DE LICENCIA: ";
    getline(cin,client.licencia_conducir.numero_licencia);
    cout<<"FECHA DE CADUCIDAD."<<endl;
    fflush(stdin);
    cout<<"INGRESE DIA: ";
    cin>>client.licencia_conducir.fecha_caducidad.dia;
    cout<<"INGRESE MES: ";
    cin>>client.licencia_conducir.fecha_caducidad.mes;
    cout<<"INGRESE AÑO: ";
    cin>>client.licencia_conducir.fecha_caducidad.anio;
    fflush(stdin);
    cout<<"\n-----DATOS DE LA TARJETA DE CREDITO-----"<<endl;
    cout<<"INGRESE NUMERO DE TARJETA: ";
    getline(cin,client.tarjeta_credito.nro_tarjeta);
    cout<<"INGRESE TIPO DE TARJETA(DEBITO O CREDITO): ";
    getline(cin,client.tarjeta_credito.tipo_tarjeta);
    fflush(stdin);
    cout<<"FECHA DE CADUCIDAD."<<endl;
    cout<<"INGRESE DIA: ";
    cin>>client.tarjeta_credito.fecha_caducidad_Tcredito.dia;
    cout<<"INGRESE MES: ";
    cin>>client.tarjeta_credito.fecha_caducidad_Tcredito.mes;
    cout<<"INGRESE AÑO: ";
    cin>>client.tarjeta_credito.fecha_caducidad_Tcredito.anio;
    client.estado="ACTIVO";

    ofstream escribir;
    //crea archivo y agrega dato o agrega datos si el archivo existe
    escribir.open("registro_cliente.txt",ios::out|ios::app);
    if(escribir.is_open())
    {
        escribir<<"ID DE CLIENTE: "<<client.id<<endl;
        escribir<<"NOMBRES: "<<client.nombre<<endl;
        escribir<<"APELLIDOS: "<<client.apellidos<<endl;
        escribir<<"DNI: "<<client.dni<<endl;
        escribir<<"CORREO: "<<client.correo<<endl;
        escribir<<"TELEFONO: "<<client.telefono<<endl;
        escribir<<"EDAD: "<<client.edad<<endl;
        escribir<<"NUMERO DE LICENCIA: "<<client.licencia_conducir.numero_licencia<<endl;
        escribir<<"FECHA DE CADUCIDAD LICENCIA: "<<client.licencia_conducir.fecha_caducidad.dia<<" "<<client.licencia_conducir.fecha_caducidad.mes<<" "<<client.licencia_conducir.fecha_caducidad.anio<<endl;
        escribir<<"NUMERO DE TARJETA: "<<client.tarjeta_credito.nro_tarjeta<<endl;
        escribir<<"TIPO DE TARJETA: "<<client.tarjeta_credito.tipo_tarjeta<<endl;
        escribir<<"FECHA DE CADUCIDAD TARJETA: "<<client.tarjeta_credito.fecha_caducidad_Tcredito.dia<<" "<<client.tarjeta_credito.fecha_caducidad_Tcredito.mes<<" "<<client.tarjeta_credito.fecha_caducidad_Tcredito.anio<<endl;
        escribir<<"ESTADO: "<<client.estado<<endl<<endl;
        escribir.close();
    }
    else
    {
        cout<<"EL ARCHIVO NO SE PUEDE ABRIR"<<endl;
    }
}

void consulta_lista_clientes()
{
    system("cls");
    string texto;
    int i=1;

    ifstream lectura;
    //lectura de archivos
    lectura.open("registro_cliente.txt",ios::out|ios::in);
    if(lectura.is_open())
    {
        cout<<"-------------------LISTA DE CLIENTES-------------------"<<endl<<endl;
        cout<<"=========================================="<<endl;
        while(!lectura.eof())
        {
            if(i==1||i==2||i==3||i==13)
            {
                getline(lectura,texto);
                cout<<texto<<endl;
            }
            else
            {
                getline(lectura,texto);
            }
            if(i==14)
            {
                cout<<"=========================================="<<endl;
                i=0;
            }
            i++;
        }
        lectura.close();
    }
    else
    {
        cout<<"EL ARCHIVO NO SE PUEDE ABRIR"<<endl;
    }
}

void lectura_cliente(string id)
{
    string texto;
    string linea="ID DE CLIENTE: ";
    bool encontrado= false;
    //concatenar
    id=linea+id;
    ifstream lectura;
    //lectura de archivos
    lectura.open("registro_cliente.txt",ios::out|ios::in);
    if(lectura.is_open())
    {
        while(!lectura.eof())
        {
            getline(lectura,texto);
            if(id==texto)
            {
                encontrado = true;
                cout<<"=============================================="<<endl;
                cout<<"\t"<<texto<<endl;
                for(int i=0; i<12; i++)
                {
                    getline(lectura,texto);
                    cout<<"\t"<<texto<<endl;
                }
                cout<<"=============================================="<<endl;
            }
        }
        if(encontrado==false)
        {
            cout<<"NO SE ENCUENTRA USUARIO EN EL REGISTRO..."<<endl;
        }
        lectura.close();
    }
    else
    {
        cout<<"EL ARCHIVO NO SE PUEDE ABRIR"<<endl;
    }
}

void consulta_datos_por_cliente()
{
    system("cls");
    string id;

    cout<<"--------------------CONSULTA DE DATOS POR CLIENTE--------------------"<<endl<<endl;
    cout<<"INGRESE ID DEL CLIENTE --->";
    fflush(stdin);
    getline(cin,id);
    cout<<endl;
    lectura_cliente(id);
}

void eliminar_cliente()
{
    system("cls");
    bool encontrado= false;
    string texto;
    string linea="ID DE CLIENTE: ";
    string id;
    char option;

    cout<<"--------------------ELIMINACION DE CLIENTE--------------------"<<endl<<endl;
    cout<<"INGRESE ID DEL CLIENTE --->";
    fflush(stdin);
    getline(cin,id);
    cout<<endl;
    //concatenar
    id=linea+id;

    do
    {
        cout<<"¿DESEA ELIMINAR ESTE CLIENTE?(s = si / n = no): ";
        cin>>option;
    }
    while(option!='s'&&option!='n');

    if(option=='s')
    {
        ofstream aux;
        ifstream lectura;
        //lectura de archivos
        lectura.open("registro_cliente.txt",ios::out|ios::in);
        //escritura en un archivo temporal
        aux.open("auxiliar_cliente.txt", ios::out);

        if(lectura.is_open() && aux.is_open())
        {
            while(!lectura.eof())
            {
                getline(lectura,texto);
                aux<<texto<<endl;
                if(id==texto)
                {
                    encontrado = true;
                    for(int i=0; i<12; i++)
                    {
                        if(i==11)
                        {
                            getline(lectura,texto);
                            aux<<"ESTADO: DESHABILITADO"<<endl;
                        }
                        else
                        {
                            getline(lectura,texto);
                            aux<<texto<<endl;
                        }
                    }
                }
            }
            if(encontrado==false)
            {
                cout<<"\nNO SE ENCUENTRA USUARIO EN EL REGISTRO..."<<endl<<endl;
            }
            else
            {
                cout<<"\nCLIENTE ELIMINADO...."<<endl<<endl;
            }
            lectura.close();
            aux.close();
            remove("registro_cliente.txt");
            rename("auxiliar_cliente.txt","registro_cliente.txt");
        }
        else
        {
            cout<<"\nEL ARCHIVO NO SE PUEDE ABRIR"<<endl<<endl;
        }
    }
    else
    {
        cout<<"\nNO SE HA REALIZADO NINGUNA ACCION... "<<endl<<endl;
    }
}


void agregar_vehiculo()
{
    system("cls");
    TpAutomovil automovil;
    fflush(stdin);
    cout<<"---------------REGISTRO DE AUTOMOVIL---------------"<<endl<<endl;
    cout<<"INGRESE UN ID DE AUTOMOVIL: ";
    getline(cin,automovil.id_auto);
    cout<<"INGRESE MATRICULA DEL AUTOMOVIL: ";
    getline(cin,automovil.matricula_auto);
    cout<<"INGRESE LA MARCA DEL AUTOMOVIL: ";
    getline(cin,automovil.marca);
    cout<<"INGRESE EL MODELO DEL AUTOMOVIL: ";
    getline(cin,automovil.modelo);
    cout<<"INGRESE COLOR DEL AUTOMOVIL: ";
    getline(cin,automovil.color);
    cout<<"INGRESE TIPO DE AUTOMOVIL(COMPACTO / MEDIANO / DE LUJO): ";
    getline(cin,automovil.tipo);
    fflush(stdin);
    cout<<"INGRESE PRECIO POR DIA: ";
    cin>>automovil.precio;
    automovil.estado="DISPONIBLE";

    ofstream escribir;
    //crea archivo y agrega dato o agrega datos si el archivo existe
    escribir.open("registro_automovil.txt",ios::out|ios::app);
    if(escribir.is_open())
    {
        automovil.estado="DISPONIBLE";

        escribir<<"ID AUTOMOVIL: "<<automovil.id_auto<<endl;
        escribir<<"MATRICULA: "<<automovil.matricula_auto<<endl;
        escribir<<"MARCA: "<<automovil.marca<<endl;
        escribir<<"MODELO: "<<automovil.modelo<<endl;
        escribir<<"COLOR: "<<automovil.color<<endl;
        escribir<<"TIPO: "<<automovil.tipo<<endl;
        escribir<<"PRECIO: "<<automovil.precio<<endl;
        escribir<<"ESTADO: "<<automovil.estado<<endl<<endl;
        escribir.close();
    }
    else
    {
        cout<<"EL ARCHIVO NO SE PUEDE ABRIR"<<endl;
    }
}

void consulta_lista_vehiculos()
{
    system("cls");
    string texto;
    int i=1;

    ifstream lectura;
    //lectura de archivos
    lectura.open("registro_automovil.txt",ios::out|ios::in);
    if(lectura.is_open())
    {
        cout<<"-------------------LISTA DE VEHICULOS-------------------"<<endl<<endl;
        cout<<"=========================================="<<endl;
        while(!lectura.eof())
        {
            if(i==1||i==3||i==4||i==8)
            {
                getline(lectura,texto);
                cout<<texto<<endl;
            }
            else
            {
                getline(lectura,texto);
            }
            if(i==9)
            {
                cout<<"=========================================="<<endl;
                i=0;
            }
            i++;
        }
        lectura.close();
    }
    else
    {
        cout<<"EL ARCHIVO NO SE PUEDE ABRIR"<<endl;
    }
}

void consulta_lista_vehiculos_cliente()
{
    system("cls");
    string texto;
    int i=1;

    ifstream lectura;
    //lectura de archivos
    lectura.open("registro_automovil.txt",ios::out|ios::in);
    if(lectura.is_open())
    {
        cout<<"-------------------LISTA DE VEHICULOS-------------------"<<endl<<endl;
        cout<<"=========================================="<<endl;
        while(!lectura.eof())
        {
            if(i==1||i==3||i==4||i==5||i==7||i==8)
            {
                getline(lectura,texto);
                cout<<texto<<endl;
            }
            else
            {
                getline(lectura,texto);
            }
            if(i==9)
            {
                cout<<"=========================================="<<endl;
                i=0;
            }
            i++;
        }
        lectura.close();
    }
    else
    {
        cout<<"EL ARCHIVO NO SE PUEDE ABRIR"<<endl;
    }
}

void lectura_vehiculo(string id)
{
    ifstream lectura;
    string texto;
    string linea="ID AUTOMOVIL: ";
    //CONCATENAR
    id=linea+id;
    bool encontrado= false;
    //lectura de archivos
    lectura.open("registro_automovil.txt",ios::out|ios::in);
    if(lectura.is_open())
    {
        while(!lectura.eof())
        {
            getline(lectura,texto);
            if(id==texto)
            {
                encontrado = true;
                cout<<"=============================================="<<endl;
                cout<<"\t"<<texto<<endl;
                for(int i=0; i<7; i++)
                {
                    getline(lectura,texto);
                    cout<<"\t"<<texto<<endl;
                }
                cout<<"=============================================="<<endl;
            }
        }
        if(encontrado==false)
        {
            cout<<"NO SE ENCUENTRA VEHICULO EN EL REGISTRO..."<<endl;
        }
        lectura.close();
    }
    else
    {
        cout<<"EL ARCHIVO NO SE PUEDE ABRIR"<<endl;
    }
}

void consulta_datos_por_vehiculo()
{
    system("cls");
    string id;

    cout<<"--------------------CONSULTA DE DATOS POR VEHICULO--------------------"<<endl<<endl;
    cout<<"INGRESE ID DEL AUTOMOVIL --->";
    fflush(stdin);
    getline(cin,id);
    cout<<endl;
    lectura_vehiculo(id);
}

void eliminar_vehiculo()
{
    system("cls");
    bool encontrado= false;
    string texto;
    string linea="ID AUTOMOVIL: ";
    string id;
    char option;

    cout<<"--------------------ELIMINACION DE AUTOMOVIL--------------------"<<endl<<endl;
    cout<<"INGRESE ID DEL AUTOMOVIL --->";
    fflush(stdin);
    getline(cin,id);
    cout<<endl;
    //concatenar
    id=linea+id;

    do
    {
        cout<<"¿DESEA ELIMINAR ESTE AUTOMOVIL?(s = si / n = no): ";
        cin>>option;
    }
    while(option!='s'&&option!='n');

    if(option=='s')
    {
        ofstream aux;
        ifstream lectura;
        //lectura de archivos
        lectura.open("registro_automovil.txt",ios::out|ios::in);
        //escritura en un archivo temporal
        aux.open("auxiliar_automovil.txt", ios::out);

        if(lectura.is_open() && aux.is_open())
        {
            while(!lectura.eof())
            {
                getline(lectura,texto);
                aux<<texto<<endl;
                if(id==texto)
                {
                    encontrado = true;
                    for(int i=0; i<7; i++)
                    {
                        if(i==6)
                        {
                            getline(lectura,texto);
                            aux<<"ESTADO: DESHABILITADO"<<endl;
                        }
                        else
                        {
                            getline(lectura,texto);
                            aux<<texto<<endl;
                        }
                    }
                }
            }
            if(encontrado==false)
            {
                cout<<"\nNO SE ENCUENTRA VEHICULO EN EL REGISTRO..."<<endl<<endl;
            }
            else
            {
                cout<<"\nVEHICULO ELIMINADO...."<<endl<<endl;
            }
            lectura.close();
            aux.close();
            remove("registro_automovil.txt");
            rename("auxiliar_automovil.txt","registro_automovil.txt");
        }
        else
        {
            cout<<"\nEL ARCHIVO NO SE PUEDE ABRIR"<<endl<<endl;
        }
    }
    else
    {
        cout<<"\nNO SE HA REALIZADO NINGUNA ACCION... "<<endl<<endl;
    }
}

int numero_dias(int dia, int mes, int anio)
{
    int nDias;
    nDias=(anio*365) + (mes-1)*30 + dia;
    return nDias;
}

void reservar_vehiculo()
{
    system("cls");
    string texto;
    string linea="ID AUTOMOVIL: ";
    string id;
    bool encontrado = false;

    int nDias1;
    int nDias2;
    TpReserva reserva;
    char option;
    fflush(stdin);
    cout<<"--------------------RESERVA DE AUTOMOVIL--------------------"<<endl<<endl;
    cout<<"INGRESE ID DEL VEHICULO QUE DESEA RENTAR: ";
    getline(cin,reserva.id_vehiculo);
    cout<<endl;
    lectura_vehiculo(reserva.id_vehiculo);
    cout<<"INGRESE ID DE CLIENTE: ";
    getline(cin,reserva.id_cliente);
    cout<<endl;
    lectura_cliente(reserva.id_cliente);
    do
    {
        cout<<"¿ESTA SEGURO DE RENTAR ESTE AUTOMOVIL?(s = si / n = no): ";
        cin>>option;
    }
    while(option!='s'&&option!='n');

    if(option=='s')
    {
        fflush(stdin);
        cout<<"\n----FECHA DE RESERVA----"<<endl;
        cout<<"DIA: ";
        cin>>reserva.fecha_inicial.dia;
        cout<<"MES: ";
        cin>>reserva.fecha_inicial.mes;
        cout<<"ANIO: ";
        cin>>reserva.fecha_inicial.anio;
        fflush(stdin);
        cout<<"\n----FECHA DE ENTREGA----"<<endl;
        cout<<"DIA: ";
        cin>>reserva.fecha_final.dia;
        cout<<"MES: ";
        cin>>reserva.fecha_final.mes;
        cout<<"ANIO: ";
        cin>>reserva.fecha_final.anio;
        fflush(stdin);
        cout<<"INGRESE EL PRECIO X DIA: ";
        cin>>reserva.precio_total;

        nDias1= numero_dias(reserva.fecha_inicial.dia,reserva.fecha_inicial.mes,reserva.fecha_inicial.anio);
        nDias2= numero_dias(reserva.fecha_final.dia,reserva.fecha_final.mes,reserva.fecha_final.anio);

        reserva.precio_total=(nDias2-nDias1)*reserva.precio_total;

        reserva.estado="RESERVADO";

        //CREANDO ARCHIVO
        ofstream escribir;
        //crea archivo y agrega dato o agrega datos si el archivo existe
        escribir.open("lista_reservas.txt",ios::out|ios::app);
        if(escribir.is_open())
        {

            escribir<<"ID CLIENTE: "<<reserva.id_cliente<<endl;
            escribir<<"ID VEHICULO: "<<reserva.id_vehiculo<<endl;
            escribir<<"FECHA DE RESERVA"<<endl;
            escribir<<reserva.fecha_inicial.dia<<" "<<reserva.fecha_inicial.mes<<" "<<reserva.fecha_inicial.anio<<endl;
            escribir<<"FECHA DE DEVOLUCION"<<endl;
            escribir<<reserva.fecha_final.dia<<" "<<reserva.fecha_final.mes<<" "<<reserva.fecha_final.anio<<endl;
            escribir<<"PRECIO TOTAL: "<<reserva.precio_total<<endl;
            escribir<<"ESTADO: "<<reserva.estado<<endl<<endl;
            escribir.close();
        }
        else
        {
            cout<<"EL ARCHIVO NO SE PUEDE ABRIR"<<endl;
        }

        //EDITANDO ARCHIVO
        ofstream aux;
        ifstream lectura;
        id=linea+reserva.id_vehiculo;
        //lectura de archivos
        lectura.open("registro_automovil.txt",ios::out|ios::in);
        //escritura en un archivo temporal
        aux.open("auxiliar_automovil.txt", ios::out);

        if(lectura.is_open() && aux.is_open())
        {
            while(!lectura.eof())
            {
                getline(lectura,texto);
                aux<<texto<<endl;
                if(id==texto)
                {
                    encontrado = true;
                    for(int i=0; i<7; i++)
                    {
                        if(i==6)
                        {
                            getline(lectura,texto);
                            aux<<"ESTADO: RESERVADO"<<endl;
                        }
                        else
                        {
                            getline(lectura,texto);
                            aux<<texto<<endl;
                        }
                    }
                }
            }
            if(encontrado==false)
            {
                cout<<"\nNO SE ENCUENTRA VEHICULO EN EL REGISTRO..."<<endl<<endl;
            }
            else
            {
                cout<<"\nRESERVA REALIZADA CON EXITO...."<<endl<<endl;
            }
            lectura.close();
            aux.close();
            remove("registro_automovil.txt");
            rename("auxiliar_automovil.txt","registro_automovil.txt");
        }
        else
        {
            cout<<"\nEL ARCHIVO NO SE PUEDE ABRIR"<<endl<<endl;
        }
    }
    else
    {
        cout<<"NO SE HA REALIZADO NINGUNA ACCION..."<<endl;
    }
}

void consulta_lista_reservas()
{
    system("cls");
    string texto;
    int i=1;

    ifstream lectura;
    //lectura de archivos
    lectura.open("lista_reservas.txt",ios::out|ios::in);
    if(lectura.is_open())
    {
        cout<<"-------------------LISTA DE RESERVAS-------------------"<<endl<<endl;
        cout<<"=========================================="<<endl;
        while(!lectura.eof())
        {
            getline(lectura,texto);
            cout<<texto<<endl;
            if(i==9)
            {
                cout<<"=========================================="<<endl;
                i=0;
            }
            i++;
        }
        lectura.close();
    }
    else
    {
        cout<<"EL ARCHIVO NO SE PUEDE ABRIR"<<endl;
    }
}




