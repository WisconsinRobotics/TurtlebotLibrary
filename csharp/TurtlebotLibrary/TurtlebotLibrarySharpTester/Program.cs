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

            //            Drive d = new Drive(100, 50);
            //            byte[] buffer = d.Serialize();
            //
            //            foreach (byte b in buffer)
            //                Console.Write("{0:X} ", b);
            //            Console.WriteLine();
            //
            //            Console.Read();

            string serialPort = "";
            bool testMode = false;

            for (int index = 0; index < args.Length; ++index)
            {
                if (args[index][0] != '-')
                {
                    continue;
                }

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
            //Drive driveMessage = new Drive((int)100, (int)Drive.STRAIGHT);
            //c.SendTurtlebotMessage(driveMessage);
            //WaitTime w = new WaitTime(10);
            //c.SendTurtlebotMessage(w);
            //System.Threading.Thread.Sleep(5000);
            //Drive stop = new Drive((int)0, (int)Drive.STRAIGHT);
            //c.SendTurtlebotMessage(stop);
            Console.Read();
        }
    }
}
