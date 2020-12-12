#include <Iostream>
using namespace std;

class Node {
	public:
		int key;
		int data;
		Node* next;

		Node()
		{
			key = 0;
			data = 0;
			next = NULL;
		}
		Node(int k, int d)
		{
			key = k;
			data = d;
		}
};

class SinglyLinkedList {
	public:
		Node* head;
		
		SinglyLinkedList()
		{
			head = NULL;
		}
		SinglyLinkedList(Node *n)
		{
			head = n;
		}

		// 1. Check if node exists using key value
		Node* nodeExists(int k)
		{
			Node* temp = NULL;

			Node* ptr = head;
			while (ptr != NULL)
			{
				if (ptr->key == k)
				{
					temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}

		// Append a node to the List
		void appendNode(Node* n) {
			if (nodeExists(n->key)!=NULL) {
				cout << "Node already exists width key value: " << n->key << endl;
			}
			else {
				// 아무것도 안들어 있을 때
				if (head == NULL) {
					head = n;
					cout << "Node Append" << endl;
				}
				else {
					Node* ptr = head;
					// ptr을 마지막 노드로 위치
					while(ptr->next != NULL) {
						ptr = ptr->next;
					}
					// 마지막 노드에 추가
					ptr->next = n;
				}
			}
		}

		// 3. Prepend Node - Attach a node at the start
		void prependNode(Node* n) {
			if (nodeExists(n->key) != NULL) {
				cout << "Node already exists width key value: " << n->key << endl;
			}
			else {
				// 첫번째 노드인 head를 가리킨다.
				n -> next = head;
				// 그리고 n이 첫번째 노드가 된다.
				head = n;
				cout << "Node Prepended" << endl;
			}
		}

		// 4. Insert a Node after a particular node in the List
		void insertNodeAfter(int k, Node* n) {
			Node* ptr = nodeExists(k);
			// 조건1: k값 존재해야 함
			if (ptr == NULL)
			{
				cout << "No node exists width key value: " << k << endl;
			}
			else {
				// 조건2: n->key 존재 x
				if (nodeExists(n->key) != NULL) {
					cout << "Node already exists width key value: " << n->key << endl;
				}
				else {
					// k값 위치에서 n노드 추가
					n->next = ptr->next;
					ptr->next = n;
					cout << "Node Inserted" << endl;
				}
			}
		}

		// 5. Delete node by unique key
		void deleteNodeByKey(int k)
		{
			if (head == NULL)
			{
				cout << "Singly Linked List already Empty." << endl;
			}
			// 첫번째 노드라면 그냥 지운다.
			else if (head != NULL) {
				if (head->key == k) {
					head = head->next;
					cout << "Node Unlinked with keys value: " << k << endl;
				}
				else
				{
					Node* temp = NULL;
					// 이전 노드
					Node* prevptr = head;
					// 현재 노드
					Node* currentptr = head->next;
					while (currentptr != NULL)
					{
						// 위치 찾으면 temp에 저장
						if (currentptr->key == k)
						{
							temp = currentptr;
							currentptr = NULL;
						}
						else {
							// 다음 노드로 이동
							prevptr = prevptr->next;
							currentptr = currentptr->next;
						}
					}
					// 위치 찾았을 경우 이전 노드의 위치만 다다음 노드로 바꿔줌(제거)
					if (temp != NULL)
					{
						prevptr->next = temp->next;
						cout << "Node Unlinked with keys value : " << k << endl;
					}
					else
					{
						cout << "Node Doesn't exist with key value : " << k << endl;
					}
				}
			}
			
		}

		// 6. update node
		void updateNodeByKey(int k, int d)
		{
			Node* ptr = nodeExists(k);
			if (ptr != NULL)
			{
				ptr->data = d;
				cout << "Node data updated successfully" << endl;
			}
			else
			{
				cout << "Node Doesn't exist with key value : " << k << endl;
			}
		}

		// 7. printing
		void printList()
		{
			if (head == NULL)
			{
				cout << "Node Nodes in Singly Linked List";
			}
			else
			{
				cout << endl << "Singly Linked List Values : " ;
				Node* temp = head;

				while (temp != NULL)
				{
					cout<<"("<<temp->key<<","<<temp->data<<") --> ";
					temp = temp->next;
				}
			}
		}
};
int main() {

	SinglyLinkedList s;
	int option;
	int key1, k1, data1;
	do {
		cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNodeAfter()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print()" << endl;
		cout << "7. Clear Screen" << endl << endl;

		cin >> option;
		Node* n1 = new Node();
		//Node n1;

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.appendNode(n1);
			//cout<<n1.key<<" = "<<n1.data<<endl;
			break;

		case 2:
			cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.prependNode(n1);
			break;

		case 3:
			cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
			cin >> k1;
			cout << "Enter key & data of the New Node first: " << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;

			s.insertNodeAfter(k1, n1);
			break;

		case 4:

			cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
			cin >> k1;
			s.deleteNodeByKey(k1);

			break;
		case 5:
			cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
			cin >> key1;
			cin >> data1;
			s.updateNodeByKey(key1, data1);

			break;
		case 6:
			s.printList();

			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);

	return 0;
}