
#ifndef ALGORITMOS_PILA_H
#define ALGORITMOS_PILA_H
template <typename T>
    struct nodo{
        T dato;
        nodo *anterior;
    };

template <typename T>
    class Pila {

    private:
        nodo<T> *tope;
        int lenght = 0;

public:
        void push(T dato);
        T pop();
        T peek();
        int getLenght(){ return this->lenght;};

    };

template<typename T>
    void Pila<T>::push(T dato) {
        if(tope == nullptr){
        tope = new nodo<T>();
        tope->dato = dato;
        tope->anterior = nullptr;
    } else{
        auto *nodoN = new nodo<T>();
        nodoN->dato = dato;
        nodoN->anterior = tope;
        tope = nodoN;
    }
    this->lenght ++;
}

template<typename T>
    T Pila<T>::pop() {
        nodo<T> *aux;
        aux = tope;
        tope = tope->anterior;
        T dato;
        dato = aux->dato;
        free(aux);
        this->lenght --;
        return dato;
    }

template<typename T>
    T Pila<T>::peek() {
        return this->tope->dato;
    }
#endif //ALGORITMOS_PILA_H
