using System;
using System.Collections.Generic;
using System.Text;

namespace CalculadoraCommand
{
    public class ConcreteCommand : Command
    {
        public ConcreteCommand(Receiver receiver) : base(receiver)
        {
            Console.WriteLine("New Concrete Command");
        }
        public override void Execute()
        {
            Console.WriteLine("Executeeee");
            receiver.Action();
        }
    }
}
