using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Examen2doParcial
{
    public class Profesor : Supervisor
    {
        public int[] Alumnos { get; set; }
        public Profesor(string Nombre, string FechaDeNacimiento, string Ciudad, string Password, int Id, int Año, int[] Alumnos) : base(Nombre, FechaDeNacimiento, Ciudad, Password, Id)
        {
            this.Alumnos = Alumnos;
        }
    }
}
