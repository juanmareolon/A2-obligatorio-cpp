#ifndef LIST_IMP
#define LIST_IMP

#include "List.h"

#include <cassert>

template <class T>
class ListImp : public List<T>
{
private:
    class NodoLista
    {
    public:
        T element;
        NodoLista *next;
        NodoLista(T element, NodoLista *next) : element(element), next(next) {}
    };

    NodoLista *head;
    NodoLista *tail;
    int size;

public:
    ListImp() : head(NULL), size(0) {}

    void insert(T element)
    {
        NodoLista *newNodoLista = new NodoLista(element, NULL, this->tail);
        if (isEmpty())
        {
            head = newNodoLista;
            tail = newNodoLista;
        }
        else
        {
            tail->next = newNodoLista;
            tail = newNodoLista;
        }
        size++;
    }

    void insertAt(int index, T element)
    {
        assert(index >= 0 && index < size);
        NodoLista *newNodoLista = new NodoLista(element, NULL, NULL);
        if (index == 0)
        {
            newNodoLista->next = head;
            head->previous = newNodoLista;
            head = newNodoLista;
        }
        else if (index == size)
        {
            tail->next = newNodoLista;
            newNodoLista->previous = tail;
            tail = newNodoLista;
        }
        else
        {
            NodoLista *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            newNodoLista->next = current;
            newNodoLista->previous = current->previous;
            current->previous->next = newNodoLista;
            current->previous = newNodoLista;
        }
        size++;
    }

    void remove(T element)
    {
        NodoLista *current = head;
        while (current != NULL)
        {
            // note: that the elment should implement == operator
            if (current->element == element)
            {
                if (current == head)
                {
                    head = current->next;
                    if (head != NULL)
                    {
                        head->previous = NULL;
                    }
                }
                else if (current == tail)
                {
                    tail = current->previous;
                    if (tail != NULL)
                    {
                        tail->next = NULL;
                    }
                }
                else
                {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                }
                delete current;
                size--;
                return;
            }
            current = current->next;
        }
    }

    void removeAt(int index)
    {
        assert(index >= 0 && index < size);
        NodoLista *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        if (current == head)
        {
            head = current->next;
            if (head != NULL)
            {
                head->previous = NULL;
            }
        }
        else if (current == tail)
        {
            tail = current->previous;
            if (tail != NULL)
            {
                tail->next = NULL;
            }
        }
        else
        {
            current->previous->next = current->next;
            current->next->previous = current->previous;
        }
        delete current;
        size--;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    T get(int index)
    {
        assert(index >= 0 && index < size);
        NodoLista *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->element;
    }

    int getSize()
    {
        return size;
    }
};

#endif