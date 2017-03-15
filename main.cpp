#include<iostream>
#include<string.h>
#include <windows.h>

using namespace std;

struct nombres
{
    char cadena[20];
    char paterno[20];
    char materno[20];
    char rfc[20];
    char year[20];
    int lugar;
};

class empleados
{
    private:
        int n;
        nombres *x;
        int cont;
    public:
        empleados(int);
        void inserta();
        void mostrar();
        void anadir();
        void eliminar();
        void orden_year();
        void orden_rfc();
        void orden_name();
        void mostrar_normal();
        void busca_rfc();

        ~empleados();

};

empleados::empleados(int num)
{
    x=new nombres[num];
    n=num;
    cont=0;
}
void empleados::inserta()
{
    if(cont<n)
    {
        int emp;
        cout<<"cuantos empleados deseas instertar?:"<<endl;
        cin>>emp;
        for(int i=0;i<emp;++i)
        {
            cout<<"empleado "<<i+1<<"= ";
            cout<<endl;
            cout<<"nombre:"<<endl;
            cin>>x[i].cadena;
            cout<<endl;
            cout<<"apellido paterno:"<<endl;
            cin>>x[i].paterno;
            cout<<endl;
            cout<<"apellido materno:"<<endl;
            cin>>x[i].materno;
            cout<<endl;
            cout<<"RFC:"<<endl;
            cin>>x[i].rfc;
            cout<<endl;
            cout<<"anio de ingreso:"<<endl;
            cin>>x[i].year;
            cout<<endl;
            ++cont;
        }
        cout<<endl;
    }
    else
        cout<<"No se aceptan mas mpleados";
}
void empleados::mostrar()
{
    if(cont>0)
    {
        cout<<"Empleados: ";
        for(int i=0;i<cont;i++)
        {
            cout<<"empleado "<<i+1<<endl;
            cout<<"nombre:"<<endl;
            cout<<x[i].cadena;
            cout<<endl;
            cout<<"apellido paterno:"<<endl;
            cout<<x[i].paterno;
            cout<<endl;
            cout<<"apellido materno:"<<endl;
            cout<<x[i].materno;
            cout<<endl;
            cout<<"RFC:"<<endl;
            cout<<x[i].rfc;
            cout<<endl;
            cout<<"anio de ingreso:"<<endl;
            cout<<x[i].year;
            cout<<endl;
            cout<<x[i].lugar;
            cout<<endl;
        }
    }
    else
        cout<<"No hay empleados"<<endl;
}

void empleados::eliminar()
{
    if(cont > 0)
    {
        char rfcempleado[20];
        cout<<"Ingresa el rfc del empleado a eliminar: "<<endl;
        cin>>rfcempleado;
        cout<<rfcempleado;

        for(int i=0; i<cont ;++i)
        {
            if(strcmp(rfcempleado,x[i].rfc)==0)
            {
                for(int j=i; j<cont; ++j)
                {
                    strcpy(x[j].cadena,x[j+1].cadena);
                    strcpy(x[j].paterno,x[j+1].paterno);
                    strcpy(x[j].materno,x[j+1].materno);
                    strcpy(x[j].rfc,x[j+1].rfc);
                    strcpy(x[j].year,x[j+1].year);
                    --cont;
                }
                cout<<"empleado eliminado";
            }

        }

    }
    else
        cout<<"No hay elementos";
}

void empleados::orden_year()
{
    for(int i=0;i<n-1;++i)
    {
        bool comp=false;
        for(int j=0; j<n-1-i;++j)
        {
            if(strcmp(x[j].year,x[j+1].year)>0)
            {
                char aux[20];
                strcpy(aux,x[j].year);
                strcpy(x[j].year,x[j+1].year);
                strcpy(x[j+1].year,aux);

                char aux_dos[20];
                strcpy(aux_dos,x[j].cadena);
                strcpy(x[j].cadena,x[j+1].cadena);
                strcpy(x[j+1].cadena,aux_dos);

                char aux_tres[20];
                strcpy(aux_tres,x[j].paterno);
                strcpy(x[j].paterno,x[j+1].paterno);
                strcpy(x[j+1].paterno,aux_tres);

                char aux_cuatro[20];
                strcpy(aux_cuatro,x[j].materno);
                strcpy(x[j].materno,x[j+1].materno);
                strcpy(x[j+1].materno,aux_cuatro);


                char aux_cinco[20];
                strcpy(aux_cinco,x[j].rfc);
                strcpy(x[j].rfc,x[j+1].rfc);
                strcpy(x[j+1].rfc,aux_cinco);

                int aux_seis;
                aux_seis=x[j].lugar;
                x[j].lugar=x[j+1].lugar;
                x[j+1].lugar=aux_seis;
                comp=true;
            }
        }
        if(!comp)
        break;
    }
}
void empleados::orden_rfc()
{
    for(int i=0;i<n-1;++i)
    {
        bool comp=false;
        for(int j=0; j<n-1-i;++j)
        {
            if(strcmp(x[j].rfc,x[j+1].rfc)>0)
            {
                char aux[20];
                strcpy(aux,x[j].year);
                strcpy(x[j].year,x[j+1].year);
                strcpy(x[j+1].year,aux);

                char aux_dos[20];
                strcpy(aux_dos,x[j].cadena);
                strcpy(x[j].cadena,x[j+1].cadena);
                strcpy(x[j+1].cadena,aux_dos);

                char aux_tres[20];
                strcpy(aux_tres,x[j].paterno);
                strcpy(x[j].paterno,x[j+1].paterno);
                strcpy(x[j+1].paterno,aux_tres);

                char aux_cuatro[20];
                strcpy(aux_cuatro,x[j].materno);
                strcpy(x[j].materno,x[j+1].materno);
                strcpy(x[j+1].materno,aux_cuatro);


                char aux_cinco[20];
                strcpy(aux_cinco,x[j].rfc);
                strcpy(x[j].rfc,x[j+1].rfc);
                strcpy(x[j+1].rfc,aux_cinco);

                int aux_seis;
                aux_seis=x[j].lugar;
                x[j].lugar=x[j+1].lugar;
                x[j+1].lugar=aux_seis;
                comp=true;
            }
        }
        if(!comp)
        break;
    }
}
void empleados::orden_name()
{
    for(int i=0;i<n-1;++i)
    {
        bool comp=false;
        for(int j=0; j<n-1-i;++j)
        {
            if(strcmp(x[j].paterno,x[j+1].paterno)>0)
            {
                char aux[20];
                strcpy(aux,x[j].year);
                strcpy(x[j].year,x[j+1].year);
                strcpy(x[j+1].year,aux);

                char aux_dos[20];
                strcpy(aux_dos,x[j].cadena);
                strcpy(x[j].cadena,x[j+1].cadena);
                strcpy(x[j+1].cadena,aux_dos);

                char aux_tres[20];
                strcpy(aux_tres,x[j].paterno);
                strcpy(x[j].paterno,x[j+1].paterno);
                strcpy(x[j+1].paterno,aux_tres);

                char aux_cuatro[20];
                strcpy(aux_cuatro,x[j].materno);
                strcpy(x[j].materno,x[j+1].materno);
                strcpy(x[j+1].materno,aux_cuatro);


                char aux_cinco[20];
                strcpy(aux_cinco,x[j].rfc);
                strcpy(x[j].rfc,x[j+1].rfc);
                strcpy(x[j+1].rfc,aux_cinco);

                int aux_seis;
                aux_seis=x[j].lugar;
                x[j].lugar=x[j+1].lugar;
                x[j+1].lugar=aux_seis;
                comp=true;
            }
            else
            {
                if(strcmp(x[j].paterno,x[j+1].paterno)==0)
                {
                    if(strcmp(x[j].materno,x[j+1].materno)>0)
                    {
                        char aux[20];
                        strcpy(aux,x[j].year);
                        strcpy(x[j].year,x[j+1].year);
                        strcpy(x[j+1].year,aux);

                        char aux_dos[20];
                        strcpy(aux_dos,x[j].cadena);
                        strcpy(x[j].cadena,x[j+1].cadena);
                        strcpy(x[j+1].cadena,aux_dos);

                        char aux_tres[20];
                        strcpy(aux_tres,x[j].paterno);
                        strcpy(x[j].paterno,x[j+1].paterno);
                        strcpy(x[j+1].paterno,aux_tres);

                        char aux_cuatro[20];
                        strcpy(aux_cuatro,x[j].materno);
                        strcpy(x[j].materno,x[j+1].materno);
                        strcpy(x[j+1].materno,aux_cuatro);


                        char aux_cinco[20];
                        strcpy(aux_cinco,x[j].rfc);
                        strcpy(x[j].rfc,x[j+1].rfc);
                        strcpy(x[j+1].rfc,aux_cinco);

                        int aux_seis;
                        aux_seis=x[j].lugar;
                        x[j].lugar=x[j+1].lugar;
                        x[j+1].lugar=aux_seis;
                        comp=true;
                    }
                    else
                    {
                        if(strcmp(x[j].materno,x[j+1].materno)==0)
                        {
                            if(strcmp(x[j].cadena,x[j+1].cadena)>0)
                            {
                                char aux[20];
                                strcpy(aux,x[j].year);
                                strcpy(x[j].year,x[j+1].year);
                                strcpy(x[j+1].year,aux);

                                char aux_dos[20];
                                strcpy(aux_dos,x[j].cadena);
                                strcpy(x[j].cadena,x[j+1].cadena);
                                strcpy(x[j+1].cadena,aux_dos);

                                char aux_tres[20];
                                strcpy(aux_tres,x[j].paterno);
                                strcpy(x[j].paterno,x[j+1].paterno);
                                strcpy(x[j+1].paterno,aux_tres);

                                char aux_cuatro[20];
                                strcpy(aux_cuatro,x[j].materno);
                                strcpy(x[j].materno,x[j+1].materno);
                                strcpy(x[j+1].materno,aux_cuatro);


                                char aux_cinco[20];
                                strcpy(aux_cinco,x[j].rfc);
                                strcpy(x[j].rfc,x[j+1].rfc);
                                strcpy(x[j+1].rfc,aux_cinco);

                                int aux_seis;
                                aux_seis=x[j].lugar;
                                x[j].lugar=x[j+1].lugar;
                                x[j+1].lugar=aux_seis;
                                comp=true;
                            }
                        }
                    }
                }
            }
        }
        if(!comp)
        break;
    }

}
void empleados::anadir()
{
    if(cont>=0 && cont<n)
    {
        x[cont].lugar=cont;
        cout<<"Inserta tu empleado:"<<endl;
        cout<<"nombre"<<endl;
        cin>>x[cont].cadena;
        cout<<endl;
        cout<<"apellido paterno"<<endl;
        cin>>x[cont].paterno;
        cout<<endl;
        cout<<"apellido materno"<<endl;
        cin>>x[cont].materno;
        cout<<endl;
        cout<<"RFC"<<endl;
        cin>>x[cont].rfc;
        cout<<endl;
        cout<<"anio de ingreso"<<endl;
        cin>>x[cont].year;
        cout<<endl;
        ++cont;
    }
    else
        cout<<"No hay espacio";
}
void empleados::mostrar_normal()
{
    if(cont>0)
    {
        for(int i=0;i<n-1;++i)
        {
            bool comp=false;
            for(int j=0; j<n-1-i;++j)
            {
                if(x[i].lugar>x[i+1].lugar)
                {
                    char aux[20];
                    strcpy(aux,x[j].year);
                    strcpy(x[j].year,x[j+1].year);
                    strcpy(x[j+1].year,aux);

                    char aux_dos[20];
                    strcpy(aux_dos,x[j].cadena);
                    strcpy(x[j].cadena,x[j+1].cadena);
                    strcpy(x[j+1].cadena,aux_dos);

                    char aux_tres[20];
                    strcpy(aux_tres,x[j].paterno);
                    strcpy(x[j].paterno,x[j+1].paterno);
                    strcpy(x[j+1].paterno,aux_tres);

                    char aux_cuatro[20];
                    strcpy(aux_cuatro,x[j].materno);
                    strcpy(x[j].materno,x[j+1].materno);
                    strcpy(x[j+1].materno,aux_cuatro);


                    char aux_cinco[20];
                    strcpy(aux_cinco,x[j].rfc);
                    strcpy(x[j].rfc,x[j+1].rfc);
                    strcpy(x[j+1].rfc,aux_cinco);
                    comp=true;
                }
            }
            if(!comp)
            break;
        }
        mostrar();

    }
    else
        cout<<"No hay empleados";
}
void empleados::busca_rfc()
{
    //que ingrese lo que busca guardarlo en un arreglo char y buscar con find teniendo ese arreglo como condicion, y decir si existe o no
    if(cont>0)
    {
        cout<<"ingresa caracteres contenidos en el rfc del empleado a mostrar:"<<endl;
        string coincidencia;
        cin>>coincidencia;
        cout<<"el empleado buscado por: "<<coincidencia;
        cout<<endl;
        /*
        char a[]="hello world!";
        char b[]="el";
        //find substring b[] in a[]
        string str(a);
        string substr(b);
        found = str.find(substr);
        */
        for(int i=0; i<n; ++i)
        {
            string str(x[i].rfc);
            //bool comp=false;

            if (str.find(coincidencia) != string::npos)
             //(strstr(phrase.c_str(),profana.c_str()))
            {
                cout<<"Si existe"<<endl;
                cout<<"empleado: "<<endl;
                cout<<"nombre:"<<endl;
                cout<<x[i].cadena;
                cout<<endl;
                cout<<"apellido paterno:"<<endl;
                cout<<x[i].paterno;
                cout<<endl;
                cout<<"apellido materno:"<<endl;
                cout<<x[i].materno;
                cout<<endl;
                cout<<"RFC:"<<endl;
                cout<<x[i].rfc;
                cout<<endl;
                cout<<"anio de ingreso:"<<endl;
                cout<<x[i].year;
                cout<<endl;

            }
        }
    }
    else
        cout<<"No hay empleados registrados";
}
/*vamos a meter de un empleado por empleado en una funcion insertar empleado, cuando ya se haya preguntado el limite de empleados.
todos los datos de ese empleado a meter se van a meter en la misma funcion.
no se necesitan todos esos auxiliares en la funcion puedo declarar nombres aux y va a guardar todas las estructuras de los empleados que hasyamos metido.
*/
int main()
{
    int num=0;
    cout<<"cuantos empleados quieres?: "<<endl;
    cin>>num;

    empleados x(num);

    int menu;
    do
    {
        system("cls");//limpia pantalla para que no se amontone
        cout<<"Que deseas hacer?"<<endl;
        cout<<"1.-Mostrar empleados"<<endl;
        cout<<"2.-Buscar un empleado por RFC"<<endl;
        cout<<"3.-Insertar un elemento a la lista"<<endl;
        cout<<"4.-orden por anio"<<endl;
        cout<<"5.-Anadir un nuevo empleado"<<endl;
        cout<<"6.-Eliminar un elemento de la lista"<<endl;
        cout<<"7.-Mostrar empleados como se ingresaron"<<endl;
        cout<<"8.-Ordenar por rfc"<<endl;
        cout<<"9.-Ordenar por ap paterno, materno, nombre"<<endl;
        cout<<"Presiona cualquier otra tecla para salir"<<endl;
        cin>>menu;
        switch(menu)
        {
            case 1:
                {
                    x.mostrar();
                    cout<<endl;
                    system("pause");
                    break;
                }
            case 2:
                {
                    x.busca_rfc();
                    cout<<endl;
                    system("pause");
                    break;
                }
            case 3:
                {
                    x.inserta();
                    cout<<endl;
                    system("pause");
                    break;
                }
            case 4:
                {
                    x.orden_year();
                    cout<<endl;
                    system("pause");
                    break;
                }
            case 5:
                {
                    x.anadir();
                    cout<<endl;
                    system("pause");
                    break;
                }
            case 6:
                {
                    x.eliminar();
                    cout<<endl;
                    system("pause");
                    break;
                }
            case 7:
                {
                    x.mostrar_normal();
                    cout<<endl;
                    system("pause");
                    break;
                }
            case 8:
                {
                    x.orden_rfc();
                    cout<<endl;
                    system("pause");
                    break;
                }
            case 9:
                {
                    x.orden_name();
                    cout<<endl;
                    system("pause");
                    break;
                }

                default:
                    cout<<"Elegiste salir";
            }
    }while(menu>0 && menu<=10);


    return 0;
}
empleados::~empleados()
{
    delete []x;
}
