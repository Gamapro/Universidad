using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace IteratorPattern
{
    public abstract class Aggregate : IEnumerable
    {
        public abstract IEnumerator GetEnumerator();
        public abstract void CreateIterator();

    }
}
