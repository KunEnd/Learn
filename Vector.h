#include<iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3  //默认的初始容量

template <typename T> class Vector//向量模板
{
protected:
    Rank _size; int _capacity; T* _elem; //规模、容量、数据区
    void copyFrom(T const* A, Rank lo, Rank hi); //复制数组区间A[lo, hi)
    void expand(); //空间不足时扩容
    void shrink(); //装填因子过小时压缩
    bool bubble(Rank lo, Rank hi); //扫描交换
    void bubbleSort(Rank lo, Rank hi); //冒泡排序
    Rank max(Rank lo, Rank hi); //选取最大值（×）
    void selectionSort(Rank lo, Rank hi); //选择排序
    void merge(Rank lo, Rank mi, Rank hi); //归并
    void mergeSort(Rank lo, Rank hi); //归并排序
    Rank partition(Rank lo, Rank hi); //轴点创造算法（×）
    void quickSort(Rank lo, Rank hi); //快速排序（×）
    void heapSort(Rank lo, Rank hi); //堆排序（×）
public:
//构造函数
    Vector(int c=DEFAULT_CAPACITY, int s=0, T v=0)//容量为c，规模为s、所有元素初始为v
    {
        _elem=new T[_capacity=c];
        for(_size=0;_size<s;_elem[_size++]=v);//s<=c
    }
    Vector(T const* A, Rank lo, Rank hi){copyFrom(A, lo, hi);}//数组区复制
    Vector(T const* A, Rank n){copyFrom(A,0,n);}//数组整体复制
    Vector(Vector<T> const &V, Rank lo, Rank hi){copyFron(V._elem, lo, hi);}//向量区间复制
    Vector(Vector<T> const &V){copyFrom(V._elem, 0, V._size);}//向量整体复制
//析构函数
    ~Vector(){delete [] _elem;}//释放内部空间
//只读访问接口
    Rank size() const {return _size;}//规模
    bool empty() const {return !_size;}//判空
    int disordered() const; //判断向量是否已排序
    Rank find(T const& e, Rank lo, Rank hi) const;//无序向量区间查找
    Rank find(T const& e) const {return find(e, 0, _size);}//无序向量整体查找
    Rank search(T const& e) const//有序向量整体查找
    {return (0>= _size) ? -1 : search(e, 0, _size);}
    Rank search(T const& e, Rank lo, Rank hi) const;//有序向量区间查找
//可写访问接口
    T& operator[](Rank r)const;//重载下标操作符，可以类似于数组形式引用各元素
    Vector<T> & operator=(Vector<T> const&);//重载赋值操作符号，以便直接克隆向量
    T remove(Rank r);//删除秩为r的元素
    int remove(Rank lo, Rank hi);//删除秩在区间[lo, hi)之内的元素
    Rank insert(Rank r, T const& e);//插入元素
    Rank insert(T const& e){return insert(_size, e);}//默认作为末元素插入
    void sort(Rank lo, Rank hi);//对[lo, hi)排序
    void sort();//整体排序
    void unsort(Rank lo, Rank hi);//对[lo, hi)置乱
    void unsort();//整体置乱
    int deduplicate();//无序去重
    int uniquify();//有序去重
//遍历
    void traverse(void (*)(T&)); //遍历（使用函数指针，只读或局部性修改）
    template <typename VST> void traverse(VST&);//遍历（使用函数对象，可全局性修改）
};

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)//以数组区间A[lo, hi)为蓝本复制向量
{
    _elem=new T[_capacity=2*(hi-lo)];_size=0;//分配空间，规模清零
    while(lo<hi)
        _elem[_size++]=A[lo++];//将A[lo, hi)逐一复制到_elem[0,hi-lo)
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V)//重载赋值操作符
{
    if(_elem)delete[] _elem;//释放原内容
    copyFrom(V._elem, 0, V.size());//整体赋值
    return *this;//返回当前对象的引用
}

template <typename T> 
void Vector<T>::expand()//向量空间不足时扩容
{
    if(_size<_capacity)return;//未满，不必扩容
    if(_size<DEFAULT_CAPACITY) _capacity=DEFAULT_CAPACITY;//不小于最小容量
    T* oldElem=_elem; _elem=new T[_capacity*2];//容量加倍
    for(int i=0;i<_size;i++)
        _elem[i]=oldElem[i];//复制向量内容
    delete [] oldElem;//释放原空间
}

template <typename T>
void Vector<T>::shrink()//装填因子过小压缩向量所需空间
{
    if(_capacity<DEFAULT_CAPACITY <<1)return;//不致收缩到DEFAULT_CAPACITY以下
    if(_size<<2 > _capacity)return;//以25%为界
    T* oldElem=_elem;_elem=new T[_capacity>>=1];//容量减半
    for(int i=0;i<_size;i++)
        _elem[i]=oldElem[i];//复制原向量内容
    delete [] oldElem;//释放原空间
}

template <typename T>
T& Vector<T>::operator[](Rank r)const//重载[]
{
    return _elem[r];
}

template <typename T> 
void permute(Vector<T> &V)//随机置乱向量，使各元素等概率出现在每一个位置
{
    for(int i=V.size();i>0;i--)
        swap(V[i-1], V[rand() % i]);//V[i-1]与V[0,i)中某一随机元素交换
}

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)//等概率随机置乱向量区间[lo, hi)
{
    T* V=_elem+lo;
    for(Rank i=hi-lo;i>0;i--)
        swap(V[i-1], V[rand() % i]);//将V[i-1]与V[0,i)中某一随机元素交换
}

template <typename T> static bool lt(T* a, T* b){return lt(*a,*b);}//less than
template <typename T> static bool lt(T& a,T& b){return a<b;}//less than
template <typename T> static bool eq(T* a, T* b){return eq(*a, *b);}//equal
template <typename T> static bool eq(T& a,T& b){return a==b;}//equal

template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const//无序向量的顺序查找，返回最后一个元素e的位置
{
    while((lo<hi--)&&(e!=_elem[hi]));//从后往前，顺序查找
        return hi;//若hi<lo，表示查找失败，否则hi命中元素的秩
}

template <typename T>
Rank Vector<T>::insert(Rank r,T const& e)//将e作为秩为r的元素插入
{
    expand();//如果有必要，进行扩容
    for(int i=_size;i>r;i--)_elem[i]=_elem[i-1];//从后往前，后继元素顺次后移一单位
    _elem[r]=e;_size++;//置入新元素并更新规模
    return r;//返回秩
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)//删除区间[lo, hi)
{
    if(lo==hi)return 0;
    while(hi<_size)_elem[lo++]=_elem[hi++];//[hi, _size)的数据顺次前移hi-lo个单位
    _size=lo;//更改规模，丢弃尾部[lo, _size=)区间
    shrink();//如果有必要，进行缩容
    return(hi-lo);//返回被删除元素数量
}

template <typename T>
T Vector<T>::remove(Rank r)//删除向量中秩为r的元素
{
    T e=_elem[r];//备份被删除的元素
    remove(r, r+1);//调用区间删除，等效于对区间[r, r+1)的删除
    return e;//返回被删除的元素
}

template <typename T>
int Vector<T>::deduplicate()//删除无序向量中重复的元素
{
    int oldsize=_size;//记录未删除前的规模
    Rank i=1;//从1开始
    while(i<_size)
        (find(_elem[i], 0, i)<0) ? i++:remove(i);//访问到_elem[i]时，遍历遍历前面的元素，如果有相同的删除，否则继续
    return oldsize - _size;//向量规模变化，即是被删除的元素数量
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T&))//利用指针机制的遍历
{for(int i=0;i<_size;i++)visit(_elem[i]);}

template <typename T> template <typename VST>//元素类型、操作器
void Vector<T>::traverse(VST& visit)//利用函数对象机制的遍历
{for(int i=0;i<_size;i++)visit(_elem[i]);}

template <typename T>
int Vector<T>::disordered() const//返回向量中逆序相邻元素对的总数
{
    int n=0;//计数器
    for(int i=1;i<_size;i++)
        if(_elem[i-1]>_elem[i])n++;//逐一检查_size-1对相邻元素
    return n;//向量有序当且仅当n=0
}

template <typename T>
int Vector<T>::uniquify()//有序向量重复元素提出算法
{
    Rank i=0,j=0;
    while(++j<_size)//逐一扫描直到末元素
        if(_elem[i] != _elem[j])//跳过相同的
            _elem[++i]=_elem[j];//发现不同的元素，向前移到紧邻于前者
    _size=++i;shrink();//直接截取尾部多余的元素
    return j-i;//向量规模变化量，即被删除元素数量
}

template <typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi)const//在有序区间内，查找指定秩
{
    return(rand() % 2)?
        binSearch(_elem, e, lo, hi) : binSearch0(_elem, e, lo, hi);//二分查找或者Fibonacci查找
}

//二分法查找算法：在有序向量区间[lo, hi)内查找元素e
template <typename T>static Rank binSearch(T* A, T const& e, Rank lo, Rank hi)
{
    while(lo<hi)
    {
        Rank mi=(lo+hi)/2;//以中点为轴
        if(e<A[mi])hi=mi;//向前面查找
        else if(e>A[mi])lo=mi;//向后面查找
        else return mi;//mi处命中
    }//查找成功提前结束
    return -1;//查找失败返回-1
}

//二分查找算法另一版本，
template <typename T> static Rank binSearch0(T* A, T const& e, Rank lo, Rank hi)
{
    while(1<hi-lo)//每步迭代仅需做一次比较判断，有两个分支
    {
        Rank mi=(lo+hi)/2;//以中点为轴
        (e<A[mi])?hi=mi:lo=mi;//经比较确定深入[lo, mi)或[mi, hi)
    }//出口时hi=lo+1，查找区间仅含一个元素A[lo]
    return (e==A[lo])?lo:-1;//查找成功返回对应的秩，否则返回-1
}

template <typename T> 
void Vector<T>::sort(Rank lo, Rank hi)//向量[lo, hi)排序
{
    switch (rand() % 5)//随机选取排序算法
    {
        case 1:bubbleSort(lo, hi);break;//冒泡排序表
        case 2:selectionSort(lo, hi);break;//选择排序
        case 3:mergeSort(lo, hi);break;//归并排序
        case 4:heapSort(lo, hi);break;//堆排序
        default:quickSort(lo, hi);break;//快速排序
    }
}

template <typename T>//向量的气泡排序
void Vector<T>::bubbleSort(Rank lo, Rank hi)
{while(!bubble(lo, hi--));}//逐趟做扫描交换，直到全序

template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi)//一趟扫描交换
{
    bool sorted=true;//标志是否有序
    while(++lo<hi)//从左到右扫描
        if(_elem[lo-1] > _elem[lo])
        {
            sorted=false;//仍然是无序
            swap(_elem[lo-1], _elem[lo]);//交换使局部有序
        }
    return sorted;//返回有序标志
}

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi)//向量归并排序
{
    if(hi-lo<2)return;//
    int mi=(lo+hi)/2;//以中心为轴
    mergeSort(lo, mi);mergeSort(mi, hi);merge(lo, mi, hi);//分别对前后半段进行排序，然后归并
}

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi)//有序向量的归并
{
    T* A=_elem+lo;//合并后的向量A[0, hi-lo)=_elem[lo, hi]
    int lb=mi-lo;T* B=new T[lb];//前子向量B[0, lb]=_elem[lo, mi]
    for(Rank i=0;i<lb;B[i]=A[i++]);//复制前子向量
    int lc=hi-mi;T* C=_elem+mi;//后子向量c[0, lc]=_elem[mi, hi]
    for(Rank i=0, j=0, k=0;(j<lb)||(k<lc);)//将B[j]和c[k]中的小者续到A末尾
    {
        if((j<lb)&&(!(k<lc)||(B[j]<=C[k])))A[i++]=B[j++];
        if((k<lc)&&(!(j<lb)||(C[k]< B[j])))A[i++]=C[k++];
    }
    delete [] B;//释放临时空间B
}
