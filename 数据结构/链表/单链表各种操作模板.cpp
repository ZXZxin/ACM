//����������㷨
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

//ͷ�巨����
LinkList CreatListF(void)
{
    //���ص������ͷָ��
    char ch;
    LinkList head;//ͷָ��
    ListNode *s; //����ָ��
    head=NULL; //����ʼΪ��
    ch=getchar(); //����� 1 ���ַ�
    while(ch!='\n')
    {
        s=(ListNode *)malloc(sizeof(ListNode));//�����½��
        s->data=ch; //����������ݷ����½�����������
        s->next=head;
        head=s;
        ch=getchar(); //������һ�ַ�
    }
    return head;
}

//β�巨����
LinkList CreatListR(void)
{
    //���ص������ͷָ��
    char ch;
    LinkList head;//ͷָ��
    ListNode *s,*r; //����ָ��
    head=NULL; //����ʼΪ��
    r=NULL;//βָ���ֵΪ��
    ch=getchar(); //����� 1 ���ַ�
    while(ch!='\n')
    {
        s=(ListNode *)malloc(sizeof(ListNode));//�����½��
        s->data=ch; //����������ݷ����½�����������
        if (head!=NULL)
            head=s;//�½�����ձ�
        else
            r->next=s;//���½��嵽*r ֮��
        r=s;//βָ��ָ���±�β
        ch=getchar(); //������һ�ַ�
    }//endwhile
    if (r!=NULL)
        r->next=NULL;//���ڷǿձ���β���ָ�����ÿ� head=s;
    return head;
}

//β�巨����ͷ��������㷨
LinkList CreatListR1(void)
{
    //��β�巨������ͷ���ĵ�����
    char ch;
    LinkList head=(ListNode *)malloc(sizeof(ListNode));//����ͷ���
    ListNode *s,*r; //����ָ��
    r=head; // βָ���ֵҲָ��ͷ���
    while((ch=getchar())!='\n')
    {
        s=(ListNode *)malloc(sizeof(ListNode));//�����½��
        s->data=ch; //����������ݷ����½�����������
        r->next=s;
        r=s;
    }
    r->next=NULL;//�ն˽���ָ�����ÿգ���ձ��ͷ���ָ�����ÿ�
    return head;
}


//�������������
ListNode* GetNode(LinkList head,int i)
{
    //�ڴ�ͷ���ĵ����� head �в��ҵ� i ����㣬���ҵ���0��i��n����
//�򷵻ظý��Ĵ洢λ�ã����򷵻� NULL��
    int j;
    ListNode *p;
    p=head;
    j=0;//��ͷ��㿪ʼɨ��
    while(p->next&&j<i) //˳ָ�����ɨ�裬ֱ�� p->next Ϊ NULL �� i=j Ϊֹ
    {
        p=p->next;
        j++;
    }
    if(i==j)
        return p;//�ҵ��˵� i �����
    else return NULL;//�� i<0 �� i>0 ʱ���Ҳ����� i �����
}


//��ֵ����
ListNode* LocateNode (LinkList head,DataType key)
{
    //�ڴ�ͷ���ĵ����� head �в�����ֵΪ key �Ľ��
    ListNode *p=head->next;//�ӿ�ʼ���Ƚϡ���ǿգ�p ��ʼֵָ��ʼ���
    while(p&&p->data!=key)//ֱ�� p Ϊ NULL �� p->data Ϊ key Ϊֹ
        p=p->next;//ɨ����һ���
    return p;//�� p=NULL�������ʧ�ܣ����� p ָ��ֵΪ key �Ľ��
}

//��������
void InsertList(LinkList head,DataType x,int i)
{
    //��ֵΪ x ���½����뵽��ͷ���ĵ����� head �ĵ� i ������λ����
    ListNode *p;
    p=GetNode(head,i-1);//Ѱ�ҵ� i-1 �����
    if (p==NULL)//i<1 �� i>n+1 ʱ����λ�� i �д�
        Error("position error")��
        s=(ListNode *)malloc(sizeof(ListNode));
    s->data=x;
    s->next=p->next;
    p->next=s;
}

//ɾ������
void DeleteList(LinkList head,int i)
{
    //ɾ����ͷ���ĵ����� head �ϵĵ� i �����
    ListNode *p,*r;
    p=GetNode(head,i-1);//�ҵ��� i-1 �����
    if (p==NULL||p->next==NULL)//i<1 �� i>n ʱ��ɾ��λ�ô�
        Error("position error");//�˳���������
    r=p->next;//ʹ r ָ��ɾ���Ľ�� ai
    p->next=r->next;//�� ai ������ժ��
    free(r);//�ͷŽ�� ai �Ŀռ���洢��
}

