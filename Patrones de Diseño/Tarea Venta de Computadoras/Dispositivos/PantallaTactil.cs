using System;

namespace Computadoras{
	class PantallaTactil : Dispositivo{

        public PantallaTactil(){
            nombre = "Unidad Pantalla";
            conexion = "Usb";
            nombreDelFabricante = "Juan Pedro Inc";
    		modelo = 12;
            precio = 777;
            for(int i = 0; i < 1; i++){
                puertos.Add(i);
            } 
        }

	}
}