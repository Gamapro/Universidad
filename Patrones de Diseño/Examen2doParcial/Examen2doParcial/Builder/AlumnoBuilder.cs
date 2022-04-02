using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Examen2doParcial.Builder
{
    public class AlumnoBuilder : Builder
    {
        private Alumno alumno;
        private Login login;
        private InfoForm form;
        public AlumnoBuilder(Alumno alumno, ref Login login)
        {
            this.alumno = alumno;
            this.login = login;
        }
        public override void BuildDownloadGrades()
        {

        }
        public override void BuildConsultGrades()
        {

        }
        public override void BuildBasicInfo()
        {

        }
        public override InfoForm GetResult()
        {
            InfoForm form = new InfoForm(alumno, ref login);
            return form;
        }

    }

}
