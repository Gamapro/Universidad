using System;

namespace CalculadoraCommand
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Client client = new Client();
            client.Run('+',1,2);
        }
    }
}
