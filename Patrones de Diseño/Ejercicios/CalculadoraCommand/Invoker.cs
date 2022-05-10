using System;
using System.Collections.Generic;
using System.Text;

namespace CalculadoraCommand
{
    public class Invoker
    {
        public void Invoke(Command command)
        {
            Console.WriteLine("Execute command from invoker");
            command.Execute();
        }
    }
}
