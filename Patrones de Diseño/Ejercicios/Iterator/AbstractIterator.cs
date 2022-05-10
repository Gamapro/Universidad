using System;
using System.Collections.Generic;
using System.Text;

namespace IteratorPattern
{
    public class AbstractIterator : Iterator
    {
        private List<Weekdays> weekdays;
        private int position;
        public AbstractIterator(List<Weekdays> weekdays)
        {
            this.weekdays = weekdays;
        }
        public override object Current
        {
            get { return weekdays[position]; }
        }
        public override bool First()
        {
            throw new NotImplementedException();
        }
        public override bool MoveNext()
        {
            position = Math.Min(position+1, weekdays.Count);
            return position < weekdays.Count && position >= 0;
        }

        public override void Reset()
        {
            throw new NotImplementedException();
        }
    }
}
