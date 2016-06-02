#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define DEFAULT_MAX_SIZE 1024
#include "Node.h"
using namespace std;
template <typename E>

class LinkedList
{
     private:
        Node<E>* head; // Puntero a la cabeza
        Node<E>* tail; // Puntero a la cola
        Node<E>* current; // Puntero a la posición actual
        int size; // Tamaño de la lista enlazada

    public:
        LinkedList(){
            tail = current = head = new Node<E>();
            size = 0;
        } // Constructor de la lista enlazada
        virtual ~LinkedList(){
            clear();
            delete head;
        } // Destructor de clase

        Node<E>* searchPrevious(Node<E>* pNode){
            if (current == head){
                return NULL;
            }
            Node<E>* res = head;
            while(res->next != current){
                res = res->next;
            }
            return res;
        }

        void previous(){
            if (current != head){ // Si no es la cabeza, tiene un anterior
                current = searchPrevious(current); // SearchPrevious metodo que busca al anterior
            }
        }

        void insert(E pElement){ // Se inserta un nodo nuevo
            current->next = new Node<E>(pElement, current->next);
            if(current == tail){
                tail = tail->next;
            }
            size++; // Se aumenta el tamaño de la lista
        }

        void append(E pElement){ // Se añade un nodo nuevo al final
            tail->next = new Node<E>(pElement);
            tail = tail->next;
            size++; // Se aumenta el tamaño de la lista
        }

        E remove()throw(runtime_error){
            if(current->next == NULL){
                throw runtime_error("No element"); // Se informa que no se pudo eliminar un elemento
            }
            Node<E>* temp = current->next; // Puntero temporal que apunta al siguiente de current
            E result = current->next->element;
            current->next = current->next->next;

            if (temp == tail) {
                tail = current;
            }
            delete temp; // Se borra el puntero temporal
            size--; // Se disminuye el tamaño de la lista
            return result;
        }

        void clear(){
            current = head;
            while (head != NULL) { // Se borra uno por uno hasta que no quede ninguno
                head = head->next;
                delete current;
                current = head;
            }
            head = tail = current = new Node<E>();
            size = 0; // Se reincia el contador de tamaño
        }

        E getElement()throw(runtime_error){
            if(current->next == NULL){
                throw runtime_error("No element"); // Se informa que no se pudo obtener un elemento
            }
            return current->next->element; // Se retorna el elemento
        }

        void goToStart(){
            current = head; // La cabeza pasa a ser current
        }
        void goToEnd(){
            current = head; // Se empieza desde la cabeza y se recorre hacia el final
            while (current->next->next != NULL){ // Verifica si a lo que apunta el siguiente elemento de current es el ultimo y no es NULL
                current = current->next;
            }
        }
        void goToPos(int pPos)throw(runtime_error){
            if((pPos < 0) || (pPos > size)){
                throw runtime_error("Fuera del limite"); // Se informa que no se ha salido del limite de la lista
            }
            current = head;
            for(int i = 0; i < pPos; i++){
                current = current->next; // Se va a la posicion indicada dentro del ciclo
            }
        }

        void next(){
            if(current != tail){
                current = current->next; // Se va al elemento siguiente
            }
        }

        int getPos(){
            int pos = 0;
            Node<E>* temp = head;
            while(temp != current){
                pos++;
                temp = temp->next;
            }
            return pos; // Se devuelve la posicion
        }

        int getSize(){
            return size; // Se devuleve size que contiene el tamaño de la lista
        }
};

#endif // LINKEDLIST_H
