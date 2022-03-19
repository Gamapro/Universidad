using System;

namespace Computadoras{
    class UnidadCentral : Dispositivo{

        public UnidadCentral(){
            nombre = "Unidad";
            conexion = "Usb";
            nombreDelFabricante = "Juan Inc";
    		modelo = 111;
            precio = 5;
            for(int i = 0; i < 16; i++){
                puertos.Add(i);
            } 
        }

	}
}