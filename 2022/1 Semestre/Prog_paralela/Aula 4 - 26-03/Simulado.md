# Simulado

## 1. O que se entende por programação paralela e quais são as formas de execução?

>R: É a execução de um ou mais código, processos, threads ou programas simultaneamente, temos como executar a programação paralela em um processador com varios nucleos, em uma maquina com varios processadores, utilizar o processador da gpu que possui varios nucleos, em rede entre varias maquinas.

## 2. Defina Processos

>R: Processo é um programa em execução, esse processo fica na memória e nele contem, codigo e dados do programa, pilha de execução, associação a um conjunto de registradores, outras informações necessárias para execução do programa.

    Slide: 
        • Um programa em execução necessita de recursos de hardware: Processador, Memória e Dispositivos de I/O (Entrada e Saída)
        • O Sistema Operacional é responsável por fornecer esses recursos aos 
        programas
        • Como vários programas podem estar ativos ao mesmo tempo, o sistema operacional utiliza a abstração de Processo para gerenciar o acesso concorrente aos recursos de hardware
        • Assim, cria-se a ilusão de que os programas estejam sendo executados ao mesmo tempo e que cada um possui recursos de hardware exclus
        • Um processo é portanto, um programa em execução
        • Quando um programa é executado, é criado um processo na 
        memória para este programa, e neste processo contem:
        • Código e dados do programa
        • Pilha de execução (espaço de memória usado para as chamadas de funções)
        • Associação a um conjunto de registradores, e dentre eles: • Apontador de instruções (endereço da próxima instrução a ser executada) • Apontador do topo da pilha
        • Outras informações e recursos necessários para a execução do programa

## 3. Defina Threads

    R: Thread(linha) significa linha de execução de um processo, são independentes dentro de um processo, exceto pelos recursos do hardware, nos novos computadores de varios núcleos, as threads podem ser executadas em paralelo em cada nucleo ou em cada processador em maquinas com mais de um.

    Slide:
        • Nos sistemas operacionais antigos e tradicionais, um Processo possuía apenas uma linha de execução, ou também chamado fluxo de controle, ou simplesmente Thread
        • A tradução de thread é linha, e neste contexto refere-se à linha de execução de um processo
        • Nos sistemas operacionais modernos, um processo pode ter diversas linhas de execuções, ou seja, diversas Threads, como se fossem “subprocessos dentro do processo”
        • As Threads dentro de um processo são independentes, exceto pelos recursos de hardware do processo que são compartilhados entre as Threads, incluindo a Memória e os dispositivos de entrada e saída, entre 
        outros...
        • Com o surgimento de processados com vários núcleos, e também computadores com vários processadores, as Threads podem ser executadas em paralelo em cada núcleo do processador ou em cada processador no caso da máquina tiver vários processadores 

## 4. Cite três APIs que possibilita a programação paralela utilizando Threads

    R:  • OpenMP
        • Win32 Threads
        • POSIX Threads (Pthreads)

## 5. O que é OpenMP e para quais linguagens de programação está disponível?

    R: É uma API que possui um conjunto de funções e diretivas para o compilador que permite a criação de programas paralelos com compartilhamento de memória, através da criação automática e automatizada de um conjunto de Threads, está disponível para as linguagens C/C++ e Fortran.

## 6. Como funciona a programação paralela utilizando OpenMP? É por memória compartilhada ou memória única com troca de mensagens? Utiliza o esquema fork join (explique)?

    R: Varias threads são criadas a partir de um ponto, onde são trabalhadas individualmente e depois são fechadas ou colocadas em pausa, utiliza memoria compartilhada, sim  
    baseia-se no modelo do tipo forkjoin, ou seja, várias Threads são criadas a partir de um fork e em um determinado outro ponto são eliminada (join) ou colocadas em espera para futuras chamadas.

## 7. Qual a diferença entre as funções omp_get_max_threads(), omp_get_num_threads() e omp_get_thread_num() ?

    R:  omp_get_max_threads() -> Retorna numero maximo de nucleos disponiveis.
        omp_get_num_threads() -> Retorna numero maximo de nucleos disponiveis do time atual, se estiver na regiao serial , é 1 se estiver na paralela, é o numero de threads definidas.
        omp_get_thread_num() - > Retorna o ID da thread

## 8. Quando se inicia a região paralela com a diretiva #pragma omp parallel, quantas threads são criadas no time ? É possível iniciar a região paralela com um número diferente de threads ? (explique)

    R: #pragma omp parallel quando sem especificação, cria uma região paralela com a quantidade maxima de nucleos/threads que o processador tem, mas podemos especificar com #pragma omp parallel num_threads(n) e no lugar de n podemos definir a quantidade de threads que será criado na região paralela

## 9. Explique a cláusula if da diretiva #pragma omp parallel

    R: A cláusula if é utilizada para validar se irá compensar parelizar aquele código, então, por ela podemos definir uma condição minima de registros ou um minimo valor de entrada para que o código seja parelizado.

## 10. Explique o escopo de variáveis utilizando programação paralela com OpenMP

    R: Variaveis declaradas fora do bloco de codigo da parelização #parallel são consideradas globais, e poderam ser vistas e alteradas por todas as threads, já as declaradas dentro do bloco, se tornam privadas para cada thread, assim se temos uma variavel X será criada uma variavel X em cada thread, não podendo visualizar valores de outra thread alheia.

## 11. Explique a cláusula private. Dê um exemplo

    R: Clausula private é utilizada quando precisamos que uma variavel que é global se mantenha privada em cada thread, então passamos #pragma omp parallel private(x, y), assim mesmo sendo x e y globais(fora do bloco), elas serão privadas em cada thread paraela criada.

    {
        int i, ,j, x, y;

        #pragma omp parallel private(x, y)
        {
            x = omp_get_thread_num();
            y = x + 2;

            printf("%d", x + y);
        }
    }

## 12. Explique os seguintes construtores de trabalho, e dê exemplos de cada um

    a. for: #pragma omp parallel for 
            -> Divide a tarefa da estrutura for de forma igual para todas as threads do time da região paralela, se tivermos 4 thread, cada thread irá executar n/4 somas(EXEMPLO ABAIXO), o construtor também faz com que a variável de controle seja privada em todas as threads  

            {
                #pragma omp parallel // fork
                
                int i;

                #pragma omp for
                for(i = 0; i < n; i++){
                    C[i] = A[i] + B[i];
                }
            } // join
        
    b. single: #pragma omp single 
            -> Faz com que o bloco de código seja executado em 
            apenas uma thread

            #pragma omp parallel // fork   -> será executado em paralelo em n threads do time
            {
                printf("%d", omp_get_thread_num());

                #pragma omp single   -> será executado em apenas uma das threads do time
                {
                    printf("%d", omp_get_thread_num());
                }
            } // join

    c. master: #pragma omp master
            -> Semelhante ao contrutor de trabalho single, tambem executa em apenas thread, com a particularidade que é a thread é em especifico a principal  a thread master

            #pragma omp parallel -> será executado em paralelo em n threads do time
            {
                prinft("%d", omp_get_thread_num());

                #pragma omp master -> será executado em apenas uma das thread, sendo ela a thread master
                {
                    printf("%d", omp_get_thread_num());
                }
            } // join 

    d. sections: #pragma omp sections
            -> Nem sempre o problema que está se resolvendo necessita  trabalhar em paralelo com todas as threads/núcleos disponíveis no sistema
            • O construtor sections faz com que blocos de códigos       individuais sejam executados em threads individuais, blocos de codígos diferentes são executados paralelamente
            •  Exemplo: Atribuir valores para dois vetores A e B, 
            sendo que a atribuição dos valores de A deve ser 
            numa thread e atribuição dos valores de B em outra 
            thread

            {
                #pragma omp parallel
                {
                    #pragma omp sections 
                    {
                        #pragma omp section
                        {
                            for(int i=0; i<n; i++){
                                printf("\nSection A: %d \n", omp_get_thread_num());
                                A[i] = i + 10;
                            }
                        }
                        
                        #pragma omp section
                        {
                            for(int i=0; i<n; i++){
                                printf("\nSection B: %d\n", omp_get_thread_num());
                                B[i] = i * 8;
                            }
                        }
                    }
                }
            }

## 13. Quando se utiliza mais de um construtor de trabalho, são criadas barreiras. Explique

    R: Barreiras são criadas a cada fechamento('}') de construtor de trabalho, assim outro construtor só inicia, após termino do anterior, se temos um contrutor sections seguido de um single, o single só executará após o termino do do processamento das sections, mas essas barreiras podem ser liberadas usando a clausula 'nowait', assim o proximo construtor podera ser executado em paralelo tambem  

    {
        #pragma omp parallel
        {
            #pragma omp sections nowait
            {
                #pragma omp section
                {
                    for(int i=0; i<n; i++){
                        printf("\nSection A: %d \n", omp_get_thread_num());
                        A[i] = i + 10;
                    }
                }
                
                #pragma omp section
                {
                    for(int i=0; i<n; i++){
                        printf("\nSection B: %d\n", omp_get_thread_num());
                        B[i] = i * 8;
                    }
                }
            }
            
            #pragma omp single
            {
                for(int i = 0; i<n; i++){
                    printf("\nSingle: %d\n", omp_get_thread_num());
                    C[i]= i + 158;
                }
            }
        }
    }

## 14. O que é e quando ocorre uma situação de região crítica? Existe algum recurso para resolver este problema?

    R: É um determinado trecho de código onde não se pode executar de forma paralela, geralmente nestes trechos de códigos, região crítica, há uma ou mais variáveis PÚBLICAS a todas as Threads que são atualizadas, e por serem publicas não se pode atualizalas paralelamente, pois a logica seria quebrada

    • Podemos solucionar usando a clausula 'critical', para que seja executado apenas em uma thread, evitando atualizações de variaveis publicas em paralelo.

## 15. Implemente um problema utilizando programação paralela que contém região crítica

    R: Exemplo: Produto escalar entre dois vetores A e B
        formula: P = A[1]*B[1] + A[2]*B[2]...

        No single
        {
            P = 0;
            for(int i = 0; i<n; i++){
                P = P + A[i] * B[i];
            }
        }

        No paralelo: variavel P global para todas as threads, assim é atualizada por todas, podendo ser calculada errada
        {
            P = 0;

            #pragma omp parallel
            {
                #pragma omp for
                for(int i = 0; i<n; i++)
                {
                    P = P + A[i] * B[i]; // regiao critica
                }
            }
        }

        Usando Critical: Corrigi, não teremos atualizações em paralelo, porque o critical garante que a atualização seja feita apenas por uma thread de cada vez, mas dessa forma usando apenas uma thread o desempenho fica parecido com o não paralelizado, pior que o single por ter de criar as regioes antes criticas 
        {
            P = 0;

            #pragma omp parallel
            {
                #pragma omp for
                for(int i = 0; i<n; i++)
                {
                    #pragma omp critical
                    {
                        P = P + A[i] * B[i]; // regiao critica
                    }               
                }
            }
        }

        Critial + Desempenho: com P auxiliar, não temos problema de atualizações paralelas na mesma variavel, neste formato a regiao critica será executada na mesma quantidade de numero de threads, no anterior seria 'N' vezes
        {
            P = 0;

            #pragma omp parallel
            {
                PAUX = 0; // variavel auxiliar privada de cada thread

                #pragma omp for
                for(int i = 0; i<n; i++)
                {
                    PAUX = PAUX + A[i] * B[i];   // soma feita na variavel privada de cada thread    
                }// barreira
                //executa após a soma terminar
                #pragma omp critical
                {
                    P = P + PAUX; // regiao critica
                } // agrega valor da soma no P global 1 vez
            }
        }//JOIN

## Fim simulado
