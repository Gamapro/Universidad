using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Examen2doParcial
{
    public partial class UserForm: Form
    {
        public UserForm()
        {
            InitializeComponent();
        }

        public System.Windows.Forms.Button Regresar;
        public System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        public System.Windows.Forms.DataGridView gradesTable;
        public System.Windows.Forms.DataGridView dataTable;
        public System.Windows.Forms.Label DatosLabel;
        public System.Windows.Forms.Label calificacionesLabel;
        public System.Windows.Forms.Button botonDescarga;

    }
}
