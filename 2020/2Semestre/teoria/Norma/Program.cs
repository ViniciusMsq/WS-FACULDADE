using System;

namespace Teoria
{
    class Program{
        
        static void Main(string[] args)
        {
            int opcao = 1;
            while((opcao>0) && (opcao<4)){
                Console.Write("1- Soma racional 2- Soma Preservando 3 - Multiplicação Racional\n opcaocao : ");
                opcao = int.Parse(Console.ReadLine());

                switch(opcao){
                    case 1: SomaRac();
                        break;
                    case 2: PresSoma();
                        break;
                    case 3: MultRac();
                        break;
                        default: Console.WriteLine("teste");
                        break;
                }
            }
        }

        public static void MultRac(){
            int a, b, c, d;
            double res = 0.0, r1, r2;

            Console.WriteLine("dividendo: ");
            a =  int.Parse(Console.ReadLine());

            Console.WriteLine("dividor: ");
            b =  int.Parse(Console.ReadLine());

            Console.WriteLine("segundo dividendo: ");
            c =  int.Parse(Console.ReadLine());
            
            Console.WriteLine("segundo divisor: ");
            d =  int.Parse(Console.ReadLine());

            Console.WriteLine("\n({0}, {1}) * ({2}, {3}): ", a, b, c, d);
            
            r1 = a*c;
            r2 = b*d;

            Console.Write("({0}, {1})", r1, r2);
            res = r1/r2;
            Console.WriteLine("\nresultado: {0}", res); 
            Console.ReadKey();
        }
        public static void PresSoma(){
            
            int a, b, c=0;

            Console.WriteLine("A: ");
            a = int.Parse(Console.ReadLine());
            Console.WriteLine("B: ");
            b = int.Parse(Console.ReadLine());

            while(!(b==0)){
                a = a+1;
                c = c+1;
                b = b - 1;
            }
            while(!(c==0)){
                b=b+1;
                c= c-1;
            }

            Console.WriteLine("Resultado: "+ a);
        }
        public static void SomaRac(){
            int a, b, c, d, r1, r2;

            Console.WriteLine("dividendo: ");
            a =  int.Parse(Console.ReadLine());

            Console.WriteLine("dividor: ");
            b =  int.Parse(Console.ReadLine());

            Console.WriteLine("segundo dividendo: ");
            c =  int.Parse(Console.ReadLine());
            
            Console.WriteLine("segundo divisor: ");
            d =  int.Parse(Console.ReadLine());

            Console.WriteLine("\n({0}, {1}) + ({2}, {3}): ", a, b, c, d);
            
            r1 = (a*d)+(b*c);
            r2 = b*d;

            Console.Write("({0}, {1})", r1, r2);

            Console.WriteLine("\nresultado: {0}", (r1/r2)); 
        }
    }
}
