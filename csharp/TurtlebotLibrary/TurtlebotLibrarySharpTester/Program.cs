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
            string serialPort = "";
            bool testMode = false;

            for (int index = 0; index < args.Length; ++index)
            {
                if (args[index][0] != '-')
                    continue;

                switch (args[index][1])
                {
                    case 's':
                        ++index;
                        if (index == args.Length)
                            return;
                        serialPort = args[index];
                        break;
                    case 't':
                        testMode = true;
                        break;
                    default:
                        return;
                }
            }

            TurtlebotCommandSender c = new TurtlebotCommandSender();
            c.Initialize(serialPort, DriveMode.Safe);

            if (!testMode)
            {
                int velocity = 100;
                int radius = Drive.STRAIGHT;

                Drive d = new Drive(velocity, radius);
                c.SendTurtlebotMessage(d);
                
                byte[] buffer = d.Serialize();
                foreach (byte b in buffer)
                    Console.Write("{0:X} ", b);
                Console.WriteLine();
            }

            Console.Read();
        }
    }
}
