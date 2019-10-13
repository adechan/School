using System;

namespace NetLab3
{
    public class Manager
    {
        // atributes
        // globally unique id
        public Guid Id { get; private set; }
        public string firstName { get; private set; }
        public string lastName { get; private set; }
        public DateTime startDate { get; private set; }
        public DateTime endDate { get; private set; }
        public int salary { get; private set; }

        public Manager(string firstName, string lastName, DateTime startDate,
            DateTime endDate, int salary)
        {
            this.Id = new Guid();
            this.firstName = firstName;
            this.lastName = lastName;
            this.startDate = startDate;
            this.endDate = endDate;
            this.salary = salary;       
        }

        public string GetFullName()
        {
            string fullName = firstName + " " + lastName;
            return fullName;
        }

        public Boolean IsActive()
        {
            if (this.endDate > DateTime.Now)
                return true;
            return false;
        }

        public virtual string Salutation()
        {
            return "Hello manager, " + this.firstName + " " + this.lastName;
        }
        
    }
}
