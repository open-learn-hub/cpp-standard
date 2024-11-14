#ifndef LINKED_LIST_DOUBLY_H
#define LINKED_LIST_DOUBLY_H
namespace dll
{
    template<typename T>
    struct Node
    {
        T data;
        Node<T>* pNext;
        Node<T>* pPrevious;
    };

    template<typename T>
    struct List
    {
        Node<T>* pHead;
        Node<T>* pTail;
    };
    
    template<typename T>
    List<T>* CreateList()
    {
        List<T>* list = new List<T>();
        list->pHead = nullptr;
        list->pTail = nullptr;
        return list;
    }

    template<typename T>
    Node<T>* CreateNode(T data)
    {
        Node<T>* n = new Node<T>();
        n->data = data;
        n->pNext = nullptr;
        n->pPrevious = nullptr;
        return n;
    }

    template<typename T>
    void Add(List<T>* list, const T value) 
    { 
        Node<T>* n = CreateNode<T>(value);
        if (list->pHead == nullptr)
        {
            list->pHead = n;
            list->pTail = n;
        }
        else
        {
            n->pNext = nullptr;
            n->pPrevious = list->pTail;
            list->pTail->pNext = n;
            list->pTail = n;
        }
    }

    template<typename T>
    void AddHead(List<T>* list, const T value) 
    { 
        Node<T>* n = CreateNode<T>(value);
        if (list->pHead == nullptr)
        {
            list->pHead = n;
            list->pTail = n;
        }
        else
        {
            n->pNext = list->pHead;
            list->pHead->pPrevious = n;   
            list->pHead = n;
        }
    }

    template<typename T>
    bool Remove(List<T>* list, const T value)
    {
        if (list == nullptr) return false;

        Node<T>* current = list->pHead;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                
                if (current == list->pHead && current == list->pTail)
                {
                    // The list contains only one item and it is being removed
                    list->pHead = nullptr;
                    list->pTail = nullptr;
                }
                else if (current == list->pHead)
                {
                    // Removing head
                    list->pHead = current->pNext;
                    list->pHead->pPrevious = nullptr;
                }
                else if (current == list->pTail)
                {
                    // Removing tail
                    list->pTail = current->pPrevious;
                    list->pTail->pNext = nullptr;
                }
                else
                {
                    // Removing the node in the middle
                    Node<T>* it1 = current->pPrevious;
                    // it2 is current
                    Node<T>* it3 = current->pNext;
                    it1->pNext = it3;
                    it3->pPrevious = it1;
                }

                // Terminate
                return true;
            }
            current = current->pNext;
        }
        return false;
    }

    template<typename T>
    int Count(const List<T>* list)
    {
        if (list == nullptr) return 0;

        Node<T>* current = list->pHead;
        int count = 0;
        while (current != nullptr)
        {
            count++;
            current = current->pNext;
        }
        return count;
    }

    template<typename T>
    int Count(const List<T>* list, std::function<bool(T)> predicate)
    {
        if (list == nullptr) return 0;

        Node<T>* current = list->pHead;
        int count = 0;
        while (current != nullptr)
        {
            if (predicate == nullptr || predicate(current->data))
            {
                count++;
            }
            current = current->pNext;
        }
        return count;
    }

    template<typename T>
    bool GetByIndex(const List<T>* list, const int index, T& outValue)
    {
        Node<T>* current = list->pHead;
        int count = 0;
        while (current != nullptr)
        {
            
            current = current->pNext;
            count++;

            if (count == index)
            {
                outValue = current->data;
                return true;
            }
        }
        return false;
    }
    
    template<typename T>
    bool InsertAtIndex(List<T>* list, const int index, const T value)
    {
        Node<T>* current = list->pHead;
        int count = 0;
        Node<T> n = CreateNode<T>(value);

        if (list->pHead == nullptr && index == 0)
        {
            list->pHead = n;
            list->pTail = n;
            return true;
        }

        while (current != nullptr)
        {
            if (count == index)
            {
                if (current == list->pHead)
                {
                    n->pNext = current;
                    current->pPrevious = n;
                    list->pHead = n;
                }
                else if (current == list->pTail)
                {
                    n->pPrevious = list->pTail->pPrevious;
                    n->pNext = list->pTail;

                    list->pTail->pPrevious->pNext = n;
                    list->pTail->pPrevious = n;
                }
                else 
                {
                    n->pNext = current;
                    n->pPrevious = current->pPrevious;
                    current->pPrevious->pNext = n;
                }
                return true;
            }
            count++;
            current = current->pNext;
        }

        delete n;
        n = nullptr;
        return false;
    }

    template<typename T>
    void Foreach(List<T>* list, std::function<void(T)> handler) 
    { 
        if (handler == nullptr || list == nullptr) return;

        Node<T>* current = list->pHead;
        while (current != nullptr)
        {
            handler(current->data);
            current = current->pNext;
        }
    }
}
#endif