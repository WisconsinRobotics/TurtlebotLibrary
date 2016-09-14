using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using TurtlebotLibrarySharp;

namespace TurtlebotLibrarySharpTester
{
    class Program
    {
        static void Main(string[] args)
        {
            Drive d = new Drive(100, 50);
            byte[] buffer = d.Serialize();

            foreach (byte b in buffer)
                Console.Write("{0:X} ", b);
            Console.WriteLine();

            Console.Read();
        }
    }
}
