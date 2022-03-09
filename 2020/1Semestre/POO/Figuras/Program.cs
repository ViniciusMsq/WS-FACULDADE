using System;

namespace Figuras
{
    class Program
    {
        static IFiguras If;
        static Circulo c;
        static Retangulo r;
        static Circulo[] vCirculo;
        static int indice;

        static void Main(string[] args)
        {
            vCirculo[10] = new Circulo[10];
            IMenu Im;
            int op=1;        
            If = new IFiguras();
            Im = new IMenu();
            
            indice = 0;

            while ((op > 0) && (op < 5))
            {
                op = Im.LeMenu();
                Console.Clear();
                if ((op > 0) && (op < 5))
                {
                    trataMenu(op);
                }
                Console.ReadKey();
                Console.Clear();
                
            }
        }
        static void trataMenu(int op)
        {
            switch (op)
            {

                case 1:
                    vCirculo[indice] = If.ILeCirculo();
                    
                    break;
                case 2:
                    //If.IMostraCirculo(c);
                    //If.IMostraAreaC(c);
                    If.IMostraVCirculo(vCirculo, indice);
                    break;
                case 3:
                    r = If.ILeRetangulo();
                    break;
                case 4:
                    If.IMostraRetangulo(r);
                    If.IMostraAreaR(r);
                    break;
                case 5:

                    break;
            }
        }
    }
}
