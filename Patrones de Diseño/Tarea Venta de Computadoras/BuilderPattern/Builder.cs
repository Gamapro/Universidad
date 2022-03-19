using System;

namespace Computadoras{

	abstract class Builder{
	    public abstract void BuildUnidadCentral();
		public abstract void BuildPantallaTactil();
		public abstract void BuildImpresora();
		public abstract void BuildMouse();
		public abstract void BuildTeclado();
		public abstract void BuildTarjetaGrafica();
		public abstract Product GetProduct();
	}
}