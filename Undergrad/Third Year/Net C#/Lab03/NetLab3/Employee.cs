using System;
using System.Text.RegularExpressions;

namespace NetLab3
{
    public abstract class Employee
    {
        // atributes
        // globally unique id
        public Guid Id { get; private set; }
        public string firstName { get; private set; }
        public string lastName { get; private set; }
        public DateTime startDate { get; private set; }
        public DateTime endDate { get; private set; }
        public int salary { get; private set; }

        public Employee(string firstName, string lastName, DateTime startDate,
            DateTime endDate, int salary)
        {
            this.Id = new Guid();
            if (Regex.IsMatch(firstName, @"^[a-zA-Z]+$"))
            {
                this.firstName = firstName;
            }
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

        public abstract string Salutation();

    }
}
