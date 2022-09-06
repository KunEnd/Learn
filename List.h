#include<iostream>
using namespace std;

typedef int Rank;//秩
#define ListNodePosi(T) ListNode<T>* //列表节点位置

template <typename T> 
struct ListNode//列表节点模板类
{
//成员
    T data; ListNodePosi(T) pred; ListNodePosi(T) succ;//数值、前驱、后继
//构造函数
    ListNode() {}//针对header和trailer的构造
    ListNode(T e, ListNodePosi(T) p=NULL, ListNodePosi(T) s=NULL)
        :data(e), pred(p), succ(s){}//默认构造器
//操作接口
    ListNodePosi(T) insertAsPred(T const& e);//紧靠当前节点之前插入新节点
    ListNodePosi(T) insertAsSucc(T const& e);//紧靠当前节点之后插入新结点
};

template <typename T> 
class List//列表模板类
{
private:
    int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;//规模、头哨兵、尾哨兵

protected:
    void init();//列表创建时的初始化
    int clear();//清除所有节点
    void copyNodes(ListNodePosi(T), int);//复制列表中自位置p起的n项
    void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int);//有序列表区间归并
    void mergeSort(ListNodePosi(T), int);//对从p开始连续的n个节点归并排序
    void selectionSort(ListNodePosi(T), int);//对从p开始连续的n个节点选择排序（×）
    void insertionSort(ListNodePosi(T), int);//对从p开始连续的n个节点插入排序（×）

public:
//构造函数
    List(){init();}//默认
    List(List<T> const& L);//整体复制列表L
    List(List<T> const& L, Rank r, int n);//复制列表L中自第r项起的n项
    List(ListNodePosi(T) p, int n);//复制列表中自位置p起的n项
//析构函数
    ~List();//释放所有节点
//只读访问接口
    Rank size() const{return _size;}//规模
    bool empty() const{return _size<=0;}//判空（×）
    T& operator [] (Rank r)const;//重载
    ListNodePosi(T) first() const {return header->succ;}//首节点位置
    ListNodePosi(T) last() const {return trailer->pred;}//末节点位置
    bool valid(ListNodePosi(T) p)//判断位置p是否对外合法
        {return p&&(trailer!=p)&&(header!=p);}//将头、尾节点等同于NULL
    int disordered() const;//判断列表是否已经排序
    ListNodePosi(T) find(T const& e) const//无序列表查找
        {return find(e, _size, trailer);}
    ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p)const;//无序区间查找
    ListNodePosi(T) search(T const& e) const//有序列表查找
        {return search(e, _size, trailer);}
    ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;//有序区间查找
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);//在p及其前n-1个后继中选出最大值
    ListNodePosi(T) selectMax(){return selectMax(header->succ, _size);}//整体最大值
//可写访问接口
    ListNodePosi(T) insertAsFirst(T const& e);//将e当作首节点插入
    ListNodePosi(T) insertAsLast(T const& e);//将e当作末节点插入
    ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const& e);//将e作为p的前驱插入
    ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const& e);//将e作为p的后继插入
    T remove(ListNodePosi(T) p);//删除合法位置p处的节点，返回被删除节点
    void merge(List<T>& L){merge(first(), size, L, L.first(), L._size);}//全列表归并
    void sort(ListNodePosi(T) p, int n);//列表区间排序
    void sort() {sort(first(), _size);}//列表整体排序
    int deduplicate();//无序去重
    int uniquify();//有序去重
    void reverse();//前后倒置
//遍历
    void traverse(void (*)(T&));//遍历，依次实施visit操作
    template <typename VST>//操作器
    void traverse(VST&);//遍历，依次实施visit操作
};//List

template <typename T>
void List<T>::init()//初始化列表，在创建列表对象时统一使用
{
    header=new ListNode<T>;//创建头节点
    trailer=new ListNode<T>;//创建尾节点
    header->succ=trailer;header->pred=NULL;
    trailer->pred=header;trailer->succ=NULL;
    _size=0;//规模置0
}

template <typename T>
T& List<T>::operator[](Rank r)const//重载下标操作符，已通过秩直接访问列表节点
{
    ListNodePosi(T) p=first();//从首节点出发
    while(r-->0)p=p->succ;//顺次第r个节点就是
    return p->data;//返回节点的秩
}

template <typename T>//在无序列表内节点p的n个前驱中，找到等于e的节点
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p)const
{
    while(n-- > 0)//对于p的n个前驱，从右向左
        if(e==(p=p->pred)->data)) return p;//逐个比对直到越界
    return NULL;//查找失败返回NULL
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e)//e当作首节点插入
{_size++;return header->insertAsSucc(e);}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e)//e当作末节点插入
{_size++;return trailer->insertAsPred(e);}

template <typename T>
ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T const& e)//e当作p的前驱插入
{_size++;return p->insertAsPred(e);}

template <typename T>
ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const& e)//e当作p的后继插入
{_size++;return p->insertAsSucc(e);}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e)//将e紧靠当前节点之前插入当前节点所属列表
{
    ListNodePosi(T) x=new ListNode(e, pred, this);//创建新节点
    pred->succ=x; pred=x;//设置正向链接
    return x;//返回新节点的位置
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e)//将e紧靠当前节点之后插入当前节点所属列表
{
    ListNodePosi(T) x=new ListNode(e, succ, this)//创建新节点
    succ->pred=x; succ=x;//设置逆向链接
    return x;//返回新节点位置
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n)//复制列表中自p起的n项
{
    init();//初始化
    while(n--) {insertAsFirst(p->data); p=p->succ;}//将自p起n项依次作为末节点进行插入
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n)//复制列表中自p起的n项
{copyNodes(p, n);}

template <typename T>
List<T>::List(List<T> const& L)//整体复制列表L
{copyNodes(L.first(), L._size);}

template <typename T>
List<T>::List(List<T> const& L, int r, int n)//复制L中自第r项起的n项
{copyNodes(L[r], n);}

template <typename T>
T List<T>::remove(ListNodePosi(T) p)//删除合法位置p处节点，返回其数值
{
    T e = p->data;
    p->pred->succ=p->succ;//p的前节点的后继指向p的后继
    p->succ->pred=p->pred;//p的后节点的前驱指向p的前驱
    delete p;_size--;//释放节点，更新规模
    return e;//返回备份数据
}

template <typename T>
List<T>::~List()//列表析构函数
{clear();delete header;delete trailer;}//清空列表，删除头节点、尾节点

template <typename T>
int List<T>::clear()//清空列表
{
    int oldSize=_size;//保留原规模
    while(_size<0)remove(header->succ);反复删除首节点，直到列表清空
    return oldSize;
}

template <typename T>
int List<T>::deduplicate()//剔除无序列表中的重复节点
{
    if(_size < 2)return 0;//无重复
    int oldSize=_size;//记录原规模
    ListNodePosi(T) p=header->pred;Rank r=0;//p从首节点开始
    while((p=p->succ)!=trailer)//依次直到末节点
    {
        ListNodePosi(T) q=find(p->data, r, p);
        q ? remove(q):r++;//若存在则删除，不存在则秩加一
    }
    return oldSize - _size;//返回列表规模变化，即被删除元素总数
}

template <typename T>
void List<T>::traverse(void (*visit)(T&))//利用函数指针机制的遍历
{for(ListNodePosi(T) p = header->succ;p != trailer;p = p->succ)visit(p->data);}

template <typename T> template <typename VST>
void List<T>::traverse(VST& visit)//利用函数对象机制的遍历
{for(ListNodePosi(T) p = header->succ;p != trailer;p = p->succ)visit(p->data);}

template <typename T>
int List<T>::uniquify()//有序列表的唯一化
{
    if(_size<2)return 0;//无重复返回0
    int oldSize=_size;//记录原规模
    ListNodePosi(T) p;ListNodePosi(T) q;
    for(p=header->succ,q=p->succ;trailer != q;p=q, q=q->succ)
        if(p->data==q->data){remove(q);q=p;}//若相同删除后面位元素
    return oldSize - _size;//返回被删除的元素数量
}

template <typename T>//在有序列表内节点p的n个前驱中，找到不大于e的最后者
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p)const
{
    while(n--)
        if(((p=p->succ)->data)<=e)break;//直到命中或者越界
    return p;//返回查找到的终止位置
}

template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n)//列表区间排序
{
    switch(rand() % 3)//随机选取排序算法，可根据具体问题的特点灵活选取
    {
        case 1:insertionSort(p, n);break;//插入排序
        case 2:selectionSort(p, n);break;//选择排序
        case 3:mergeSort(p, n);break;//归并排序
    }
}

template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n)//列表的插入排序，对起始位置p的n个元素排序
{
    for(int r=0;i<ne;r++)//逐一进行检查
    {
        insertAfter(search(p->data, r, p), p->data);//寻找合适位置进行插入
        p=p->succ;remove(p->pred);//转向下一节点，并删除原节点
    }
}

template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n)//列表的选择排序算法，对起始位置p的n个元素排序
{
    ListNodePosi(T) head=p->pred;ListNodePosi(T) tail=p;
    for(int i=0;i<n;i++)tail=tail->succ;//待排序区间为(head, tail)
    while(1<n)//在至少还剩两个节点之前，在待排序区间内
    {
        ListNodePosi(T) max=selectMax(head->succ, n);//找出最大者
        insertBefore(tail, remove(max));//将其移至无序区间末尾
        tail=tail->pred;n--;
    }
}

template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n)//从起始p的n个元素中找出最大值
{
    ListNodePosi(T) max=p;//最大者暂定为首节点p
    for(ListNodePosi(T) cur=p;1<n;n--)//从首节点出发，将后续节点逐一与max进行比较
        if(!lt((cur=cur->succ)->data, max->data))//若当前元素不小于max
            max=cur;//更新最大元素位置
    return max;//返回最大节点位置
}

template <typename T>//有序列表的归并：当前列表自p起n个元素，与列表L中自q起m个元素归并
void List<T>::merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m)
{
    ListNodePosi(T) pp=p->pred;//借助前驱，以便返回
    while(0<m)//在q尚未移处区间之前
        if((0<n) && (p->data <= q->data))//若p仍在区间内且满足条件
            {if(q==(p=p->succ))break;n--}//将p替换成其后继
        else
            {insertBefore(p, L.remove((q=q->succ)->pred));m--;}//将q移到p之前
    p=pp->succ;//确定归并后区间的新起点
}

template <typename T>
void List<T>::mergeSort(ListNodePosi(T) p, int n)//列表的归并排序算法，对起始位置p的n个元素排序
{
    if(n<2)return;
    int m=m/2;
    ListNodePosi(T) q=p;for(int i=0;i<m;i++)q=q->succ;
    mergeSort(p, m);mergeSort(q, n-m);//对前后子列表分别排序
    merge(p, m, *this, q, n-m);//归并
}


