using System;

namespace Computadoras{
	class Director{
        public void Construct(Builder builder){
			builder.BuildUnidadCentral();
			builder.BuildMouse();
			builder.BuildTeclado();
			builder.BuildMouse();
			builder.BuildPantallaTactil();
			builder.BuildMouse();
			builder.BuildImpresora();
		}
        
	}
}