using System;

namespace NetLab3
{
    public class Architect : Employee
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
