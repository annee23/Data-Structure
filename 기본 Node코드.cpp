#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node* next;
    int value;
    Node() // �����ϸ鼭 �ʱ�ȭ
    {
        next = NULL;
        value = 0;
    }
};

struct List
{
    Node* head;
    List()
    {
        head = NULL;
    }
};

/* ����Ʈ�� �� �տ� ���ο� ��� �߰��ϴ� �Լ� */
void addFront(List* mylist, int value) {
    Node* new_node = new Node(); // ���ο� ��� ����
    new_node->value = value; // ��忡 ������ ����

    if (mylist->head == NULL) // ����Ʈ�� ����־����� new_node�� ����Ʈ�� ��尡 ��
        new_node->next = NULL;
    else                      // ������� �ʾҴٸ� ������ ��带 �ι�° ���(head->next)�� ����
        new_node->next = mylist->head;

    mylist->head = new_node;
}

/* ����Ʈ�� �� �� ��� �����ϴ� �Լ� */
int removeFront(List* mylist)
{
    if (mylist->head == NULL)   // ����Ʈ ����־����� -1 ����
        return -1;
    Node* tmp_node = mylist->head;  // ��� ������ �� �ּҸ� ã�� ���� �ӽ� ���
    int ret = tmp_node->value;  // ������ �� �����ϱ� ���ؼ� �ӽ÷� �����صδ� ����
    mylist->head = mylist->head->next;   // ������ �ι�° ��带 ���� ����
    delete tmp_node;    // �� �� ��� ����

    return ret;
}

int main() {
    int n;
    cin >> n;

    List mylist;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "addFront")
        {
            int num;
            cin >> num;
            addFront(&mylist, num);
        }
        else if (s == "removeFront")
        {
            int ans = removeFront(&mylist);
            cout << ans << "\n";
        }
    }

    return 0;
}