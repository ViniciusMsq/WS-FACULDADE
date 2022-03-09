using System;
using System.Collections.Generic;
using System.Text;

namespace projeto2002
{
        class Pincel
        {
            string cor;
            double preco, tamanho;

            public void setCor(string cor)
            {
                this.cor = cor;
            }
            public string getCor()
            {
                return cor;
            }

            public void setPreco(double preco)
            {
                this.preco = preco;
            }

            public double getPreco()
            {
                return preco;
            }
            public void setTamanho(double tamanho)
            {
                this.tamanho = tamanho;
            }

            public double getTamanho()
            {
                return tamanho;
            }
            public void Pintar()
            {

                Console.WriteLine("Estou pintando usando a cor " + cor);
            }
        }
}
