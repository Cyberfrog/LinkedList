typedef struct linkedList LinkedList;
typedef struct node Node;

struct linkedList{
	Node* head;
	Node* tail;
	int count;
};
struct node
{
	void* data;
	Node* next;
};

LinkedList createList(void);
Node * create_node(void *data);
int add_to_list(LinkedList *,Node *);