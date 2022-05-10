using System;
using System.Collections.Generic;
using System.Text;

namespace CalculadoraCommand
{
    public abstract class Command
    {
        protected Receiver receiver;
        public Command(Receiver receiver)
        {
            this.receiver = receiver;
        }
        public abstract void Execute();
    }
}
