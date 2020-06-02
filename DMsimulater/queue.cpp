class MyQueue {
public:
    MyQueue(int queueCapacity); //��ʼ������ѭ������
    virtual ~MyQueue(); //���ٶ���
    void ClearQueue(); //��ն���
    bool QueueEmpty() const; //�ж϶����Ƿ�Ϊ��
    bool QueueFull(); //�ж϶����Ƿ�Ϊ��
    int QueueLength() const; // ���г���
    bool EnQueue(int element); // �����β�����Ԫ��
    bool DeQueue(int& element); //�ڶ�����ɾ����ͷԪ��
    void QueueTraverse(); // ��������
private:
    int* m_pQueue;   // ָ��һ������
    int m_iQueueLen;  // ���г���
    int m_iQueueCapacity; //��������
    int m_iHead; //��ͷ
    int m_iTail; //��β
};
