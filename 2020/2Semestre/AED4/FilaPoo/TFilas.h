#ifndef TFILAS_H
#define TFILAS_H

class TFilas
{
        
    public:

        typedef int TInfoFila;

        struct TNoFila{
            TInfoFila dado;
            TNoFila *prox;
        };

        struct TFila{
            TNoFila *Comeco;
            TNoFila *Final;
        };

        void Q_Init(TFila *&Fila);

        bool Q_IsEmpty(TFila *Fila);

        void Enqueue(TFila *&Fila, TInfoFila elemento);

        TInfoFila Dequeue(TFila *Fila);

        TInfoFila Q_Comeco(TFila *Fila);

        TInfoFila Q_Final(TFila *Fila);
   
        void PrintFila(TFila *F);
        
};

#endif
