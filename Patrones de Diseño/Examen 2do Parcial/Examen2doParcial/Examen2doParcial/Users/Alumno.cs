using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Examen2doParcial
{
    public class Alumno : Supervisor
    {
        public string Carrera { get; set; }
        public int[] Calificaciones { get; set; }
        public Alumno(int[] Calificaciones,string Nombre, string FechaDeNacimiento, string Ciudad, string Password, int Id, int Año, string Carrera) : base(Nombre, FechaDeNacimiento, Ciudad, Password, Id)
        {
            this.Carrera = Carrera;
            this.Calificaciones = Calificaciones;
        }
    }
}
