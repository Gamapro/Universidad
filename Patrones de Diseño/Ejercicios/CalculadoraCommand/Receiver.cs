using System;
using System.Collections.Generic;
using System.Text;

namespace CalculadoraCommand
{
    public class Receiver
    {
        private char operation;
        private int num1, num2;
        public Receiver(char op, int a, int b)
        {
            operation = op;
            num1 = a;
            num2 = b;
        }
        public void Action()
        {
            Console.WriteLine("Receiver Action");
            switch (operation)
            {
                case '+': Add();
                    break;
            };
        }
        public void Add()
        {
            Console.WriteLine("Action Add {0}+{1}={2}",num1,num2,num1+num2);
        }
        public void Substract()
        {
            Console.WriteLine("Action Substract {0}-{1}={2}", num1, num2, num1 - num2);
        }
        public void Multiplicate()
        {
            Console.WriteLine("Action Multiplicate {0}*{1}={2}", num1, num2, num1 * num2);
        }
        public void Divide()
        {
            Console.WriteLine("Action Divide {0}/{1}={2}", num1, num2, num1 / num2);
        }
    }
}
