using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Examen2doParcial.Builder
{
    public class Director
    {
		public Director()
        {
        }
		public void Construct(Builder builder)
		{
			builder.BuildDownloadGrades();
			builder.BuildConsultGrades(); 
			builder.BuildBasicInfo();
		}
	}

}
