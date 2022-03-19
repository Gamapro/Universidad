using System;

namespace Computadoras{

    class Computadora1 : Builder{
        private Product p = new Product();
        public override void BuildUnidadCentral(){
            p.addDispositivo(new UnidadCentral());
        }
		public override void BuildPantallaTactil(){
            
        }
		public override void BuildImpresora(){
            p.addDispositivo(new Impresora("tiner", 1));

        }
		public override void BuildMouse(){
            p.addDispositivo(new Input("Mouse", 20));
        }
		public override void BuildTeclado(){
            p.addDispositivo(new Input("Teclado", 11));
        }
		public override void BuildTarjetaGrafica(){
            p.addDispositivo(new Input("Tarjeta Grafica", 31));
        }
		public override Product GetProduct(){
            return p;
        }
    
    }

}