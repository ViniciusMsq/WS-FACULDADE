using System;
using System.Collections.Generic;
using System.Text;

namespace CadastroAluno
{
    class IAluno
    {
        public Aluno ILeAluno() //faz o cadastro dos alunos pela opção 1
        {
            Aluno aluno;
            string nome, endereco, curso;
            int anoIngresso, ra;

            Console.WriteLine("Nome: ");
            nome = Console.ReadLine();
            Console.WriteLine("Endereço: ");
            endereco = Console.ReadLine();
            Console.WriteLine("Curso: ");
            curso = Console.ReadLine();
            Console.WriteLine("Ano de Ingresso: ");
            anoIngresso = int.Parse(Console.ReadLine());
            Console.WriteLine("RA: ");
            ra = int.Parse(Console.ReadLine());
            aluno = new Aluno(nome, endereco, curso, anoIngresso, ra);

            return aluno;//retorno do aluno cadastrado
        }
        
        public void PesquisarRa(Aluno[] vAluno, int indice, int ra)
        {    //faz a pesquisa pelo Ra e devolve informações do aluno requisitado
            
            int i = 0;

            while (i< indice)
            {
                if (ra == vAluno[i].getRa())
                {
                    Console.WriteLine("Aluno: "+ i+" <- iição de alteração");
                    Console.WriteLine("Nome: " + vAluno[i].getNome());
                    Console.WriteLine("Endereço: " + vAluno[i].getEndereco());
                    Console.WriteLine("Curso: " + vAluno[i].getCurso());
                    Console.WriteLine("Ano de Ingresso: " + vAluno[i].getAnoIngresso());
                    Console.WriteLine("RA: " + vAluno[i].getRa());
                    Console.ReadKey();
                    break;
                }
                i++;
            }
            
            
        }
        public void MostrarAlunos(Aluno[] vAluno, int indice)
        {//exibe todos os alunos em um loop

            if(indice>0){
            for (int i =0; i<indice; i++)
            {
                Console.WriteLine("Aluno " + (i + 1));
                Console.WriteLine("   "+ vAluno[i].getNome());
                Console.WriteLine("   " + vAluno[i].getEndereco());
                Console.WriteLine("   " + vAluno[i].getCurso());
                Console.WriteLine("   " + vAluno[i].getAnoIngresso());
                Console.WriteLine("   " + vAluno[i].getRa());
            }
            }else{
                Console.WriteLine("nenhum aluno cadastrado");
            }
            Console.ReadKey();
            Console.Clear();
        }

        public void ModificarAluno(Aluno[] vAluno, int indice, int ra)
        {//pega a iição vetorial do aluno, exibe seus dados, e permite modificação total
            Console.Clear();
            int i = 0, cont =0;
            
            while (i< indice)
            {
                if (ra == vAluno[i].getRa())
                {
                    cont++;
                    Console.WriteLine("Nome: " + vAluno[i].getNome());
                    Console.WriteLine("Endereço: " + vAluno[i].getEndereco());
                    Console.WriteLine("Curso: " + vAluno[i].getCurso());
                    Console.WriteLine("Ano de Ingresso: " + vAluno[i].getAnoIngresso());
                    Console.WriteLine("RA: " + vAluno[i].getRa());
                    Console.ReadKey();
                    break;
                }
                i++;
            }
            //teste
            if(cont>0){
            Console.WriteLine("Modificação: ");

            string nome, endereco, curso;
            int anoIngresso;
            //parte para modificar
            Console.WriteLine("Nome: ");
            nome = Console.ReadLine();
            Console.WriteLine("Endereço: ");
            endereco = Console.ReadLine();
            Console.WriteLine("Curso: ");
            curso = Console.ReadLine();
            Console.WriteLine("Ano de Ingresso: ");
            anoIngresso = int.Parse(Console.ReadLine());

            vAluno[i].setNome(nome);
            vAluno[i].setEndereco(endereco);
            vAluno[i].setCruso(curso);
            vAluno[i].setAnoIngresso(anoIngresso);
            }else{
                Console.WriteLine("Ra não existe");
                Console.ReadKey();
            }

        }
        public void ListarAlunosCurso(Aluno[] vAluno, int indice, string cursos){
            // metodo para listar alunos do curso desejado
            int cont=0;//contador para fazermos um teste simples
            Console.Clear();
            Console.WriteLine("Alunos do curso de "+ cursos);
            for(int i = 0; i<indice; i++){// for para percorrer o vetor todo de alunos

                if(cursos == vAluno[i].getCurso()){
                    //vai comparar se o curso escolhido antes é o mesmo do aluno [i posição do vetor]
                    cont++;//nosso teste simples, caso entre na condição a gente incrementa
                    Console.WriteLine("-----------------------------");
                    Console.WriteLine(" RA: " + vAluno[i].getRa());
                    Console.WriteLine(" Nome: " + vAluno[i].getNome());
                    Console.WriteLine(" Endereço: " + vAluno[i].getEndereco());
                    Console.WriteLine(" Curso: " + vAluno[i].getCurso());
                    Console.WriteLine(" Ano de Ingresso: " + vAluno[i].getAnoIngresso());
                    //faz todas as impressoes de dados dos alunos       
                }   
            }
            //acabado o for, a gente usa nosso teste rapido,
            // caso tenha entrado na condição la em cima ele vai ta maior que 0
            // se nao entrou nenhuma vez, é porque nao existia curso, ai vai ta 0 ainda
            if(cont==0){
                Console.WriteLine("Nenhum aluno cadastrado no curso ou curso não existente");
            }


            Console.ReadKey();
        }


    }
}
