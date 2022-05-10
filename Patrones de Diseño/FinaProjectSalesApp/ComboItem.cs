using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
    class ComboItem
    {
        public int ID { get; set; }
        public string Text { get; set; }
        public override string ToString()
        {
            if (ID == -1) return "";
            return "Store : " + Text + ", ID : "+ID.ToString();
        }
    }
}
