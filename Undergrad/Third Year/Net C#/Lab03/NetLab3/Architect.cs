using System;
using System.Collections.Generic;
using System.Text;

namespace NetLab3
{
    public class Architect : Manager
    {
        public Architect(string firstName, string lastName, DateTime startDate,
            DateTime endDate, int salary) : base(firstName, lastName, startDate, 
                endDate, salary)
        {

        }

        public override string Salutation()
        {
            return "Hello architect, " + this.firstName + " " + this.lastName;
        }
    }
}
