using System;

namespace Computadoras{
	class Input : Dispositivo{

        string tipo = "";
        public Input(string tipo, int precio){
            this.tipo = tipo;
            nombre = "Unidad de Entrada";
            conexion = "Usb";
            nombreDelFabricante = "Juan Inc";
    		modelo = 1;
            this.precio = precio;
            for(int i = 0; i < 4; i++){
                puertos.Add(i);
            } 
        }

	}
}