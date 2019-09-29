#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node* next;
    int value;
    Node() // 생성하면서 초기화
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

/* 리스트의 맨 앞에 새로운 노드 추가하는 함수 */
void addFront(List* mylist, int value) {
    Node* new_node = new Node(); // 새로운 노드 생성
    new_node->value = value; // 노드에 데이터 저장

    if (mylist->head == NULL) // 리스트가 비어있었으면 new_node가 리스트의 헤드가 됨
        new_node->next = NULL;
    else                      // 비어있지 않았다면 기존의 헤드를 두번째 노드(head->next)로 설정
        new_node->next = mylist->head;

    mylist->head = new_node;
}

/* 리스트의 맨 앞 노드 삭제하는 함수 */
int removeFront(List* mylist)
{
    if (mylist->head == NULL)   // 리스트 비어있었으면 -1 리턴
        return -1;
    Node* tmp_node = mylist->head;  // 노드 삭제할 때 주소를 찾기 위한 임시 노드
    int ret = tmp_node->value;  // 삭제될 값 리턴하기 위해서 임시로 저장해두는 변수
    mylist->head = mylist->head->next;   // 기존의 두번째 노드를 헤드로 설정
    delete tmp_node;    // 맨 앞 노드 삭제

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