using System;
using System.Collections.Generic;
using System.Text;

namespace CalculadoraCommand
{
    public class Client
    {
        public Client()
        {
        }
        public void Run(char op, int a, int b)
        {
            Console.WriteLine("Client Run");
            Receiver receiver = new Receiver(op, a, b);
            Command command = new ConcreteCommand(receiver);

            Invoker invoker = new Invoker();
            invoker.Invoke(command);
        }
    }
}
