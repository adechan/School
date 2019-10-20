using System;

namespace NetLab3
{
    public static class StringExtensions
    {
        public static int CountWords(this String str)
        {
            return str.Split(new char[] { ' ', '.', '?' },
                             StringSplitOptions.RemoveEmptyEntries).Length;
        }
    }
}
