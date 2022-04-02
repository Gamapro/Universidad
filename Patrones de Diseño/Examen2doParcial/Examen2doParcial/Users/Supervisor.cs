using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Examen2doParcial
{
    public class Supervisor
    {
        public string Nombre { get; set; }
        public string FechaDeNacimiento { get; set; }
        public string Ciudad { get; set; }
        public string Password { get; set; }
        public int Id { get; set; }
        public string Mail { get; set; }
        public Supervisor(string Nombre, string FechaDeNacimiento, string Ciudad, string Password, int Id)
        {
            this.Nombre = Nombre;
            this.FechaDeNacimiento = FechaDeNacimiento;
            this.Ciudad = Ciudad;
            this.Password = Password;
            this.Id = Id;
        }

    }

}
