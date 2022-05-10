using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FinaProjectSalesApp
{
	class Singleton
	{
		private static Singleton _instance = null;
		public Orders ordersForm = null;
		public Mediator mediator = null;
		private static object _handle = new object();
		public Factory breadFactory, sodaFactory, vegetablesFactory;
		public int numberStores;
		protected Singleton()
		{
			breadFactory = new BreadFactory();
			sodaFactory = new SodaFactory();
			vegetablesFactory = new VegetablesFactory();
			numberStores = 0;
		}
		public static Singleton Instance
		{
			get
			{
				lock (_handle)
				{
					if (_instance == null) _instance = new Singleton();
				}
				return _instance;
			}
		}
		public static Singleton GetInstance()
		{
			if (_instance == null)
			{
				_instance = new Singleton();
			}
			return _instance;
		}
        public void mediatorUpdateStoreTable()
        {
			if(mediator == null)
            {
				mediator = new Mediator(ref ordersForm);
            }
			mediator.updateStoreTable();
        }
	}
}
