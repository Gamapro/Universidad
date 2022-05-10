using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace IteratorPattern
{
    public abstract class Iterator : IEnumerator
    {
        public abstract object Current { get; }
        public abstract bool First();
        public abstract bool MoveNext();
        public abstract void Reset();
    }
}
