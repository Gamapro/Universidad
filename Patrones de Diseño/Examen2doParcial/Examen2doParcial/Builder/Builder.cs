using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Examen2doParcial
{
	public abstract class Builder
	{
		public abstract void InitializeFormElements();
		public abstract void BuildDownloadGrades();
		public abstract void BuildConsultGrades();
		public abstract void BuildBasicInfo();
		public abstract UserForm GetResult();
	}
}
