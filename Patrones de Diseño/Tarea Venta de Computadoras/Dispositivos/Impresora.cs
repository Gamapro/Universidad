using System;

namespace Computadoras{

	class Impresora : Dispositivo{
        public string cartucho = "";
        public int tipo = 0;

        public Impresora(string cartucho, int tipo){
            this.cartucho = cartucho;
            this.tipo = tipo;
            precio = 10;
        }

	}
}