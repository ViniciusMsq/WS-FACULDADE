using System;

namespace Figuras
{
    class Program
    {
        static void Main(string[] args)
        {
            
            Circulo c;
            Retangulo r;
            IFiguras If;
            IMenu Im;
            int op;        
            If = new IFiguras();
            Im = new IMenu();
            op = Im.LeMenu();
            
            
            if (op == 1)
            {
                c = If.ILeCirculo();
                If.IMostraCirculo(c);
                If.IMostraAreaC(c);
            }
            else if (op == 2)
            {

                r = If.ILeRetangulo();
                If.IMostraRetangulo(r);
                If.IMostraAreaR(r);
            }
            else
            {
                Console.WriteLine("Valor invalido");
            }
        }
    }
}
