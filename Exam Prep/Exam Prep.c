void moveToEnd(Node* &front, Node* &end, int k)
{
    end->next = front;
    k--;
    if (k > 0)
    {
        moveToEnd(front->next, end, k)
    }
}

void dutch(int* list, int size)
{
    int mid = size/2;

    if 
}