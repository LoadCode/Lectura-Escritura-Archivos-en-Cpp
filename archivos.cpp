#include <iostream>
#include <fstream>

using namespace std;

#define ESCRITURA //LECTURA



bool EscribirArchivo(string fileName, string texto)
{
    ofstream writer;
    writer.open(fileName); //Se abre un archivo para escritura, sino existe se crea, si existe se sobreescribe

    if(writer.fail()) //Revisa si se abrió correctamente el archivo, sino se retorna false
        return false;
    else
        writer << texto;  //Se escribe el conteniedo ene l archivo

    writer.close(); //Se cierra el flujo del archivo

    return true;
}

string LeerArchivo(string fileName)
{
    ifstream reader;

    reader.open(fileName);
    string linea,texto = "";

    if(reader.fail()) //Si el archivo no se abrió correctamente se retorna una cadena vacía
        return "";
    else
        while(!reader.eof())
        {
            getline(reader,linea);
            cout<<linea<<endl;
            texto += linea;
        }
    return texto;
}

int main(void)
{
    string fileName, textoEscribir, textoLeido;

    fileName     = "ArchivoTexto.txt";

    #ifdef ESCRITURA
        textoEscribir = "Este es el contenido escrito en un\narchivo de texto con C++.\n\nA continuación vamos a ver con la palabra anterior\nsi se reconocen caracteres especiales\n";

        if(EscribirArchivo(fileName,textoEscribir))
            cout<<"Archivo Escrito Correctamente"<<endl;
        else
            cout<<"Error al Escribir Archivo"<<endl;

    #else
        textoLeido = LeerArchivo(fileName);
        cout<<"\n\nEl texto en una sola cadena es:\n\n";
        cout<<textoLeido<<endl<<endl;

    #endif // ESCRITURA

    return 0;
}
