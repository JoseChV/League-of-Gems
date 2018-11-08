


#ifndef A_SIMPLELIST_H
#define A_SIMPLELIST_H

template<class T>
struct nodoS{
    T data;
    nodoS *next = nullptr;

    nodoS(T data) {
        this->data = data;
    }
};

template <class T>
class SimpleList{

    int length = 0;
    nodoS<T> *primero;

public :
    SimpleList(){
        primero = nullptr;
    }

    void add(T p_data){
        nodoS<T> *nuevo = new nodoS<T>(p_data);
        if (this->primero == nullptr){
            primero = nuevo;
        }
        else{
            nodoS<T> *temp;
            temp = primero;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = nuevo;
        }
        this->length ++;
    }

    T* getData(int pos){
        nodoS<T> *temp = primero;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
        return &temp->data;
    }

    void setData(int pos, T newData) {
        nodoS<T> *temp = primero;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
        temp->data = newData;
    }

    int getLength(){
        return this->length;
    }

    bool isEmpty(){
        return this->length == 0;
    }

    void deleteNode(int pos){
        nodoS<T> *aux = primero;
        if(pos == 0){
            primero = aux->next;
            free(aux);
        } else {
            nodoS<T> * prev = aux;
            for (int i = 0; i < this->length; i++) {
                if (i == pos) {
                    prev->next = aux->next;
                    free(aux);
                    break;
                }
                prev = aux;
                aux = aux->next;
            }
        }
        this->length--;
    }
};


#endif //ALGORITMOS_SIMPLELIST_H
