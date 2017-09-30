//单链表插入算法
int link_ins(NODE **head,int i,elemtype x)
{
    int j=1;
    NODE *p,*q;
    q=(NODE *)malloc(sizeof(NODE));
    q->data=x;
    if(i==0)
    {
        q->link=*head;
        *head=q;
        return(0);
    }
    p=*head;
    j=0;
    while(++j<i&&p!=NULL)
        p=p->link;
    if(i<0||j<i)
        return(1);
    else
    {
        q->link=p->link;
        p->link=q;
        return(0);
    }
}

//头插法建表
LinkList CreatListF(void)
{
    //返回单链表的头指针
    char ch;
    LinkList head;//头指针
    ListNode *s; //工作指针
    head=NULL; //链表开始为空
    ch=getchar(); //读入第 1 个字符
    while(ch!='\n')
    {
        s=(ListNode *)malloc(sizeof(ListNode));//生成新结点
        s->data=ch; //将读入的数据放入新结点的数据域中
        s->next=head;
        head=s;
        ch=getchar(); //读入下一字符
    }
    return head;
}

//尾插法建表
LinkList CreatListR(void)
{
    //返回单链表的头指针
    char ch;
    LinkList head;//头指针
    ListNode *s,*r; //工作指针
    head=NULL; //链表开始为空
    r=NULL;//尾指针初值为空
    ch=getchar(); //读入第 1 个字符
    while(ch!='\n')
    {
        s=(ListNode *)malloc(sizeof(ListNode));//生成新结点
        s->data=ch; //将读入的数据放入新结点的数据域中
        if (head!=NULL)
            head=s;//新结点插入空表
        else
            r->next=s;//将新结点插到*r 之后
        r=s;//尾指针指向新表尾
        ch=getchar(); //读入下一字符
    }//endwhile
    if (r!=NULL)
        r->next=NULL;//对于非空表，将尾结点指针域置空 head=s;
    return head;
}

//尾插法建带头结点链表算法
LinkList CreatListR1(void)
{
    //用尾插法建立带头结点的单链表
    char ch;
    LinkList head=(ListNode *)malloc(sizeof(ListNode));//生成头结点
    ListNode *s,*r; //工作指针
    r=head; // 尾指针初值也指向头结点
    while((ch=getchar())!='\n')
    {
        s=(ListNode *)malloc(sizeof(ListNode));//生成新结点
        s->data=ch; //将读入的数据放入新结点的数据域中
        r->next=s;
        r=s;
    }
    r->next=NULL;//终端结点的指针域置空，或空表的头结点指针域置空
    return head;
}


//单链表查找运算
ListNode* GetNode(LinkList head,int i)
{
    //在带头结点的单链表 head 中查找第 i 个结点，若找到（0≤i≤n），
//则返回该结点的存储位置，否则返回 NULL。
    int j;
    ListNode *p;
    p=head;
    j=0;//从头结点开始扫描
    while(p->next&&j<i) //顺指针向后扫描，直到 p->next 为 NULL 或 i=j 为止
    {
        p=p->next;
        j++;
    }
    if(i==j)
        return p;//找到了第 i 个结点
    else return NULL;//当 i<0 或 i>0 时，找不到第 i 个结点
}


//按值查找
ListNode* LocateNode (LinkList head,DataType key)
{
    //在带头结点的单链表 head 中查找其值为 key 的结点
    ListNode *p=head->next;//从开始结点比较。表非空，p 初始值指向开始结点
    while(p&&p->data!=key)//直到 p 为 NULL 或 p->data 为 key 为止
        p=p->next;//扫描下一结点
    return p;//若 p=NULL，则查找失败，否则 p 指向值为 key 的结点
}

//插入运算
void InsertList(LinkList head,DataType x,int i)
{
    //将值为 x 的新结点插入到带头结点的单链表 head 的第 i 个结点的位置上
    ListNode *p;
    p=GetNode(head,i-1);//寻找第 i-1 个结点
    if (p==NULL)//i<1 或 i>n+1 时插入位置 i 有错
        Error("position error")；
        s=(ListNode *)malloc(sizeof(ListNode));
    s->data=x;
    s->next=p->next;
    p->next=s;
}

//删除操作
void DeleteList(LinkList head,int i)
{
    //删除带头结点的单链表 head 上的第 i 个结点
    ListNode *p,*r;
    p=GetNode(head,i-1);//找到第 i-1 个结点
    if (p==NULL||p->next==NULL)//i<1 或 i>n 时，删除位置错
        Error("position error");//退出程序运行
    r=p->next;//使 r 指向被删除的结点 ai
    p->next=r->next;//将 ai 从链上摘下
    free(r);//释放结点 ai 的空间给存储池
}

