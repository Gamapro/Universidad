using System;

namespace Computadoras{

	public class Product{
	    private List<Dispositivo> dispositivos = new List<Dispositivo>();
        
        List<Dispositivo> getDispositivos(){
            return dispositivos;
        }

        public void addDispositivo(Dispositivo d){
            this.dispositivos.Add(d);
        }

        public int getPrecio(){
            int precioTotal = 0;
            Console.WriteLine("Calculando precio");
            foreach( var d in dispositivos){
                precioTotal += d.precio;
            }
            return precioTotal;
        }

	}
}