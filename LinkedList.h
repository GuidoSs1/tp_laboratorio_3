#ifndef __LINKEDLIST
#define __LINKEDLIST

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif


/** \brief Funcion que crea una LinkedList en memoria de forma dinamica
 *
 * \param void
 * \return un espacio en memoria || NULL si no encontro espacio en memoria
 *
 */
LinkedList* ll_newLinkedList(void);

/** \brief Funcion que retorna la cantidad de elementos en la lista enlazada
 *
 * \param LinkedList* puntero a la lista enlazada
 * \return la cantidad de elementos en la lista enlazada || NULL si el puntero es nulo
 *
 */
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);

int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Funcion que agrega un elemento a la lista enlazada
 *
 * \param LinkedList* puntero a la lista enlazada
 * \param void* puntero del elemento que es agregado a lista
 * \return 0 si se agrego el elemento || -1 si hubo un error o el puntero es NULL
 *
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief Funcion que toma un elemento de la lista enlazada
 *
 * \param LinkedList* puntero a la lista enlazada
 * \param int indice del elemento en la lista
 * \return 0 si tomo el elemento en la lista correctamente || -1 si hubo un error o el puntero es nulo
 *
 */
void* ll_get(LinkedList* this, int index);

/** \brief Funcion que remueve un elemento de la lista enlazada
 *
 * \param LinkedList* puntero a la lista enlazada
 * \param int indice del elemento a remover en la lista
 * \return 0 si removio el elemento de la lista correctamente || -1 si hubo un error o el puntero es nulo
 *
 */
int ll_remove(LinkedList* this,int index);

/** \brief Funcio que remueve todos los elementos en la lista dejandola vacia
 *
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si removio todos los elementos de la lista || -1 si hubo un error o el puntero es nulo
 *
 */
int ll_clear(LinkedList* this);

/** \brief Funcion que elimina la lista enlazada completamente
 *
 * \param LinkedList* puntero a la lista enlazada
 * \return 0 si la lista fue eliminada con exito || -1 si hubo un error o el puntero es nulo
 *
 */
int ll_deleteLinkedList(LinkedList* this);

int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);

/** \brief Funcion que permite ordenar los elementos de la lista enlazada segun el ordenamiento del puntero a funcion
 *
 * \param LinkedList* puntero a la lista enlazada
 * \param int (*pFunc) (void*, void*) puntero a la funcion de ordenamiento
 * \param int 1 para ordenar de forma ascendete || 0 para ordenar de forma descendente
 * \return 0 si pudo ordenar la lista correctamente || -1 si hubo un error
 *
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

/** \brief Funcio que permite modificar un elemento en la lista enlazada
 *
 * \param LinkedList* puntero a la lista enlazada
 * \param int indice del elemento a modificar en la lista
 * \param void* puntero al nuevo elemento modificado
 * \return 0 si el elemento fue modificado con exito || -1 si hubo un error
 *
 */
int ll_set(LinkedList* this, int index,void* pElement);


int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);

int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);

LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);


