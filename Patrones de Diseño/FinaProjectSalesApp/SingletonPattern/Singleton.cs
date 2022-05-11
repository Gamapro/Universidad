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
		public TruckFactory breadTruckFactory, sodaTruckFactory, vegetablesTruckFactory;
		public int numberStores;
		public List<Truck> trucks;
		public FacadeQR facade;
		public Binacle binnacle;
		protected Singleton()
		{
			binnacle = new Binacle();
			facade = new FacadeQR();
			trucks = new List<Truck>();
			breadFactory = new BreadFactory();
			sodaFactory = new SodaFactory();
			vegetablesFactory = new VegetablesFactory();
			breadTruckFactory = new BreadTruckFactory();
			sodaTruckFactory = new SodasTruckFactory();
			vegetablesTruckFactory = new VegetablesTruckFactory();
			for(int i = 0; i < 3; i++)
            {
				trucks.Add(sodaTruckFactory.FactoryCreate());
				trucks.Add(breadTruckFactory.FactoryCreate());
				trucks.Add(vegetablesTruckFactory.FactoryCreate());
			}
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
