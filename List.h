template <typename T>
struct Node2 {
    T value;
    Node2* next = nullptr;
    Node2* prev = nullptr;
    bool operator ==(const Node2<T>& object)
    {
        return this->value == object.value;
    }

};

template <typename T>
class List {
    Node2<T>* head = nullptr;
    Node2<T>* tail = nullptr;
    int counter = 0;
public:
    List() {}
    List(T& object) {
        Node2<T>* node = new Node2<T>{ object };
        head = node;
        tail = node;
        counter++;
    }
    void addToHead(T& object) {
        if (counter == 0) {
            Node2<T>* node = new Node2<T>{ object };
            head = node;
            tail = node;
            counter++;
        }
        else {
            Node2<T>* node = new Node2<T>{ object, head,nullptr };
            head->prev = node;
            head = node;
            counter++;
        }
    }
    void addToTail(T& object) {
        if (counter == 0) {
            Node2<T>* node = new Node2<T>{ object };
            head = node;
            tail = node;
            counter++;
        }
        else {
            Node2<T>* node = new Node2<T>{ object, nullptr, tail };
            tail->next = node;
            tail = node;
            counter++;
        }
    }
    void deleteFromHead() {
        if (counter != 0) {
            //Node2<T>* buf = head;
            if (counter == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
                counter--;
            }
            else {
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
                counter--;
            }
        }
    }
    void deleteFromTail() {
        if (counter != 0) {
            if (counter == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
                counter--;
            }
            else {
                Node2<T>* buf = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete buf;
                counter--;
            }
        }
    }
    void deleteAll() {
        while (counter != 0) {
            deleteFromHead();
        }
        head = nullptr;
    }
    void insert(T data, int index)
    {
        if (index == 0)
        {
            addToHead(data);
        }
        else if (counter / 2 >= index)
        {
            Node2<T>* buf = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                buf = buf->next;

            }
            buf->next = new Node2<T>{ data,buf->next,buf };
            buf->next->next->prev = buf->next;
        }
        else if (counter / 2 < index)
        {
            Node2<T>* buf = this->tail;
            for (int i = counter; i > index + 1; i--)
            {
                buf = buf->prev;

            }
            buf->prev = new Node2<T>{ data,buf,buf->prev };
            buf->prev->prev->next = buf->prev;
        }
        counter++;
    }
    void revers()
    {
        Node2<T>* buf = this->head;
        Node2<T>* buf2 = this->tail;
        for (int i = 0; i < counter / 2; i++)
        {
            swap(buf->value, buf2->value);
            buf = buf->next;
            buf2 = buf2->prev;
        }
    }
    List<T>& operator =(List<T>& object)
    {
        Node2<T>* buf = object.head;
        while (buf->next!=nullptr)
        {
            addToHead(buf->value);
            buf = buf->next;
        }
        addToHead(buf->value);
        return *this;
    }
    List<T>& operator+(List<T>& object)
    {
        int size = this->counter + object.counter;
        List<T>* buf = new List<T>[size];
        Node2<T>* buf2 = this->head;
        while (buf2->next != nullptr)
        {
            buf->addToHead(buf2->value);
            buf2 = buf2->next;
        }
        buf->addToHead(buf2->value);
        Node2<T>* buf3 = object.head;
        while (buf3->next != nullptr)
        {
            buf->addToHead(buf3->value);
            buf3 = buf3->next;
        }
        buf->addToHead(buf3->value);
        return *buf;
    }
    List<T>& operator *(List<T>& object)
    {
        Node2<T>* buf2 = head;      
        while (buf2->next != nullptr)
        {
            Node2<T>* buf3 = object.head;
            while (buf3->next != nullptr)
            {
                if (buf2->value!=buf3->value) {
                    buf3 = buf3->next;
                }                
                else {
                    addToHead(buf3->value);
                    break;
                }
            }
            buf2 = buf2->next;
        }
        Node2<T>* buf3 = object.head;
        while (buf3->next != nullptr)
        {
            if (buf2->value != buf3->value) {
                buf3 = buf3->next;
            }
            else {
                addToHead(buf3->value);
                break;
            }
        }
        return *this;
    }
    void show() {
        if (counter != 0) {
            Node2<T>* buf = head;
            while (buf->next != nullptr) {
                cout << buf->value << ", ";
                buf = buf->next;
            }
            cout << buf->value << endl;
        }
    }
};


