import java.util.ArrayList;
import java.util.List;
import java.util.Vector;


public class LRU {
    private static int N=5;        //页面的最长长度

    Object[] Seq = new Object[N];     //当前页面序列
    private int size;
    Vector<Object> Replace = new Vector<Object>();        //置换序列

    public LRU() {}

    public boolean isOverStack()      //序列是否溢出
    {
        if(size>=N) return true;
        else return false;
    }

    public int IndexofEle(Object o)      //元素o的位置
    {
        for (int i=0; i<N; i++) {
            if (o == Seq[i])
                return i;
        }
        return -1;
    }

    public Object Operate(Object o)   //元素o申请序列位置，并移除相应元素
    {
        int t=-1;
        if(!isOverStack() && IndexofEle(o)==-1)           //序列为满且元素o不在序列中
        {
            Seq[size]=o;
            size++;
        }

        else if(isOverStack() && IndexofEle(o)==-1)      //序列已满但元素o不在序列中
        {
            //此时需要进行置换
            Replace.add(Seq[0]);
            for(int i=0; i<size-1; i++) Seq[i]=Seq[i+1];
            Seq[size-1]=o;
        }
        else
        {

            t=IndexofEle(o);
            for(int i=t; i<size-1; i++) Seq[i]=Seq[i+1];
            Seq[size-1]=o;

        }
        if(t==-1) return null;
        else {
            return Seq[t];
        }
    }


    public void show()
    {
        System.out.println("页面序列：");
        for (int i=0; i<size; i++)
        {
            System.out.print(Seq[i]+"\t");
        }

    }

    public static void main(String[] args)
    {
        Integer iter[] ={4,7,0,7,1,0,1,2,1,2,6,5,8,7,4,3,1,9};
        LRU lru=new LRU();
        for(int i=0; i<iter.length; i++) {
            lru.Operate(iter[i]);
            lru.show();
            System.out.println();
        }
        System.out.println("置换的页面序列");
        for (int i=0; i<lru.Replace.size(); i++)
        {
            System.out.print(lru.Replace.get(i)+"\t");
        }
        System.out.println();
        System.out.println("共置换了"+lru.Replace.size()+"次");
    }
}