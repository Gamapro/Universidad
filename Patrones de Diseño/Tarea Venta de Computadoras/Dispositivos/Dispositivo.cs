using System;

namespace Computadoras{
	public abstract class Dispositivo{
        public String nombre = "";
		public String conexion = "";
		public String nombreDelFabricante = "";
		public int modelo = 0; 
		public int precio = 0;
		public List<int> puertos = new List<int>();

	}
}