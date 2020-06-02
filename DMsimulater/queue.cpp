class MyQueue {
public:
    MyQueue(int queueCapacity); //初始化构建循环队列
    virtual ~MyQueue(); //销毁队列
    void ClearQueue(); //清空队列
    bool QueueEmpty() const; //判断队列是否为空
    bool QueueFull(); //判断队列是否为满
    int QueueLength() const; // 队列长度
    bool EnQueue(int element); // 向队列尾部添加元素
    bool DeQueue(int& element); //在队列中删除队头元素
    void QueueTraverse(); // 遍历队列
private:
    int* m_pQueue;   // 指向一个队列
    int m_iQueueLen;  // 队列长度
    int m_iQueueCapacity; //队列容量
    int m_iHead; //队头
    int m_iTail; //队尾
};
