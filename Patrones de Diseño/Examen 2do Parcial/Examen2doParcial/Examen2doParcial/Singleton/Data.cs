using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Examen2doParcial
{
    class Data
    {
        // public List<Supervisor> Supervisores { get; }
        public Supervisor[] Supervisores { get; set; }
        public Alumno[] Alumnos { get; set; }
        public Profesor[] Profesores { get; set; }
        public string[] Materias { get; set; }
        public Data()
        {

        }
    }
}
