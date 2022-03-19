using System;

namespace Computadoras{

	class Program{

    	public static void Main(string[] args){
			
			Console.WriteLine("Bienvenido a la tienda de computadoras!");
			Director director = new Director();
			Product p = new Product();

			while(true){

				Program.displayOptions();

				int x = Convert.ToInt32(Console.ReadLine());
				if(x == 1){
					Console.WriteLine("Computadora 1 seleccionada.");
					Builder builder = new Computadora1();
					director.Construct(builder);
					p = builder.GetProduct();
				}else if(x == 2){
					Console.WriteLine("Computadora 2 seleccionada.");
					Builder builder = new Computadora2();
					director.Construct(builder);
					p = builder.GetProduct();
				}else if(x == 3){
					Console.WriteLine("Gracias por tu visita :)");
					return;
				}else{
					Console.WriteLine("Opcion invalida. Intenta de nuevo.");
					continue;
				}
				break;
			}

			while(true){
				Program.displayAdd();
				int x = Convert.ToInt32(Console.ReadLine());
				if(x == 0){
					p.addDispositivo(new Impresora("toner", 0));
				}else if(x == 1){
					p.addDispositivo(new Impresora("tiner", 1));
				}else if(x == 2){
					p.addDispositivo(new Input("Mouse", 20));
				}else if(x == 3){
					p.addDispositivo(new Input("Teclado", 11));
				}else if(x == 4){
					p.addDispositivo(new Input("Tarjeta Grafica", 31));
				}else if(x == 5){
					break;
				}else{
					Console.WriteLine("Opcion invalida. Intenta de nuevo.");
				}

			}
			Console.WriteLine(String.Format("Precio total: {0}", p.getPrecio()));
			Console.WriteLine("Gracias por tu visita :)");
    	}

		static void displayAdd(){
			Console.WriteLine("Desea añadir otro componente: ");
			Console.WriteLine("0 - Impresora Laser");
			Console.WriteLine("1 - Impresora Inyeccion");
			Console.WriteLine("2 - Mouse");
			Console.WriteLine("3 - Teclado");
			Console.WriteLine("4 - Tarjeta Grafica");
			Console.WriteLine("5 - No");
		}

		static void displayOptions(){
			Console.WriteLine("A continuacion te presentamos las computadoras disponibles.");
			Console.WriteLine("Computadora 1: ");
			Console.WriteLine("Computadora 2: ");
			Console.WriteLine("Elige tu opcion: ");
			Console.WriteLine("1 - Computadora 1");
			Console.WriteLine("2 - Computadora 2");
			Console.WriteLine("3 - Salir");
		}

	}
}