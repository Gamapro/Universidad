using System;

namespace Computadoras{

    class Computadora2 : Builder{
        private Product p = new Product();
        public override void BuildUnidadCentral(){
            p.addDispositivo(new UnidadCentral());
        }
		public override void BuildPantallaTactil(){
            p.addDispositivo(new PantallaTactil());
        }
		public override void BuildImpresora(){
            p.addDispositivo(new Impresora("toner", 0));
        }
		public override void BuildMouse(){

        }
		public override void BuildTeclado(){

        }
		public override void BuildTarjetaGrafica(){

        }
		public override Product GetProduct(){
            return p;
        }
    
    }

}