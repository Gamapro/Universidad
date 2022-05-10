using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace IteratorPattern
{
    public class Weekdays : Aggregate
    {
        private string day { get; set; }
        Weekdays(string day)
        {
            this.day = day;
        }
        public override void CreateIterator()
        {
            throw new NotImplementedException();
        }
        public override IEnumerator GetEnumerator()
        {
            throw new NotImplementedException();
        }
    }
}
