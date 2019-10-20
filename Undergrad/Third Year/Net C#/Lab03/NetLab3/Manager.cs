using System;

namespace NetLab3
{
    public class Manager : Employee
    {
        public Manager(string firstName, string lastName, DateTime startDate,
         DateTime endDate, int salary) : base(firstName, lastName, startDate,
         endDate, salary)
        {

        }

        public override string Salutation()
        {
            return "Hello manager, " + this.firstName + " " + this.lastName;
        }
        
    }
}
