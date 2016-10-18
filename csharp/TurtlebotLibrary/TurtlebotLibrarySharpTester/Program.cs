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
            Script s = new Script();
            Drive driveStraight = new Drive(100, Drive.STRAIGHT);
            Drive turnRight = new Drive(100, Drive.CLOCKWISE);
            Drive turnLeft = new Drive(100, Drive.COUNTERCLOCKWISE);
            Drive stop = new Drive(0, Drive.STRAIGHT);
            WaitDistance halfMeter = new WaitDistance(500);
            WaitAngle rightTurn = new WaitAngle(-90);
            WaitAngle leftTurn = new WaitAngle(90);

            s.AddCommand(driveStraight);
            s.AddCommand(halfMeter);
            s.AddCommand(turnRight);
            s.AddCommand(leftTurn);
            s.AddCommand(driveStraight);
            s.AddCommand(halfMeter);
            s.AddCommand(turnLeft);
            s.AddCommand(leftTurn);
            s.AddCommand(driveStraight);
            s.AddCommand(halfMeter);
            s.AddCommand(stop);
            Console.Read();
        }
    }
}
